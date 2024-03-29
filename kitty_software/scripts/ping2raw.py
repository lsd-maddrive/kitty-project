#!/usr/bin/env python
import rospy
from sensor_msgs.msg import Image
from std_msgs.msg import Float32, Bool

def image_callback(msg):
    # Получаем текущее время и временную метку
    now = rospy.Time.now()
    header_time = msg.header.stamp.to_sec()

    # Вычисляем задержку
    delay = now.to_sec() - header_time

    # Публикация задержки
    delay_msg = Float32()
    delay_msg.data = delay
    delay_pub.publish(delay_msg)
    # rospy.loginfo("Delay: {:.4f} seconds".format(delay))

    # Публикация в топик "check" если задержка превышает 1 секунду
    if delay > 1.0:
        check_msg = Bool()
        check_msg.data = True
        check_pub.publish(check_msg)
    else:
        check_msg = Bool()
        check_msg.data = False
        check_pub.publish(check_msg)

if __name__ == '__main__':
    try:
        # Инициализация узла
        rospy.init_node('ping2raw')

        # Подписка на топик с изображениями
        rospy.Subscriber("/front_rs_d435i_camera/color/image_raw", Image, image_callback)

        # Публикатор для задержки
        delay_pub = rospy.Publisher('/delay_raw', Float32, queue_size=1)

        # Публикатор для "check"
        check_pub = rospy.Publisher('/big_raw_picture_transport_delay', Bool, queue_size=1)

        # Входим в цикл
        rospy.spin()
    except rospy.ROSInterruptException:
        pass
