#include <opencv2/opencv.hpp>

int main (int argc, char** argv) {
  cv::Mat img_rgb = cv::imread(argv[1]);
  cv::Mat img_gry, img_cny;
  cv::cvtColor (img_rgb, img_gry, CV_BGR2GRAY);
  cv::namedWindow("Gray", cv::WINDOW_AUTOSIZE);
  cv::namedWindow("Canny", cv::WINDOW_AUTOSIZE);
  cv::imshow("Gray", img_gry);
  cv::Canny(img_gry, img_cny, 10, 100, 3, true);
  cv::imshow("Canny", img_cny);
  cv::waitKey(0);
}
