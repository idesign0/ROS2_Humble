#!/usr/bin/env python3
import rclpy
from rclpy.node import Node
from my_robot_interfaces.msg import HardwareStatus
 
 
class HardwareStatus(Node):
    def __init__(self):
        super().__init__("Hardware_Status_Node")

        self.publisher_ = self.create_publisher(HardwareStatus,"hardware_Status",10)
        self.timer_ = self.create_timer(0.5, self.HardwareStatus_publisher)
        self.get_logger().info("Hardware Status Publisher is set!")

    def HardwareStatus_publisher(self): 
        msg = HardwareStatus()
        msg.temperature = 20
        msg.are_motors_ready = True
        msg.debug_message = "motor is now ready"

        self.publisher_.publish(msg)

def main(args=None):
    rclpy.init(args=args)
    node = HardwareStatus()
    rclpy.spin(node)
    rclpy.shutdown()
 
 
if __name__ == "__main__":
    main()
