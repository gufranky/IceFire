#include "engine.h"
#include"Barrier.h"
engine::engine(QWidget* parent)
{
	x = 0, y = 0;
	p1 = new IFaccomplish(0,0,QString(":/IceFire/re/fire.png"));
	barrier = new Barrier();
	barrier->add(800, 800, 100, 100);
	scene = new QGraphicsScene(parent);
	scene->addItem(p1);
	barrier->show(scene);
	p1->GetBarrier(barrier);
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
	QObject::connect(this, &engine::signalA, p1, &IFaccomplish::handleSignalA);
}

engine::~engine()
{
	delete p1;
	delete layout;
	delete view;
	delete barrier;
	delete scene;
}
void engine::keyPressEvent(QKeyEvent* event)
{
	if (event->text() == "w")
	{
		emit signalA(0);
	}
	if (event->text() == "a")
	{
		emit signalA(1);
	}
	if (event->text() == "s")
	{
		emit signalA(2);
	}
	if (event->text() == "d")
	{
		emit signalA(3);
	}
}
void engine::keyReleaseEvent(QKeyEvent* event)
{
	if (event->text() == "w")
	{
		emit signalA(4);
	}
	if (event->text() == "a")
	{
		emit signalA(5);
	}
	if (event->text() == "s")
	{
		emit signalA(6);
	}
	if (event->text() == "d")
	{
		emit signalA(7);
	}
}
