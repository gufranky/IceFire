#pragma once

#include <QObject>
#include<QWidget>
#include <QPushButton>
#include<QDebug>

class LevelChoose  : public QWidget
{
	Q_OBJECT

public:
	LevelChoose(int p,QWidget *parent);
	~LevelChoose();
	void paintEvent(QPaintEvent* event);
	void handleLevelButtonClick(int Level);
	void unlockNextLevel();
	static int currentLevel;//��ǰ�����Ĺؿ�
	static int levelCompleted;//��ǰ��ɵĹؿ�
private:
	QPushButton *LevelButton;
signals:
	void level(int i);
	
};
