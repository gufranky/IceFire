#include "IFaccomplish.h"
void IFaccomplish::SetPos(int xx, int yy)
{
	x = xx;
	y = yy;
	if (x < 0) x = 0;
	if (x > 1900) x = 1900;
	if (y < 0) y = 0;
	if (y > 1050) y = 1050;
	setPos(x, y);
}
void IFaccomplish::PosChange(int Deltax, int Deltay)
{
	SetPos(x + Deltax, y + Deltay);
}
