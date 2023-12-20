
#pragma once

#include <QObject>
#include<QWidget>
#include<qlabel.h>
#include <QPushButton>
#include<QDebug>
#include <QPixmap>
#include <QPainter>
#include <QGraphicsScene>
#include <QGraphicsTextItem>
#include <QFont>
#include <QTimer>
#include <QPropertyAnimation>
#include <QSoundEffect>
#include <QStackedWidget>
#include<QApplication>
class LevelChoose  : public QWidget
{
	Q_OBJECT

public:
	LevelChoose(int p,QWidget* parent);
	~LevelChoose();
	void paintEvent(QPaintEvent* event);
	void handleLevelButtonClick(int Level);
	void unlockNextLevel();
	void onBackButtonClicked();
	static int currentLevel;//��ǰ�����Ĺؿ�
	static int levelCompleted;//��ǰ��ɵĹؿ�
	QPushButton *LevelButton;
	QPushButton* BackButton;
	QLabel* textItem;
	QGraphicsScene* scene;
	QStackedWidget* stackedWidget;
	QTimer timer;
	QPropertyAnimation* fadeAnimation;
	QWidget* p;
	signals:
	void level(int i);
	void p2backClicked();

	
};
