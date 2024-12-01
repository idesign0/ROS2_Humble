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

        self.aliveTurtles = TurtleArray()
        
        self.pub_turtleList = self.create_publisher(TurtleArray,"alive_turtles",10)
        timer_ = self.create_timer(0.5,self.call_spawn_srv)

        self.call_spawn_srv()

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
            turtle = Turtle()
            turtle.x = request.x
            turtle.y = request.y
            turtle.theta = request.theta
            turtle.name = request.name

            self.aliveTurtles.turtlearray.append(turtle)
            self.pub_turtleList.publish(self.aliveTurtles)

        except Exception as e:
            self.get_logger().error("Service call Failed %r" %(e,))


    def call_kill_srv(self):
        kill_turtle_client = self.create_client(Kill,"/Kill")

     
def main(args=None):
    rclpy.init(args=args)
    node = turtle_spawner()
    rclpy.spin(node)
    rclpy.shutdown()
 
 
if __name__ == "__main__":
    main()
