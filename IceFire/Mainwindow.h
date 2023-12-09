#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
#include <QStackedWidget>
#include "engine.h"
#include "start.h"

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
    void onButtonClicked();
    start *page1=nullptr;
    LevelChoose *page2=nullptr;
    engine* page3=nullptr;
private:
    Ui::Mainwindow* ui;
};
#endif // MAINWINDOW_H
