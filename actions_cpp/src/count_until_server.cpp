#include "rclcpp/rclcpp.hpp"
#include "rclcpp_action/rclcpp_action.hpp"
#include "my_robot_interfaces/action/count_until.hpp"

using CountUntil = my_robot_interfaces::action::CountUntil;
using CountUntilGoalHandle = rclcpp_action::ServerGoalHandle<CountUntil>;
using namespace std::placeholders;

class CountUntilServerNode : public rclcpp::Node // MODIFY NAME
{
public:
CountUntilServerNode() : Node("count_until_server") // MODIFY NAME
    {   
        cb_group_ = this->create_callback_group(rclcpp::CallbackGroupType::Reentrant); 
        count_until_server_ = rclcpp_action::create_server<CountUntil>(
            this,
            "count_until",
            std::bind(&CountUntilServerNode::goal_callback,this,_1,_2),
            std::bind(&CountUntilServerNode::cancel_callback,this,_1),
            std::bind(&CountUntilServerNode::handle_accepted_callback,this,_1),
            rcl_action_server_get_default_options(),
            cb_group_
        );
        RCLCPP_INFO(this->get_logger(),"Action Server has been started.");
    }
 
private:
    
    rclcpp_action::GoalResponse goal_callback(const rclcpp_action::GoalUUID &uuid,std::shared_ptr<const CountUntil::Goal> goal){
        (void)uuid;

        RCLCPP_INFO(this->get_logger(),"Received a Goal");
        
        // Policy: Refuse new goal is one goal is bein active
        // {
        //     std::lock_guard<std::mutex> lock(mutex_);
        //     if(goal_handle_){
        //         if(goal_handle_->is_active()){
        //             RCLCPP_INFO(this->get_logger(),"A Goal is still active, Reject a new goal."); 
        //             return rclcpp_action::GoalResponse::REJECT;
        //         }
        //     }
        // }


        if (goal->target_number <= 0){
            RCLCPP_INFO(this->get_logger(),"Rejecting a Goal");
            return rclcpp_action::GoalResponse::REJECT;
        }

        // Policy: Preemt existing goal while receiving the new valid goal
        {
                std::lock_guard<std::mutex> lock(mutex_);
                if(goal_handle_){
                    if(goal_handle_->is_active()){
                        RCLCPP_INFO(this->get_logger(),"Abort current goal and Accept New Goal");
                        preemted_goal_id_ = goal_handle_->get_goal_id();
                    }
                } 
        }

        RCLCPP_INFO(this->get_logger(),"Accepting  a Goal");
        return rclcpp_action::GoalResponse::ACCEPT_AND_EXECUTE;
    }
    
    rclcpp_action::CancelResponse cancel_callback(std::shared_ptr<CountUntilGoalHandle> goal_handle){
        RCLCPP_INFO(this->get_logger(),"We have accepted the canceling request.");
        (void)goal_handle;
        return rclcpp_action::CancelResponse::ACCEPT;
    }

    void handle_accepted_callback(const std::shared_ptr<CountUntilGoalHandle> goal_handle){
        RCLCPP_INFO(this->get_logger(),"Executing the goal");
        execute_goal(goal_handle); 
    }

    void execute_goal(const std::shared_ptr<CountUntilGoalHandle> goal_handle){
        {
        std::lock_guard<std::mutex> lock(mutex_);
        this->goal_handle_ = goal_handle;
        }
        // get request from the goal
        int target_number = goal_handle->get_goal()->target_number;
        double period = goal_handle->get_goal()->period;

        // Execute the action
        int counter = 0;
        auto feedback = std::make_shared<CountUntil::Feedback>();
        auto result = std::make_shared<CountUntil::Result>();
        rclcpp::Rate loop_rate(1.0/period);
        for(int i=0;i<target_number;i++){
            if(goal_handle->is_canceling()){
                result->reached_number = counter;
                goal_handle->canceled(result);   
                return;     
            }
            {
                std::lock_guard<std::mutex> lock(mutex_); 
                if(goal_handle->get_goal_id()==preemted_goal_id_){
                    result->reached_number = counter;
                    goal_handle->abort(result);   
                    return;
                }
            }
            counter++;
            RCLCPP_INFO(this->get_logger(),"Counter: %d",counter);
            feedback->current_number = counter;
            goal_handle->publish_feedback(feedback);
            loop_rate.sleep();
        }

        // Set the final state and return the result
        result->reached_number = counter;
        goal_handle->succeed(result);
    }
    
    rclcpp_action::Server<CountUntil>::SharedPtr count_until_server_;
    rclcpp::CallbackGroup::SharedPtr cb_group_;
    std::mutex mutex_;
    std::shared_ptr<CountUntilGoalHandle> goal_handle_;
    rclcpp_action::GoalUUID preemted_goal_id_;
};
 
int main(int argc, char **argv)
{
    rclcpp::init(argc, argv);
    auto node = std::make_shared<CountUntilServerNode>(); // MODIFY NAME
    rclcpp::executors::MultiThreadedExecutor executor;
    executor.add_node(node);
    executor.spin();
    rclcpp::shutdown();
    return 0;
}