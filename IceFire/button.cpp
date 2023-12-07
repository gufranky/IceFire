#include "button.h"
button::button(int xx, int yy, int ww, int hh, IFaccomplish* p11, IFaccomplish* p22) : SpiritBase(xx, yy, NULL)
{
	x = xx;
	y = yy;
	w = ww;
	h = hh;;
	isPressed = false;
	update();
	this->p1 = p11;
	this->p2 = p22;
	Shadow = new QGraphicsRectItem(x, y, w, h);
	cold = true;
}
void button::interaction()
{
	if(p1->Epress==true)
		if (cold)
		if ((this->Shadow->collidesWithItem(p1->Shadow)) || ((this->Shadow->collidesWithItem(p2->Shadow))))
		{
			isPressed = !isPressed;
			update();
			cold = false;
			coldtimer.setInterval(1000);
			coldtimer.start();
			emit bepress(isPressed);
			QObject::connect(&coldtimer, &QTimer::timeout, [=]() {
				coldtimer.stop();
				cold = true;
				});
		}

}
void button::paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget)
{
	if (isPressed)
	{
		painter->setPen(Qt::green);
		painter->setBrush(Qt::green);
		painter->drawRect(x, y + h / 3 * 2, w, h / 3);
	}
	else
	{
		painter->setPen(Qt::red);
		painter->setBrush(Qt::red);
		painter->drawRect(x, y + h / 3, w, h / 3 * 2);
	}


}
void button::Show(QGraphicsScene* s)
{
	s->addItem(this);
}
void button::Reload()
{
	isPressed = false;
	update();
	emit bepress(isPressed);

}
button::~button()
{
	delete Shadow;
}