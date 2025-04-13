// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from my_robot_interfaces:action/ReachUntil.idl
// generated code does not contain a copyright notice

#ifndef MY_ROBOT_INTERFACES__ACTION__DETAIL__REACH_UNTIL__BUILDER_HPP_
#define MY_ROBOT_INTERFACES__ACTION__DETAIL__REACH_UNTIL__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "my_robot_interfaces/action/detail/reach_until__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace my_robot_interfaces
{

namespace action
{

namespace builder
{

class Init_ReachUntil_Goal_velocity
{
public:
  explicit Init_ReachUntil_Goal_velocity(::my_robot_interfaces::action::ReachUntil_Goal & msg)
  : msg_(msg)
  {}
  ::my_robot_interfaces::action::ReachUntil_Goal velocity(::my_robot_interfaces::action::ReachUntil_Goal::_velocity_type arg)
  {
    msg_.velocity = std::move(arg);
    return std::move(msg_);
  }

private:
  ::my_robot_interfaces::action::ReachUntil_Goal msg_;
};

class Init_ReachUntil_Goal_position
{
public:
  Init_ReachUntil_Goal_position()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_ReachUntil_Goal_velocity position(::my_robot_interfaces::action::ReachUntil_Goal::_position_type arg)
  {
    msg_.position = std::move(arg);
    return Init_ReachUntil_Goal_velocity(msg_);
  }

private:
  ::my_robot_interfaces::action::ReachUntil_Goal msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::my_robot_interfaces::action::ReachUntil_Goal>()
{
  return my_robot_interfaces::action::builder::Init_ReachUntil_Goal_position();
}

}  // namespace my_robot_interfaces


namespace my_robot_interfaces
{

namespace action
{

namespace builder
{

class Init_ReachUntil_Result_message
{
public:
  explicit Init_ReachUntil_Result_message(::my_robot_interfaces::action::ReachUntil_Result & msg)
  : msg_(msg)
  {}
  ::my_robot_interfaces::action::ReachUntil_Result message(::my_robot_interfaces::action::ReachUntil_Result::_message_type arg)
  {
    msg_.message = std::move(arg);
    return std::move(msg_);
  }

private:
  ::my_robot_interfaces::action::ReachUntil_Result msg_;
};

class Init_ReachUntil_Result_position
{
public:
  Init_ReachUntil_Result_position()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_ReachUntil_Result_message position(::my_robot_interfaces::action::ReachUntil_Result::_position_type arg)
  {
    msg_.position = std::move(arg);
    return Init_ReachUntil_Result_message(msg_);
  }

private:
  ::my_robot_interfaces::action::ReachUntil_Result msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::my_robot_interfaces::action::ReachUntil_Result>()
{
  return my_robot_interfaces::action::builder::Init_ReachUntil_Result_position();
}

}  // namespace my_robot_interfaces


namespace my_robot_interfaces
{

namespace action
{

namespace builder
{

class Init_ReachUntil_Feedback_current_position
{
public:
  Init_ReachUntil_Feedback_current_position()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::my_robot_interfaces::action::ReachUntil_Feedback current_position(::my_robot_interfaces::action::ReachUntil_Feedback::_current_position_type arg)
  {
    msg_.current_position = std::move(arg);
    return std::move(msg_);
  }

private:
  ::my_robot_interfaces::action::ReachUntil_Feedback msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::my_robot_interfaces::action::ReachUntil_Feedback>()
{
  return my_robot_interfaces::action::builder::Init_ReachUntil_Feedback_current_position();
}

}  // namespace my_robot_interfaces


namespace my_robot_interfaces
{

namespace action
{

namespace builder
{

class Init_ReachUntil_SendGoal_Request_goal
{
public:
  explicit Init_ReachUntil_SendGoal_Request_goal(::my_robot_interfaces::action::ReachUntil_SendGoal_Request & msg)
  : msg_(msg)
  {}
  ::my_robot_interfaces::action::ReachUntil_SendGoal_Request goal(::my_robot_interfaces::action::ReachUntil_SendGoal_Request::_goal_type arg)
  {
    msg_.goal = std::move(arg);
    return std::move(msg_);
  }

private:
  ::my_robot_interfaces::action::ReachUntil_SendGoal_Request msg_;
};

class Init_ReachUntil_SendGoal_Request_goal_id
{
public:
  Init_ReachUntil_SendGoal_Request_goal_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_ReachUntil_SendGoal_Request_goal goal_id(::my_robot_interfaces::action::ReachUntil_SendGoal_Request::_goal_id_type arg)
  {
    msg_.goal_id = std::move(arg);
    return Init_ReachUntil_SendGoal_Request_goal(msg_);
  }

private:
  ::my_robot_interfaces::action::ReachUntil_SendGoal_Request msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::my_robot_interfaces::action::ReachUntil_SendGoal_Request>()
{
  return my_robot_interfaces::action::builder::Init_ReachUntil_SendGoal_Request_goal_id();
}

}  // namespace my_robot_interfaces


namespace my_robot_interfaces
{

namespace action
{

namespace builder
{

class Init_ReachUntil_SendGoal_Response_stamp
{
public:
  explicit Init_ReachUntil_SendGoal_Response_stamp(::my_robot_interfaces::action::ReachUntil_SendGoal_Response & msg)
  : msg_(msg)
  {}
  ::my_robot_interfaces::action::ReachUntil_SendGoal_Response stamp(::my_robot_interfaces::action::ReachUntil_SendGoal_Response::_stamp_type arg)
  {
    msg_.stamp = std::move(arg);
    return std::move(msg_);
  }

private:
  ::my_robot_interfaces::action::ReachUntil_SendGoal_Response msg_;
};

class Init_ReachUntil_SendGoal_Response_accepted
{
public:
  Init_ReachUntil_SendGoal_Response_accepted()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_ReachUntil_SendGoal_Response_stamp accepted(::my_robot_interfaces::action::ReachUntil_SendGoal_Response::_accepted_type arg)
  {
    msg_.accepted = std::move(arg);
    return Init_ReachUntil_SendGoal_Response_stamp(msg_);
  }

private:
  ::my_robot_interfaces::action::ReachUntil_SendGoal_Response msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::my_robot_interfaces::action::ReachUntil_SendGoal_Response>()
{
  return my_robot_interfaces::action::builder::Init_ReachUntil_SendGoal_Response_accepted();
}

}  // namespace my_robot_interfaces


namespace my_robot_interfaces
{

namespace action
{

namespace builder
{

class Init_ReachUntil_GetResult_Request_goal_id
{
public:
  Init_ReachUntil_GetResult_Request_goal_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::my_robot_interfaces::action::ReachUntil_GetResult_Request goal_id(::my_robot_interfaces::action::ReachUntil_GetResult_Request::_goal_id_type arg)
  {
    msg_.goal_id = std::move(arg);
    return std::move(msg_);
  }

private:
  ::my_robot_interfaces::action::ReachUntil_GetResult_Request msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::my_robot_interfaces::action::ReachUntil_GetResult_Request>()
{
  return my_robot_interfaces::action::builder::Init_ReachUntil_GetResult_Request_goal_id();
}

}  // namespace my_robot_interfaces


namespace my_robot_interfaces
{

namespace action
{

namespace builder
{

class Init_ReachUntil_GetResult_Response_result
{
public:
  explicit Init_ReachUntil_GetResult_Response_result(::my_robot_interfaces::action::ReachUntil_GetResult_Response & msg)
  : msg_(msg)
  {}
  ::my_robot_interfaces::action::ReachUntil_GetResult_Response result(::my_robot_interfaces::action::ReachUntil_GetResult_Response::_result_type arg)
  {
    msg_.result = std::move(arg);
    return std::move(msg_);
  }

private:
  ::my_robot_interfaces::action::ReachUntil_GetResult_Response msg_;
};

class Init_ReachUntil_GetResult_Response_status
{
public:
  Init_ReachUntil_GetResult_Response_status()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_ReachUntil_GetResult_Response_result status(::my_robot_interfaces::action::ReachUntil_GetResult_Response::_status_type arg)
  {
    msg_.status = std::move(arg);
    return Init_ReachUntil_GetResult_Response_result(msg_);
  }

private:
  ::my_robot_interfaces::action::ReachUntil_GetResult_Response msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::my_robot_interfaces::action::ReachUntil_GetResult_Response>()
{
  return my_robot_interfaces::action::builder::Init_ReachUntil_GetResult_Response_status();
}

}  // namespace my_robot_interfaces


namespace my_robot_interfaces
{

namespace action
{

namespace builder
{

class Init_ReachUntil_FeedbackMessage_feedback
{
public:
  explicit Init_ReachUntil_FeedbackMessage_feedback(::my_robot_interfaces::action::ReachUntil_FeedbackMessage & msg)
  : msg_(msg)
  {}
  ::my_robot_interfaces::action::ReachUntil_FeedbackMessage feedback(::my_robot_interfaces::action::ReachUntil_FeedbackMessage::_feedback_type arg)
  {
    msg_.feedback = std::move(arg);
    return std::move(msg_);
  }

private:
  ::my_robot_interfaces::action::ReachUntil_FeedbackMessage msg_;
};

class Init_ReachUntil_FeedbackMessage_goal_id
{
public:
  Init_ReachUntil_FeedbackMessage_goal_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_ReachUntil_FeedbackMessage_feedback goal_id(::my_robot_interfaces::action::ReachUntil_FeedbackMessage::_goal_id_type arg)
  {
    msg_.goal_id = std::move(arg);
    return Init_ReachUntil_FeedbackMessage_feedback(msg_);
  }

private:
  ::my_robot_interfaces::action::ReachUntil_FeedbackMessage msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::my_robot_interfaces::action::ReachUntil_FeedbackMessage>()
{
  return my_robot_interfaces::action::builder::Init_ReachUntil_FeedbackMessage_goal_id();
}

}  // namespace my_robot_interfaces

#endif  // MY_ROBOT_INTERFACES__ACTION__DETAIL__REACH_UNTIL__BUILDER_HPP_
