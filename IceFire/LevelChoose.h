#pragma once

#include <QObject>
#include<QWidget>
#include <QPushButton>

class LevelChoose  : public QWidget
{
	Q_OBJECT

public:
	LevelChoose(QWidget *parent);
	~LevelChoose();
private:
	QPushButton *LevelButton;
signals:
	void level(int i);
};
