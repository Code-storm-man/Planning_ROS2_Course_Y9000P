#ifndef LOCAL_SPEEDS_PLANNER_H_
#define LOCAL_SPEEDS_PLANNER_H_

#include "rclcpp/rclcpp.hpp"
#include "config_reader.h"
#include "polynomial_curve.h"
#include "decision_center.h"  // 决策中心里面也有速度决策中心
#include "local_speeds_smoother.h"

namespace Planning
{
    class LocalSpeedsPlanner  // 局部速度规划器
    {
        public:
            LocalSpeedsPlanner();
    };
}  // namespace Planning
#endif  // LOCAL_SPEEDS_PLANNER_H_