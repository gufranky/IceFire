#include "engine.h"
#include"Barrier.h"
engine::engine(QWidget* parent)
{
	x = 0, y = 0;
	p = new Person(QString(":/IceFire/re/fire.png"));
	scene = new QGraphicsScene(parent);
	scene->addItem(p);
	scene->setSceneRect(0, 0, 1920, 1080);
	view = new QGraphicsView(scene, parent);
	view->setFixedSize(1920, 1080);
	view->setContentsMargins(0, 0, 0, 0);
	view->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
	view->setRenderHint(QPainter::Antialiasing, true);
	view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
	view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
	layout = new QVBoxLayout(parent);
	layout->addWidget(view);
	layout->setSizeConstraint(QLayout::SetNoConstraint);
	layout->setContentsMargins(0, 0, 0, 0);
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