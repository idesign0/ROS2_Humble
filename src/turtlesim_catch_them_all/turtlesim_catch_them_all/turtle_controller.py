#!/usr/bin/env python3
import rclpy
from rclpy.node import Node
from my_robot_interfaces.srv import Catch
from my_robot_interfaces.msg import TurtleArray
from my_robot_interfaces.msg import Turtle
from turtlesim.msg import Pose
from geometry_msgs.msg import Twist
from functools import partial

class turtle_controller(Node):
    
    def __init__(self):
        super().__init__("turtle_controller")
        self.turtle = Turtle()
        self.turtleList_sub = self.create_subscription(TurtleArray,"alive_turtles",self.turtlelist_callback,10)
        self.turtlePose_sub = self.create_subscription(Pose,'turtle1/pose',self.pose_callback,10)
        self.turtlevel_pub = self.create_publisher(Twist,'turtle1/cmd_vel',10)
        control_timer_ = self.create_timer(1,self.callback_control)

    def turtlelist_callback(self,msg):

        if not (len(msg.turtlearray) > 0):
            self.get_logger().warning("No turtles in the array.")
            exit
        else:
            self.turtle = msg.turtlearray[0]

    def pose_callback(self,msg):
        self.master_pos = msg

    def callback_control(self):

        err = 0.00001
        if (abs(self.turtle.x - self.master_pos.x) < err) and (abs(self.turtle.y - self.master_pos.y) < err):
            self.catch_the_turtle
        else:
            msg = Twist()
            msg.linear.x = (self.turtle.x - self.master_pos.x)
            msg.linear.y = (self.turtle.y - self.master_pos.y)
            self.turtlevel_pub.publish(msg)
            
    def catch_the_turtle(self):
        catch_turtle_client = self.create_client(Catch,"catch_turtle")

        while(not catch_turtle_client.wait_for_service(1.0)):
            self.get_logger().warn("Waiting for Service: Catch to start..")
        
        request = Catch.Request()
        request.turtle = self.turtle
        future = catch_turtle_client.call_async(request)
        future.add_done_callback(partial(self.callback_catch_turtles))

    def callback_catch_turtles(self,future):
        try:
            self.get_logger().info(self.turtle.name + " Kill:Success")
        except Exception as e:
            self.get_logger().error("Service call Failed %r" %(e,))

 
def main(args=None):
    rclpy.init(args=args)
    node = turtle_controller()
    rclpy.spin(node)
    rclpy.shutdown()
 
 
if __name__ == "__main__":
    main()
