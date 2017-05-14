#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QCloseEvent>
#include <object.h>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    //capture frame width and height
    const int WIDTH = 640;
    const int HEIGHT = 480;
    //Variables to hold HSV values. (HSV = HUE, SATURATION and VALUE)
    int H_MIN, H_MAX, S_MIN, S_MAX, V_MIN, V_MAX;


    bool breakLoop=false;

    //names that appear at the top of each window
    const std::string imageWindow = "Original Image";
    const std::string hsvWindow = "HSV Image";
    const std::string thresholdWindow = "Thresholded Image";

    //Matrix to store each frame of the webcam feed
    cv::VideoCapture capture;
    cv::Mat cameraFeed;
    //matrix storage for HSV image
    cv::Mat HSV;
    cv::Mat threshold;

    void closeEvent (QCloseEvent *event);

    void Start();

    ~MainWindow();

private slots:

    void on_resetButton_clicked();

    void on_colorSelect_currentIndexChanged();

private:
    Ui::MainWindow *ui;
    Object *object;
    int changed = false;
};

#endif // MAINWINDOW_H
