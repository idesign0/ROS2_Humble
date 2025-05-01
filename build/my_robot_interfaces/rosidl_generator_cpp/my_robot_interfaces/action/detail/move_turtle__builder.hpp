// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from my_robot_interfaces:action/MoveTurtle.idl
// generated code does not contain a copyright notice

#ifndef MY_ROBOT_INTERFACES__ACTION__DETAIL__MOVE_TURTLE__BUILDER_HPP_
#define MY_ROBOT_INTERFACES__ACTION__DETAIL__MOVE_TURTLE__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "my_robot_interfaces/action/detail/move_turtle__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace my_robot_interfaces
{

namespace action
{

namespace builder
{

class Init_MoveTurtle_Goal_duration_sec
{
public:
  explicit Init_MoveTurtle_Goal_duration_sec(::my_robot_interfaces::action::MoveTurtle_Goal & msg)
  : msg_(msg)
  {}
  ::my_robot_interfaces::action::MoveTurtle_Goal duration_sec(::my_robot_interfaces::action::MoveTurtle_Goal::_duration_sec_type arg)
  {
    msg_.duration_sec = std::move(arg);
    return std::move(msg_);
  }

private:
  ::my_robot_interfaces::action::MoveTurtle_Goal msg_;
};

class Init_MoveTurtle_Goal_angular_vel_z
{
public:
  explicit Init_MoveTurtle_Goal_angular_vel_z(::my_robot_interfaces::action::MoveTurtle_Goal & msg)
  : msg_(msg)
  {}
  Init_MoveTurtle_Goal_duration_sec angular_vel_z(::my_robot_interfaces::action::MoveTurtle_Goal::_angular_vel_z_type arg)
  {
    msg_.angular_vel_z = std::move(arg);
    return Init_MoveTurtle_Goal_duration_sec(msg_);
  }

private:
  ::my_robot_interfaces::action::MoveTurtle_Goal msg_;
};

class Init_MoveTurtle_Goal_linear_vel_y
{
public:
  explicit Init_MoveTurtle_Goal_linear_vel_y(::my_robot_interfaces::action::MoveTurtle_Goal & msg)
  : msg_(msg)
  {}
  Init_MoveTurtle_Goal_angular_vel_z linear_vel_y(::my_robot_interfaces::action::MoveTurtle_Goal::_linear_vel_y_type arg)
  {
    msg_.linear_vel_y = std::move(arg);
    return Init_MoveTurtle_Goal_angular_vel_z(msg_);
  }

private:
  ::my_robot_interfaces::action::MoveTurtle_Goal msg_;
};

class Init_MoveTurtle_Goal_linear_vel_x
{
public:
  Init_MoveTurtle_Goal_linear_vel_x()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_MoveTurtle_Goal_linear_vel_y linear_vel_x(::my_robot_interfaces::action::MoveTurtle_Goal::_linear_vel_x_type arg)
  {
    msg_.linear_vel_x = std::move(arg);
    return Init_MoveTurtle_Goal_linear_vel_y(msg_);
  }

private:
  ::my_robot_interfaces::action::MoveTurtle_Goal msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::my_robot_interfaces::action::MoveTurtle_Goal>()
{
  return my_robot_interfaces::action::builder::Init_MoveTurtle_Goal_linear_vel_x();
}

}  // namespace my_robot_interfaces


namespace my_robot_interfaces
{

namespace action
{

namespace builder
{

class Init_MoveTurtle_Result_message
{
public:
  explicit Init_MoveTurtle_Result_message(::my_robot_interfaces::action::MoveTurtle_Result & msg)
  : msg_(msg)
  {}
  ::my_robot_interfaces::action::MoveTurtle_Result message(::my_robot_interfaces::action::MoveTurtle_Result::_message_type arg)
  {
    msg_.message = std::move(arg);
    return std::move(msg_);
  }

private:
  ::my_robot_interfaces::action::MoveTurtle_Result msg_;
};

class Init_MoveTurtle_Result_success
{
public:
  Init_MoveTurtle_Result_success()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_MoveTurtle_Result_message success(::my_robot_interfaces::action::MoveTurtle_Result::_success_type arg)
  {
    msg_.success = std::move(arg);
    return Init_MoveTurtle_Result_message(msg_);
  }

private:
  ::my_robot_interfaces::action::MoveTurtle_Result msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::my_robot_interfaces::action::MoveTurtle_Result>()
{
  return my_robot_interfaces::action::builder::Init_MoveTurtle_Result_success();
}

}  // namespace my_robot_interfaces


namespace my_robot_interfaces
{

namespace action
{


}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::my_robot_interfaces::action::MoveTurtle_Feedback>()
{
  return ::my_robot_interfaces::action::MoveTurtle_Feedback(rosidl_runtime_cpp::MessageInitialization::ZERO);
}

}  // namespace my_robot_interfaces


namespace my_robot_interfaces
{

namespace action
{

namespace builder
{

class Init_MoveTurtle_SendGoal_Request_goal
{
public:
  explicit Init_MoveTurtle_SendGoal_Request_goal(::my_robot_interfaces::action::MoveTurtle_SendGoal_Request & msg)
  : msg_(msg)
  {}
  ::my_robot_interfaces::action::MoveTurtle_SendGoal_Request goal(::my_robot_interfaces::action::MoveTurtle_SendGoal_Request::_goal_type arg)
  {
    msg_.goal = std::move(arg);
    return std::move(msg_);
  }

private:
  ::my_robot_interfaces::action::MoveTurtle_SendGoal_Request msg_;
};

class Init_MoveTurtle_SendGoal_Request_goal_id
{
public:
  Init_MoveTurtle_SendGoal_Request_goal_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_MoveTurtle_SendGoal_Request_goal goal_id(::my_robot_interfaces::action::MoveTurtle_SendGoal_Request::_goal_id_type arg)
  {
    msg_.goal_id = std::move(arg);
    return Init_MoveTurtle_SendGoal_Request_goal(msg_);
  }

private:
  ::my_robot_interfaces::action::MoveTurtle_SendGoal_Request msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::my_robot_interfaces::action::MoveTurtle_SendGoal_Request>()
{
  return my_robot_interfaces::action::builder::Init_MoveTurtle_SendGoal_Request_goal_id();
}

}  // namespace my_robot_interfaces


namespace my_robot_interfaces
{

namespace action
{

namespace builder
{

class Init_MoveTurtle_SendGoal_Response_stamp
{
public:
  explicit Init_MoveTurtle_SendGoal_Response_stamp(::my_robot_interfaces::action::MoveTurtle_SendGoal_Response & msg)
  : msg_(msg)
  {}
  ::my_robot_interfaces::action::MoveTurtle_SendGoal_Response stamp(::my_robot_interfaces::action::MoveTurtle_SendGoal_Response::_stamp_type arg)
  {
    msg_.stamp = std::move(arg);
    return std::move(msg_);
  }

private:
  ::my_robot_interfaces::action::MoveTurtle_SendGoal_Response msg_;
};

class Init_MoveTurtle_SendGoal_Response_accepted
{
public:
  Init_MoveTurtle_SendGoal_Response_accepted()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_MoveTurtle_SendGoal_Response_stamp accepted(::my_robot_interfaces::action::MoveTurtle_SendGoal_Response::_accepted_type arg)
  {
    msg_.accepted = std::move(arg);
    return Init_MoveTurtle_SendGoal_Response_stamp(msg_);
  }

private:
  ::my_robot_interfaces::action::MoveTurtle_SendGoal_Response msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::my_robot_interfaces::action::MoveTurtle_SendGoal_Response>()
{
  return my_robot_interfaces::action::builder::Init_MoveTurtle_SendGoal_Response_accepted();
}

}  // namespace my_robot_interfaces


namespace my_robot_interfaces
{

namespace action
{

namespace builder
{

class Init_MoveTurtle_GetResult_Request_goal_id
{
public:
  Init_MoveTurtle_GetResult_Request_goal_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::my_robot_interfaces::action::MoveTurtle_GetResult_Request goal_id(::my_robot_interfaces::action::MoveTurtle_GetResult_Request::_goal_id_type arg)
  {
    msg_.goal_id = std::move(arg);
    return std::move(msg_);
  }

private:
  ::my_robot_interfaces::action::MoveTurtle_GetResult_Request msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::my_robot_interfaces::action::MoveTurtle_GetResult_Request>()
{
  return my_robot_interfaces::action::builder::Init_MoveTurtle_GetResult_Request_goal_id();
}

}  // namespace my_robot_interfaces


namespace my_robot_interfaces
{

namespace action
{

namespace builder
{

class Init_MoveTurtle_GetResult_Response_result
{
public:
  explicit Init_MoveTurtle_GetResult_Response_result(::my_robot_interfaces::action::MoveTurtle_GetResult_Response & msg)
  : msg_(msg)
  {}
  ::my_robot_interfaces::action::MoveTurtle_GetResult_Response result(::my_robot_interfaces::action::MoveTurtle_GetResult_Response::_result_type arg)
  {
    msg_.result = std::move(arg);
    return std::move(msg_);
  }

private:
  ::my_robot_interfaces::action::MoveTurtle_GetResult_Response msg_;
};

class Init_MoveTurtle_GetResult_Response_status
{
public:
  Init_MoveTurtle_GetResult_Response_status()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_MoveTurtle_GetResult_Response_result status(::my_robot_interfaces::action::MoveTurtle_GetResult_Response::_status_type arg)
  {
    msg_.status = std::move(arg);
    return Init_MoveTurtle_GetResult_Response_result(msg_);
  }

private:
  ::my_robot_interfaces::action::MoveTurtle_GetResult_Response msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::my_robot_interfaces::action::MoveTurtle_GetResult_Response>()
{
  return my_robot_interfaces::action::builder::Init_MoveTurtle_GetResult_Response_status();
}

}  // namespace my_robot_interfaces


namespace my_robot_interfaces
{

namespace action
{

namespace builder
{

class Init_MoveTurtle_FeedbackMessage_feedback
{
public:
  explicit Init_MoveTurtle_FeedbackMessage_feedback(::my_robot_interfaces::action::MoveTurtle_FeedbackMessage & msg)
  : msg_(msg)
  {}
  ::my_robot_interfaces::action::MoveTurtle_FeedbackMessage feedback(::my_robot_interfaces::action::MoveTurtle_FeedbackMessage::_feedback_type arg)
  {
    msg_.feedback = std::move(arg);
    return std::move(msg_);
  }

private:
  ::my_robot_interfaces::action::MoveTurtle_FeedbackMessage msg_;
};

class Init_MoveTurtle_FeedbackMessage_goal_id
{
public:
  Init_MoveTurtle_FeedbackMessage_goal_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_MoveTurtle_FeedbackMessage_feedback goal_id(::my_robot_interfaces::action::MoveTurtle_FeedbackMessage::_goal_id_type arg)
  {
    msg_.goal_id = std::move(arg);
    return Init_MoveTurtle_FeedbackMessage_feedback(msg_);
  }

private:
  ::my_robot_interfaces::action::MoveTurtle_FeedbackMessage msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::my_robot_interfaces::action::MoveTurtle_FeedbackMessage>()
{
  return my_robot_interfaces::action::builder::Init_MoveTurtle_FeedbackMessage_goal_id();
}

}  // namespace my_robot_interfaces

#endif  // MY_ROBOT_INTERFACES__ACTION__DETAIL__MOVE_TURTLE__BUILDER_HPP_
