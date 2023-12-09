#include "engine.h"
#include"Barrier.h"
#include <fstream>
#include <string>
#include <sstream>
#include<iostream>
using namespace std;

engine::engine(QWidget* par)
{
	Gameover = new QLabel("Gameover", par);
	Gameover->setFont(QFont("Arial", 40));  
	Gameover->setAlignment(Qt::AlignCenter); 
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
	p1->timeChange();
	p2->timeChange();
	sp->inte();
	m->onemove();
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
	m = new MoveBarrier();
	m->add(1000, 800, 300, 50, 5, 1000, 300, 90, p1, p2);
	sp->getm(m);
	sp->add(1000, 1000, 100, 100, 0, 5);
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
	std::ifstream configFile("D:\\ice&fire\\IceFire\\l2.cfg");

	if (configFile.is_open()) {
		
		string  line1, line2 ,line3, line4, line5;
		while (std::getline(configFile, line1)) {
			// �жϵ�ǰ���Ƿ����"fire"�ؼ���
			if (line1.find("fire") != string::npos) {
				// ��ȡ��һ�У����а�����������
				std::getline(configFile, line1);

				// ʹ���ַ���������2������
				std::istringstream iss1(line1);
				int x11, y11;
				iss1 >> x11 >> y11;
				p1x = x11;
				p1y = y11;
				break;
			}
		}
		while (std::getline(configFile, line2)) {
			// �жϵ�ǰ���Ƿ����"ice"�ؼ���

			if (line2.find("ice") != string::npos) {
				// ��ȡ��һ�У����а�����������
				std::getline(configFile, line2);

				// ʹ���ַ���������2������
				std::istringstream iss2(line2);
				int x22, y22;
				iss2 >> x22 >> y22;
				p2x = x22;
				p2y = y22;
				break;

			}
		}
		//player��д���
		p1 = new IFaccomplish(p1x, p1y, true);
		p2 = new IFaccomplish(p2x, p2y, false);
		p1->GetAnother(p2);
		p2->GetAnother(p1);
		barrier = new Barrier();
		//����дwall
		while (std::getline(configFile, line3)) {
			// �жϵ�ǰ���Ƿ����"wall"�ؼ���
			if (line3.find("[wall]") != std::string::npos)
				// �жϵ�ǰ���Ƿ����"wall"�ؼ���
			{
				while (1)
				{
					// ��ȡ��һ�У����а����ĸ�����
					std::getline(configFile, line3);

					// ʹ���ַ����������ĸ�����
					std::istringstream iss(line3);
					int x1, y1, x2, y2;
					iss >> x1 >> y1 >> x2 >> y2;
					// ���� barrier �� add ���������ĸ�������Ϊ��������
					barrier->add(x1, y1, x2, y2);
					if (line3.find("break") != std::string::npos) { break; }
					//������ȡ���ݣ�����break����ѭ��
				}
			}
			if (line3.find("break") != std::string::npos) { break; }
		}
		//wall�����
		m = new MoveBarrier();
		//����дmove
		while (std::getline(configFile, line4)) {
			// �жϵ�ǰ���Ƿ����"wall"�ؼ���
			if (line4.find("[movewall]") != std::string::npos)
				// �жϵ�ǰ���Ƿ����"wall"�ؼ���
			{
				while (1) {
					std::getline(configFile, line4);
					// ��ȡ��һ�У����а���8������
					std::istringstream iss(line4);
					// ʹ���ַ���������8������
					int a, b, c, d, e, f, g, h;
					iss >> a >> b >> c >> d >> e >> f >> g >> h;
					// ���� m�� add ��������8��������Ϊ��������
					m->add(a, b, c, d, e, f, g, h, p1, p2);
					//������ȡ���ݣ�����break����ѭ��
					if (line4.find("break") != std::string::npos) { break; }

				}
			}
			if (line4.find("break") != std::string::npos) { break; }
		}

		//move�����
		//����дsp
		while (getline(configFile, line5)) {

			if (line5.find("spirit") != string::npos) {
				while (1) {
					getline(configFile, line5);
					istringstream iss(line5);
					int a, b, c, d, e, f;
					iss >> a >> b >> c >> d >> e >> f;
					sp->add(a, b, c, d, e, f);
					if (line5.find("break") != std::string::npos) { break; }
				}
			}
			if (line5.find("break") != std::string::npos) { break; }
		}
		sp = new Spirit();
		sp->addplayer(p1, p2);
		sp->getm(m);
		//sp�����
		p1->GetBarrier(barrier);
		p2->GetBarrier(barrier);
		p1->GetMoveBarrier(m);
		p2->GetMoveBarrier(m);
		scene = new QGraphicsScene(parent);
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
	configFile.close();
}
void engine::Win()
{
	timer.stop();
	Gameover->setStyleSheet("color: red;");
	Gameover->setText("Win!!!");
	Gameover->show();
}
