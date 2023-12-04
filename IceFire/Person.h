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
	QPixmap pixmap; // �洢ͼ��
	qreal width = 100; // ͼԪ���
	qreal height = 100; // ͼԪ�߶�
	QGraphicsItem* p;
	QString st;
private:
signals:
	void death();
	void enter();
	void exit();
};
