#!/usr/bin/env python3
import rclpy
from rclpy.node import Node
from rclpy.action import ActionClient
from rclpy.action.client import ClientGoalHandle, GoalStatus, CancelGoal
from my_robot_interfaces.action import ReachUntil
from example_interfaces.msg import Empty
 
class ReachUntilClientNode(Node):
    def __init__(self):
        super().__init__("reach_until_client_node")
        self.client_ = ActionClient(self,ReachUntil,"reach_until")
        self.goal_handle_ = None
        self.cancel_sub_ = self.create_subscription(Empty,"cancel_move",self.callback_cancel_move,10)

    def send_goal(self,target_pos,velocity):
        self.client_.wait_for_server()

        goal = ReachUntil.Goal()
        goal.position = target_pos
        goal.velocity = velocity

        self.get_logger().info("Sending Goal")
        self.client_.send_goal_async(goal=goal,feedback_callback=self.goal_feedback_callback).add_done_callback(self.goal_response_callback)

    def goal_response_callback(self,future):
        self.goal_handle_:ClientGoalHandle = future.result()
        if self.goal_handle_.accepted:
            self.get_logger().info("Goal got accepted")
            self.goal_handle_.get_result_async().add_done_callback(self.goal_result_callback)
    
    def goal_result_callback(self,future):
        status = future.result().status
        result = future.result().result
        
        if status == GoalStatus.STATUS_SUCCEEDED:
            self.get_logger().info("Success")
        elif status == GoalStatus.STATUS_ABORTED:
            self.get_logger().error("Aborted") 
        elif status == GoalStatus.STATUS_CANCELED:
            self.get_logger().warn("Canceled") 

        self.get_logger().info("Result: " + str(result.position))
        self.get_logger().info("Result: " + str(result.message))

    def goal_feedback_callback(self,feedback_msg):
        number = feedback_msg.feedback.current_position
        self.get_logger().info("Got Feedback: " + str(number))

    def callback_cancel_move(self,msg):
        self.cancel_goal()

    def cancel_goal(self):
        if self.goal_handle_ is not None:
            self.get_logger().info("Send a cancel Reuest")
            self.goal_handle_.cancel_goal_async()


def main(args=None):
    rclpy.init(args=args)
    node = ReachUntilClientNode()
    node.send_goal(78,1)
    rclpy.spin(node)
    rclpy.shutdown()
 
 
if __name__ == "__main__":
    main()
