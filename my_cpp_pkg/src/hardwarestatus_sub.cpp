#include "rclcpp/rclcpp.hpp"
#include "my_robot_interfaces/msg/hardware_status.hpp"

typedef my_robot_interfaces::msg::HardwareStatus HardwareStatus;

class hardwarestatus_sub : public rclcpp::Node 
{
public:
    hardwarestatus_sub() : Node("hardwarestatus_sub")
    {
        sub = this->create_subscription<HardwareStatus>("hardware_Status",10,std::bind(&hardwarestatus_sub::sub_hardwarestatus,this,std::placeholders::_1));

    }
 
private:

    void sub_hardwarestatus(HardwareStatus msg){
        auto temp = msg.temperature;
        auto dbg_msg = msg.debug_message;
        RCLCPP_INFO(this->get_logger(),"Temperature: %ld Message: %s",temp,dbg_msg.c_str());
    }

    rclcpp::Subscription<HardwareStatus>::SharedPtr sub;

};
 
int main(int argc, char **argv)
{
    rclcpp::init(argc, argv);
    auto node = std::make_shared<hardwarestatus_sub>(); 
    rclcpp::spin(node);
    rclcpp::shutdown();
    return 0;
}
