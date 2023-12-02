#pragma once

#include <QObject>
#include <QGraphicsPixmapItem>
#include<qstring.h>
#include <QPainter>
class Person  : public QObject,public QGraphicsItem
{
	Q_OBJECT
public:
	Person(int x,int y,QString c,QGraphicsItem*parent=nullptr,QObject* p = nullptr);
	~Person();
	QRectF boundingRect() const override {
		return QRectF(0, 0, width, height);
	}

	// ��д paint ��������ͼԪ�Ļ���
	void paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget = nullptr) override;
	void setPos(qreal x, qreal y) ;
	void Change(QString c);
private:
	QPixmap pixmap; // �洢ͼ��
	qreal width = 100; // ͼԪ���
	qreal height = 100; // ͼԪ�߶�
	QGraphicsItem* p;
	QString st;
};
