from launch import LaunchDescription
from launch_ros.actions import Node

def generate_launch_description():
    ld = LaunchDescription()
    number_publisher_node = Node(
        package = "my_py_pkg",
        executable = "number_publisher",
        name = "my_number_publisher",
        remappings= [
             ("number", "my_number")
        ],
        parameters=[
            {"number_to_publish": 4},
            {"frequency": 2.5}
        ]
    ) 
    
    counter_node = Node(
        package="my_cpp_pkg",
        executable="number_counter",
        name = "my_number_counter",
        remappings= [
            ("number", "my_number"),
            ("number_count", "my_number_count")
        ]
    )
    
    ld.add_action(number_publisher_node)
    ld.add_action(counter_node)
    
    return ld