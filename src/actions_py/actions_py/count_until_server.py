#!/usr/bin/env python3
import rclpy
import time
from rclpy.node import Node
import threading
from rclpy.action import ActionServer, GoalResponse, CancelResponse
from rclpy.action.server import ServerGoalHandle
from my_robot_interfaces.action import CountUntil
from rclpy.executors import MultiThreadedExecutor
from rclpy.callback_groups import ReentrantCallbackGroup
 
class CountUntilServer(Node): # count_until_server
    def __init__(self):
        super().__init__("count_until_server") # MODIFY NAME
        self.goal_handle_ :ServerGoalHandle = None
        self.goal_lock_ =  threading.Lock() 
        self.goal_queue_ = []
        self.count_until_number_server_ = ActionServer(self,CountUntil,"count_until",
                                                       goal_callback=self.goal_callback,
                                                       handle_accepted_callback=self.goal_handle_accepted_callback,
                                                       cancel_callback=self.goal_cancel_callback,
                                                       execute_callback=self.execute_callback,
                                                       callback_group=ReentrantCallbackGroup())
        self.get_logger().info("Action server has been started")

    def goal_callback(self,goal_request:CountUntil.Goal):
        self.get_logger().info("Received a goal")
        
        # Policy: refuse the new goal if current goal is active.
        #with self.goal_lock_:
        #    if self.goal_handle_ is not None and self.goal_handle_.is_active:
        #        self.get_logger().info("The Goal is already active, rejecting new goal")
        #        return GoalResponse.REJECT

        # Validate the goal request
        if goal_request.target_number <= 0:
            self.get_logger().info("Rejecting the goal")
            return GoalResponse.REJECT
        
        # Policy: preemt existing goal when receiving new goal 
        #with self.goal_lock_:
        #    if self.goal_handle_ is  not None and self.goal_handle_.is_active:
        #        self.get_logger().info("Abort the current goal and accept the new goal")
        #        self.goal_handle_.abort()

        self.get_logger().info("Accepting the goal")
        
        return GoalResponse.ACCEPT

    def goal_handle_accepted_callback(self,goal_handle:ServerGoalHandle):
        with self.goal_lock_:
            if self.goal_handle_ is not None:
                self.goal_queue_.append(goal_handle)
            else:
                goal_handle.execute()

    def goal_cancel_callback(self,goal_handle:ServerGoalHandle):
        self.get_logger().info("Recieved a cancel request")
        return CancelResponse.ACCEPT

    def execute_callback(self,goal_handle:ServerGoalHandle):
        with self.goal_lock_:
            self.goal_handle_ = goal_handle

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
                self.get_logger().info("Canceling the goal")
                goal_handle.canceled()
                result.reached_number = counter
                self.process_new_goal_in_queue()
                return result
            
            if not goal_handle.is_active:
                result.reached_number = counter
                self.process_new_goal_in_queue()
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
        self.process_new_goal_in_queue()
        return result

    def process_new_goal_in_queue(self):
        with self.goal_lock_:
            if len(self.goal_queue_) > 0:
                self.goal_queue_.pop(0).execute()
            else:
                self.goal_handle_=None
 
def main(args=None):
    rclpy.init(args=args)
    node = CountUntilServer() # count_until_server
    rclpy.spin(node,MultiThreadedExecutor())
    rclpy.shutdown()
 
 
if __name__ == "__main__":
    main()
