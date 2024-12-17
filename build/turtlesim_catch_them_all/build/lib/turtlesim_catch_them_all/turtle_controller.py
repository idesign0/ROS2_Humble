#!/usr/bin/env python3
import rclpy
from rclpy.node import Node
from my_robot_interfaces.srv import Catch
from my_robot_interfaces.msg import TurtleArray
from turtlesim.msg import Pose
from geometry_msgs.msg import Twist
from functools import partial

class turtle_controller(Node):
    
    def __init__(self):
        super().__init__("turtle_controller")
        self.turtleList_sub = self.create_subscription(TurtleArray,"alive_turtle",self.turtlelist_callback)
        self.turtlePose_sub = self.create_subscription(Pose,'/turtle1/pose',self.pose_callback)
        self.turtlevel_pub = self.create_publisher(Twist,'/turtle1/cmd_vel',10)
        control_timer_ = self.create_timer(5,self.callback_control)

    def turtlelist_callback(self,msg):
        self.turtle = msg.turtlearray[0]

    def pose_callback(self,msg):
        self.master_pos = msg

    def callback_control(self):

        if self.turtle.x == self.turtle.x and self.turtle.y == self.turtle.y and self.turtle.theta == self.master_pos.theta:
             self.catch_the_turtle()
        else:
            msg = Twist()
            msg.linear.x = (self.turtle.x - self.master_pos.x)*3
            msg.linear.y = (self.turtle.y - self.master_pos.y)*3
            msg.angular.z = (self.turtle.theta - self.master_pos.theta)*3
            self.turtlevel_pub.publish(msg)

    def catch_the_turtle(self):
        catch_turtle_client = self.create_client(Catch,"/catch_turtle")

        while(not catch_turtle_client.wait_for_service(1.0)):
            self.get_logger().warn("Waiting for Service: Catch to start..")
        
        request = Catch.Request()
        request.turtle = self.turtle
        future = catch_turtle_client.call_async(request)
        future.add_done_callback(self.callback_catch_turtles)

    def callback_catch_turtles(self):
        try:
            response_msg = "Catch:Success"
        except Exception as e:
            self.get_logger().error("Service call Failed %r" %(e,))

 
def main(args=None):
    rclpy.init(args=args)
    node = turtle_controller()
    rclpy.spin(node)
    rclpy.shutdown()
 
 
if __name__ == "__main__":
    main()
