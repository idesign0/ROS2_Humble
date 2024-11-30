from launch import LaunchDescription
from launch_ros.actions import Node

remap_number_topic = ("number","my_number_2")

def generate_launch_description():
    ld = LaunchDescription()
    number_publisher_node = Node(
        package="number_counter",
        executable="number_pub",
        name = "my_number_publisher_2",
        
        remappings=[
            remap_number_topic
        ]

        parameters=[
            {"name123":4,}
        ]
    )

    counter_node = Node(
        package="number_counter",
        executable="number_count",
        name = "my_num_counter_2",
        remappings=[
            remap_number_topic,
            ("number_count","my_number_count")
        ]
    )

    ld.add_action(number_publisher_node)
    ld.add_action(counter_node)
    return ld