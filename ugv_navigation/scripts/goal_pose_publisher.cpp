#include "rclcpp/rclcpp.hpp"
#include "geometry_msgs/msg/pose_stamped.hpp"

void addPoint(std::vector<geometry_msgs::msg::PoseStamped>& points, double x, double y)
{
  geometry_msgs::msg::PoseStamped point;
  //point.header.stamp.sec = seconds;
  point.header.frame_id = "map";
  point.pose.position.x = x;
  point.pose.position.y = y;
  point.pose.position.z = 0.0;
  point.pose.orientation.w = 1.0;
  points.push_back(point);
}

int main(int argc, char *argv[])
{
  rclcpp::init(argc, argv);
  auto node = rclcpp::Node::make_shared("goal_pose_publisher");
  auto publisher = node->create_publisher<geometry_msgs::msg::PoseStamped>("/goal_pose", 10);

  std::vector<geometry_msgs::msg::PoseStamped> points;

  // Adicione os pontos usando a função addPoint
  float pos_x[5] = {1.0,3.0,6.0,8.0};
  float pos_y[8] = {1.0,4.0,6.0,9.0,12.0,15.0,18.0,21.0};
  bool flag = false;
  for (size_t i = 0; i < 4; i++)
  {
    for (size_t j = 0; j < 8; j++)
    {
      if (flag)
      {
        addPoint(points, pos_x[i],pos_y[7-j]);
        
      }
      else{
        addPoint(points, pos_x[i],pos_y[j]);
      }
    }
    if(i == 0){
        addPoint(points, 0.25, 21.0);
        addPoint(points, 0.25, 22.0);
      }
    flag=!flag;
  }
  addPoint(points, 10.0,9.0);
  addPoint(points, 10.0,12.0);
  addPoint(points, 10.0,15.0);
  addPoint(points, 10.0,18.0);
  addPoint(points, 10.0,21.0);
  int interval = 5;

  auto timer_callback = [&publisher, &points, interval, node]() {
    static int current_point_index = 0;
    RCLCPP_INFO(node->get_logger(), "Enviando posição: [%.2f, %.2f]",
                points[current_point_index].pose.position.x,
                points[current_point_index].pose.position.y);
    publisher->publish(points[current_point_index]);

    current_point_index++;
    if (current_point_index >= static_cast<int>(points.size())) {
      current_point_index = 0;
      RCLCPP_INFO(node->get_logger(), "Navegação concluída!");

      rclcpp::shutdown();
    }
  };

  auto timer = node->create_wall_timer(std::chrono::seconds(interval), timer_callback);
  rclcpp::spin(node);

  return 0;
}

