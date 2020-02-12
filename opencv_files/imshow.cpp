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
