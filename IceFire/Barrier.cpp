#include "Barrier.h"

void Barrier::add(int x, int y, int w, int h)
{
	a[NowBarrier].setRect(x, y, w, h);
	NowBarrier++;
}

void Barrier::show(QGraphicsScene* s)
{
	for (int i = 0; i < NowBarrier; i++)
	{
		s->addItem(&a[i]);
	}
}

Barrier::Barrier()
{
	NowBarrier = 0;
	a = new QGraphicsRectItem[MAXBARRIER];
}

Barrier::~Barrier()
{
	delete[] a;
}
