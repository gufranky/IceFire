#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
#include <QStackedWidget>
#include "engine.h"
#include "start.h"
#include "mywidget.h"

namespace Ui {
    class Mainwindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
        QStackedWidget* stackedWidget;
    QLayout* currentLayout;

public:
    MainWindow(QWidget* parent = nullptr);
    ~MainWindow();
    void onButtonClicked();
    start *page1;
    engine *page2;

private:
    Ui::Mainwindow* ui;
    MyWidget* myWidget;
};
#endif // MAINWINDOW_H
