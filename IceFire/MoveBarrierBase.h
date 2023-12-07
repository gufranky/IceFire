#pragma once
#include <QObject>
#include <QGraphicsPixmapItem>
#include<qstring.h>
#include <QPainter>
#include"IFaccomplish.h"
class IFaccomplish;
class MoveBarrierBase	:	public QObject, public QGraphicsItem
{
	Q_OBJECT
public slots:
	void getit(bool x);
public:
	MoveBarrierBase(int x, int y, int w, int h, int movemod, int x2, int y2,int time, IFaccomplish* p1, IFaccomplish*p2, QGraphicsItem* parent = nullptr, QObject* p = nullptr);
	MoveBarrierBase() :MoveBarrierBase(0, 0, 0, 0, 3, 0, 0, 100, nullptr, nullptr) {};
	~MoveBarrierBase();
	bool cansee;
	void set(int xx, int yy, int ww, int hh, int mmovemod, int xx2, int yy2, int ttime, IFaccomplish* p11, IFaccomplish* p22);
	QRectF boundingRect() const override 
	{
		return QRectF(0, 0, 1920, 1080);
	}
void paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget = nullptr) override;
void onemove();
void check(int x,int y);
void Reload();
QGraphicsRectItem* Shadow;
private:
	IFaccomplish* p1, * p2;

	double x, y, w, h, x2, y2, nowx, nowy,time,nowtime;
	int turnmark;
	int movemod;
	int nowturn;//0Í£Ö¹ 1Ïòx2£¬y2

};

