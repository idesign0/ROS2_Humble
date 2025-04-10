#!/usr/bin/env python3
import rclpy
from rclpy.node import Node
from rclpy.action import ActionClient
from rclpy.action.client import ClientGoalHandle, GoalStatus
from my_robot_interfaces.action import CountUntil
 
 
class CountUntilClient(Node): # count_until_client
    def __init__(self):
        super().__init__("count_until_client") # count_until_client
        self.count_until_client_ = ActionClient(self,CountUntil,"count_until")

    def send_goal(self,target_number,period):
        # wait for the server
        while not self.count_until_client_.wait_for_server(1.0):
            self.get_logger().info("Client is waiting for the server to start.")
        
        # goal
        goal = CountUntil.Goal()
        goal.target_number = target_number
        goal.period = period
 
        # sending goal
        self.get_logger().info("Sending Goal")
        self.count_until_client_.send_goal_async(goal,feedback_callback=self.goal_feedback_callback).add_done_callback(self.goal_response_callback)
        self.timer_ = self.create_timer(2.0,self.cancel_goal)

    def cancel_goal(self):
        self.get_logger().info("Send a cancel Request.")
        self.goal_handle_.cancel_goal_async()
        self.timer_.cancel()

    def goal_response_callback(self,future):
        self.goal_handle_:ClientGoalHandle = future.result()
        if self.goal_handle_.accepted:
            self.get_logger().info("Goal got accepted.")
            self.goal_handle_.get_result_async().add_done_callback(self.goal_result_callback)
        else:
             self.get_logger().warn("Goal got rejected")


    def goal_result_callback(self,future):
        status = future.result().status
        result = future.result().result
        
        if status == GoalStatus.STATUS_SUCCEEDED:
            self.get_logger().info("Success")
        elif status == GoalStatus.STATUS_ABORTED:
            self.get_logger().error("Aborted") 
        elif status == GoalStatus.STATUS_CANCELED:
            self.get_logger().error("Canceled") 

        self.get_logger().info("Result: " + str(result.reached_number))

    def goal_feedback_callback(self,feedback_msg):
        number = feedback_msg.feedback.current_number
        self.get_logger().info("Got Feedback: " + str(number))

def main(args=None):
    rclpy.init(args=args)
    node = CountUntilClient() # count_until_client
    node.send_goal(6,1.0)
    rclpy.spin(node)
    rclpy.shutdown()
  
 
if __name__ == "__main__":
    main()