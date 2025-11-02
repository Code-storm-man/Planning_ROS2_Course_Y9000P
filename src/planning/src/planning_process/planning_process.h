#ifndef PLANNING_PROCESS_H_
#define PLANNING_PROCESS_H_

#include "rclcpp/rclcpp.hpp"
#include "config_reader.h"
#include "main_car_info.h"
#include "obs_car_info.h"
#include "reference_line_creator.h"
#include "decision_center.h"
#include "local_path_planner.h"
#include "local_speeds_planner.h"
#include "local_trajectory_combiner.h"

#include <vector>
#include <cmath>
#include <algorithm>

// 命名空间
namespace Planning
{
    // 类名称
    class PlanningProcess : public rclcpp::Node // 规划总流程
    {
        public:
        PlanningProcess();
        bool process(); // 总流程函数
        
        private:

    };
}  // namespace Planning
#endif  // PLANNING_PROCESS_H_

