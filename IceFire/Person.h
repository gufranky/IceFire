#pragma once

#include <QObject>
#include <QGraphicsPixmapItem>
#include<qstring.h>
#include <QPainter>
class SpiritBase  : public QObject,public QGraphicsItem
{
	Q_OBJECT
public:
	SpiritBase(int x,int y,QString c, int w = 100, int h = 100,QGraphicsItem*parent=nullptr,QObject* p = nullptr);

	~SpiritBase();
	QRectF boundingRect() const override {
		return QRectF(0, 0, 1920, 1080);
	}
	void paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget = nullptr) override;
	void setPos(qreal x, qreal y) ;
	void Change(QString c);
	virtual void Show(QGraphicsScene* s)=0;
	virtual void interaction();
	QPixmap pixmap; // 存储图像
	qreal width = 100; // 图元宽度
	qreal height = 100; // 图元高度
	QGraphicsItem* p;
	QString st;
private:
signals:
	void death();
	void enter();
	void exit();
};
