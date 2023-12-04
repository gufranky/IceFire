#include "Door.h"

Door::Door(int xx, int yy, int ww, int hh, bool fire,IFaccomplish* p11, IFaccomplish* p22):SpiritBase(xx,yy,NULL)
{
	x = xx;
	y = yy;
	w = ww;
	h = hh;
	this->fire = fire;
	here = false;
	update();
	this->p1 = p11;
	this->p2 = p22;
	Shadow = new QGraphicsRectItem(x, y, w, h);
}

void Door::interaction()
{
	if (((this->Shadow->collidesWithItem(p1->Shadow)) && (this->fire == p1->player))||((this->Shadow->collidesWithItem(p2->Shadow)) && (this->fire == p2->player)))
	{
		if (!here)
		{
			here = true;
			update();
			emit enter();
		}
	}
	else
	{
		if (here)
		{
			here = false;
			update();
			emit exit();
		}
	}
}

void Door::paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget)
{
	Q_UNUSED(option);
	Q_UNUSED(widget);
	if (here)
	{
		painter->setPen(QPen(Qt::green, 4));
		painter->drawRect(0, 0, w, h);
	}
	else
	{
		if (fire)
		{
			painter->setPen(QPen(Qt::red, 4));
			painter->drawRect(0, 0, w, h);
		}
		else
		{
			painter->setPen(QPen(Qt::blue, 4));
			painter->drawRect(0, 0, w, h);
		}
	}
	setPos(x, y);
}

void Door::Show(QGraphicsScene* s)
{
	s->addItem(this);
}
Door::~Door()
{
	delete Shadow;
}

