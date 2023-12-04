#pragma once

#include <QObject>
#include <QGraphicsScene>
const int MAXSPIRIT = 20;
#include <QGraphicsRectItem>
#include "Person.h"
#include "IFaccomplish.h"
#include "Door.h"
#include "WaterFire.h"
class Spirit :public QObject
{
	Q_OBJECT
public:
	~Spirit();
	void add(int x, int y, int w, int h,int i,int more);
	void show(QGraphicsScene* s);
	void inte();
	void addplayer(IFaccomplish* p1, IFaccomplish* p2);
	void dead();
	std::vector<std::unique_ptr<SpiritBase>> spirits;
private:
	IFaccomplish* p1, * p2;
	int winner=0;
signals:
	void gameover();
	void win();
};
