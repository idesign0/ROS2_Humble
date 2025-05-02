#include "rclcpp/rclcpp.hpp"
#include "my_robot_interfaces/srv/set_led.hpp" 

typedef my_robot_interfaces::srv::SetLED setLedtype;

class battery_node : public rclcpp::Node 
{
public:
    battery_node() : Node("battery_node") 
    {   
        threads.push_back(std::thread(std::bind(&battery_node::call_the_service,this,100)));
        std::this_thread::sleep_for(std::chrono::seconds(4));
        threads.push_back(std::thread(std::bind(&battery_node::call_the_service,this,0)));
        std::this_thread::sleep_for(std::chrono::seconds(6));
        threads.push_back(std::thread(std::bind(&battery_node::call_the_service,this,100)));
    }
    
    void call_the_service(int b){

        auto client = this->create_client<setLedtype>("set_led");
        
        while(!client->wait_for_service(std::chrono::seconds(1))){
            RCLCPP_WARN(this->get_logger(),"Waiting for the service...");
        }

        auto request = std::make_shared<setLedtype::Request>();
        request->battery_state = b;

        auto future = client->async_send_request(request);
        try
        {   
            auto response = future.get();
            RCLCPP_INFO(this->get_logger(),"Battery Status: %f, Response Message: %s", request->battery_state,response->response_msg.c_str());
        }
        catch(const std::exception& e)
        {
            RCLCPP_ERROR(this->get_logger(),"Service call Failed here.");
        }
        
    }

private:
    std::vector<std::thread> threads;
};
 
int main(int argc, char **argv)
{
    rclcpp::init(argc, argv);
    auto node = std::make_shared<battery_node>(); // MODIFY NAME
    rclcpp::spin(node);
    rclcpp::shutdown();
    return 0;
}
