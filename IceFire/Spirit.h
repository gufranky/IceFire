#pragma once

#include <QObject>
#include <QGraphicsScene>
#include <QGraphicsRectItem>
#include "Person.h"
#include "IFaccomplish.h"
#include "Door.h"
#include "WaterFire.h"
#include "Diamond.h"
const int MAXSPIRIT = 20;
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
	void reload();
	void DiamondCheck();
	std::vector<std::unique_ptr<SpiritBase>> spirits;
private:
	IFaccomplish* p1, * p2;
	int winner=0;
	int AllDiamond = 0;
	int NowDiamond = 0;

signals:
	void gameover();
	void win();
	void WinCheck();
};
