#include "MoveBarrierBase.h"
#include<qdebug.h>
MoveBarrierBase::MoveBarrierBase(int xx, int yy, int ww, int hh, int mmovemod, int xx2, int yy2,int ttime,IFaccomplish* p11, IFaccomplish* p22,QGraphicsItem* parent, QObject* p):QGraphicsItem(parent), QObject(p)
{
	Shadow = nullptr;
}

MoveBarrierBase::~MoveBarrierBase()
{
	if(Shadow!=nullptr)
		delete Shadow;
}

void MoveBarrierBase::set(int xx, int yy, int ww, int hh, int mmovemod, int xx2, int yy2, int ttime, IFaccomplish* p11, IFaccomplish* p22)
{
	x = xx; nowx = x;
	y = yy; nowy = y;
	w = ww;
	h = hh;
	movemod = mmovemod;
	x2 = xx2;
	y2 = yy2;
	time = ttime;
	turnmark = 1;
	p1 = p11;
	p2 = p22;
	cansee = true;
	if (movemod == 1)
	{
		nowturn = 1;
	}
	else
		nowturn = 0;
	if (movemod == 3)
	{
		cansee = false;
	}
	Shadow = new QGraphicsRectItem(0, 0, w, h);
	Shadow->setPos(nowx, nowy);
	nowtime = 0;
}

void MoveBarrierBase::paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget)
{
	if (cansee)
	{
		painter->setPen(QColor(255, 182, 193));
		painter->drawRect(nowx, nowy, w, h);
	}
	
}
void MoveBarrierBase::onemove()
{
	double movex = (x2 - x) / time;
	double movey = (y2 - y) / time;
	if(nowturn!=0)
	{ 
		if (nowturn == 2)
		{
			movex = -movex;
			movey = -movey;
		
		}
		nowtime += 1;
		if (nowtime==time)
		{
			nowturn = (nowturn == 1) ? 2 : 1;
			nowtime = 0;
		}
		check(movex,movey);
	}
	


}
void MoveBarrierBase::check(int mx, int my)
{
	if (cansee)
	{
		Shadow->setPos(nowx + mx, nowy + my - 2);
		if (this->Shadow->collidesWithItem(p1->Shadow))
		{
			p1->SetPos(p1->x + mx, p1->y + my);
		}
		if (this->Shadow->collidesWithItem(p2->Shadow))
		{
			p2->SetPos(p2->x + mx, p2->y + my);
		}
		Shadow->setPos(nowx + mx, nowy + my);
		if (this->Shadow->collidesWithItem(p1->Shadow))
		{
			p1->SetPos(p1->x + mx, p1->y + my);
		}
		if (this->Shadow->collidesWithItem(p2->Shadow))
		{
			p2->SetPos(p2->x + mx, p2->y + my);
		}
		Shadow->setPos(nowx + mx, nowy + my);
		nowx = nowx + mx; nowy = nowy + my;
		update();
	}
}
void MoveBarrierBase::Reload()
{
	nowtime = 0;
	turnmark = 1;
	nowx = x;
	nowy = y;
	Shadow->setPos(nowx, nowy);
	if (movemod == 1)
	{
		nowturn = 1;
	}
	else
		nowturn = 0;
	cansee = true;
	if (movemod == 3)
	{
		cansee = false;
	}
}
void MoveBarrierBase::getit(bool x)
{
	if (x == true)
	{
		if (movemod == 2)
		{
			nowturn = turnmark;
		}
		if (movemod == 3)
		{
			cansee = true;
		}
		if (movemod == 4)
		{
			cansee = false;
		}

	}
	if (x == false)
	{
			if (movemod == 2)
			{
				turnmark = nowturn;
				nowturn = 0;
			}
			if (movemod == 3)
			{
				cansee = true;
			}
			if (movemod == 4)
			{
				cansee = false;
			}
	}
}
