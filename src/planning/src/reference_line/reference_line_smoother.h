#ifndef REFERENCE_LINE_SMOOTHER_H_
#define REFERENCE_LINE_SMOOTHER_H_

#include "rclcpp/rclcpp.hpp"
#include "config_reader.h"
#include <Eigen/Dense>              // eigen
#include <OsqpEigen/OsqpEigen.h>    // osqp-eigen
#include <cmath>

namespace Planning
{
    // 这不是一个节点而是一个动态库，不需要写后面的Node部分的代码
    class ReferencelineSmoother  // 参考线平滑
    {
        public:
            ReferencelineSmoother();
        private:
    };
}  // namespace Planning
#endif  // REFERENCE_LINE_SMOOTHER_H_

