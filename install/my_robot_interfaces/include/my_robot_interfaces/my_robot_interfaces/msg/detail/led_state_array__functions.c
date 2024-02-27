// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from my_robot_interfaces:msg/LedStateArray.idl
// generated code does not contain a copyright notice
#include "my_robot_interfaces/msg/detail/led_state_array__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `led_states`
#include "rosidl_runtime_c/primitives_sequence_functions.h"
// Member `status`
#include "rosidl_runtime_c/string_functions.h"

bool
my_robot_interfaces__msg__LedStateArray__init(my_robot_interfaces__msg__LedStateArray * msg)
{
  if (!msg) {
    return false;
  }
  // led_states
  if (!rosidl_runtime_c__int64__Sequence__init(&msg->led_states, 0)) {
    my_robot_interfaces__msg__LedStateArray__fini(msg);
    return false;
  }
  // status
  if (!rosidl_runtime_c__String__init(&msg->status)) {
    my_robot_interfaces__msg__LedStateArray__fini(msg);
    return false;
  }
  return true;
}

void
my_robot_interfaces__msg__LedStateArray__fini(my_robot_interfaces__msg__LedStateArray * msg)
{
  if (!msg) {
    return;
  }
  // led_states
  rosidl_runtime_c__int64__Sequence__fini(&msg->led_states);
  // status
  rosidl_runtime_c__String__fini(&msg->status);
}

bool
my_robot_interfaces__msg__LedStateArray__are_equal(const my_robot_interfaces__msg__LedStateArray * lhs, const my_robot_interfaces__msg__LedStateArray * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // led_states
  if (!rosidl_runtime_c__int64__Sequence__are_equal(
      &(lhs->led_states), &(rhs->led_states)))
  {
    return false;
  }
  // status
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->status), &(rhs->status)))
  {
    return false;
  }
  return true;
}

bool
my_robot_interfaces__msg__LedStateArray__copy(
  const my_robot_interfaces__msg__LedStateArray * input,
  my_robot_interfaces__msg__LedStateArray * output)
{
  if (!input || !output) {
    return false;
  }
  // led_states
  if (!rosidl_runtime_c__int64__Sequence__copy(
      &(input->led_states), &(output->led_states)))
  {
    return false;
  }
  // status
  if (!rosidl_runtime_c__String__copy(
      &(input->status), &(output->status)))
  {
    return false;
  }
  return true;
}

my_robot_interfaces__msg__LedStateArray *
my_robot_interfaces__msg__LedStateArray__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  my_robot_interfaces__msg__LedStateArray * msg = (my_robot_interfaces__msg__LedStateArray *)allocator.allocate(sizeof(my_robot_interfaces__msg__LedStateArray), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(my_robot_interfaces__msg__LedStateArray));
  bool success = my_robot_interfaces__msg__LedStateArray__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
my_robot_interfaces__msg__LedStateArray__destroy(my_robot_interfaces__msg__LedStateArray * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    my_robot_interfaces__msg__LedStateArray__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
my_robot_interfaces__msg__LedStateArray__Sequence__init(my_robot_interfaces__msg__LedStateArray__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  my_robot_interfaces__msg__LedStateArray * data = NULL;

  if (size) {
    data = (my_robot_interfaces__msg__LedStateArray *)allocator.zero_allocate(size, sizeof(my_robot_interfaces__msg__LedStateArray), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = my_robot_interfaces__msg__LedStateArray__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        my_robot_interfaces__msg__LedStateArray__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
my_robot_interfaces__msg__LedStateArray__Sequence__fini(my_robot_interfaces__msg__LedStateArray__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      my_robot_interfaces__msg__LedStateArray__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

my_robot_interfaces__msg__LedStateArray__Sequence *
my_robot_interfaces__msg__LedStateArray__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  my_robot_interfaces__msg__LedStateArray__Sequence * array = (my_robot_interfaces__msg__LedStateArray__Sequence *)allocator.allocate(sizeof(my_robot_interfaces__msg__LedStateArray__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = my_robot_interfaces__msg__LedStateArray__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
my_robot_interfaces__msg__LedStateArray__Sequence__destroy(my_robot_interfaces__msg__LedStateArray__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    my_robot_interfaces__msg__LedStateArray__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
my_robot_interfaces__msg__LedStateArray__Sequence__are_equal(const my_robot_interfaces__msg__LedStateArray__Sequence * lhs, const my_robot_interfaces__msg__LedStateArray__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!my_robot_interfaces__msg__LedStateArray__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
my_robot_interfaces__msg__LedStateArray__Sequence__copy(
  const my_robot_interfaces__msg__LedStateArray__Sequence * input,
  my_robot_interfaces__msg__LedStateArray__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(my_robot_interfaces__msg__LedStateArray);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    my_robot_interfaces__msg__LedStateArray * data =
      (my_robot_interfaces__msg__LedStateArray *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!my_robot_interfaces__msg__LedStateArray__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          my_robot_interfaces__msg__LedStateArray__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!my_robot_interfaces__msg__LedStateArray__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
