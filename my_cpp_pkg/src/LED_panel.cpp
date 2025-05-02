#include "rclcpp/rclcpp.hpp"
#include "my_robot_interfaces/msg/led_states.hpp"
#include "my_robot_interfaces/srv/set_led.hpp"
 
typedef my_robot_interfaces::srv::SetLED setLedtype;
typedef my_robot_interfaces::msg::LedStates LEDstatestype;

using std::placeholders::_1;
using std::placeholders::_2;

class LED_node : public rclcpp::Node
{
public:
    LED_node() : Node("LED_node")
    {
        srv = this->create_service<setLedtype>("set_led",std::bind(&LED_node::callback_setled,this,_1,_2));
        pub = this->create_publisher<LEDstatestype>("led_states",10);
        timer = this->create_wall_timer(std::chrono::seconds(4),std::bind(&LED_node::callback_pub,this));
    }

private:
    void callback_setled(setLedtype::Request::SharedPtr request,setLedtype::Response::SharedPtr response){
        auto battery = request->battery_state;
        if(battery==100){
            LEDind[0] = 1; LEDind[1] = 1;LEDind[2] = 1;
            response->response_msg = "Battery is Full!";
        }else if(battery>= 50 and battery <100){
            LEDind[0] = 1; LEDind[1] = 1;LEDind[0] = 1;
            response->response_msg = "Battery is inbetween 50-100.";
        }else if(battery> 0 and battery <50){
            LEDind[0] = 1; LEDind[1] = 0; LEDind[2] = 0;
            response->response_msg = "Battery is inbetween 0-50.";
        }else if(battery==0){
            LEDind[0] = 0; LEDind[1] = 0; LEDind[2] = 0;
            response->response_msg = "Battery is dead";
        }else{
            RCLCPP_INFO(this->get_logger(),"Request Value is not correct!");
        }
    }

    void callback_pub(){
        auto msg = LEDstatestype();
        std::copy(LEDind,LEDind+3,&msg.states[0]);
        pub->publish(msg);
    }

    rclcpp::Service<setLedtype>::SharedPtr srv;
    rclcpp::Publisher<LEDstatestype>::SharedPtr pub;
    rclcpp::TimerBase::SharedPtr timer;
    int LEDind[3] = {0};
};
 
int main(int argc, char **argv)
{
    rclcpp::init(argc, argv);
    auto node = std::make_shared<LED_node>();
    rclcpp::spin(node);
    rclcpp::shutdown();
    return 0;
}
