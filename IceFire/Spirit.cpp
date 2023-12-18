#include "Spirit.h"


Spirit::~Spirit()
{
	
}

void Spirit::add(int x, int y, int w, int h,int more,int i)
{
	if(i==1)
	{ 
		if (more==1)
		{
			spirits.push_back(std::make_unique<Door>(x, y, w, h, true, p1, p2));
		}
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
		QObject::connect(this, &Spirit::WinCheck, lastDoor, &WaterFire::CanOpen);
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
	if (i==3)
	{
		if (more == 1)
		{
			spirits.push_back(std::make_unique<Diamond>(x, y, w, h, true, p1, p2));
			
		}
		else
			spirits.push_back(std::make_unique<Diamond>(x, y, w, h, false, p1, p2));
		auto* lastDiamond = spirits.back().get();
		QObject::connect(lastDiamond, &Diamond::HadGet, this, &Spirit::DiamondCheck);
		AllDiamond += 1;
	}
	if (i == 4)
	{
		spirits.push_back(std::make_unique<button>(x, y, w, h, p1, p2));
		auto* lastButton = spirits.back().get();
		QObject::connect(lastButton, &SpiritBase::bepress, &m->a[more], &MoveBarrierBase::getit);
	}
	if (i == 5)
	{
		spirits.push_back(std::make_unique<StoneButton>(x, y, w, h, p1, p2));
		auto* lastButton = spirits.back().get();
		QObject::connect(lastButton, &SpiritBase::bepress, &m->a[more], &MoveBarrierBase::getit);
	}
} 

void Spirit::show(QGraphicsScene * s)
{
	for (const auto& spirit : spirits) {
		spirit->Show(s);
	}
	if (AllDiamond == 0)
	{
		emit WinCheck();
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
void Spirit::DiamondCheck()
{
	NowDiamond += 1;
	if (AllDiamond = NowDiamond)
	{
		emit WinCheck();
	}
}
void Spirit::reload()
{
	for (const auto& spirit : spirits) {
		spirit->Reload();
	}
	winner = 0;
	if (AllDiamond == 0)
		emit WinCheck();
}
void Spirit::getm(MoveBarrier* mm)
{
	m = mm;
}
