#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
#include <QStackedWidget>
#include "engine.h"
#include "start.h"
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
};
#endif // MAINWINDOW_H
