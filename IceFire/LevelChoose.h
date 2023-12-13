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
	void handleLevelButtonClick(int i);
	void unlockNextLevel();
	static int currentLevel;//��ǰ�����Ĺؿ�
	static int  levelCompleted;//��ǰ��ɵĹؿ�
private:
	QPushButton *LevelButton;
signals:
	void level(int i);
	
};
