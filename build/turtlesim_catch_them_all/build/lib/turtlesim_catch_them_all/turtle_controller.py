#!/usr/bin/env python3
import rclpy
from rclpy.node import Node

class turtle_controller(Node):
    def __init__(self):
        super().__init__("turtle_controller")
 
 
def main(args=None):
    rclpy.init(args=args)
    node = turtle_controller()
    rclpy.spin(node)
    rclpy.shutdown()
 
 
if __name__ == "__main__":
    main()
