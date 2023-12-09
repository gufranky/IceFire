#include "mainwindow.h"
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
        setContentsMargins(0, 0, 0, 0); // ÉèÖÃ±ß¾àÎª0

    }
}

MainWindow::~MainWindow()
{
    delete  stackedWidget;
    if (page1 != nullptr)
    delete page1;
    if (page2 != nullptr)
        delete page2;
    if (page3 != nullptr)
       delete page3;
}

void MainWindow::onButtonClicked()
{
    this->setWindowTitle("Menu");
    page2 = new LevelChoose(this);
    stackedWidget->addWidget(page2);
    stackedWidget->setCurrentIndex(1);
    connect(page2, &LevelChoose::level, this, &MainWindow::ChooseFinish);
}
void MainWindow::ChooseFinish(int i)
{
    this->setWindowTitle("Game");
    page3 = new engine(this);
    stackedWidget->addWidget(page3);
    stackedWidget->setCurrentIndex(2);
}