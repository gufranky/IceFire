#pragma once
#include"Person.h"
#include <QObject>
#include <QTimer>
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
	void SetPos(int xx, int yy);
	void PosChange(int Deltax, int Deltay);
	QTimer timer;
	void timeChange();
private:
	double x,y,speedx,speedy;
	bool w, a, s, d,jumpfirst;
};
