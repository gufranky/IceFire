#include "engine.h"
#include"Barrier.h"
#include <fstream>
#include <string>
#include <sstream>
#include<iostream>
using namespace std;

engine::engine(int p, QWidget* par,QTcpSocket* S)
{
	Gameover = new QLabel("Gameover", par);
	Gameover->setFont(QFont("Arial", 40));
	Gameover->setAlignment(Qt::AlignCenter);
	Gameover->setGeometry(760, 440, 400, 200);
	parent = par;	
	back = new QPushButton("back",par);
	back->setFixedSize(400, 100);
	back->move(760, 900);
	LoadGame();
	player = p;
	socket = S;
	for (int i = 0; i <= 9; i++)
	{
		signal[i] = 0;
	}
	if (socket != nullptr)
	{
		connect(socket, &QTcpSocket::readyRead, this, &engine::receiveData);
	}
}
void engine::receiveData()
{
	QByteArray data = socket->readAll();
	QString c = QString::fromUtf8(data);
	if (c == "Reload")
	{
		reload();
	}
	else if (c == "Back")
	{
		emit BackMenu();
	}
	else
	{
		if (player == 1)
		{
			for (int i = 4; i <= 7; i++)
			{
				signal[i] = c[i].digitValue();
			}
		}
		else
		{
			for (int i = 0; i <= 3; i++)
			{
				signal[i] = c[i].digitValue();
			}
		}
		signal[8] = max(c[8].digitValue(), signal[8]);
	}

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
	delete back;
}
void engine::keyPressEvent(QKeyEvent* event)
{
	if (player != 2)
	{
		if (event->text() == "w")
		{
			signal[0] = 1;
		}
		if (event->text() == "a")
		{
			signal[1] = 1;
		}
		if (event->text() == "s")
		{
			signal[2] = 1;
		}
		if (event->text() == "d")
		{
			signal[3] = 1;
		}
	}
	if (player != 1)
	{
		if (event->key() == Qt::Key_Up) {
		signal[4] = 1;
		}
		if (event->key() == Qt::Key_Left) {
			signal[5] = 1;
		}
		if (event->key() == Qt::Key_Down) {
			signal[6] = 1;
		}
		if (event->key() == Qt::Key_Right) {
			signal[7] = 1;
		}
	}
	
	if (event->text() == "r")
	{
		signal[9] = 1;
		reload();
		if (socket != nullptr)
		{
			socket->write(QString("Reload").toUtf8());
			socket->flush();
		}
		
	}
	if (event->text() == "e")
	{
		signal[8] = 1;
	}

}
void engine::keyReleaseEvent(QKeyEvent* event)
{
	if (player != 2)
	{
		if (event->text() == "w")
		{
			signal[0] = 0;
		}
		if (event->text() == "a")
		{
			signal[1] = 0;
		}
		if (event->text() == "s")
		{
			signal[2] = 0;
		}
		if (event->text() == "d")
		{
			signal[3] = 0;
		}
	}
	if (player != 1)
	{
		if (event->key() == Qt::Key_Up) {
			signal[4] = 0;
		}
		else if (event->key() == Qt::Key_Left) {
			signal[5] = 0;
		}
		else if (event->key() == Qt::Key_Down) {
			signal[6] = 0;
		}
		else if (event->key() == Qt::Key_Right) {
			signal[7] = 0;
		}
	}
	
	if (event->text() == "e")
	{
		signal[8] = 0;
	}
}
void engine::Update()
{
	QString message;
	for (int i = 0; i <= 8; i++)
	{
		message += QString::number(signal[i]);
	}
	if (socket != nullptr)
	{
		socket->write(message.toUtf8());
		socket->flush();
	}
	for (int i = 0; i <= 8; i++)
	{
		emit signalA(i+((signal[i]==1)?0:9));
	}
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
	back->hide();
}
void engine::gameover()
{
	timer.stop();
	Gameover->show();
	back->show();
}
void engine::LoadGame()
{
	std::ifstream configFile("D:\\ice&fire\\IceFire\\l2.cfg");

	if (configFile.is_open()) {
		
		string  line1, line2 ,line3, line4, line5;
		while (std::getline(configFile, line1)) {
			// 判断当前行是否包含"fire"关键字
			if (line1.find("fire") != string::npos) {
				// 读取下一行，该行包含两个整数
				std::getline(configFile, line1);

				// 使用字符串流解析2个整数
				std::istringstream iss1(line1);
				int x11, y11;
				iss1 >> x11 >> y11;
				p1x = x11;
				p1y = y11;
				break;
			}
		}
		while (std::getline(configFile, line2)) {
			// 判断当前行是否包含"ice"关键字

			if (line2.find("ice") != string::npos) {
				// 读取下一行，该行包含两个整数
				std::getline(configFile, line2);

				// 使用字符串流解析2个整数
				std::istringstream iss2(line2);
				int x22, y22;
				iss2 >> x22 >> y22;
				p2x = x22;
				p2y = y22;
				break;

			}
		}
		//player读写完成
		p1 = new IFaccomplish(p1x, p1y, true);
		p2 = new IFaccomplish(p2x, p2y, false);
		p1->GetAnother(p2);
		p2->GetAnother(p1);
		barrier = new Barrier();
		//以下写wall
		while (std::getline(configFile, line3)) {
			// 判断当前行是否包含"wall"关键字
			if (line3.find("[wall]") != std::string::npos)
				// 判断当前行是否包含"wall"关键字
			{
				while (1)
				{
					// 读取下一行，该行包含四个整数
					std::getline(configFile, line3);

					// 使用字符串流解析四个整数
					std::istringstream iss(line3);
					int x1, y1, x2, y2;
					iss >> x1 >> y1 >> x2 >> y2;
					// 调用 barrier 的 add 函数，将四个整数作为参数传递
					barrier->add(x1, y1, x2, y2);
					if (line3.find("break") != std::string::npos) { break; }
					//连续读取数据，遇到break跳出循环
				}
			}
			if (line3.find("break") != std::string::npos) { break; }
		}
		//wall已完成
		m = new MoveBarrier();
		//以下写move
		while (std::getline(configFile, line4)) {
			// 判断当前行是否包含"wall"关键字
			if (line4.find("[movewall]") != std::string::npos)
				// 判断当前行是否包含"wall"关键字
			{
				while (1) {
					std::getline(configFile, line4);
					// 读取下一行，该行包含8个整数
					std::istringstream iss(line4);
					// 使用字符串流解析8个整数
					int a, b, c, d, e, f, g, h;
					iss >> a >> b >> c >> d >> e >> f >> g >> h;
					// 调用 m的 add 函数，将8个整数作为参数传递
					m->add(a, b, c, d, e, f, g, h, p1, p2);
					//连续读取数据，遇到break跳出循环
					if (line4.find("break") != std::string::npos) { break; }

				}
			}
			if (line4.find("break") != std::string::npos) { break; }
		}

		//move已完成
		//以下写sp
		sp = new Spirit();
		sp->addplayer(p1, p2);
		sp->getm(m);
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
		//sp已完成
		p1->GetBarrier(barrier);
		p2->GetBarrier(barrier);
		p1->GetMoveBarrier(m);
		p2->GetMoveBarrier(m);
		scene = new QGraphicsScene(parent);
		scene->addItem(p1);
		scene->addItem(p2);
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
		back->raise();
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
		QObject::connect(back, &QPushButton::clicked, [=]() {
			if(socket!=nullptr)
			{
				socket->write(QString("Back").toUtf8());
				socket->flush();
				QObject::disconnect(socket, &QTcpSocket::readyRead, this, &engine::receiveData);
			}
			emit BackMenu();
			
			});
	}
	configFile.close();
}
void engine::Win()
{
	timer.stop();
	Gameover->setStyleSheet("color: red;");
	Gameover->setText("Win!!!");
	Gameover->show();
	back->show();
	emit winnew();
}
