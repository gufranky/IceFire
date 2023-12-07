#pragma once

#include <QObject>
#include <QGraphicsScene>
#include <QGraphicsRectItem>
#include "Person.h"
#include "IFaccomplish.h"
#include "Door.h"
#include "WaterFire.h"
#include "Diamond.h"
#include "Barrier.h"
#include "button.h"
#include "MoveBarrier.h"
#include "StoneButton.h"
class MoveBarrier;
class Barrier;
const int MAXSPIRIT = 20;
class Spirit :public QObject
{
	Q_OBJECT
public slots:
	void handleSignal(bool check)
	{
		Epress = check;
	}
public:
	~Spirit();
	void add(int x, int y, int w, int h,int i,int more);
	void show(QGraphicsScene* s);
	void inte();
	void addplayer(IFaccomplish* p1, IFaccomplish* p2);
	void getm(MoveBarrier* m);
	void dead();
	void reload();
	void DiamondCheck();
	std::vector<std::unique_ptr<SpiritBase>> spirits;
private:
	IFaccomplish* p1, * p2;
	int winner=0;
	int AllDiamond = 0;
	int NowDiamond = 0;
	MoveBarrier* m;
	bool Epress;

signals:
	void gameover();
	void win();
	void WinCheck();
};
