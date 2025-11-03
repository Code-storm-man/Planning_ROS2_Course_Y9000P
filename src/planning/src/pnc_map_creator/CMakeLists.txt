cmake_minimum_required(VERSION 3.22.1)
project(pnc_map_creator) # 子级项目名

# 设置依赖
set(DEPENDS
    "rclcpp"
    "geometry_msgs"
    "visualization_msgs"
    "base_msgs"
)

# 注意pnc地图这里我们既要添加动态库
add_library(pnc_map_creator 
    ${CMAKE_CURRENT_SOURCE_DIR}/pnc_map_straight/pnc_map_creator_straight.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/pnc_map_sturn/pnc_map_creator_sturn.cpp
)
# 也要添加节点，与global_planner一样
add_library(pnc_map_server
    ${CMAKE_CURRENT_SOURCE_DIR}/pnc_map_server.cpp
)

set(project_targets
    pnc_map_creator
    pnc_map_server
)

# 添加依赖
foreach(target ${project_targets})
    ament_target_dependencies(${target} 
    ${DEPENDS})    
endforeach()

# 修改第三方依赖
# 先让pnc_map_creator链接上config_reader，然后让pnc_map_server链接上pnc_map_creator
# target_link_libraries(pnc_map_server
#     config_reader
#     pnc_map_creator
# )
target_link_libraries(pnc_map_creator
    config_reader
)
target_link_libraries(pnc_map_server
    pnc_map_creator
)

# 安装动态库、节点和相关的目录
install(TARGETS
    pnc_map_creator
    LIBRARY DESTINATION lib
)

install(TARGETS
    pnc_map_server
    DESTINATION lib/${PLANNING_PACKAGE_NAME}
)
