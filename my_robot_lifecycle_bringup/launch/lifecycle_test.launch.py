from launch import LaunchDescription
from launch_ros.actions import LifecycleNode

def generate_launch_description():
    ld = LaunchDescription()

    number_node= LifecycleNode(
        package="lifecycle_py",
        executable="number_publisher",
        name="my_number_publisher",
        namespace=""
    )

    ld.add_action(number_node)

    return ld