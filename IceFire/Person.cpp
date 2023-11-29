#include "Person.h"

Person::Person(QString c, QGraphicsItem* parent)
	: QGraphicsItem(parent)
{
	pixmap.load(c);

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
