#include "mainwindow.h"
#include "ui_mainwindow.h"

using namespace cv;
using namespace std;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //open capture object at location zero (default location for webcam)
    capture.open(0);
    //set height and width of capture frame
    capture.set(CV_CAP_PROP_FRAME_WIDTH, WIDTH);
    capture.set(CV_CAP_PROP_FRAME_HEIGHT, HEIGHT);

    namedWindow(imageWindow);
    namedWindow(hsvWindow);
    namedWindow(thresholdWindow);

    //To avoid windows stacking over each other,
    //these adjustmets could differ with screen sizes.
    moveWindow(imageWindow,100,0);
    moveWindow(hsvWindow, 1000,0);
    moveWindow(thresholdWindow, 1000,500);

}

void MainWindow::closeEvent(QCloseEvent *event)
{
    breakLoop=true;
    destroyAllWindows();
    capture.~VideoCapture();
    this->destroy();
    event->accept();
}

MainWindow::~MainWindow()
{

    delete ui;
}


void MainWindow::Start(){
    // changed potrebny na to, aby sa switch vykonal vzdy iba raz pri zmene comboboxu
    changed = true;

    object = new Object();

    while (true){

        if(breakLoop==true){
            return;
        }

        H_MIN = ui->hminBox->text().toInt();
        H_MAX = ui->hmaxBox->text().toInt();
        S_MIN = ui->sminBox->text().toInt();
        S_MAX = ui->smaxBox->text().toInt();
        V_MIN = ui->vminBox->text().toInt();
        V_MAX = ui->vmaxBox->text().toInt();

        if(changed){
            switch (ui->colorSelect->currentIndex()) {
                case 0 :
                    ui->hminBox->setValue(0);
                    ui->hmaxBox->setValue(22);
                    changed = false;
                    break;
                case 1 :
                    ui->hminBox->setValue(22);
                    ui->hmaxBox->setValue(38);
                    changed = false;
                    break;
                case 2 :
                    ui->hminBox->setValue(38);
                    ui->hmaxBox->setValue(75);
                    changed = false;
                    break;
                case 3 :
                    ui->hminBox->setValue(75);
                    ui->hmaxBox->setValue(130);
                    changed = false;
                    break;
                case 4 :
                    ui->hminBox->setValue(130);
                    ui->hmaxBox->setValue(160);
                    changed = false;
                    break;
                case 5 :
                    ui->hminBox->setValue(160);
                    ui->hmaxBox->setValue(179);
                    changed = false;
                    break;
            }
        }

        //priradenie ID vybraneho tvaru do shapeID
        int shapeID = ui->shapeSelect->currentIndex();

        capture.read(cameraFeed);
        cvtColor(cameraFeed,HSV, COLOR_BGR2HSV);
        inRange(HSV, Scalar(H_MIN, S_MIN, V_MIN), Scalar(H_MAX, S_MAX, V_MAX), threshold);
        //vyhladenie obrazu; vystup z trackObjectu sa zapíse do cameraFeed
        object->morphObject(threshold);
        //trackovanie objektu
        object->trackObject(threshold, cameraFeed, shapeID);

        imshow(imageWindow, cameraFeed);
        imshow(hsvWindow, HSV);
        imshow(thresholdWindow,threshold);


        //delay 30ms so that screen can refresh.
        waitKey(30);
    }
}

void MainWindow::on_resetButton_clicked()
{
    ui->hminBox->setValue(0);
    ui->hmaxBox->setValue(22);
    ui->sminBox->setValue(0);
    ui->smaxBox->setValue(255);
    ui->vminBox->setValue(0);
    ui->vmaxBox->setValue(255);
    ui->colorSelect->setCurrentIndex(0);
    ui->shapeSelect->setCurrentIndex(0);
}

void MainWindow::on_colorSelect_currentIndexChanged()
{
    changed = true;
}
