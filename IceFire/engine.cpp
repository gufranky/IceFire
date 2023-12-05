#include "engine.h"
#include"Barrier.h"
#include <fstream>
#include<string>
#include <sstream>
#include <iostream>
engine::engine(QWidget* parent)
{
	barrier = new Barrier();
	LoadGame();
	p1 = new IFaccomplish(p1x,p1y,true);
	p2 = new IFaccomplish(p2x, p2y, false);
	p1->GetAnother(p2);
	p2->GetAnother(p1);
	sp = new Spirit();
	sp->addplayer(p1, p2);
	sp->add(400, 800, 200, 200, 1, 1);
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
	setLayout(layout);
	setFocusPolicy(Qt::StrongFocus);
	timer.setInterval(30);
	timer.start();
	QObject::connect(this, &engine::signalA, p1, &IFaccomplish::handleSignalA);
	QObject::connect(this, &engine::signalA, p2, &IFaccomplish::handleSignalA);
	QObject::connect(&timer, &QTimer::timeout, this, &engine::Update);
}

engine::~engine()
{
	delete p1;
	delete layout;
	delete view;
	delete barrier;
	delete scene;
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
}

void engine::LoadGame()
{

	std::ifstream configFile("D:/ice&fire/IceFire/l1.cfg");
		//读写文件
	if (configFile.is_open()) {
		std::string line,line1,line2;
		while (std::getline(configFile, line)) {
			// 判断当前行是否包含"wall"关键字
			if (line.find("[wall]") != std::string::npos) {
				// 读取下一行，该行包含四个整数
				std::getline(configFile, line);

				// 使用字符串流解析四个整数
				std::istringstream iss(line);
				int x1, y1, x2, y2;
				if (iss >> x1 >> y1 >> x2 >> y2) {
					// 调用 barrier 的 add 函数，将四个整数作为参数传递
					barrier->add(x1, y1, x2, y2);
					break;
				}
			}
		}
		while (std::getline(configFile, line1)) {
			// 判断当前行是否包含"fire"关键字
			if (line1.find("fire") != std::string::npos) {
				// 读取下一行，该行包含两个整数
				std::getline(configFile, line1);

				// 使用字符串流解析2个整数
				std::istringstream iss1(line1);
				int x11, y11;
				if (iss1 >> x11 >> y11)
				{
					p1x = x11;
					p1y = y11;
					break;
				}
			}
			}
		while (std::getline(configFile, line2)) {
			// 判断当前行是否包含"ice"关键字

			if (line2.find("ice") != std::string::npos) {
				// 读取下一行，该行包含两个整数
				std::getline(configFile, line2);

				// 使用字符串流解析2个整数
				std::istringstream iss2(line2);
				int x22, y22;
				if (iss2 >> x22 >> y22)
				{
					p2x = x22;
					p2y = y22;
					break;
				}

			}
		}		
		}
	}

