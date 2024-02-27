// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from my_robot_interfaces:msg/HardwareStatus.idl
// generated code does not contain a copyright notice

#ifndef MY_ROBOT_INTERFACES__MSG__DETAIL__HARDWARE_STATUS__STRUCT_HPP_
#define MY_ROBOT_INTERFACES__MSG__DETAIL__HARDWARE_STATUS__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__my_robot_interfaces__msg__HardwareStatus __attribute__((deprecated))
#else
# define DEPRECATED__my_robot_interfaces__msg__HardwareStatus __declspec(deprecated)
#endif

namespace my_robot_interfaces
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct HardwareStatus_
{
  using Type = HardwareStatus_<ContainerAllocator>;

  explicit HardwareStatus_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->temp = 0ll;
      this->motors_ready = false;
      this->debug_msg = "";
    }
  }

  explicit HardwareStatus_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : debug_msg(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->temp = 0ll;
      this->motors_ready = false;
      this->debug_msg = "";
    }
  }

  // field types and members
  using _temp_type =
    int64_t;
  _temp_type temp;
  using _motors_ready_type =
    bool;
  _motors_ready_type motors_ready;
  using _debug_msg_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _debug_msg_type debug_msg;

  // setters for named parameter idiom
  Type & set__temp(
    const int64_t & _arg)
  {
    this->temp = _arg;
    return *this;
  }
  Type & set__motors_ready(
    const bool & _arg)
  {
    this->motors_ready = _arg;
    return *this;
  }
  Type & set__debug_msg(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->debug_msg = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    my_robot_interfaces::msg::HardwareStatus_<ContainerAllocator> *;
  using ConstRawPtr =
    const my_robot_interfaces::msg::HardwareStatus_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<my_robot_interfaces::msg::HardwareStatus_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<my_robot_interfaces::msg::HardwareStatus_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      my_robot_interfaces::msg::HardwareStatus_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<my_robot_interfaces::msg::HardwareStatus_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      my_robot_interfaces::msg::HardwareStatus_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<my_robot_interfaces::msg::HardwareStatus_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<my_robot_interfaces::msg::HardwareStatus_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<my_robot_interfaces::msg::HardwareStatus_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__my_robot_interfaces__msg__HardwareStatus
    std::shared_ptr<my_robot_interfaces::msg::HardwareStatus_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__my_robot_interfaces__msg__HardwareStatus
    std::shared_ptr<my_robot_interfaces::msg::HardwareStatus_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const HardwareStatus_ & other) const
  {
    if (this->temp != other.temp) {
      return false;
    }
    if (this->motors_ready != other.motors_ready) {
      return false;
    }
    if (this->debug_msg != other.debug_msg) {
      return false;
    }
    return true;
  }
  bool operator!=(const HardwareStatus_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct HardwareStatus_

// alias to use template instance with default allocator
using HardwareStatus =
  my_robot_interfaces::msg::HardwareStatus_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace my_robot_interfaces

#endif  // MY_ROBOT_INTERFACES__MSG__DETAIL__HARDWARE_STATUS__STRUCT_HPP_
