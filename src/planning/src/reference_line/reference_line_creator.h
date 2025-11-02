#ifndef REFERENCE_LINE_CREATOR_H_
#define REFERENCE_LINE_CREATOR_H_

#include "rclcpp/rclcpp.hpp"
#include "config_reader.h"
#include "curve.h"  // 这个曲线头文件就是为参考线服务的
#include "reference_line_smoother.h"

namespace Planning
{
    // 这不是一个节点而是一个动态库，不需要写后面的Node部分的代码
    class ReferencelineCreator  // 创建参考线
    {
        public:
            ReferencelineCreator();
        private:
    };
}  // namespace Planning
#endif  // REFERENCE_LINE_CREATOR_H_
