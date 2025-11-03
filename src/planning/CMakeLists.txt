cmake_minimum_required(VERSION 3.22)
project(planning)

# 设置C/C++标准
if(NOT CMAKE_C_STANDARD)
  set(CMAKE_C_STANDARD 99)
endif()
if(NOT CMAKE_CXX_STANDARD)
  set(CMAKE_CXX_STANDARD 17)
endif()

# 原本的CMAKE_COMPTLER_IS_CNUCXX在新版cmake中已经被启用，改用CMAKE_CXX_COMPILER_ID
if(CMAKE_CXX_COMPILER_ID MATCHES "GNU" OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# 设置预编译指令，生成compile_commands.json  
# 然后让c_cpp_properties.json读取这个文件，防止预编译找不到cmake中定义的宏而报错
# c_cpp_properties.json中添加"compileCommands": "${workspaceFolder}/build/compile_commands.json"
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# 设置包名，让子目录节点安装时使用
# !!! 第一个坑，设置包名不写就会出现编译正确，但运行结果不对的情况：
# 输出为 hello world planning package 而不输出正确的数据帧
set(PLANNING_PACKAGE_NAME ${PROJECT_NAME})

# 包含头文件目录
include_directories(
  /usr/local/include/eigen-3.4.0   # 这里表示要从根目录下找头文件
  src/common/config_reader         # 这里src前面不用加斜杠，表示当前目录下的，即从planning开始
  src/common/math
  src/decision_center
  src/pnc_map_creator
  src/pnc_map_creator/pnc_map_straight
  src/pnc_map_creator/pnc_map_sturn
  src/global_planner
  src/global_planner/global_planner_normal
  src/local_planner
  src/local_planner/local_path
  src/local_planner/local_speeds
  src/reference_line
  src/vehicle_info
  src/vehicle_info/main_car
  src/vehicle_info/obs_car
  src/planning_process
  src/move_cmd
)

# find dependencies 查找依赖
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(tf2 REQUIRED)                # 坐标变换相关的依赖
find_package(tf2_ros REQUIRED)            # 坐标变换相关的依赖
find_package(geometry_msgs REQUIRED)      # ros2自带的消息类型
find_package(nav_msgs REQUIRED)           # ros2自带的消息类型
find_package(visualization_msgs REQUIRED) # ros2自带的消息类型
find_package(base_msgs REQUIRED)          # 自定义消息类型
find_package(yaml-cpp REQUIRED)           # 三方库的消息格式  
find_package(ament_index_cpp REQUIRED)    # 三方库的消息格式  
find_package(Eigen3 REQUIRED)             # 三方库的消息格式
find_package(OsqpEigen REQUIRED)          # 三方库的消息格式  

# 添加子目录 连接到每个子目录里面的cmake_list
add_subdirectory(src/common)
add_subdirectory(src/decision_center)
add_subdirectory(src/pnc_map_creator)
add_subdirectory(src/global_planner)
add_subdirectory(src/local_planner)
add_subdirectory(src/reference_line)
add_subdirectory(src/vehicle_info)
add_subdirectory(src/planning_process)
add_subdirectory(src/move_cmd)

# 安装辅助目录
install(DIRECTORY 
  config launch urdf rviz
  DESTINATION lib/${PROJECT_NAME})

# # 测试用，可以删掉
# if(BUILD_TESTING)
#   find_package(ament_lint_auto REQUIRED)
#   # the following line skips the linter which checks for copyrights
#   # comment the line when a copyright and license is added to all source files
#   set(ament_cmake_copyright_FOUND TRUE)
#   # the following line skips cpplint (only works in a git repo)
#   # comment the line when this package is in a git repo and when
#   # a copyright and license is added to all source files
#   set(ament_cmake_cpplint_FOUND TRUE)
#   ament_lint_auto_find_test_dependencies()
# endif()

ament_package()

# 安全安装可选目录
install(
  DIRECTORY launch/ config/ urdf/ rviz/
  DESTINATION share/${PROJECT_NAME}/
  OPTIONAL
)
