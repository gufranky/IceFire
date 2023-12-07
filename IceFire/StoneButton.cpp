#include "StoneButton.h"

void StoneButton::paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget)
{
	if (isPressed)
	{
		QColor color(255, 242, 226);
		painter->setPen(color);
		painter->setBrush(color);
		painter->drawRect(0, 0 + h / 3 * 2, w, h / 3);
	}
	else
	{
		QColor color(250, 249, 222);
		painter->setPen(color);
		painter->setBrush(color);
		painter->drawRect(0, 0 + h / 3, w, h / 3 * 2);
	}
}
StoneButton::StoneButton(int xx, int yy, int ww, int hh, IFaccomplish* p11, IFaccomplish* p22):SpiritBase(xx,yy,NULL)
{
	x = xx;
	y = yy;
	w = ww;
	h = hh;
	isPressed = false;
	update();
	this->p1 = p11;
	this->p2 = p22;
	Shadow = new QGraphicsRectItem(x, y, w, h);
	coldtimer.setInterval(1000);
	cold = true;
	QObject::connect(&coldtimer, &QTimer::timeout, [=]() {
		coldtimer.stop();
		isPressed = false;
		update();
		emit bepress(isPressed);
		});

}
void StoneButton::interaction()
{
	if ((this->Shadow->collidesWithItem(p1->Shadow)) || ((this->Shadow->collidesWithItem(p2->Shadow))))
	{
		if (!isPressed)
		{
			isPressed = true;
			update();
			emit bepress(isPressed);
		}
		coldtimer.stop();
	}
	else
	{
		if (isPressed)
		{
			if (!coldtimer.isActive())
			{
				coldtimer.start();
			}
		}
	}
}
void StoneButton::Show(QGraphicsScene* s)
{
	s->addItem(this);
}
void StoneButton::Reload()
{
	isPressed = false;
	cold = true;
	coldtimer.stop();
	update();
	emit bepress(isPressed);
}
StoneButton::~StoneButton()
{
	delete Shadow;
}