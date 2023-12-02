#include "Person.h"
#include <qdebug.h>
SpiritBase::SpiritBase(int xx,int yy,QString c, int w, int h, QGraphicsItem* parent, QObject* pt)
	: QGraphicsItem(parent),QObject(pt)
{
    width = w;
    height = h;
    setPos(xx, yy);
    p = parent;
    st = c;
    pixmap.load(c);
}

SpiritBase::~SpiritBase()
{}
void SpiritBase::paint(QPainter *painter, const QStyleOptionGraphicsItem* option, QWidget* widget)  {
    Q_UNUSED(option);
    Q_UNUSED(widget);
    if(st!=NULL)
    // ���������ͼ��
    painter->drawPixmap(0, 0, pixmap);
}
void SpiritBase::setPos(qreal x, qreal y){
    QGraphicsItem::setPos(x, y);

    // �������ִ��������λ�ñ仯ʱ��Ҫ�Ĳ���
}

void SpiritBase::Change(QString c)
{
    prepareGeometryChange();
    st = c;
    pixmap.load(c);
    update();
}

void SpiritBase::interaction()
{
}
