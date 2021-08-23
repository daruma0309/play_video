#include <opencv2/opencv.hpp>
#include <iostream>

using namespace std;

int main(int argc, char **argv) {
  int camera;
  if (argc != 2) {
    cout << "[usage] ./play_video [camera_number]" << endl;
    return 0;
  } else {
     camera = atoi(argv[1]);
  }
  // 動画ファイルを取り込むためのオブジェクトを宣言する
  cv::VideoCapture cap;

  // カメラを開く
  cap.open(camera);
  if (cap.isOpened() == false) {  // 動画ファイルが開けなかったときは終了する
    return 0;
  }

  cv::Mat frame ;
  while(cap.read(frame)) {
    // リサイズして描画
    cv::Mat small;
    cv::resize(frame, small, cv::Size(), 0.8, 0.8);
    cv::imshow("showing", small); // ウィンドウに動画を表示する

    if (cv::waitKey(1) == 'q') break; //qを押すと終了
  }
  
  cv::destroyAllWindows();
  return 0;
}

