// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from my_robot_interfaces:msg/LedStates.idl
// generated code does not contain a copyright notice

#ifndef MY_ROBOT_INTERFACES__MSG__DETAIL__LED_STATES__BUILDER_HPP_
#define MY_ROBOT_INTERFACES__MSG__DETAIL__LED_STATES__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "my_robot_interfaces/msg/detail/led_states__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace my_robot_interfaces
{

namespace msg
{

namespace builder
{

class Init_LedStates_msg
{
public:
  explicit Init_LedStates_msg(::my_robot_interfaces::msg::LedStates & msg)
  : msg_(msg)
  {}
  ::my_robot_interfaces::msg::LedStates msg(::my_robot_interfaces::msg::LedStates::_msg_type arg)
  {
    msg_.msg = std::move(arg);
    return std::move(msg_);
  }

private:
  ::my_robot_interfaces::msg::LedStates msg_;
};

class Init_LedStates_led3
{
public:
  explicit Init_LedStates_led3(::my_robot_interfaces::msg::LedStates & msg)
  : msg_(msg)
  {}
  Init_LedStates_msg led3(::my_robot_interfaces::msg::LedStates::_led3_type arg)
  {
    msg_.led3 = std::move(arg);
    return Init_LedStates_msg(msg_);
  }

private:
  ::my_robot_interfaces::msg::LedStates msg_;
};

class Init_LedStates_led2
{
public:
  explicit Init_LedStates_led2(::my_robot_interfaces::msg::LedStates & msg)
  : msg_(msg)
  {}
  Init_LedStates_led3 led2(::my_robot_interfaces::msg::LedStates::_led2_type arg)
  {
    msg_.led2 = std::move(arg);
    return Init_LedStates_led3(msg_);
  }

private:
  ::my_robot_interfaces::msg::LedStates msg_;
};

class Init_LedStates_led1
{
public:
  Init_LedStates_led1()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_LedStates_led2 led1(::my_robot_interfaces::msg::LedStates::_led1_type arg)
  {
    msg_.led1 = std::move(arg);
    return Init_LedStates_led2(msg_);
  }

private:
  ::my_robot_interfaces::msg::LedStates msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::my_robot_interfaces::msg::LedStates>()
{
  return my_robot_interfaces::msg::builder::Init_LedStates_led1();
}

}  // namespace my_robot_interfaces

#endif  // MY_ROBOT_INTERFACES__MSG__DETAIL__LED_STATES__BUILDER_HPP_
