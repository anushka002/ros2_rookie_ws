// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from my_robot_interfaces:msg/HardwareStatus.idl
// generated code does not contain a copyright notice

#ifndef MY_ROBOT_INTERFACES__MSG__DETAIL__HARDWARE_STATUS__BUILDER_HPP_
#define MY_ROBOT_INTERFACES__MSG__DETAIL__HARDWARE_STATUS__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "my_robot_interfaces/msg/detail/hardware_status__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace my_robot_interfaces
{

namespace msg
{

namespace builder
{

class Init_HardwareStatus_debug_msg
{
public:
  explicit Init_HardwareStatus_debug_msg(::my_robot_interfaces::msg::HardwareStatus & msg)
  : msg_(msg)
  {}
  ::my_robot_interfaces::msg::HardwareStatus debug_msg(::my_robot_interfaces::msg::HardwareStatus::_debug_msg_type arg)
  {
    msg_.debug_msg = std::move(arg);
    return std::move(msg_);
  }

private:
  ::my_robot_interfaces::msg::HardwareStatus msg_;
};

class Init_HardwareStatus_motors_ready
{
public:
  explicit Init_HardwareStatus_motors_ready(::my_robot_interfaces::msg::HardwareStatus & msg)
  : msg_(msg)
  {}
  Init_HardwareStatus_debug_msg motors_ready(::my_robot_interfaces::msg::HardwareStatus::_motors_ready_type arg)
  {
    msg_.motors_ready = std::move(arg);
    return Init_HardwareStatus_debug_msg(msg_);
  }

private:
  ::my_robot_interfaces::msg::HardwareStatus msg_;
};

class Init_HardwareStatus_temp
{
public:
  Init_HardwareStatus_temp()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_HardwareStatus_motors_ready temp(::my_robot_interfaces::msg::HardwareStatus::_temp_type arg)
  {
    msg_.temp = std::move(arg);
    return Init_HardwareStatus_motors_ready(msg_);
  }

private:
  ::my_robot_interfaces::msg::HardwareStatus msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::my_robot_interfaces::msg::HardwareStatus>()
{
  return my_robot_interfaces::msg::builder::Init_HardwareStatus_temp();
}

}  // namespace my_robot_interfaces

#endif  // MY_ROBOT_INTERFACES__MSG__DETAIL__HARDWARE_STATUS__BUILDER_HPP_
