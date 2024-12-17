// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from my_robot_interfaces:srv/Catch.idl
// generated code does not contain a copyright notice

#ifndef MY_ROBOT_INTERFACES__SRV__DETAIL__CATCH__STRUCT_HPP_
#define MY_ROBOT_INTERFACES__SRV__DETAIL__CATCH__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


// Include directives for member types
// Member 'turtle'
#include "my_robot_interfaces/msg/detail/turtle__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__my_robot_interfaces__srv__Catch_Request __attribute__((deprecated))
#else
# define DEPRECATED__my_robot_interfaces__srv__Catch_Request __declspec(deprecated)
#endif

namespace my_robot_interfaces
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct Catch_Request_
{
  using Type = Catch_Request_<ContainerAllocator>;

  explicit Catch_Request_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : turtle(_init)
  {
    (void)_init;
  }

  explicit Catch_Request_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : turtle(_alloc, _init)
  {
    (void)_init;
  }

  // field types and members
  using _turtle_type =
    my_robot_interfaces::msg::Turtle_<ContainerAllocator>;
  _turtle_type turtle;

  // setters for named parameter idiom
  Type & set__turtle(
    const my_robot_interfaces::msg::Turtle_<ContainerAllocator> & _arg)
  {
    this->turtle = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    my_robot_interfaces::srv::Catch_Request_<ContainerAllocator> *;
  using ConstRawPtr =
    const my_robot_interfaces::srv::Catch_Request_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<my_robot_interfaces::srv::Catch_Request_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<my_robot_interfaces::srv::Catch_Request_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      my_robot_interfaces::srv::Catch_Request_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<my_robot_interfaces::srv::Catch_Request_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      my_robot_interfaces::srv::Catch_Request_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<my_robot_interfaces::srv::Catch_Request_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<my_robot_interfaces::srv::Catch_Request_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<my_robot_interfaces::srv::Catch_Request_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__my_robot_interfaces__srv__Catch_Request
    std::shared_ptr<my_robot_interfaces::srv::Catch_Request_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__my_robot_interfaces__srv__Catch_Request
    std::shared_ptr<my_robot_interfaces::srv::Catch_Request_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const Catch_Request_ & other) const
  {
    if (this->turtle != other.turtle) {
      return false;
    }
    return true;
  }
  bool operator!=(const Catch_Request_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct Catch_Request_

// alias to use template instance with default allocator
using Catch_Request =
  my_robot_interfaces::srv::Catch_Request_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace my_robot_interfaces


#ifndef _WIN32
# define DEPRECATED__my_robot_interfaces__srv__Catch_Response __attribute__((deprecated))
#else
# define DEPRECATED__my_robot_interfaces__srv__Catch_Response __declspec(deprecated)
#endif

namespace my_robot_interfaces
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct Catch_Response_
{
  using Type = Catch_Response_<ContainerAllocator>;

  explicit Catch_Response_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->response_msg = "";
    }
  }

  explicit Catch_Response_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : response_msg(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->response_msg = "";
    }
  }

  // field types and members
  using _response_msg_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _response_msg_type response_msg;

  // setters for named parameter idiom
  Type & set__response_msg(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->response_msg = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    my_robot_interfaces::srv::Catch_Response_<ContainerAllocator> *;
  using ConstRawPtr =
    const my_robot_interfaces::srv::Catch_Response_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<my_robot_interfaces::srv::Catch_Response_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<my_robot_interfaces::srv::Catch_Response_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      my_robot_interfaces::srv::Catch_Response_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<my_robot_interfaces::srv::Catch_Response_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      my_robot_interfaces::srv::Catch_Response_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<my_robot_interfaces::srv::Catch_Response_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<my_robot_interfaces::srv::Catch_Response_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<my_robot_interfaces::srv::Catch_Response_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__my_robot_interfaces__srv__Catch_Response
    std::shared_ptr<my_robot_interfaces::srv::Catch_Response_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__my_robot_interfaces__srv__Catch_Response
    std::shared_ptr<my_robot_interfaces::srv::Catch_Response_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const Catch_Response_ & other) const
  {
    if (this->response_msg != other.response_msg) {
      return false;
    }
    return true;
  }
  bool operator!=(const Catch_Response_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct Catch_Response_

// alias to use template instance with default allocator
using Catch_Response =
  my_robot_interfaces::srv::Catch_Response_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace my_robot_interfaces

namespace my_robot_interfaces
{

namespace srv
{

struct Catch
{
  using Request = my_robot_interfaces::srv::Catch_Request;
  using Response = my_robot_interfaces::srv::Catch_Response;
};

}  // namespace srv

}  // namespace my_robot_interfaces

#endif  // MY_ROBOT_INTERFACES__SRV__DETAIL__CATCH__STRUCT_HPP_
