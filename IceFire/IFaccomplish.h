#pragma once
#include"Person.h"
#include <QObject>
class IFaccomplish:public Person
{
	Q_OBJECT
public slots:
	void handleSignalA(int value)
	{
		if (value == 0)
		{
			PosChange(0, -10);
		}
		if (value == 1)
		{
			PosChange(-10, 0);
		}
		if (value == 2)
		{
			PosChange(0, 10);
		}
		if (value == 3)
		{
			PosChange(10, 0);
		}


};
public:
	IFaccomplish(int x = 100, int y = 100, QString c=NULL) :x(x), y(y), Person(c){};
	void SetPos(int xx, int yy);
	void PosChange(int Deltax, int Deltay);
private:
	int x,y;
};
