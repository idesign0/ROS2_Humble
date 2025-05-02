#!/usr/bin/env python3
import rclpy
import time
import threading
from rclpy.node import Node
from rclpy.action import ActionServer
from rclpy.action.server import ServerGoalHandle, GoalResponse, CancelResponse
from my_robot_interfaces.action import ReachUntil
from rclpy.executors import MultiThreadedExecutor
from rclpy.callback_groups import ReentrantCallbackGroup
 
class ReachUntilServerNode(Node): # MODIFY NAME
    def __init__(self):
        super().__init__("reach_until_server_node") # MODIFY NAME
        self.robot_position_ = 50
        self.goal_lock_ = threading.Lock()
        self.goal_handle_ : ServerGoalHandle = None

        self.server_ = ActionServer(self,ReachUntil,"reach_until",
                                    goal_callback=self.goal_callback,
                                    cancel_callback=self.goal_cancel_callback,
                                    execute_callback=self.goal_execute_callback,
                                    callback_group=ReentrantCallbackGroup())

        self.get_logger().info("Server is listening!")
        self.get_logger().info("Robot Position: " + str(self.robot_position_))

    def goal_callback(self,goal_request:ReachUntil.Goal):
        self.get_logger().info("Received the new goal")
        
        if goal_request.position not in range(0,100) or goal_request.velocity <= 0:
            self.get_logger().warn("Invalid position/velocity, reject goal.")
            return GoalResponse.REJECT

        # new goal is valid and abort previous goal and accept new goal
        with self.goal_lock_:
            if self.goal_handle_ is not None and  self.goal_handle_.is_active:
                self.get_logger().error("Goal is aborted")
                self.goal_handle_.abort()

        self.get_logger().info("Accept Goal.")
        return GoalResponse.ACCEPT        

    def goal_cancel_callback(self,goal_handle:ServerGoalHandle):
        self.get_logger().info("Received a cancel request")
        return CancelResponse.ACCEPT

    def goal_execute_callback(self, goal_handle : ServerGoalHandle):
        with self.goal_lock_:
            self.goal_handle_ = goal_handle

        self.get_logger().info("Getting the Goal!")
        target_position = goal_handle.request.position
        velocity = goal_handle.request.velocity

        self.get_logger().info("Executing the Goal!")
        current_position = self.robot_position_
        feedback = ReachUntil.Feedback()
        result = ReachUntil.Result()

        while (current_position is not target_position):
            self.robot_position_ = current_position
            if not self.goal_handle_.is_active:
                result.position = current_position
                result.message = "Preemted by another goal."
                return result
            
            if  self.goal_handle_.is_cancel_requested:
                result.position = current_position
                if current_position == target_position:
                    result.message = "Success after canceled request."
                    goal_handle.succeed()
                else:
                    result.message = "Canceled."
                    goal_handle.canceled()
                
                return result

            difference = target_position - current_position
            if difference > 0:
                if (abs(difference)>=velocity):
                    current_position = current_position+velocity     
                else:
                    current_position = current_position+difference   
            else:
                if (abs(difference)>=velocity):
                    current_position = current_position-velocity           
                else:
                    current_position = current_position-difference
            
            feedback.current_position = current_position
            goal_handle.publish_feedback(feedback)
            self.get_logger().info(str(current_position))                                        
            time.sleep(1)

        self.get_logger().info("Getting the Result.")
        result.position = current_position
        result.message = "Target has been reached successfully!"

        goal_handle.succeed()
        self.get_logger().info("Publishing the Result.")
        return result

def main(args=None):
    rclpy.init(args=args)
    node = ReachUntilServerNode() # MODIFY NAME
    rclpy.spin(node,MultiThreadedExecutor())
    rclpy.shutdown()
 
 
if __name__ == "__main__":
    main()
