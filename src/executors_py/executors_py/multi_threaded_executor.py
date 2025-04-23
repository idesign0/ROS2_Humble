#!/usr/bin/env python3
import rclpy
from rclpy.node import Node
from rclpy.executors import MultiThreadedExecutor
from rclpy.callback_groups import ReentrantCallbackGroup
from rclpy.callback_groups import MutuallyExclusiveCallbackGroup
import time


class Node1(Node):
    def __init__(self):
        super().__init__("node1")
        self.cb_group_1 = MutuallyExclusiveCallbackGroup() # cannot reenter themselves
        self.cb_group_2 = MutuallyExclusiveCallbackGroup()
        self.cb_group_3 = MutuallyExclusiveCallbackGroup()

        self.timer1_ = self.create_timer(1.0, self.callback_timer1,callback_group=self.cb_group_1)
        self.timer2_ = self.create_timer(1.0, self.callback_timer2,callback_group=self.cb_group_2)
        self.timer3_ = self.create_timer(1.0, self.callback_timer3,callback_group=self.cb_group_3)

    def callback_timer1(self):
        time.sleep(2.0)
        self.get_logger().info("cb 1")

    def callback_timer2(self):
        time.sleep(2.0)
        self.get_logger().info("cb 2")

    def callback_timer3(self):
        time.sleep(2.0)
        self.get_logger().info("cb 3")


def main(args=None):
    rclpy.init(args=args)
    node1 = Node1()
    executor = MultiThreadedExecutor()
    executor.add_node(node1)
    executor.spin()
    rclpy.shutdown()


if __name__ == "__main__":
    main()