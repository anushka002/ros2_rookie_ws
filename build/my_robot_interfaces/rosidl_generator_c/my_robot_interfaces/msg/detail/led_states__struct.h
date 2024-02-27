// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from my_robot_interfaces:msg/LedStates.idl
// generated code does not contain a copyright notice

#ifndef MY_ROBOT_INTERFACES__MSG__DETAIL__LED_STATES__STRUCT_H_
#define MY_ROBOT_INTERFACES__MSG__DETAIL__LED_STATES__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'msg'
#include "rosidl_runtime_c/string.h"

/// Struct defined in msg/LedStates in the package my_robot_interfaces.
typedef struct my_robot_interfaces__msg__LedStates
{
  bool led1;
  bool led2;
  bool led3;
  rosidl_runtime_c__String msg;
} my_robot_interfaces__msg__LedStates;

// Struct for a sequence of my_robot_interfaces__msg__LedStates.
typedef struct my_robot_interfaces__msg__LedStates__Sequence
{
  my_robot_interfaces__msg__LedStates * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} my_robot_interfaces__msg__LedStates__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // MY_ROBOT_INTERFACES__MSG__DETAIL__LED_STATES__STRUCT_H_
