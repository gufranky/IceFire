#pragma once
#include"Person.h"
#include <QObject>
#include <QTimer>
#include"Barrier.h"
class IFaccomplish:public Person
{
	Q_OBJECT
public slots:
	void handleSignalA(int value)
	{
		if (value == 0)
		{
			w = true;
		}
		if (value == 1)
		{
			a = true;
		}
		if (value == 2)
		{
			s = true;
		}
		if (value == 3)
		{
			d = true;
		}
		if (value == 4)
		{
			w = false;
		}
		if (value == 5)
		{
			a = false;
		}
		if (value == 6)
		{
			s = false;
		}
		if (value == 7)
		{
			d = false;
		}


};
public:
	IFaccomplish(int x , int y , QString c );
	~IFaccomplish();
	void SetPos(double xx, double yy);
	void PosChange(int Deltax, int Deltay);
	QTimer timer;
	void timeChange();
	bool collides(double x, double y);
	void GetBarrier(Barrier *b);
	void checkspeed();
private:
	double x,y,speedx,speedy;
	Barrier *bar;
	bool w, a, s, d,jumpfirst;
	QGraphicsRectItem* Shadow;
};
