#include <opencv2/opencv.hpp>


void smooth( cv::Mat & image) {
  // Create some windows to show the input

  cv::namedWindow("example-in", cv::WINDOW_AUTOSIZE);
  cv::namedWindow("example-out", cv::WINDOW_AUTOSIZE);

  // Create a window to show out input image

  cv::imshow("example-in", image);

  // Create an image to hold the smoothed output
  cv::Mat out;

  // soothing
  cv::GaussianBlur( image, out, cv::Size(5, 5), 3, 3);
  cv::GaussianBlur( out, out, cv::Size(5, 5), 3, 3);

  // show output window
  cv::imshow("example-out", out);

  cv::waitKey(0);
}    

int main (int argc, char** argv) {
  cv::Mat img = cv::imread( argv[1], -1);
  smooth(img);
  if( img.empty()) 
    return -1;

}
