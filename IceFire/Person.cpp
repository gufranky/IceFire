#include "Person.h"

Person::Person(QString c, QGraphicsItem* parent, QObject* pt)
	: QGraphicsItem(parent),QObject(pt)
{
    p = parent;
    st = c;
	pixmap.load(c);
    pixmap = pixmap.scaled(pixmap.size() * 2);

}

Person::~Person()
{}
void Person::paint(QPainter *painter, const QStyleOptionGraphicsItem* option, QWidget* widget)  {
    Q_UNUSED(option);
    Q_UNUSED(widget);

    // 在这里绘制图像
    painter->drawPixmap(0, 0, pixmap);
}
void Person::setPos(qreal x, qreal y){
    QGraphicsItem::setPos(x, y);

    // 这里可以执行其他在位置变化时需要的操作
}
