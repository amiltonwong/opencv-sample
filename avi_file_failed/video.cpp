#include <opencv2/opencv.hpp>
#include <iostream>

int main (int argc, char* argv[]) {
  cv::namedWindow("example", cv::WINDOW_AUTOSIZE);
  cv::namedWindow("Log_Polar", cv::WINDOW_AUTOSIZE);
  cv::VideoCapture capture;
  double fps = capture.get( CV_CAP_PROP_FPS);
  cv::Size size(
    (int) capture.get(CV_CAP_PROP_FRAME_WIDTH),
    (int) capture.get(CV_CAP_PROP_FRAME_HEIGHT)
    );
  cv::VideoWriter writer;
  writer.open( argv[2], CV_FOURCC('M', 'J', 'P', 'G'), fps, size);
  cv::Mat logpolar_frame(size,cv::U8C3), bgr_frame;
  for(;;) {
    capture >> bgr_frame;
    if(bgr_frame.empty()) break;

    cv::imshow("example", bgr_frame);
    cv::LogPolar(
      bgr_frame,
      logpolar_frame,
      cv::Point2f(
        bgr_frame.cols/2,
        bgr_frame.rows/2
      ),
      40,
      CV_WARP_FILL_OUTLIERS
    );
    cv::imshow("Log_Polar", logpolar_frame);
    writer << logpolar_frame;
    char c = cv::waitKey(10);
    if(c == 27) break;

  }
  capture.release();
}
