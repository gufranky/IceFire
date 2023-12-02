#include "Person.h"
#include <qdebug.h>
Person::Person(int xx,int yy,QString c, QGraphicsItem* parent, QObject* pt)
	: QGraphicsItem(parent),QObject(pt)
{
    setPos(xx, yy);
    p = parent;
    st = c;

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

void Person::Change(QString c)
{
    prepareGeometryChange();
    st = c;
    pixmap.load(c);
    update();
}