#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/opencv.hpp>

using namespace cv;
using namespace std;

// 视频来源于摄像头
VideoCapture capture(0);
Mat edges;

int main(int argc, const char *argv[]) {
    Mat frame;
    while (true) {

        // 每一帧
        capture >> frame;
        imshow("capture", frame);

        // 转为灰度图
        cvtColor(frame, edges, COLOR_BGR2GRAY);
        imshow("gray", edges);

        blur(edges, edges, Size(5, 5));
        imshow("blur", edges);

        // 边缘检测并显示边缘
        Canny(edges, edges, 0, 30, 3);
        imshow("Read Video", edges);

        // 等待用户输入,有输入则退出程序
        if (waitKey(100) >= 0) {
            break;
        }
    }
    return 0;
}
