#ifndef GLOBAL_PLANNER_NORMAL_H_
#define GLOBAL_PLANNER_NORMAL_H_

#include "global_planner_base.h"  // 注意这里不是包含ROS2的节点而是全局规划器基类

namespace Planning
{
    class GlobalPlannerNormal : public GlobalPlannerBase  // 不是继承ROS2节点而是继承基类
    {
        public:
            GlobalPlannerNormal();
    };
}  // namespace Planning
#endif  // GLOBAL_PLANNER_NORMAL_H_
