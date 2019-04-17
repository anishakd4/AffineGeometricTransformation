#include<opencv2/imgproc.hpp>
#include<opencv2/highgui.hpp>
#include<iostream>

using namespace cv;
using namespace std;

int main(){
    Mat image, result1, result2;
    image = imread("../assets/putin.jpg", IMREAD_COLOR);

    line(image, Point2f(450,100), Point2f(750, 650), Scalar(0, 0, 255), 5, 8, 0);
    line(image, Point2f(750,650), Point2f(1000, 300), Scalar(0, 0, 255), 5, 8, 0);
    line(image, Point2f(1000,300), Point2f(450, 100), Scalar(0, 0, 255), 5, 8, 0);

    Mat warpMat1 = (Mat_<double>(2,3) <<1.2, 0.2, 2, -0.3, 1.3, 1);
    Mat warpMat2 = (Mat_<double>(2,3) <<1.2, 0.3, 2, 0.2, 1.3, 1);

    warpAffine(image, result1, warpMat1, Size(1.5*image.cols, 1.4*image.rows), INTER_LINEAR, BORDER_REFLECT_101);
    warpAffine(image, result2, warpMat2, Size(1.5*image.cols, 1.4*image.rows), INTER_LINEAR, BORDER_REFLECT_101);

    namedWindow("image", WINDOW_NORMAL);
    namedWindow("result1", WINDOW_NORMAL);
    namedWindow("result2", WINDOW_NORMAL);

    imshow("image", image);
    imshow("result1", result1);
    imshow("result2", result2);

    waitKey(0);
    destroyAllWindows();
    return 0;
}