#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
#include <QStackedWidget>
#include "engine.h"
#include "start.h"
#include"PersonChoose.h"
#include <QPushButton>
#include <QPixmap>
#include <QPalette>
#include <QStackedWidget>
#include <QVBoxLayout>
#include "LevelChoose.h"
namespace Ui {
    class Mainwindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
        QStackedWidget* stackedWidget;
    QLayout* currentLayout;
public slots:
    void ChooseFinish(int i);
public:
    MainWindow(QWidget* parent = nullptr);
    ~MainWindow();
    void moreClicked();
    void onButtonClicked();
    int player;
    QTcpSocket* socket;
    bool more;
    start *page1=nullptr;
    LevelChoose *page2=nullptr;
    engine* page3=nullptr;
    PersonChoose* page4=nullptr;
    void receiveData()
    {
        QByteArray data = socket->readAll();
        QString c = QString::fromUtf8(data);
        ChooseFinish(c.toInt());
        disconnect(socket, &QTcpSocket::readyRead, this, &MainWindow::receiveData);
    }

private:
    Ui::Mainwindow* ui;
};
#endif // MAINWINDOW_H
