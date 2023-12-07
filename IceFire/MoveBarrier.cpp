#include "MoveBarrier.h"
MoveBarrier::MoveBarrier()
{
	NowBarrier = 0;
	a = new MoveBarrierBase[MAXBARRIER];
}
MoveBarrier::~MoveBarrier()
{
	delete[] a;
}
void MoveBarrier::add(int xx, int yy, int ww, int hh, int mmovemod, int xx2, int yy2, int ttime, IFaccomplish* p11, IFaccomplish* p22)
{
	a[NowBarrier].set(xx, yy, ww, hh, mmovemod, xx2, yy2, ttime, p11, p22);
	NowBarrier++;
}
void MoveBarrier::show(QGraphicsScene* s)
{
	for (int i = 0; i < NowBarrier; i++)
	{
		s->addItem(&a[i]);
	}
}
void MoveBarrier::onemove()
{
	for (int i = 0; i < NowBarrier; i++)
	{
		a[i].onemove();
	}
}
void MoveBarrier::reload()
{
	for (int i = 0; i < NowBarrier; i++)
	{
		a[i].Reload();
	}
}