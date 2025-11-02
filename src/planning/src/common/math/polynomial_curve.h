#ifndef POLYNOMIAL_CURVE_H_
#define POLYNOMIAL_CURVE_H_

#include "rclcpp/rclcpp.hpp"
#include <cmath>
#include <Eigen/Dense> // 多项式的运算会用到矩阵的运算，包含在Eigen库里面

namespace Planning
{
    class PolynomialCurve
    {
    public:
        PolynomialCurve() = default;
    };
}  // namespace Planning
#endif  // POLYNOMIAL_CURVE_H_
