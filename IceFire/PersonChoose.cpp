#include "PersonChoose.h"

PersonChoose::PersonChoose(QTcpSocket* S, QWidget* parent)
	: QWidget(parent)
{
	word = new QLabel(this);
	socket = S;
	iceButton = new QPushButton("ice", this);
	fireButton = new QPushButton("Fire", this);
	lineEdit = new QLineEdit(this);
	button = new QPushButton("enter", this);
	word->show();
	word->setGeometry(960, 300, 200, 30);
	lineEdit->setGeometry(100, 100, 200, 30);
	button->move(960, 540);
	if (socket != nullptr)
	{
		word->setText("Connect Success");
		connect(button, &QPushButton::clicked, this, [=]()
			{
				QString str = lineEdit->text();
				socket->write(str.toUtf8());
				socket->flush();
				lineEdit->clear();
			}
		);
		connect(socket, &QTcpSocket::readyRead, this, &PersonChoose::receiveData);
		lineEdit->show();
		button->show();
		iceButton->setEnabled(false);
		fireButton->setEnabled(false);

	}
	else
	{
		word->setText("Single play");
		lineEdit->hide();
		button->hide();
	}


	player = new QMediaPlayer(this);
	playlist = new QMediaPlaylist(this);
	playlist->addMedia(QUrl("qrc:/IceFire/re/menu.mp3"));
	playlist->setPlaybackMode(QMediaPlaylist::Loop);
	player->setPlaylist(playlist);
	player->play();//播放音乐
	iceButton->move(960, 900);
	iceButton->setFixedSize(400, 100);
	iceButton->show();
	iceButton->setStyleSheet("QPushButton {"
		"    border-radius: 20px;"  // 控制圆角半径，可以根据需要调整
		"    background-color:rgb(0, 128, 255);"
		"    color: white;"
		"    border: none;"
		"    font-size: 28px;"
		"}"
		"QPushButton:hover {"
		"    background-color: lightblue;"  // 鼠标悬停时的背景色
		"}");
	fireButton->move(460, 900);
	fireButton->setFixedSize(400, 100);
	fireButton->show();
	fireButton->setStyleSheet("QPushButton {"
		"    border-radius: 20px;"  // 控制圆角半径，可以根据需要调整
		"    background-color:rgb(0, 128, 255);"
		"    color: white;"
		"    border: none;"
		"    font-size: 28px;"
		"}"
		"QPushButton:hover {"
		"    background-color: lightblue;"  // 鼠标悬停时的背景色
		"}");
	//按钮设置
	imageLabel = new QLabel(this);
	QPixmap image;
	image.load(":/IceFire/re/back.jpg");
	imageLabel->setPixmap(image);
	imageLabel->setScaledContents(true);
	imageLabel->lower();
	//图片生成
	connect(iceButton, &QPushButton::clicked, this, &PersonChoose::iceClicked);
	connect(iceButton, &QPushButton::clicked, this, [=]()
		{
			player->stop();
		}
	);
	connect(fireButton, &QPushButton::clicked, this, &PersonChoose::fireClicked);
	connect(fireButton, &QPushButton::clicked, this, [=]()
		{
			player->stop();
		}
	);
}

PersonChoose::~PersonChoose()
{
	delete player;
	delete playlist;
	delete fireButton;
	delete imageLabel;
	delete iceButton;
	delete lineEdit;
	delete button;
	delete word;
}
void PersonChoose::receiveData()
{
	QByteArray data = socket->readAll();
	QString c = QString::fromUtf8(data);
	if (c == "OK")
	{
		iceButton->setEnabled(true);
		fireButton->setEnabled(true);
		word->setText("OK");
		disconnect(socket, &QTcpSocket::readyRead, this, &PersonChoose::receiveData);
	}
	else
	{
		word->setText("Error");
	}

}
