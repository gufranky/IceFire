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
private:
	QPushButton *LevelButton;
signals:
	void level(int i);
	
};
