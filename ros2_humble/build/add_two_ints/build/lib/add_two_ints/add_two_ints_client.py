#!/usr/bin/env python3
import rclpy
from rclpy.node import Node
from example_interfaces.srv import AddTwoInts
from functools import partial 
 
class add_two_ints_client(Node): 
    def __init__(self):
        super().__init__("add_two_ints_client")
        self.call_two_ints_server(4,5) 
        self.call_two_ints_server(6,23) 
        self.call_two_ints_server(43,2) 

    def call_two_ints_server(self,a,b):
        client_ = self.create_client(AddTwoInts,"add_two_ints")
        self.get_logger().info("Client has Started.")
       
        while not client_.wait_for_service(1.0):
            self.get_logger().warn("Waiting for server Add two Ints..")
        
        request_ = AddTwoInts.Request()
        request_.a = a
        request_.b = b

        future_ = client_.call_async(request_)
        future_.add_done_callback(partial(self.callback_call_add_two_ints,a=a,b=b))

    def callback_call_add_two_ints(self,future,a,b):
        try:
            response = future.result()
            self.get_logger().info(str(a)+"+"+str(b)+"="+str(response.sum))
        except Exception as e:
            self.get_logger().error("Service call Failed %r" %(e,))

def main(args=None):
    rclpy.init(args=args)
    node = add_two_ints_client() 
    rclpy.shutdown()
 
 
if __name__ == "__main__":
    main()
