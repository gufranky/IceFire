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
    explicit start(QWidget* parent = nullptr);
    ~start();
    void onStartButtonClicked();
private:
    QPushButton* startButton;
    QLabel* imageLabel;
signals:
    // ����һ���źţ���ʾ��ť�����
    void buttonClicked();
};

#endif // START_H
