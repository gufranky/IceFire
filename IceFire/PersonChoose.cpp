#include "PersonChoose.h"

PersonChoose::PersonChoose(QTcpSocket* S, QWidget* parent)
	: QWidget(parent)
{
	BackButton = new QPushButton(this);
	QString buttonText = "Back";  // 文本内容
	BackButton->setText(buttonText);
	QFont font1;
	font1.setPointSize(21);  // 设置字体大小
	font1.setBold(true);     // 设置粗体
	BackButton->setFont(font1);
	BackButton->move(100, 100);
	BackButton->setFixedSize(120, 80);
	BackButton->show();
	connect(BackButton, &QPushButton::clicked, this, &PersonChoose::onBackButtonClicked);

	word = new QLabel(this);
	socket = S;
	iceButton = new QPushButton("ice", this);
	fireButton = new QPushButton("Fire", this);
	lineEdit = new QLineEdit(this);
	button = new QPushButton("enter", this);
	word->show();
	word->setGeometry(530, 300, 800, 300);
	QFont font;
	font.setPointSize(36); 
	font.setBold(true);   
	word->setFont(font);
	word->setStyleSheet("color: blue;"); 
	word->setAlignment(Qt::AlignCenter); 
	QGraphicsDropShadowEffect* shadowEffect = new QGraphicsDropShadowEffect(this);
	shadowEffect->setBlurRadius(5);
	shadowEffect->setColor(QColor(0, 0, 0, 160));
	shadowEffect->setOffset(3, 3);
	word->setGraphicsEffect(shadowEffect);
	lineEdit->setGeometry(760, 500, 300, 80);
	connect(lineEdit, &QLineEdit::textChanged, this, [=](const QString& text)
		{
			QFont font;

			// 根据输入文本的总宽度动态计算字体大小
			int totalWidth = lineEdit->fontMetrics().width(text);
			// 设置一个基础字体大小
			int baseFontSize = 26;
			// 根据总宽度计算字体大小，确保不小于最小值
			int fontSize = qMax(baseFontSize - totalWidth / 15, 20);
			font.setPointSize(fontSize);

			lineEdit->setFont(font);
		});
	button->move(760, 740);
	
	button->setFixedSize(320, 70);
	button->setStyleSheet("QPushButton {"
		"    border-radius: 20px;"  // 控制圆角半径，可以根据需要调整
		"    background-color:rgb(0, 128, 255);"
		"    color: white;"
		"    border: none;"
		"    font-size: 28px;"
		"}"
		"QPushButton:hover {"
		"    background-color: lightblue;"  // 鼠标悬停时的背景色
		"}");
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
void PersonChoose::onBackButtonClicked()
{
	emit p4backClicked(); // 发出信号通知MainWindow
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
	delete BackButton;
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
