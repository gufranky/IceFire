#pragma once

#include <QObject>
#include<QWidget>
#include <QPushButton>
#include<QDebug>

class LevelChoose  : public QWidget
{
	Q_OBJECT

public:
	LevelChoose(QWidget *parent);
	~LevelChoose();
	void paintEvent(QPaintEvent* event);
	void handleLevelButtonClick(int Level);
	void unlockNextLevel();
	void handleTimeout();
	static int currentLevel;//当前解锁的关卡
	static int levelCompleted;//当前完成的关卡
private:
	QPushButton *LevelButton;
signals:
	void level(int i);
	
};
