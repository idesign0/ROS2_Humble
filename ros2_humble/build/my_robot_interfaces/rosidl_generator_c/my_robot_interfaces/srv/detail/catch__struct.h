// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from my_robot_interfaces:srv/Catch.idl
// generated code does not contain a copyright notice

#ifndef MY_ROBOT_INTERFACES__SRV__DETAIL__CATCH__STRUCT_H_
#define MY_ROBOT_INTERFACES__SRV__DETAIL__CATCH__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'turtle'
#include "my_robot_interfaces/msg/detail/turtle__struct.h"

/// Struct defined in srv/Catch in the package my_robot_interfaces.
typedef struct my_robot_interfaces__srv__Catch_Request
{
  my_robot_interfaces__msg__Turtle turtle;
} my_robot_interfaces__srv__Catch_Request;

// Struct for a sequence of my_robot_interfaces__srv__Catch_Request.
typedef struct my_robot_interfaces__srv__Catch_Request__Sequence
{
  my_robot_interfaces__srv__Catch_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} my_robot_interfaces__srv__Catch_Request__Sequence;


// Constants defined in the message

/// Struct defined in srv/Catch in the package my_robot_interfaces.
typedef struct my_robot_interfaces__srv__Catch_Response
{
  uint8_t structure_needs_at_least_one_member;
} my_robot_interfaces__srv__Catch_Response;

// Struct for a sequence of my_robot_interfaces__srv__Catch_Response.
typedef struct my_robot_interfaces__srv__Catch_Response__Sequence
{
  my_robot_interfaces__srv__Catch_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} my_robot_interfaces__srv__Catch_Response__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // MY_ROBOT_INTERFACES__SRV__DETAIL__CATCH__STRUCT_H_
