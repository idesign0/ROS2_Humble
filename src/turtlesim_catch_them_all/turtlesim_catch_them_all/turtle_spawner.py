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
        self.call_spawn_srv()
        self.aliveTurtles = TurtleArray()

    def call_spawn_srv(self):
        new_turtle_srv = self.create_client(Spawn,"/spawn")

        while(not new_turtle_srv.wait_for_service(1.0)):
            self.get_logger().warn("Waiting for Service: Spawn to start..")

        request = Spawn.Request()
        request.x = uniform(0,11)
        request.y = uniform(0,11)
        request.theta =uniform(0,3.14)
    
        future = new_turtle_srv.call_async(request)
        
        future.add_done_callback(partial(self.callback_add_turtle,request))

    def callback_add_turtle(self,future,request):
        try:
            response = future.result()
            request.name = response.name

            self.aliveTurtle = self.aliveTurtle + request

        except Exception as e:
            self.get_logger().error("Service call Failed %r" %(e,))

    def call_kill_srv(self):
        kill_turtle_client = self.create_client(Kill,"/Kill")

     
def main(args=None):
    rclpy.init(args=args)
    node = turtle_spawner()
    rclpy.shutdown()
 
 
if __name__ == "__main__":
    main()
