#include "planning_process.h"

int main(int argc, char * argv[])
{
  rclcpp::init(argc, argv);
  // RCLCPP_INFO
  // RCLCPP_INFO(this->get_logger(), "Planning node started")
  // 函数中this只有在这个函数在“类”里面作为成员函数来调用的时候才有this
  // 现在改为通过作用域来直接调用get_logger函数
  RCLCPP_INFO(rclcpp::get_logger("planning_node"), "Planning start");
  
  auto node = std::make_shared<Planning::PlanningProcess>();
  if(!node->process())
  {
    RCLCPP_ERROR(rclcpp::get_logger("planning_node"), "Planning failed");
    rclcpp::shutdown();  // 让整个程序停掉
    return 1;
  }


  // printf("hello world planning!\n");
  
  rclcpp::spin(node);
  rclcpp::shutdown();
  return 0;


}