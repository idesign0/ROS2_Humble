from setuptools import find_packages, setup

package_name = 'add_two_ints'

setup(
    name=package_name,
    version='0.0.0',
    packages=find_packages(exclude=['test']),
    data_files=[
        ('share/ament_index/resource_index/packages',
            ['resource/' + package_name]),
        ('share/' + package_name, ['package.xml']),
    ],
    install_requires=['setuptools'],
    zip_safe=True,
    maintainer='parallels',
    maintainer_email='parallels@todo.todo',
    description='TODO: Package description',
    license='TODO: License declaration',
    tests_require=['pytest'],
    entry_points={
        'console_scripts': [
            "add_two_ints_server = add_two_ints.add_two_ints_server:main",
            "add_two_ints_client_no_oop = add_two_ints.add_two_ints_client_no_oop:main",
            "add_two_ints_client = add_two_ints.add_two_ints_client:main"
        ],
    },
)
