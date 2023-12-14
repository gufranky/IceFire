#ifndef START_H
#define START_H

#include <QObject>
#include <QWidget>
#include <QMediaPlayer>
#include <QMediaPlaylist>
#include <QApplication>
#include <QPushButton>
#include <QPalette>
#include <QStackedWidget>
#include <QLabel>
//#include "engine.h"
class start : public QWidget
{
    Q_OBJECT
        QMediaPlayer* player;
    QMediaPlaylist* playlist;

public:
    start(QWidget* parent = nullptr);
    ~start();
private:
    QPushButton* startButton,*moreButton;
    QLabel* imageLabel;
signals:
    // 定义一个信号，表示按钮被点击
    void buttonClicked();
    void moreClicked();
};

#endif // START_H
