#include <rclcpp/rclcpp.hpp>
#include <example_interfaces/msg/string.hpp>

class robot_radio_station : public rclcpp::Node
{
public:
    robot_radio_station() : Node("robot_radio_station")
    {   
        this->declare_parameter<std::string>("robot_name","name_default");
        robot_name_ = this->get_parameter("robot_name").as_string();
        publisher_ = this->create_publisher<example_interfaces::msg::String>("robot_news", 10);
        timer_ = create_wall_timer(std::chrono::milliseconds(500), std::bind(&robot_radio_station::publisher, this));
        RCLCPP_INFO(this->get_logger(), "Publischer successfully initiated");
    }

private:
    void publisher()
    {
        auto msg = example_interfaces::msg::String();
        msg.data = std::string("Hii, this is ") + robot_name_ + std::string(" from the robot new station");
        publisher_->publish(msg);
    }

    rclcpp::Publisher<example_interfaces::msg::String>::SharedPtr publisher_;
    rclcpp::TimerBase::SharedPtr timer_;
    std::string robot_name_;
};

int main(int argc, char **argv)
{
    rclcpp::init(argc, argv);
    auto node = std::make_shared<robot_radio_station>();
    rclcpp::spin(node);
    rclcpp::shutdown();
    return 0;
}
