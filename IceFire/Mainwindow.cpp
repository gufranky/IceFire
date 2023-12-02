#include "mainwindow.h"
#include "engine.h"
#include "start.h"
#include <QPushButton>
#include <QPixmap>
#include <QPalette>
#include <QStackedWidget>
#include <QVBoxLayout>
#include"mywidget.h"

MainWindow::MainWindow(QWidget* parent)
    : QMainWindow(parent)
{ 
    {
        stackedWidget = new QStackedWidget(this);
        page1 = new start;
        this->setFixedSize(1920, 1080);
        this->setWindowTitle("Myrt1e");
        stackedWidget->addWidget(page1);
        stackedWidget->setCurrentIndex(0);
        this->setCentralWidget(stackedWidget);
        connect(page1, &start::buttonClicked, this, &MainWindow::onButtonClicked);
        setContentsMargins(0, 0, 0, 0); // 设置边距为0

    }
    // 创建按钮
    QPushButton* mainButton = new QPushButton("Main Button", this);

    // 设置按钮的位置
    mainButton->setGeometry(50, 150, 150, 30);

    // 连接按钮的点击信号与槽函数
    connect(mainButton, SIGNAL(clicked()), this, SLOT(onMainButtonClicked()));
}

MainWindow::~MainWindow()
{
    delete  stackedWidget;
    delete page1;
    delete page2;
}

void MainWindow::onButtonClicked()
{
    this->setWindowTitle("Menu");
    page2 = new engine(this);
    stackedWidget->addWidget(page2);
    stackedWidget->setCurrentIndex(1);
    qDebug() << "Main Button Clicked!";
}
