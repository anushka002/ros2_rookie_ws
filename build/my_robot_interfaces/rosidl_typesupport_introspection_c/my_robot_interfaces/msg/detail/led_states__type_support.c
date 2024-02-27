// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from my_robot_interfaces:msg/LedStates.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "my_robot_interfaces/msg/detail/led_states__rosidl_typesupport_introspection_c.h"
#include "my_robot_interfaces/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "my_robot_interfaces/msg/detail/led_states__functions.h"
#include "my_robot_interfaces/msg/detail/led_states__struct.h"


// Include directives for member types
// Member `msg`
#include "rosidl_runtime_c/string_functions.h"

#ifdef __cplusplus
extern "C"
{
#endif

void my_robot_interfaces__msg__LedStates__rosidl_typesupport_introspection_c__LedStates_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  my_robot_interfaces__msg__LedStates__init(message_memory);
}

void my_robot_interfaces__msg__LedStates__rosidl_typesupport_introspection_c__LedStates_fini_function(void * message_memory)
{
  my_robot_interfaces__msg__LedStates__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember my_robot_interfaces__msg__LedStates__rosidl_typesupport_introspection_c__LedStates_message_member_array[4] = {
  {
    "led1",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_BOOLEAN,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(my_robot_interfaces__msg__LedStates, led1),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "led2",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_BOOLEAN,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(my_robot_interfaces__msg__LedStates, led2),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "led3",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_BOOLEAN,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(my_robot_interfaces__msg__LedStates, led3),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "msg",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(my_robot_interfaces__msg__LedStates, msg),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers my_robot_interfaces__msg__LedStates__rosidl_typesupport_introspection_c__LedStates_message_members = {
  "my_robot_interfaces__msg",  // message namespace
  "LedStates",  // message name
  4,  // number of fields
  sizeof(my_robot_interfaces__msg__LedStates),
  my_robot_interfaces__msg__LedStates__rosidl_typesupport_introspection_c__LedStates_message_member_array,  // message members
  my_robot_interfaces__msg__LedStates__rosidl_typesupport_introspection_c__LedStates_init_function,  // function to initialize message memory (memory has to be allocated)
  my_robot_interfaces__msg__LedStates__rosidl_typesupport_introspection_c__LedStates_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t my_robot_interfaces__msg__LedStates__rosidl_typesupport_introspection_c__LedStates_message_type_support_handle = {
  0,
  &my_robot_interfaces__msg__LedStates__rosidl_typesupport_introspection_c__LedStates_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_my_robot_interfaces
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, my_robot_interfaces, msg, LedStates)() {
  if (!my_robot_interfaces__msg__LedStates__rosidl_typesupport_introspection_c__LedStates_message_type_support_handle.typesupport_identifier) {
    my_robot_interfaces__msg__LedStates__rosidl_typesupport_introspection_c__LedStates_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &my_robot_interfaces__msg__LedStates__rosidl_typesupport_introspection_c__LedStates_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
