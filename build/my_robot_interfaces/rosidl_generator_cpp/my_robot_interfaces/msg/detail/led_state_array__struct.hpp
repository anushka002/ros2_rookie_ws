// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from my_robot_interfaces:msg/LedStateArray.idl
// generated code does not contain a copyright notice

#ifndef MY_ROBOT_INTERFACES__MSG__DETAIL__LED_STATE_ARRAY__STRUCT_HPP_
#define MY_ROBOT_INTERFACES__MSG__DETAIL__LED_STATE_ARRAY__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__my_robot_interfaces__msg__LedStateArray __attribute__((deprecated))
#else
# define DEPRECATED__my_robot_interfaces__msg__LedStateArray __declspec(deprecated)
#endif

namespace my_robot_interfaces
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct LedStateArray_
{
  using Type = LedStateArray_<ContainerAllocator>;

  explicit LedStateArray_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->status = "";
    }
  }

  explicit LedStateArray_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : status(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->status = "";
    }
  }

  // field types and members
  using _led_states_type =
    std::vector<int64_t, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<int64_t>>;
  _led_states_type led_states;
  using _status_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _status_type status;

  // setters for named parameter idiom
  Type & set__led_states(
    const std::vector<int64_t, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<int64_t>> & _arg)
  {
    this->led_states = _arg;
    return *this;
  }
  Type & set__status(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->status = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    my_robot_interfaces::msg::LedStateArray_<ContainerAllocator> *;
  using ConstRawPtr =
    const my_robot_interfaces::msg::LedStateArray_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<my_robot_interfaces::msg::LedStateArray_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<my_robot_interfaces::msg::LedStateArray_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      my_robot_interfaces::msg::LedStateArray_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<my_robot_interfaces::msg::LedStateArray_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      my_robot_interfaces::msg::LedStateArray_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<my_robot_interfaces::msg::LedStateArray_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<my_robot_interfaces::msg::LedStateArray_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<my_robot_interfaces::msg::LedStateArray_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__my_robot_interfaces__msg__LedStateArray
    std::shared_ptr<my_robot_interfaces::msg::LedStateArray_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__my_robot_interfaces__msg__LedStateArray
    std::shared_ptr<my_robot_interfaces::msg::LedStateArray_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const LedStateArray_ & other) const
  {
    if (this->led_states != other.led_states) {
      return false;
    }
    if (this->status != other.status) {
      return false;
    }
    return true;
  }
  bool operator!=(const LedStateArray_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct LedStateArray_

// alias to use template instance with default allocator
using LedStateArray =
  my_robot_interfaces::msg::LedStateArray_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace my_robot_interfaces

#endif  // MY_ROBOT_INTERFACES__MSG__DETAIL__LED_STATE_ARRAY__STRUCT_HPP_
