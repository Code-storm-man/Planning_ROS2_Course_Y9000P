cmake_minimum_required(VERSION 3.29)
project(common) # 子级项目名

# 设置依赖
set(CONFIG_DEPENDS
    "rclcpp"
    "yaml-cpp"
    "ament_index_cpp"
)

# 设置依赖
set(MATH_DPENDS
    "rclcpp"
    "base_msgs"
    "geometry_msgs"
    "nav_msgs"
)

# 添加动态库
# 首先将config_reader.cpp编译成动态库
add_library(config_reader SHARED 
    ${CMAKE_CURRENT_SOURCE_DIR}/config_reader/config_reader.cpp
)
# 将math中cpp编译成动态库 
add_library(mathlibs SHARED  # 更新名称为mathlibs
#   ${CMAKE_CURRENT_SOURCE_DIR}/math/vec2d.cpp  # 向量运算相关的文件，这里用不到
  ${CMAKE_CURRENT_SOURCE_DIR}/math/curve.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/math/polynomial_curve.cpp
)

# 统一代码风格
set(config_target
    config_reader
)
set(math_target
    mathlibs
)
# 让动态库关联上依赖
ament_target_dependencies(
    ${config_target}
    ${CONFIG_DEPENDS}
)
ament_target_dependencies(
    ${math_target}
    ${MATH_DPENDS}
)

target_link_libraries(${config_target}  # ！！！这里是花括号
    yaml-cpp
)
target_link_libraries(${math_target}
    Eigen3::Eigen
)

# 安装动态库、节点和相关的目录
install(TARGETS
    ${config_target}
    ${math_target}
    LIBRARY DESTINATION lib
)

