from launch import LaunchDescription
from launch_ros.actions import Node

def generate_launch_description():
    ld = LaunchDescription()
    
    node_spawn = Node(
        package="turtlesim_catch_them_all",
        executable="turtle_spawn",
    )

    node_control = Node(
        package="turtlesim_catch_them_all",
        executable="turtle_controll",
    )
    
    node_turtle = Node(
        package="turtlesim",
        executable="turtlesim_node",
    )

    ld.add_action(node_spawn)
    ld.add_action(node_control)
    ld.add_action(node_turtle)

    return ld