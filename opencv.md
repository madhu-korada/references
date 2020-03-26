Things to remember always 

--> Always reads as BGR.

--> rows are (x or y)??
OpenCV, like may other libraries, treat matrices (and images) in row-major order. That means every access is defined as (row, column). Note that if you're working with x and y coordinates of an image, this becomes (y, x), if y is your vertical axis.

Notable exceptions from this general rule are Matlab and Eigen libraries.


while looping through pixels use (rows or cols) first


#### size of img cpp
rows :- img.rows , cols:- img.cols (returns as int)
size :- img.size() (returns as cv::Size format)

#### python
height, width, channels = img.shape 

PYTHON:

creating a copy image : 

put text : 

draw bounding box :

draw cicle :

draw line : 

gaussian_blur: 

blurred = cv2.GaussianBlur(image, (11, 11), 0)
# kernel size = (11, 11)

flip :

resize :

rotate patricular angle:

rotate (90,-90) :

crop (array slicing) :

bgr to gray :

rgb to luv :

rgb to hsv :

access pixel at (x, y) :

shape : image.shape

waitkey : 

show image in window : cv2.imshow("Image", image)

write video :

read the video : 

write image :

read the image : cv2.imread('image_location')

clone the image : 

### IMSHOW

```cpp
#include <iostream>
#include <opencv2/highgui.hpp>
// #include <opencv2/imgcodecs.hpp>
// #include <opencv2/imgproc.hpp>

int main() {

  cv::Mat image;
  std::string file = "../sample.jpeg";
  image = cv::imread(file , 1);

  if(! image.data ) {
      std::cout <<  "Could not open or find the image" << std::endl ;
      return -1;
    }

  cv::namedWindow( "Display window", cv::WINDOW_AUTOSIZE );
  cv::imshow( "Display window", image );

  cv::waitKey(0);
  return 0;
}
```


--> using svm (ml module of opencv)
	training

	inferencing




CPP:

resize :

rotate :

crop :


create cv::Mat :

write video :

read the video : 

write image :

read the image : 

clone the image : cv::Mat cloned = img.clone();

#### Read video and extract frames cpp

Check out the readSpeedExtractFrames.cpp file [here](https://github.com/madhu-korada/references/tree/master/opencv_files)

#### Compile with opencv and c++11:
```$ g++ -std=c++11 name.cpp `pkg-config --libs opencv` ```



CMAKE example:




XML and YAML read and writing:
source: <https://docs.opencv.org/master/dd/d74/tutorial_file_input_output_with_xml_yml.html>
few things to remember using YAML in opencv
>> Always make sure the first line is ```%YAML:1.0```
>> you can write any numpy based data to yaml using this FileStorage module
>> 


Write data to YAML file
```python
yaml_path = "/home/sample_yaml.yaml"
yaml_file = cv2.FileStorage(yaml_path, cv2.FileStorage_WRITE)
yaml_file.write("Data", data)
    
```
Read data from YAML file
```python
yaml_path = "/home/sample_yaml.yaml"
fs = cv2.FileStorage(yaml_path, cv2.FILE_STORAGE_READ)
K = fs.getNode("Camera matrix")
K = K.mat()
```

Write data to YAML file
```cpp

```

Read data from YAML file
```cpp

```


