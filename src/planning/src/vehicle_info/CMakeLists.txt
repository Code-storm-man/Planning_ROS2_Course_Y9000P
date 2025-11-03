cmake_minimum_required(VERSION 3.22.1)
project(vehicle_info) # 子级项目名

# 设置依赖
set(DEPENDS
    "rclcpp"
    "geometry_msgs"
    "nav_msgs"
    "base_msgs"
    "tf2"
)

# 添加动态库
add_library(vehicle_info SHARED
    ${CMAKE_CURRENT_SOURCE_DIR}/main_car/main_car_info.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/obs_car/obs_car_info.cpp
)

set(target
    vehicle_info
)

# 添加依赖
ament_target_dependencies(${target} 
    ${DEPENDS}
)

target_link_libraries(${target}
    config_reader
    mathlibs
)

# 安装动态库、节点和相关的目录
install(TARGETS
    ${target}
    LIBRARY DESTINATION lib
)
