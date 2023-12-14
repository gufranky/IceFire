#pragma once

#include <QObject>
#include <QWidget>
#include <QMediaPlayer>
#include <QMediaPlaylist>
#include <QApplication>
#include <QPushButton>
#include <QPalette>
#include <QStackedWidget>
#include <QLabel>

class PersonChoose  : public QWidget
{
	Q_OBJECT
		QMediaPlayer* player;
	QMediaPlaylist* playlist;
public:
	PersonChoose(QWidget *parent);
	~PersonChoose();
	QPushButton* fireButton, * iceButton;
	QLabel* imageLabel;
signals:
	// ����һ���źţ���ʾ��ť�����
	void iceClicked();
	void fireClicked();
};
