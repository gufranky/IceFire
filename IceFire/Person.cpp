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

    // ���������ͼ��
    painter->drawPixmap(0, 0, pixmap);
}
void Person::setPos(qreal x, qreal y){
    QGraphicsItem::setPos(x, y);

    // �������ִ��������λ�ñ仯ʱ��Ҫ�Ĳ���
}

void Person::Change(QString c)
{
    prepareGeometryChange();
    st = c;
    pixmap.load(c);
    update();
}