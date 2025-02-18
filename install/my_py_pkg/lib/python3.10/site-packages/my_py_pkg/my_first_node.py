#!/usr/bin/env python3
import rclpy
from rclpy.node import Node

class MyNode(Node):

    def __init__(self):
        super().__init__("py_test")
        self.counterX = 0
        self.get_logger().info("Hello ROS2")
        self.create_timer(2,self.timer_callback)

    def timer_callback(self):
        self.counterX += 1
        self.get_logger().info("Hello"+str(self.counterX))


def main(args=None):
    rclpy.init(args=args)
    node = MyNode()
    rclpy.spin(node)
    rclpy.shutdown()

if __name__ == "__main__":
    main()