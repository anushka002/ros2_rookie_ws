from setuptools import find_packages, setup

package_name = 'my_py_pkg'

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
    maintainer='anushka',
    maintainer_email='anoushkasatav002@gmail.com',
    description='TODO: Package description',
    license='TODO: License declaration',
    tests_require=['pytest'],
    entry_points={
        'console_scripts': [
            "py_node_p = my_py_pkg.my_firrst_node:main",
            "robot_news_station = my_py_pkg.robot_news_station_u:main",
            "mobilephone = my_py_pkg.mobile_u:main",
            "my_add_service = my_py_pkg.my_add_service:main",
            "add_two_ints_client= my_py_pkg.add_two_ints_client:main",
            "number_publisher = my_py_pkg.number_publisher_code:main",
            "number_counter = my_py_pkg.number_counter_code:main",
            "add_two_ints_oop_client = my_py_pkg.add_two_ints_oop:main",
            "hardware_exe = my_py_pkg.hardware_msg_test:main",
            "led_status_server = my_py_pkg.led_status_server:main",
            "battery_client_exe = my_py_pkg.battery_client:main"
        ],
    },
)
