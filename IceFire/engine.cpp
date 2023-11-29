#include "engine.h"
#include"Barrier.h"
engine::engine(QWidget* parent)
{
	*p =new Barrier(this);
	
}

engine::~engine()
{
	delete p;
}
