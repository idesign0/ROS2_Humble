// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from my_robot_interfaces:srv/Catch.idl
// generated code does not contain a copyright notice

#ifndef MY_ROBOT_INTERFACES__SRV__DETAIL__CATCH__BUILDER_HPP_
#define MY_ROBOT_INTERFACES__SRV__DETAIL__CATCH__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "my_robot_interfaces/srv/detail/catch__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace my_robot_interfaces
{

namespace srv
{

namespace builder
{

class Init_Catch_Request_turtle
{
public:
  Init_Catch_Request_turtle()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::my_robot_interfaces::srv::Catch_Request turtle(::my_robot_interfaces::srv::Catch_Request::_turtle_type arg)
  {
    msg_.turtle = std::move(arg);
    return std::move(msg_);
  }

private:
  ::my_robot_interfaces::srv::Catch_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::my_robot_interfaces::srv::Catch_Request>()
{
  return my_robot_interfaces::srv::builder::Init_Catch_Request_turtle();
}

}  // namespace my_robot_interfaces


namespace my_robot_interfaces
{

namespace srv
{


}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::my_robot_interfaces::srv::Catch_Response>()
{
  return ::my_robot_interfaces::srv::Catch_Response(rosidl_runtime_cpp::MessageInitialization::ZERO);
}

}  // namespace my_robot_interfaces

#endif  // MY_ROBOT_INTERFACES__SRV__DETAIL__CATCH__BUILDER_HPP_
