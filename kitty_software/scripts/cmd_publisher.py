#!/usr/bin/env python3
from logging import shutdown
import rospy
from std_msgs.msg import Float32MultiArray

rospy.init_node('cmd_publisher')
pub = rospy.Publisher('set_speed', Float32MultiArray, queue_size=10)
rate = rospy.Rate(1)
my_msg = Float32MultiArray()
while not rospy.is_shutdown():  
    my_msg.data = [0.0,0.0]
    pub.publish(my_msg)
    rate.sleep()


# rospy.init_node('talker')
# pub = rospy.Publisher('my_chat_topic', String, queue_size=10)
# rate = rospy.Rate(1)

# def start_talker():
#     msg = String()
#     while not rospy.is_shutdown():
#         hello_str = "hi =) %s" % rospy.get_time()
#         rospy.loginfo(hello_str)

#         msg.data = hello_str
#         pub.publish(msg)

#         rate.sleep()

# try:
#     start_talker()
# except (rospy.ROSInterruptException, KeyboardInterrupt):
#     rospy.logerr('Exception catched')