// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from my_robot_interfaces:msg/LedStateArray.idl
// generated code does not contain a copyright notice

#ifndef MY_ROBOT_INTERFACES__MSG__DETAIL__LED_STATE_ARRAY__BUILDER_HPP_
#define MY_ROBOT_INTERFACES__MSG__DETAIL__LED_STATE_ARRAY__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "my_robot_interfaces/msg/detail/led_state_array__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace my_robot_interfaces
{

namespace msg
{

namespace builder
{

class Init_LedStateArray_status
{
public:
  explicit Init_LedStateArray_status(::my_robot_interfaces::msg::LedStateArray & msg)
  : msg_(msg)
  {}
  ::my_robot_interfaces::msg::LedStateArray status(::my_robot_interfaces::msg::LedStateArray::_status_type arg)
  {
    msg_.status = std::move(arg);
    return std::move(msg_);
  }

private:
  ::my_robot_interfaces::msg::LedStateArray msg_;
};

class Init_LedStateArray_led_states
{
public:
  Init_LedStateArray_led_states()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_LedStateArray_status led_states(::my_robot_interfaces::msg::LedStateArray::_led_states_type arg)
  {
    msg_.led_states = std::move(arg);
    return Init_LedStateArray_status(msg_);
  }

private:
  ::my_robot_interfaces::msg::LedStateArray msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::my_robot_interfaces::msg::LedStateArray>()
{
  return my_robot_interfaces::msg::builder::Init_LedStateArray_led_states();
}

}  // namespace my_robot_interfaces

#endif  // MY_ROBOT_INTERFACES__MSG__DETAIL__LED_STATE_ARRAY__BUILDER_HPP_
