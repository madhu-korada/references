Things to remember always 

--> Always reads as BGR.

--> rows are (x or y)??
cols

while looping through pixels use (rows or cols) first



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

#### Read video and extract frames cpp

Check out the readSpeedExtractFrames.cpp file [here](https://github.com/madhu-korada/references/tree/master/opencv_files)

#### Compile with opencv and c++11:
```$ g++ -std=c++11 name.cpp `pkg-config --libs opencv` ```



CMAKE example:




XML and YAML read and writing:


