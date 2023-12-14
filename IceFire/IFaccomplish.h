#pragma once
#include"Person.h"
#include <QObject>
#include <QTimer>
#include"Barrier.h"
#include"MoveBarrier.h"
class MoveBarrier;
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
			if (value == 9)
				w = false;
			if (value == 10)
				a = false;
			if (value == 11)
				s = false;
			if (value == 12)
				d = false;
		}
		else
		{
			if (value == 4)
				w = true;
			if (value == 5)
				a = true;
			if (value == 6)
				s = true;
			if (value == 7)
				d = true;
			if (value == 13)
				w = false;
			if (value == 14)
				a = false;
			if (value == 15)
				s = false;
			if (value == 16)
				d = false;
		}
		if (value == 8)
			Epress = true;
		if (value == 17)
			Epress = false;



};
public:
	IFaccomplish(int xx , int yy , bool p );
	~IFaccomplish();
	void SetPos(double xx, double yy);
	void PosChange(int Deltax, int Deltay);
	void TimeChange();
	bool Collides(double x, double y);
	void GetBarrier(Barrier *b);
	void GetMoveBarrier(MoveBarrier* b);
	void CheckSpeed();
	void GetAnother(IFaccomplish* Ano);
	void Interaction(IFaccomplish* p);
	void Show(QGraphicsScene* s) override;
	double x, y, speedx, speedy;
	QGraphicsRectItem* Shadow;
	bool player;
	bool Epress;
	int stuckdie;
	QGraphicsRectItem* Debug()
	{
		return Shadow;
	}
private:
	Barrier *bar;
	MoveBarrier *mbar;
	IFaccomplish* Another;
	bool w, a, s, d,jumpfirst;
signals:
	void stuck();
};
