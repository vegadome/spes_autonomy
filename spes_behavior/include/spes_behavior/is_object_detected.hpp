#include "behaviortree_ros2/bt_topic_sub_node.hpp"
#include "std_msgs/msg/bool.hpp"

using namespace BT;

class IsObjectDetected : public RosTopicSubNode<std_msgs::msg::Bool>
{
public:
  IsObjectDetected(const std::string &name,
                 const NodeConfig &conf,
                 const RosNodeParams &params)
      : RosTopicSubNode<std_msgs::msg::Bool>(name, conf, params)
  {
  }

  static BT::PortsList providedPorts()
  {
    return {};
  }

  NodeStatus onTick(const std::shared_ptr<std_msgs::msg::Bool> &last_msg) override
  {

    if (last_msg == nullptr)
      return NodeStatus::SUCCESS;

    if (last_msg->data == true)
      return NodeStatus::FAILURE;

    return NodeStatus::SUCCESS;
  }
};