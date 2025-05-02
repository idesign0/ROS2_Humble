#!/usr/bin/env python3
import rclpy
from rclpy.node import Node
from std_msgs.msg import Int64 
from example_interfaces.srv import SetBool
 
 
class number_counter(Node):
    def __init__(self):
        super().__init__("number_counter") 

        self.subscriber_ = self.create_subscription(Int64,"number",self.subscribeFun,10)
        self.counter_ = Int64()
        self.counter_.data = 0
        self.publisher_ = self.create_publisher(Int64,"number_count",10)
        self.timer_ = self.create_timer(0.5,self.pubfun)
        self.service_ = self.create_service(SetBool,"reset_counter",self.setBoolService)

    def setBoolService(self,request, response):
        if request.data:
            self.counter_.data = 0
            response.message = "Counter is set to Zero!"
        else:
            response.message = "Service execution failed."
        
        return response

    def subscribeFun(self,msg):
        self.counter_.data += msg.data
        self.get_logger().info(str(self.counter_.data))

    def pubfun(self):
        self.publisher_.publish(self.counter_)

def main(args=None):
    rclpy.init(args=args)
    node = number_counter()
    rclpy.spin(node)
    rclpy.shutdown()
 
 
if __name__ == "__main__":
    main()
