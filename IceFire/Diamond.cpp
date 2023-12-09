#include "Diamond.h"
Diamond::Diamond(int xx, int yy, int ww, int hh, bool fire, IFaccomplish* p11, IFaccomplish* p22) :SpiritBase(xx, yy, NULL)
{
	x = xx;
	y = yy;
	w = ww;
	h = hh;
	this->fire = fire;
	get = false;
	update();
	this->p1 = p11;
	this->p2 = p22;
	Shadow = new QGraphicsRectItem(x, y, w, h);
}
void Diamond::interaction()
{
	if (((this->Shadow->collidesWithItem(p1->Shadow)) && (this->fire == p1->player)) || ((this->Shadow->collidesWithItem(p2->Shadow)) && (this->fire == p2->player)))
	{
		if (!get)
		{
			get = true;
			update();
			emit HadGet();
		}
	}
}
void Diamond::Show(QGraphicsScene* s)
{
	s->addItem(this);
}
Diamond::~Diamond()
{
	delete Shadow;
}
void Diamond::paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget)
{
	Q_UNUSED(option);
	Q_UNUSED(widget);
	if (!get)
	{
		if (fire)
			painter->setPen(QPen(Qt::red, 4));
		else
			painter->setPen(QPen(Qt::blue, 4));
		qreal size = 40;
		qreal halfSize = size / 2.0;
		painter->drawLine(0, halfSize, halfSize, 0);
		painter->drawLine(halfSize, 0, size, halfSize);
		painter->drawLine(size, halfSize, halfSize, size);
		painter->drawLine(halfSize, size, 0, halfSize);

	}
	setPos(x, y);
}
void Diamond::Reload()
{
	get = false;
	update();
}