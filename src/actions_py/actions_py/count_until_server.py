#!/usr/bin/env python3
import rclpy
import time
from rclpy.node import Node
from rclpy.action import ActionServer, GoalResponse, CancelResponse
from rclpy.action.server import ServerGoalHandle
from my_robot_interfaces.action import CountUntil
from rclpy.executors import MultiThreadedExecutor
from rclpy.callback_groups import ReentrantCallbackGroup
 
class CountUntilServer(Node): # count_until_server
    def __init__(self):
        super().__init__("count_until_server") # MODIFY NAME
        self.count_until_number_server_ = ActionServer(self,CountUntil,"count_until",
                                                       goal_callback=self.goal_callback,
                                                       cancel_callback=self.goal_cancel_callback,
                                                       execute_callback=self.execute_callback,
                                                       callback_group=ReentrantCallbackGroup())
        self.get_logger().info("Action server has been started")

    def goal_callback(self,goal_request:CountUntil.Goal):
        self.get_logger().info("Received a goal")
        # Validate the goal request
        if goal_request.target_number <= 0:
            self.get_logger().info("Rejecting the goal")
            return GoalResponse.REJECT
        self.get_logger().info("Accepting the goal")
        
        return GoalResponse.ACCEPT

    def goal_cancel_callback(self,goal_handle:ServerGoalHandle):
        self.get_logger().info("Recieved a cancel request")
        return CancelResponse.ACCEPT

    def execute_callback(self,goal_handle:ServerGoalHandle):
        # Get the request from the goal
        target_number = goal_handle.request.target_number
        period = goal_handle.request.period

        # Execute the action
        self.get_logger().info("Executing the Goal") 
        feedback = CountUntil.Feedback()
        result= CountUntil.Result()
        counter = 0
        for i in range(target_number):
            
            if goal_handle.is_cancel_requested:
                self.get_logger().info("Canceling  the goal")
                goal_handle.canceled()
                result.reached_number = counter
                return result
            
            counter += 1
            self.get_logger().info(str(counter))
            feedback.current_number = counter
            goal_handle.publish_feedback(feedback)
            time.sleep(period)
        
        # Once done, set goal Final state
        goal_handle.succeed()

        # send the result
        result.reached_number = counter
        return result

 
def main(args=None):
    rclpy.init(args=args)
    node = CountUntilServer() # count_until_server
    rclpy.spin(node,MultiThreadedExecutor())
    rclpy.shutdown()
 
 
if __name__ == "__main__":
    main()
