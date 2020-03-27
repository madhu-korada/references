### Creating a dummy workspace



### Subscribers and Publishers
```cpp
// ros::
```

```python

```

#### Subscribers and Publishers for images (Sensor Images)

##### Inside a class


### Working with ROS bags

##### View the images from rostopics :- ```$ rqt_image_view```

##### visualize the bag  :- ```$ rqt_bag bagname.bag```

##### Play the bag :- ```$ rosbag play bagname.bag``` 

##### Play the bag in loop :- ```$ rosbag play bagname.bag --loop``` 

##### Record a bag :- ```$ rosbag record -a```



#### Convert Videos to Rosbags :

```python
import time, sys, os
from ros import rosbag
import roslib, rospy
roslib.load_manifest('sensor_msgs')
from sensor_msgs.msg import Image

from cv_bridge import CvBridge
import cv2

TOPIC = 'camera/left/image' # name of the topic

def CreateVideoBag(videopath, bagname):
    '''Creates a bag file with a video file'''
    bag = rosbag.Bag(bagname, 'w')
    cap = cv2.VideoCapture(videopath)
    cb = CvBridge()
    prop_fps = 30#cap.get(cv2.cv.CV_CAP_PROP_FPS)
    if prop_fps != prop_fps or prop_fps <= 1e-2:
        print "Warning: can't get FPS. Assuming 24."
        prop_fps = 24
    ret = True
    frame_id = 0
    while(ret):
        ret, frame = cap.read()
        if not ret:
            break
        stamp = rospy.rostime.Time.from_sec(float(frame_id) / prop_fps)
        frame_id += 1
        image = cb.cv2_to_imgmsg(frame, encoding='bgr8')
        image.header.stamp = stamp
        image.header.frame_id = "camera"
        bag.write(TOPIC, image, stamp)
    cap.release()
    bag.close()

if __name__ == "__main__":
    videopath = 'video_09_09_21.avi'
    bagname = 'video_09_09_21.bag'
    CreateVideoBag(videopath, bagname)
```


#### Convert Rosbags to Videos or Frames:
```python

```
##### video generation from bag to avi directly.

###### In terminal 1 :- ```rosrun image_view video_recorder image:=/camera/left/image _filename:=car_front.avi _fps:='28' _codec:='I420' ```


###### In terminal 2 :- ```rosbag play bagname.bag```


#### Extracts images from the bag file 

###### In terminal 1 :- ```rosrun image_view extract_images _sec_per_frame:=0.41 image:=/camera/left/image```

###### In terminal 2 :- ```rosbag play bagname.bag```



#### Read messages from rosbag and write to a CSV file
```python
import rosbag

bag = rosbag.Bag('/home/madhu/work/avi_read/refinement_test_videos/2019-10-18-11-11-02.bag')
topics = bag.get_type_and_topic_info()[1].keys()
print(topics)

speed_file = open("/home/madhu/work/avi_read/car_back_small.csv", "w")
if speed_file:
	count = 0
	for topic, msg, t1 in bag.read_messages():
		count += 1
		if topic  == '/an_spatial/GPSfix' and count%2 == 0 :
			# speed_file.write( str(msg.data) + "\n" + str(msg.data) + "\n" + str(msg.data) + "\n" + str(msg.data) + "\n" + str(msg.data) + "\n" +str(msg.data) + "\n" + str(msg.data) + "\n" + str(msg.data) + "\n" + str(msg.data) + "\n" + str(msg.data) + "\n")
			speed_file.write(str(msg.speed) + "\n")
			print("count : ", count)
```