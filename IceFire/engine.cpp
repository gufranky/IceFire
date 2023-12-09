#include "engine.h"
#include"Barrier.h"

engine::engine(QWidget* par)
{
	Gameover = new QLabel("Gameover", par);
	Gameover->setFont(QFont("Arial", 40));  
	Gameover->setAlignment(Qt::AlignCenter); 
	Gameover->setGeometry(760, 440, 400, 200);
	parent = par;
	LoadGame();

}

engine::~engine()
{
	delete p1;
	delete layout;
	delete view;
	delete barrier;
	delete Gameover;
	delete p2;
	delete m;
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
	if (event->text() == "e")
	{
		emit signalA(16);
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
	if (event->text() == "e")
	{
		emit signalA(17);
	}
}
void engine::Update()
{
	p1->TimeChange();
	p2->TimeChange();
	sp->inte();
	m->onemove();
}
void engine::reload()
{
	p1->SetPos(p1x, p1y);
	p1->speedx = 0; p1->speedy = 0; p1->stuckdie = 0;
	p2->SetPos(p2x, p2y);
	p2->speedx = 0; p2->speedy = 0; p2->stuckdie = 0;
	timer.start();
	sp->reload();
	m->reload();
	Gameover->hide();
	scene = new QGraphicsScene(parent);
	scene->addItem(p1);
	scene->addItem(p2);
}
void engine::gameover()
{
	timer.stop();
	Gameover->show();
}
void engine::LoadGame()
{

	//player读写完成
	p1 = new IFaccomplish(p1x, p1y, true);
	p2 = new IFaccomplish(p2x, p2y, false);
	p1->GetAnother(p2);
	p2->GetAnother(p1);
	barrier = new Barrier();
	//以下写wall
	
	//wall已完成
	m = new MoveBarrier();
	//以下写move

	//move已完成
	//以下写sp
	sp = new Spirit();
	sp->addplayer(p1, p2);
	sp->getm(m);
	//sp已完成
	p1->GetBarrier(barrier);
	p2->GetBarrier(barrier);
	p1->GetMoveBarrier(m);
	p2->GetMoveBarrier(m);
	scene=new QGraphicsScene(parent);
	barrier->show(scene);
	sp->show(scene);
	m->show(scene);
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
	QObject::connect(p1, &IFaccomplish::stuck, this, &engine::gameover);
	QObject::connect(p2, &IFaccomplish::stuck, this, &engine::gameover);
}
void engine::Win()
{
	timer.stop();
	Gameover->setStyleSheet("color: red;");
	Gameover->setText("Win!!!");
	Gameover->show();
}
