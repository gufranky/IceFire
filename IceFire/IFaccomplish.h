#pragma once
#include"Person.h"
#include <QObject>
#include <QTimer>
#include"Barrier.h"
const int MAXSPEED = 7;
const int A = 1.2;
const QString FIRE=":/IceFire/fire.png";
const QString ICE=":/IceFire/ice.png";
class IFaccomplish:public SpiritBase
{
	Q_OBJECT
public slots:
	void handleSignalA(int value)
	{
		if (player)
		{
			if (value == 0)
				w = true;
			if (value == 1)
				a = true;
			if (value == 2)
				s = true;
			if (value == 3)
				d = true;
			if (value == 4)
				w = false;
			if (value == 5)
				a = false;
			if (value == 6)
				s = false;
			if (value == 7)
				d = false;
		}
		else
		{
			if (value == 8)
				w = true;
			if (value == 9)
				a = true;
			if (value == 10)
				s = true;
			if (value == 11)
				d = true;
			if (value == 12)
				w = false;
			if (value == 13)
				a = false;
			if (value == 14)
				s = false;
			if (value == 15)
				d = false;
		}


};
public:
	IFaccomplish(int xx , int yy , bool p );
	~IFaccomplish();
	void SetPos(double xx, double yy);
	void PosChange(int Deltax, int Deltay);
	void timeChange();
	bool collides(double x, double y);
	void GetBarrier(Barrier *b);
	void checkspeed();
	void GetAnother(IFaccomplish* Ano);
	void interaction(IFaccomplish* p);
	void Show(QGraphicsScene* s) override;
	double x, y, speedx, speedy;
	QGraphicsRectItem* Shadow;
	bool player;
	QGraphicsRectItem* Debug()
	{
		return Shadow;
	}
private:
	Barrier *bar;
	IFaccomplish* Another;
	bool w, a, s, d,jumpfirst;
};
