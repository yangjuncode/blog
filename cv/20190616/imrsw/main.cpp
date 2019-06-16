#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/opencv.hpp>

using namespace cv;
using namespace std;

void setColor(cv::Mat &mat, int x, int y, int r, int g, int b) {
    int gray = (r + g + b) / 3;

    switch (mat.channels()) {
        case 1:
            mat.at<uchar>(y, x) = gray;
            break;
        case 3:
            mat.at<Vec3b>(y, x)[0] = b;//blue 通道

            mat.at<Vec3b>(y, x)[1] = g;//green 通道

            mat.at<Vec3b>(y, x)[2] = r;//red 通道
            break;
        default:
            break;
    }
}

void onMouseCallback(int event, int x, int y, int flags, void *userdata) {
    cv::Mat *im = reinterpret_cast<cv::Mat *>(userdata);
    switch (event) { // mouse事件
        case cv::EVENT_LBUTTONDOWN: // 鼠标左键按下事件
            setColor(*im, x, y, 255, 0, 0);
            cout << "click on " << x << ":" << y << ":" << event << endl;

            imshow("img", *im);
            break;
    }
}

int main(int argc, const char *argv[]) {
    Mat img = imread("test.jpg");

    if (argc > 1) {
        img = imread(argv[1]);
        cout << "read img from " << argv[1] << endl;
    }

    cout << "img size row:col:" << img.rows << ":" << img.cols << endl;

    if (img.empty()) {
        cout << "read img err,exit" << endl;
        return -1;
    }
    imshow("img", img);

    setMouseCallback("img", onMouseCallback, &img);



    // 等待用户输入,有输入则退出程序
    if (waitKey(30000) >= 0) {
        imwrite("test.png", img);
        return 0;
    }
    return 0;
}
