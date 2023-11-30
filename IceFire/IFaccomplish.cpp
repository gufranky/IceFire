#include "IFaccomplish.h"
const int MAXSPEED = 6;
const int A = 1.2;
void IFaccomplish::SetPos(int xx, int yy)
{
	x = xx;
	y = yy;
	if (x < 0) 
	{
		x = 0;
		speedx = 0;
	}

	if (x > 1900)
	{
		x = 1900;
		speedx = 0;
	}
	if (y < 0) 
	{
		y = 0;
		speedy = 0;
	}
	if (y >=1000)
	{
		y = 1000;
		speedy = 0;
		jumpfirst = true;
	}
	setPos(x, y);
}
void IFaccomplish::PosChange(int Deltax, int Deltay)
{
	SetPos(x + Deltax, y + Deltay);
}
void IFaccomplish::timeChange()
{
	if (a && (speedx >= -MAXSPEED) && (!d))
	{
		speedx -= A;
		if (speedx > 0)
		{
			speedx -= A;//反向急停
		
		}
	}
	if (d && (speedx <= MAXSPEED) && (!a))
	{
		speedx += A;
		if (speedx < 0)
		{
			speedx += A;//反向急停

		}
	}
	if (a == d) 
	{
		if (speedx > 0)
		{
			speedx -= A;
		}
		if (speedx < 0)
		{
			speedx += A;
		}
		if (abs(speedx) < A)
		{
			speedx = 0;
		}
	}//水平处理已完成
	if (true)
	{
		speedy += 3;
	}//垂直处理已完成
	if (y >= 1000)
	{
		speedy = 0;
		jumpfirst = true;
	}
	if (w)
	{
		w = false;
		if(jumpfirst)
		{
			jumpfirst = false;
			speedy = -40;
		}

	}

	if ((speedx==0)&&(speedy==0))
	{
		Change(":/IceFire/re/fire.png");
	}
	if ((speedx == 0) && (speedy > 0))
	{
		Change(":/IceFire/re/fire.png");
	}
	if ((speedx==0) && (speedy < 0))
	{
		Change(":/IceFire/re/fireyplus.png");
	}
	if ((speedx > 0) && (speedy == 0))
	{
		Change(":/IceFire/re/fireright.png");
	}
	if ((speedx < 0) && (speedy == 0))
	{
		Change(":/IceFire/re/firel.png");
	}
	if ((speedx > 0) && (speedy > 0))
	{
		Change(":/IceFire/re/firerd.png");
	}
	if ((speedx > 0) && (speedy < 0))
	{
		Change(":/IceFire/re/fireru.png");
	}
	if ((speedx < 0) && (speedy > 0))
	{
		Change(":/IceFire/re/fireld.png");
	}
	if ((speedx < 0) && (speedy < 0))
	{
		Change(":/IceFire/re/firelu.png");
	}
	PosChange(speedx, speedy);
}
IFaccomplish::IFaccomplish(int x , int y , QString c ) :x(x), y(y), Person(c) 
{
	speedx = 0;
	speedy = 0;
	jumpfirst = true;
	w = false;a=false;s=false;d=false;
	setCacheMode(QGraphicsItem::NoCache);
	timer.setInterval(20);
	timer.start();
	QObject::connect(&timer, &QTimer::timeout, this, &IFaccomplish::timeChange);
};