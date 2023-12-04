#include "Spirit.h"


Spirit::~Spirit()
{
	
}

void Spirit::add(int x, int y, int w, int h,int more,int i)
{
	if(i==1)
	{ 
		if (more==1)
			spirits.push_back(std::make_unique<Door>(x,y,w,h,true,p1,p2));
		else
			spirits.push_back(std::make_unique<Door>(x, y, w, h, false, p1, p2));
		auto* lastDoor = spirits.back().get();
		QObject::connect(lastDoor, &WaterFire::enter, this, [=]() {
			winner += 1;
			if (winner == 2)
			{
				emit win();
			}
			});
		QObject::connect(lastDoor, &WaterFire::exit, this, [=]() {
				winner -= 1;
				});
	}
	if (i==2)
		if (more == 1)
		{
			spirits.push_back(std::make_unique<WaterFire>(x, y, w, h, true, p1, p2));
			auto* lastWaterFire = spirits.back().get();
			QObject::connect(lastWaterFire,&WaterFire::death,this,&Spirit::dead);
		}
		else
		{
			spirits.push_back(std::make_unique<WaterFire>(x, y, w, h, false, p1, p2));
			auto* lastWaterFire = spirits.back().get();
			QObject::connect(lastWaterFire, &WaterFire::death, this, &Spirit::dead);
		}
}

void Spirit::show(QGraphicsScene * s)
{
	for (const auto& spirit : spirits) {
		spirit->Show(s);
	}
}

void Spirit::inte()
{
	for (const auto& spirit : spirits) {
		spirit->interaction();
	}
}

void Spirit::addplayer(IFaccomplish* p11, IFaccomplish* p22)
{
	this->p1 = p11;
	this->p2 = p22;
}
void Spirit::dead()
{
	emit gameover();
}

