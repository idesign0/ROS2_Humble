#include "rclcpp/rclcpp.hpp"
#include "example_interfaces/srv/add_two_ints.hpp"

class add_two_ints_client : public rclcpp::Node 
{
public:
    add_two_ints_client() : Node("add_two_ints_client")
    {
        threads.push_back(std::thread(std::bind(&add_two_ints_client::callAddTwoIntsServive,this,1,4)));
        threads.push_back(std::thread(std::bind(&add_two_ints_client::callAddTwoIntsServive,this,4,4)));

    }

    void callAddTwoIntsServive(int a, int b){
        auto client = this->create_client<example_interfaces::srv::AddTwoInts>("add_two_ints");

        while (!client->wait_for_service(std::chrono::seconds(1))){
            RCLCPP_WARN(this->get_logger(),"Waiting for the server to be up...");
        }

        auto request = std::make_shared<example_interfaces::srv::AddTwoInts::Request>();
        request->a = a;
        request->b = b;

        auto future = client->async_send_request(request);
        try{
            auto response =future.get();
            RCLCPP_INFO(this->get_logger(),"%d + %d = %d",a,b,response->sum);
        }catch(const std::exception &e){
            RCLCPP_ERROR(this->get_logger(),"Service call Failed here.");
        }
    }

private:
    std::vector<std::thread> threads;
};
 
int main(int argc, char **argv)
{
    rclcpp::init(argc, argv);
    auto node = std::make_shared<add_two_ints_client>(); 
    rclcpp::spin(node);
    rclcpp::shutdown();
    return 0;
}
