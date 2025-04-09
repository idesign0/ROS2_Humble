#!/usr/bin/env python3
import rclpy
import time
from rclpy.node import Node
from rclpy.action import ActionServer
from rclpy.action.server import ServerGoalHandle
from my_robot_interfaces.action import CountUntil 
 
class CountUntilServer(Node): # count_until_server
    def __init__(self):
        super().__init__("count_until_server") # MODIFY NAME
        self.count_until_number_server_ = ActionServer(self,CountUntil,"count_until",
                                                       execute_callback=self.execute_callback)
        self.get_logger().info("Action server has been started")

    def execute_callback(self,goal_handle:ServerGoalHandle):
        #get the request from the goal
        target_number = goal_handle.request.target_number
        period = goal_handle.request.period

        # Execute the action
        self.get_logger().info("Executing the Goal") 
        counter = 0
        for i in range(target_number):
            counter += 1
            self.get_logger().info(str(counter))
            time.sleep(period)
        
        # Once done, set goal Final state
        goal_handle.succeed()

        # send the result
        result= CountUntil.Result()
        result.reached_number = counter
        return result

 
def main(args=None):
    rclpy.init(args=args)
    node = CountUntilServer() # count_until_server
    rclpy.spin(node)
    rclpy.shutdown()
 
 
if __name__ == "__main__":
    main()
