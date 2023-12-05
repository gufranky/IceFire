#include "engine.h"
#include"Barrier.h"

engine::engine(QWidget* par)
{
	Gameover = new QLabel("Gameover", par);
	Gameover->setFont(QFont("Arial", 40));  // ���������С
	Gameover->setAlignment(Qt::AlignCenter); // �����ı�����
	Gameover->setGeometry(760, 440, 400, 200);
	parent = par;
	FirstLoad();

}

engine::~engine()
{
	delete p1;
	delete layout;
	delete view;
	delete barrier;
	delete scene;
	delete Gameover;
	delete p2;
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
	if (event->key() == Qt::Key_Up) { emit signalA(8);
	}
	else if (event->key() == Qt::Key_Left) {
		emit signalA(9);
	}
	else if (event->key() == Qt::Key_Down) {
		emit signalA(10);
	}
	else if (event->key() == Qt::Key_Right) {
		emit signalA(11);
	}
	if (event->text() == "r")
	{
		reload();
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
	if (event->key() == Qt::Key_Up) {
		emit signalA(12);
	}
	else if (event->key() == Qt::Key_Left) {
		emit signalA(13);
	}
	else if (event->key() == Qt::Key_Down) {
		emit signalA(14);
	}
	else if (event->key() == Qt::Key_Right) {
		emit signalA(15);
	}
}
void engine::Update()
{
	p1->timeChange();
	p2->timeChange();
	sp->inte();
}

void engine::FirstLoad()
{
	p1x = 100; p1y = 100; p2x = 0; p2y = 0;
	p1 = new IFaccomplish(100, 100, true);
	p2 = new IFaccomplish(0, 0, false);
	p1->GetAnother(p2);
	p2->GetAnother(p1);
	sp = new Spirit();
	sp->addplayer(p1, p2);
	sp->add(400, 800, 200, 200, 1, 1);
	sp->add(800, 600, 200, 200, 2, 1);
	sp->add(800, 800, 200, 200, 1, 2);
	sp->add(900, 700, 100, 100, 1, 3);
	barrier = new Barrier();
	barrier->add(800, 800, 100, 100);
	scene = new QGraphicsScene(parent);
	scene->addItem(p1);
	scene->addItem(p2);
	scene->addItem(p1->Debug());
	scene->addItem(p2->Debug());
	barrier->show(scene);
	sp->show(scene);
	p1->GetBarrier(barrier);
	p2->GetBarrier(barrier);
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
	//layout->addWidget(Gameover);
	Gameover->raise();
	setLayout(layout);
	setFocusPolicy(Qt::StrongFocus);
	timer.setInterval(30);
	timer.start();
	QObject::connect(this, &engine::signalA, p1, &IFaccomplish::handleSignalA);
	QObject::connect(this, &engine::signalA, p2, &IFaccomplish::handleSignalA);
	QObject::connect(&timer, &QTimer::timeout, this, &engine::Update);
	QObject::connect(sp, &Spirit::gameover, this, &engine::gameover);
	QObject::connect(sp, &Spirit::win, this, &engine::Win);
}
void engine::reload()
{
	p1->SetPos(p1x, p1y);
	p1->speedx = 0; p1->speedy = 0;
	p2->SetPos(p2x, p2y);
	p2->speedx = 0; p2->speedy = 0;
	timer.start();
	sp->reload();
	Gameover->hide();
}
void engine::gameover()
{
	timer.stop();
	Gameover->show();
}
void engine::Win()
{
	timer.stop();
	Gameover->setStyleSheet("color: red;");
	Gameover->setText("Win!!!");
	Gameover->show();
}
