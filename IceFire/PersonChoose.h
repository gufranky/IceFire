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
#include <QtWidgets>
#include <QtNetwork>

class PersonChoose  : public QWidget
{
	Q_OBJECT
		QMediaPlayer* player;
	QMediaPlaylist* playlist;
public:
	PersonChoose(QTcpSocket* s, QWidget *parent);
	~PersonChoose();
	QLabel* word;
	QTcpSocket* socket;
	QLineEdit* lineEdit;
	QPushButton* button;
	QPushButton* fireButton, * iceButton;
	QLabel* imageLabel;
	void receiveData();
signals:
	// ����һ���źţ���ʾ��ť�����
	void iceClicked();
	void fireClicked();
};
