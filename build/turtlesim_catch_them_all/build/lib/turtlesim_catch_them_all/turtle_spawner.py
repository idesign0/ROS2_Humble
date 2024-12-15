#!/usr/bin/env python3
import rclpy
from rclpy.node import Node
from random import uniform
from turtlesim.srv import Spawn
from turtlesim.srv import Kill
from my_robot_interfaces.msg import Turtle
from my_robot_interfaces.msg import TurtleArray
from functools import partial
 
class turtle_spawner(Node):
    def __init__(self):
        super().__init__("turtle_spawner")

        self.turtle = Turtle()
        self.aliveTurtles = TurtleArray()
        self.pub_turtleList = self.create_publisher(TurtleArray,"alive_turtles",10)
        
        timer1_ = self.create_timer(2,self.call_spawn_srv)

        if(self.aliveTurtles.turtlearray):
            timer2_ = self.create_timer(0.5,self.call_kill_srv(self.aliveTurtles.turtlearray[0]))

    def call_spawn_srv(self):

        x = uniform(0,11)
        y = uniform(0,11)
        thta = uniform(0,1)

        new_turtle_srv = self.create_client(Spawn,"/spawn")

        while(not new_turtle_srv.wait_for_service(1.0)):
            self.get_logger().warn("Waiting for Service: Spawn to start..")
        
        request = Spawn.Request()
        request.x = x
        request.y = y
        request.theta = thta
    
        future = new_turtle_srv.call_async(request)
        future.add_done_callback(partial(self.callback_add_turtles,request = request))

    def callback_add_turtles(self,future,request):
        try:
            request.name = future.result().name
            self.turtle.x = request.x
            self.turtle.y = request.y
            self.turtle.theta = request.theta
            self.turtle.name = request.name

            self.aliveTurtles.turtlearray.append(self.turtle)
            self.pub_turtleList.publish(self.aliveTurtles)

        except Exception as e:
            self.get_logger().error("Service call Failed %r" %(e,))


    def call_kill_srv(self,Turtle):
        kill_turtle_client = self.create_client(Kill,"/Kill")

        if(kill_turtle_client.wait_for_service(1.0)):
            self.get_logger().warn("Waiting for Service: Kill to start..")

        request = Kill.Request()
        request.name = Turtle.name

        future = kill_turtle_client.call_async(request)
        future.add_done_callback(partial(self.catch_turtle))
     
    def catch_turtle(self,future):
        try:
            nameTurtle = future.result().name
            self.aliveTurtles.turtlearray.remove(nameTurtle)
            self.get_logger().info(nameTurtle + "killed Successfulley")

        except Exception as e:
            self.get_logger().error("Service call Failed %r" %(e,))


def main(args=None):
    rclpy.init(args=args)
    node = turtle_spawner()
    rclpy.spin(node)
    rclpy.shutdown()
 
 
if __name__ == "__main__":
    main()
