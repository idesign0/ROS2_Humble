#!/usr/bin/env python3
import rclpy
import time
from rclpy.node import Node
from rclpy.action import ActionServer
from rclpy.action.server import ServerGoalHandle
from my_robot_interfaces.action import ReachUntil
 
class ReachUntilServerNode(Node): # MODIFY NAME
    def __init__(self):
        super().__init__("reach_until_server_node") # MODIFY NAME
        self.robot_position_ = 50
        self.server_ = ActionServer(self,ReachUntil,"reach_until",execute_callback=self.goal_execute_callback)
        self.get_logger().info("Server is listening!")
        self.get_logger().info("Robot Position: " + str(self.robot_position_))

    def goal_execute_callback(self, goal_handle : ServerGoalHandle):
        self.get_logger().info("Getting the Goal!")
        target_position = goal_handle.request.position
        velocity = goal_handle.request.velocity

        self.get_logger().info("Executing the Goal!")
        current_position = self.robot_position_
        feedback = ReachUntil.Feedback()
        result = ReachUntil.Result()

        while (current_position is not target_position):
            difference = target_position - current_position
            if difference > 0:
                if (difference>=velocity):
                    current_position = current_position+velocity                  
                    goal_handle.publish_feedback(feedback)
                if (difference<velocity):
                    current_position = current_position+difference                                     
                    goal_handle.publish_feedback(feedback)
            else:
                if (difference>=velocity):
                    current_position = current_position-velocity                                      
                    goal_handle.publish_feedback(feedback)
                if (difference<velocity):
                    current_position = current_position-difference
                    goal_handle.publish_feedback(feedback)
            
            feedback.current_position = current_position
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
    rclpy.spin(node)
    rclpy.shutdown()
 
 
if __name__ == "__main__":
    main()
