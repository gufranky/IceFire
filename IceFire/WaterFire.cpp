#include "WaterFire.h"
WaterFire::WaterFire(int xx, int yy, int ww, int hh, bool fire, IFaccomplish* p11, IFaccomplish* p22) :SpiritBase(xx, yy, NULL)
{
	x = xx;
	y = yy;
	w = ww;
	h = hh;
	this->fire = fire;
	this->p1 = p11;
	this->p2 = p22;
	Shadow = new QGraphicsRectItem(x, y, w, h);
}
WaterFire::~WaterFire()
{
}
void WaterFire::interaction()
{
	if (((this->Shadow->collidesWithItem(p1->Shadow)) && (this->fire != p1->player)) || ((this->Shadow->collidesWithItem(p2->Shadow)) && (this->fire != p2->player)))
	{
		emit death();
	}
	update();
}
void WaterFire::paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget)
{
	if(fire)
	Q_UNUSED(option);
	Q_UNUSED(widget);
	if (fire)
	{
		painter->setBrush(Qt::red);
	}
	else
	{
		painter->setBrush(Qt::blue);
	}
	painter->drawRect(0, 0, w, h);
	setPos(x, y);
	QPen pen(Qt::white);
	pen.setWidth(2);
	painter->setPen(pen);
	QPainterPath path;
	for (int y = 10; y <= h; y = y + 20) {
		QPainterPath path;
		path.moveTo(0, y);
		int x;
		for (x = 0; x < w - 2 * wavelength; x += 2 * wavelength) {
			path.quadTo(x + wavelength, y - amplitude, x + 2 * wavelength, y);
		}
		int remainingWidth = w - x;
		path.quadTo(x + remainingWidth / 2, y - amplitude, w, y);
		painter->drawPath(path);
	}
}
