#ifndef CURVE_H_
#define CURVE_H_

#include "rclcpp/rclcpp.hpp"
#include <cmath>  // c++的数学库


namespace Planning
{
    // 不需要继承ROS2的节点
    class Curve // 曲线
    {
    public:
        Curve() = default;
    };
}  // namespace Planning
#endif  // CURVE_H_
