#pragma once
#include"MoveBarrierBase.h"
class MoveBarrierBase;
const int MAXMOVE = 30;
class IFaccomplish;
class MoveBarrier
{
public:
	MoveBarrier();
	~MoveBarrier();
	void add(int xx, int yy, int ww, int hh, int mmovemod, int xx2, int yy2, int ttime, IFaccomplish* p11, IFaccomplish* p22);
	void show(QGraphicsScene* s);
	void onemove();
	void reload();
	int NowBarrier=0;
	MoveBarrierBase *a;
};

