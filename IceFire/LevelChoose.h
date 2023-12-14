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
class LevelChoose  : public QWidget
{
	Q_OBJECT

public:
	LevelChoose(QWidget *parent);
	~LevelChoose();
	void paintEvent(QPaintEvent* event);
	void handleLevelButtonClick(int Level);
	void unlockNextLevel();
	static int currentLevel;//��ǰ�����Ĺؿ�
	static int levelCompleted;//��ǰ��ɵĹؿ�
private:
	QPushButton *LevelButton;
	QLabel* textItem;
	QGraphicsScene* scene;
	QTimer timer;
	QPropertyAnimation* fadeAnimation;
	QWidget* p;
signals:
	void level(int i);
};
