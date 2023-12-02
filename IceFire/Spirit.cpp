#include "Spirit.h"


Spirit::~Spirit()
{
	
}

void Spirit::add(int x, int y, int w, int h,int more,int i)
{
	if(i==1)

	spirits.push_back(std::make_unique<Door>(x,y,w,h,true,p1,p2));
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


