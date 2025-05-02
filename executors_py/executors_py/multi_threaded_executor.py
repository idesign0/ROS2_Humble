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

        self.timer1_ = self.create_timer(1.0, self.callback_timer1,callback_group=self.cb_group_1)
        self.timer2_ = self.create_timer(1.0, self.callback_timer2,callback_group=self.cb_group_2)
        self.timer3_ = self.create_timer(1.0, self.callback_timer3,callback_group=self.cb_group_2)

    def callback_timer1(self):
        time.sleep(2.0)
        self.get_logger().info("cb 1")

    def callback_timer2(self):
        time.sleep(2.0)
        self.get_logger().info("cb 2")

    def callback_timer3(self):
        time.sleep(2.0)
        self.get_logger().info("cb 3")
 
class Node2(Node):
    def __init__(self):
        super().__init__("node2")
        self.cb_group_4 = ReentrantCallbackGroup()
        self.cb_group_5 = ReentrantCallbackGroup()

        self.timer4_ = self.create_timer(1.0, self.callback_timer4,callback_group=self.cb_group_4)
        self.timer5_ = self.create_timer(1.0, self.callback_timer5,callback_group=self.cb_group_5)

    def callback_timer4(self):
        time.sleep(2.0)
        self.get_logger().info("cb 4")

    def callback_timer5(self):
        time.sleep(2.0)
        self.get_logger().info("cb 5")

def main(args=None):
    rclpy.init(args=args)
    node1 = Node1()
    node2 = Node2()
    executor = MultiThreadedExecutor()
    executor.add_node(node1)
    executor.add_node(node2)
    executor.spin()
    rclpy.shutdown()


if __name__ == "__main__":
    main()