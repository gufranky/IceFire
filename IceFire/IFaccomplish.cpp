#include "IFaccomplish.h"
void IFaccomplish::SetPos(int xx, int yy)
{
	x = xx;
	y = yy;
	setPos(x, y);
}
void IFaccomplish::PosChange(int Deltax, int Deltay)
{
	SetPos(x + Deltax, y + Deltay);
}
