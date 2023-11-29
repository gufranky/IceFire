#pragma once

#include <QObject>
#include <QGraphicsPixmapItem>
#include<qstring.h>
#include <QPainter>
class Person  : public QGraphicsItem
{
public:
	Person(QString c,QGraphicsItem*parent=nullptr);
	~Person();
	QRectF boundingRect() const override {
		return QRectF(0, 0, width, height);
	}

	// 重写 paint 方法进行图元的绘制
	void paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget = nullptr) override;
	void setPos(qreal x, qreal y) ;
private:
	QPixmap pixmap; // 存储图像
	qreal width = 100; // 图元宽度
	qreal height = 100; // 图元高度
};
