#include "button.h"
button::button(int xx, int yy, int ww, int hh, bool fire, IFaccomplish* p11, IFaccomplish* p22) : SpiritBase(xx, yy, NULL)
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
}
void button::interaction()
{
}
void button::paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget)
{

}
void button::Show(QGraphicsScene* s)
{
	s->addItem(this);
}
button::~button()
{
	delete Shadow;
}