#include "rclcpp/rclcpp.hpp"

class MyNode : public rclcpp::Node
{
public:
    MyNode() : Node("cpp_test"), counterX(0)
    {
        RCLCPP_INFO(this->get_logger(), "Hello Cpp Node");
        timer = create_wall_timer(std::chrono::seconds(1), std::bind(&MyNode::timerCallback, this));
    }

private:
    void timerCallback()
    {   
        counterX++;
        RCLCPP_INFO(this->get_logger(),"Hello %d",counterX);

    }

    rclcpp::TimerBase::SharedPtr timer;
    int counterX;
};

int main(int argc, char **argv)
{
    rclcpp::init(argc, argv);
    auto node = std::make_shared<MyNode>();
    rclcpp::spin(node);
    rclcpp::shutdown();
    return 0;
}