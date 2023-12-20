#include "mainwindow.h"
#include <QtWidgets>
#include <QtNetwork>
MainWindow::MainWindow(QWidget* parent)
	: QMainWindow(parent)
{
	{
		stackedWidget = new QStackedWidget(this);
		page1 = new start;
		this->setFixedSize(1920, 1080);
		this->setWindowTitle("Myrt1e");
		stackedWidget->addWidget(page1);
		stackedWidget->setCurrentIndex(0);
		this->setCentralWidget(stackedWidget);
		connect(page1, &start::buttonClicked, this, &MainWindow::onButtonClicked);
		connect(page1, &start::moreClicked, this, &MainWindow::moreClicked);	
		setContentsMargins(0, 0, 0, 0);
		more = false;
		socket = nullptr;
		player = 0;
		
	}
}

MainWindow::~MainWindow()
{
	if (page1 != nullptr)
		delete page1;
	if (page2 != nullptr)
		delete page2;
	if (page3 != nullptr)
		delete page3;
	if(socket != nullptr)
		delete socket;
	if (page4 != nullptr)
		delete page4;
	delete  stackedWidget;
}
void MainWindow::p2onBackButtonClicked()
{
	stackedWidget->setCurrentIndex(0); // ÇÐ»»µ½page1
}

void MainWindow::p4onBackButtonClicked()
{
	stackedWidget->setCurrentIndex(0); // ÇÐ»»µ½page1
}
void MainWindow::moreClicked()
{
	more = true;
	socket = new QTcpSocket(this);
	socket->connectToHost("localhost", 12345);
	page4= new PersonChoose(socket,this);
	stackedWidget->addWidget(page4);
	stackedWidget->setCurrentIndex(1);
	connect(page4, &PersonChoose::iceClicked, [=]() {
		player = 2;
		stackedWidget->setCurrentIndex(0);
		stackedWidget->removeWidget(page4);
		onButtonClicked();
		connect(socket, &QTcpSocket::readyRead, this, &MainWindow::receiveData);
		});
	connect(page4, &PersonChoose::fireClicked, [=]() {
		player = 1;
		stackedWidget->setCurrentIndex(0);
		stackedWidget->removeWidget(page4);
		onButtonClicked();
		});
	connect(page4, &PersonChoose::p4backClicked, this, &MainWindow::p2onBackButtonClicked);
}

void MainWindow::onButtonClicked()
{
	this->setWindowTitle("Menu");
	page2 = new LevelChoose(player,this);
	stackedWidget->addWidget(page2);
	stackedWidget->setCurrentIndex(1);
	connect(page2, &LevelChoose::level, this, &MainWindow::ChooseFinish);
	connect(page2, &LevelChoose::p2backClicked, this, &MainWindow::p2onBackButtonClicked); 
}
void MainWindow::ChooseFinish(int i)
{
	QString message= QString::number(i);
	if (more)
	{
	socket->write(message.toUtf8());
	socket->flush();
	}

	this->setWindowTitle("Game");
	
	page3 = new engine(i,player,this, socket);
	stackedWidget->addWidget(page3);
	stackedWidget->setCurrentIndex(2);
	connect(page3, &engine::winnew, page2, &LevelChoose::unlockNextLevel);
	connect(page3, &engine::BackMenu, [=]() {
		stackedWidget->setCurrentIndex(1);
		stackedWidget->removeWidget(page3);
		delete page3;
		page3 = nullptr;
		this->setWindowTitle("Menu");
		if (player == 2)
		{
			connect(socket, &QTcpSocket::readyRead, this, &MainWindow::receiveData);
		}});
}