#include <opencv2/opencv.hpp>
#include <iostream>

using namespace std;

int main(void) {   
  // 動画ファイルのパスの文字列を格納するオブジェクトを宣言する
  std::string filepath = "video.h264";
  // 動画ファイルを取り込むためのオブジェクトを宣言する
  cv::VideoCapture video;

  // 動画ファイルを開く
  video.open(filepath);
  if (video.isOpened() == false) {  // 動画ファイルが開けなかったときは終了する
    return 0;
  }

  int    width, height, fourcc;
  double fps;
  width  = (int)video.get(cv::CAP_PROP_FRAME_WIDTH);	// フレーム横幅を取得
  height = (int)video.get(cv::CAP_PROP_FRAME_HEIGHT);	// フレーム縦幅を取得
  fps    = video.get(cv::CAP_PROP_FPS);			// フレームレートを取得

  cout << "width, height, fps = " << width << ", " << height << ", " << fps << endl;

  cv::Mat image ;// 画像を格納するオブジェクトを宣言する
  while (1) {
    video >> image;

    if (image.empty() == true) break;

    // リサイズして描画
    cv::Mat small;
    cv::resize(image, small, cv::Size(), 0.5, 0.5);
    cv::imshow("showing", small); // ウィンドウに動画を表示する

    if (cv::waitKey(0) == 'q') break; //qを押すと終了
  }
  return 0;
}
