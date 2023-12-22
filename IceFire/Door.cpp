#include "Door.h"

Door::Door(int xx, int yy, int ww, int hh, bool fire, IFaccomplish* p11, IFaccomplish* p22) :SpiritBase(xx, yy, NULL)
{
	x = xx;
	y = yy;
	w = ww;
	h = hh;
	this->fire = fire;
	Open = false;
	here = false;
	update();
	this->p1 = p11;
	this->p2 = p22;
	Shadow = new QGraphicsRectItem(x, y, w, h);
}

void Door::interaction()
{
	if (Open)
		if (((this->Shadow->sceneBoundingRect().contains(p1->Shadow->sceneBoundingRect())) && (this->fire == p1->player)) || ((this->Shadow->sceneBoundingRect().contains(p2->Shadow->sceneBoundingRect())) && (this->fire == p2->player)))
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
			
			QPixmap redImage(":/IceFire/re/firedoor.png"); 
			redImage = redImage.scaled(w, h, Qt::KeepAspectRatio);
			painter->drawPixmap(0, 0, redImage);
		}
		else
		{
			QPixmap blueImage(":/IceFire/re/icedoor.png"); 
			blueImage = blueImage.scaled(w, h, Qt::KeepAspectRatio);
			painter->drawPixmap(0, 0, blueImage);
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
void Door::CanOpen()
{
	Open = true;
}
void Door::Reload()
{
	Open = false;
	here = false;
	update();

}
