#include "engine.h"
#include"Barrier.h"
engine::engine(QWidget* parent)
{
	p = new Person(QString(":/IceFire/re/fire.png"));
	scene = new QGraphicsScene(parent);
	scene->addItem(p);
	layout = new QVBoxLayout(parent);
	view = new QGraphicsView(scene, parent);
	layout->addWidget(view);
	x = 0; y = 0;
	p->setPos(x, y);
	setLayout(layout);
	setFocusPolicy(Qt::StrongFocus);
}

engine::~engine()
{
	delete p;
	delete layout;
	delete scene;
	delete view;
}
void engine::keyPressEvent(QKeyEvent* event)
{
	if (event->text() == "w")
	{
		y = y - 10;
		p->setPos(x,y);
	}
	if (event->text() == "a")
	{
		x = x - 10;
		p->setPos(x, y);
	}
	if (event->text() == "s")
	{
		y = y + 10;
		p->setPos(x, y);
	}
	if (event->text() == "d")
	{
		x = x + 10;
		p->setPos(x, y);
	}
}