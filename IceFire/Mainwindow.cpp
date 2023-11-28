#include "mainwindow.h"
#include "engine.h"
#include "start.h"
#include <QPushButton>
#include <QPixmap>
#include <QPalette>
#include <QStackedWidget>
#include <QVBoxLayout>
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
    }
}

MainWindow::~MainWindow()
{
    delete  stackedWidget;
    delete page1;
    //delete page2;
}

void MainWindow::onButtonClicked()
{
    this->setWindowTitle("Menu");
    page2 = new engine(this);
    stackedWidget->addWidget(page2);
    stackedWidget->setCurrentIndex(1);
}
