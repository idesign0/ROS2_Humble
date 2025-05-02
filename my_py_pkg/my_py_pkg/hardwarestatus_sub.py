#!/usr/bin/env python3
import rclpy
from rclpy.node import Node
from my_robot_interfaces.msg import HardwareStatus
 
class hardwarestatussub(Node): 
    def __init__(self):
        super().__init__("hardware_status_sub") 
        self.sub_ = self.create_subscription(HardwareStatus,"hardware_Status",self.sub_hardwarestatus,10)
    
    def sub_hardwarestatus(self,msg):
        temp = msg.temperature
        message = msg.debug_message
        self.get_logger().info("Temperature: " + str(temp) + " ,message: " + str(message))

def main(args=None):
    rclpy.init(args=args)
    node = hardwarestatussub()
    rclpy.spin(node)
    rclpy.shutdown()
 
 
if __name__ == "__main__":
    main()
