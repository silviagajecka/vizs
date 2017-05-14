/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_6;
    QLabel *label;
    QLabel *label_4;
    QLabel *label_5;
    QSpinBox *hminBox;
    QSlider *horizontalSlider_4;
    QSlider *horizontalSlider_3;
    QSpinBox *vmaxBox;
    QSpinBox *hmaxBox;
    QSpinBox *vminBox;
    QSlider *horizontalSlider_2;
    QSlider *horizontalSlider_6;
    QSpinBox *sminBox;
    QSlider *horizontalSlider;
    QSpinBox *smaxBox;
    QSlider *horizontalSlider_5;
    QComboBox *colorSelect;
    QLabel *label_7;
    QComboBox *shapeSelect;
    QLabel *label_9;
    QPushButton *resetButton;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(652, 643);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(30);
        sizePolicy.setVerticalStretch(30);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QStringLiteral("label_2"));

        gridLayout->addWidget(label_2, 11, 1, 1, 1);

        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QStringLiteral("label_3"));

        gridLayout->addWidget(label_3, 5, 1, 1, 1);

        label_6 = new QLabel(centralWidget);
        label_6->setObjectName(QStringLiteral("label_6"));

        gridLayout->addWidget(label_6, 21, 1, 1, 1);

        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));

        gridLayout->addWidget(label, 9, 1, 1, 1);

        label_4 = new QLabel(centralWidget);
        label_4->setObjectName(QStringLiteral("label_4"));

        gridLayout->addWidget(label_4, 7, 1, 1, 1);

        label_5 = new QLabel(centralWidget);
        label_5->setObjectName(QStringLiteral("label_5"));

        gridLayout->addWidget(label_5, 14, 1, 1, 1);

        hminBox = new QSpinBox(centralWidget);
        hminBox->setObjectName(QStringLiteral("hminBox"));
        hminBox->setMaximum(255);

        gridLayout->addWidget(hminBox, 6, 2, 1, 1);

        horizontalSlider_4 = new QSlider(centralWidget);
        horizontalSlider_4->setObjectName(QStringLiteral("horizontalSlider_4"));
        horizontalSlider_4->setMaximum(255);
        horizontalSlider_4->setValue(255);
        horizontalSlider_4->setOrientation(Qt::Horizontal);

        gridLayout->addWidget(horizontalSlider_4, 8, 1, 1, 1);

        horizontalSlider_3 = new QSlider(centralWidget);
        horizontalSlider_3->setObjectName(QStringLiteral("horizontalSlider_3"));
        horizontalSlider_3->setMaximum(255);
        horizontalSlider_3->setValue(255);
        horizontalSlider_3->setOrientation(Qt::Horizontal);

        gridLayout->addWidget(horizontalSlider_3, 22, 1, 1, 1);

        vmaxBox = new QSpinBox(centralWidget);
        vmaxBox->setObjectName(QStringLiteral("vmaxBox"));
        vmaxBox->setMaximum(255);
        vmaxBox->setValue(255);

        gridLayout->addWidget(vmaxBox, 22, 2, 1, 1);

        hmaxBox = new QSpinBox(centralWidget);
        hmaxBox->setObjectName(QStringLiteral("hmaxBox"));
        hmaxBox->setMaximum(255);
        hmaxBox->setValue(255);

        gridLayout->addWidget(hmaxBox, 8, 2, 1, 1);

        vminBox = new QSpinBox(centralWidget);
        vminBox->setObjectName(QStringLiteral("vminBox"));
        vminBox->setMaximum(255);

        gridLayout->addWidget(vminBox, 15, 2, 1, 1);

        horizontalSlider_2 = new QSlider(centralWidget);
        horizontalSlider_2->setObjectName(QStringLiteral("horizontalSlider_2"));
        horizontalSlider_2->setMaximum(255);
        horizontalSlider_2->setOrientation(Qt::Horizontal);

        gridLayout->addWidget(horizontalSlider_2, 6, 1, 1, 1);

        horizontalSlider_6 = new QSlider(centralWidget);
        horizontalSlider_6->setObjectName(QStringLiteral("horizontalSlider_6"));
        horizontalSlider_6->setMaximum(255);
        horizontalSlider_6->setOrientation(Qt::Horizontal);

        gridLayout->addWidget(horizontalSlider_6, 10, 1, 1, 1);

        sminBox = new QSpinBox(centralWidget);
        sminBox->setObjectName(QStringLiteral("sminBox"));
        sminBox->setMaximum(255);

        gridLayout->addWidget(sminBox, 10, 2, 1, 1);

        horizontalSlider = new QSlider(centralWidget);
        horizontalSlider->setObjectName(QStringLiteral("horizontalSlider"));
        horizontalSlider->setMaximum(255);
        horizontalSlider->setOrientation(Qt::Horizontal);

        gridLayout->addWidget(horizontalSlider, 15, 1, 1, 1);

        smaxBox = new QSpinBox(centralWidget);
        smaxBox->setObjectName(QStringLiteral("smaxBox"));
        smaxBox->setMaximum(255);
        smaxBox->setValue(255);

        gridLayout->addWidget(smaxBox, 12, 2, 1, 1);

        horizontalSlider_5 = new QSlider(centralWidget);
        horizontalSlider_5->setObjectName(QStringLiteral("horizontalSlider_5"));
        horizontalSlider_5->setMaximum(255);
        horizontalSlider_5->setValue(255);
        horizontalSlider_5->setOrientation(Qt::Horizontal);

        gridLayout->addWidget(horizontalSlider_5, 12, 1, 1, 1);

        colorSelect = new QComboBox(centralWidget);
        colorSelect->setObjectName(QStringLiteral("colorSelect"));

        gridLayout->addWidget(colorSelect, 2, 1, 1, 1);

        label_7 = new QLabel(centralWidget);
        label_7->setObjectName(QStringLiteral("label_7"));

        gridLayout->addWidget(label_7, 1, 1, 1, 1);

        shapeSelect = new QComboBox(centralWidget);
        shapeSelect->setObjectName(QStringLiteral("shapeSelect"));

        gridLayout->addWidget(shapeSelect, 4, 1, 1, 1);

        label_9 = new QLabel(centralWidget);
        label_9->setObjectName(QStringLiteral("label_9"));

        gridLayout->addWidget(label_9, 3, 1, 1, 1);

        resetButton = new QPushButton(centralWidget);
        resetButton->setObjectName(QStringLiteral("resetButton"));
        resetButton->setMaximumSize(QSize(5000, 16777215));

        gridLayout->addWidget(resetButton, 24, 2, 1, 1);

        MainWindow->setCentralWidget(centralWidget);
        horizontalSlider_6->raise();
        label_6->raise();
        horizontalSlider_3->raise();
        horizontalSlider->raise();
        label->raise();
        horizontalSlider_2->raise();
        label_5->raise();
        label_3->raise();
        hminBox->raise();
        sminBox->raise();
        vmaxBox->raise();
        vminBox->raise();
        label_4->raise();
        horizontalSlider_4->raise();
        hmaxBox->raise();
        label_2->raise();
        horizontalSlider_5->raise();
        smaxBox->raise();
        colorSelect->raise();
        label_7->raise();
        label_9->raise();
        shapeSelect->raise();
        resetButton->raise();
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 652, 26));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);
        QObject::connect(hminBox, SIGNAL(valueChanged(int)), horizontalSlider_2, SLOT(setValue(int)));
        QObject::connect(hmaxBox, SIGNAL(valueChanged(int)), horizontalSlider_4, SLOT(setValue(int)));
        QObject::connect(sminBox, SIGNAL(valueChanged(int)), horizontalSlider_6, SLOT(setValue(int)));
        QObject::connect(smaxBox, SIGNAL(valueChanged(int)), horizontalSlider_5, SLOT(setValue(int)));
        QObject::connect(vminBox, SIGNAL(valueChanged(int)), horizontalSlider, SLOT(setValue(int)));
        QObject::connect(vmaxBox, SIGNAL(valueChanged(int)), horizontalSlider_3, SLOT(setValue(int)));
        QObject::connect(horizontalSlider_2, SIGNAL(valueChanged(int)), hminBox, SLOT(setValue(int)));
        QObject::connect(horizontalSlider_4, SIGNAL(valueChanged(int)), hmaxBox, SLOT(setValue(int)));
        QObject::connect(horizontalSlider_6, SIGNAL(valueChanged(int)), sminBox, SLOT(setValue(int)));
        QObject::connect(horizontalSlider_5, SIGNAL(valueChanged(int)), smaxBox, SLOT(setValue(int)));
        QObject::connect(horizontalSlider, SIGNAL(valueChanged(int)), vminBox, SLOT(setValue(int)));
        QObject::connect(horizontalSlider_3, SIGNAL(valueChanged(int)), vmaxBox, SLOT(setValue(int)));

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", Q_NULLPTR));
        label_2->setText(QApplication::translate("MainWindow", "S_MAX", Q_NULLPTR));
        label_3->setText(QApplication::translate("MainWindow", "H_MIN", Q_NULLPTR));
        label_6->setText(QApplication::translate("MainWindow", "V_MAX", Q_NULLPTR));
        label->setText(QApplication::translate("MainWindow", "S_MIN", Q_NULLPTR));
        label_4->setText(QApplication::translate("MainWindow", "H_MAX", Q_NULLPTR));
        label_5->setText(QApplication::translate("MainWindow", "V_MIN", Q_NULLPTR));
        colorSelect->clear();
        colorSelect->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "Oran\305\276ov\303\241", Q_NULLPTR)
         << QApplication::translate("MainWindow", "\305\275lt\303\241", Q_NULLPTR)
         << QApplication::translate("MainWindow", "Zelen\303\241", Q_NULLPTR)
         << QApplication::translate("MainWindow", "Modr\303\241", Q_NULLPTR)
         << QApplication::translate("MainWindow", "Ru\305\276ov\303\241", Q_NULLPTR)
         << QApplication::translate("MainWindow", "\304\214erven\303\241", Q_NULLPTR)
        );
        label_7->setText(QApplication::translate("MainWindow", "Farba", Q_NULLPTR));
        shapeSelect->clear();
        shapeSelect->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "Kruh", Q_NULLPTR)
         << QApplication::translate("MainWindow", "Trojuholn\303\255k", Q_NULLPTR)
         << QApplication::translate("MainWindow", "\305\240tvoruholn\303\255k", Q_NULLPTR)
         << QApplication::translate("MainWindow", "P\303\244\305\245uholn\303\255k", Q_NULLPTR)
         << QApplication::translate("MainWindow", "\305\240es\305\245uholn\303\255k", Q_NULLPTR)
        );
        label_9->setText(QApplication::translate("MainWindow", "Tvar", Q_NULLPTR));
        resetButton->setText(QApplication::translate("MainWindow", "RESET", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
