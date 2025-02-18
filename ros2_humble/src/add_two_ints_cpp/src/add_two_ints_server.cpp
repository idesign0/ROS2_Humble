#include "rclcpp/rclcpp.hpp"
#include "example_interfaces/srv/add_two_ints.hpp"
 
using std::placeholders::_1;
using std::placeholders::_2;

class add_two_ints_server : public rclcpp::Node
{
public:
    add_two_ints_server() : Node("add_two_ints_server")
    {
        server_ = this->create_service<example_interfaces::srv::AddTwoInts>("add_two_ints",std::bind(&add_two_ints_server::callBackAddTwoInts,this,_1,_2));
        RCLCPP_INFO(this->get_logger(),"The Service has Started!");
    }
 
private:
    void callBackAddTwoInts (const example_interfaces::srv::AddTwoInts::Request::SharedPtr request, const example_interfaces::srv::AddTwoInts::Response::SharedPtr response){
        response->sum = request->a + request->b;
        RCLCPP_INFO(this->get_logger(),"%d + %d = %d",request->a,request->b,response->sum);
    }
    rclcpp::Service<example_interfaces::srv::AddTwoInts>::SharedPtr server_;     
};
 
int main(int argc, char **argv)
{
    rclcpp::init(argc, argv);
    auto node = std::make_shared<add_two_ints_server>();
    rclcpp::spin(node);
    rclcpp::shutdown();
    return 0;
}
