#!/usr/bin/env python3
import rclpy
from rclpy.node import Node
from std_msgs.msg import Int64 
 
 
class number_publisher(Node):
    def __init__(self):
        super().__init__("number_publisher")
        self.declare_parameter("name123",1)
        self.number_ = self.get_parameter("name123").value
        self.publisher_ = self.create_publisher(Int64,"number",10)
        self.timer_ = self.create_timer(0.5,self.publish_fun)
        self.get_logger().info("Publlisher is running Succesfully!")
 
    def publish_fun(self):
        msg = Int64()
        msg.data = self.number_
        self.publisher_.publish(msg)

def main(args=None):
    rclpy.init(args=args)
    node = number_publisher()
    rclpy.spin(node)
    rclpy.shutdown()
 
 
if __name__ == "__main__":
    main()
