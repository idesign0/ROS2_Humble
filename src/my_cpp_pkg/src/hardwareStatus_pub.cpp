#include "rclcpp/rclcpp.hpp"
#include "my_robot_interfaces/msg/hardware_status.hpp"
 
class hardwarestatuspub : public rclcpp::Node // MODIFY NAME
{
public:
    hardwarestatuspub() : Node("hardwarestatuspub") // MODIFY NAME
    {
        pub = this->create_publisher<my_robot_interfaces::msg::HardwareStatus>("hardware_Status",10);
        timer = this->create_wall_timer(std::chrono::seconds(1),std::bind(&hardwarestatuspub::pub_hardwarestatus,this));
    }
private:
    void pub_hardwarestatus(){
        auto msg = my_robot_interfaces::msg::HardwareStatus();
        msg.temperature = 43;
        msg.are_motors_ready = true;
        msg.debug_message = "There's nothing special with C++";

        pub->publish(msg);

    }

    rclcpp::Publisher<my_robot_interfaces::msg::HardwareStatus>::SharedPtr pub;
    rclcpp::TimerBase::SharedPtr timer;
};
 
int main(int argc, char **argv)
{
    rclcpp::init(argc, argv);
    auto node = std::make_shared<hardwarestatuspub>(); // MODIFY NAME
    rclcpp::spin(node);
    rclcpp::shutdown();
    return 0;
}
