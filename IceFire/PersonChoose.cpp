#include "PersonChoose.h"

PersonChoose::PersonChoose(QWidget *parent)
	: QWidget(parent)
{
    player = new QMediaPlayer(this);
    playlist = new QMediaPlaylist(this);
    playlist->addMedia(QUrl("qrc:/IceFire/re/menu.mp3"));
    playlist->setPlaybackMode(QMediaPlaylist::Loop);
    player->setPlaylist(playlist);
    player->play();//��������
    iceButton = new QPushButton("ice", this);
    iceButton->move(960, 900);
    iceButton->setFixedSize(400, 100);
    iceButton->show();
    iceButton->setStyleSheet("QPushButton {"
        "    border-radius: 20px;"  // ����Բ�ǰ뾶�����Ը�����Ҫ����
        "    background-color:rgb(0, 128, 255);"
        "    color: white;"
        "    border: none;"
        "    font-size: 28px;"
        "}"
        "QPushButton:hover {"
        "    background-color: lightblue;"  // �����ͣʱ�ı���ɫ
        "}");
    fireButton = new QPushButton("Fire", this);
    fireButton->move(460, 900);
    fireButton->setFixedSize(400, 100);
    fireButton->show();
    fireButton->setStyleSheet("QPushButton {"
        "    border-radius: 20px;"  // ����Բ�ǰ뾶�����Ը�����Ҫ����
        "    background-color:rgb(0, 128, 255);"
        "    color: white;"
        "    border: none;"
        "    font-size: 28px;"
        "}"
        "QPushButton:hover {"
        "    background-color: lightblue;"  // �����ͣʱ�ı���ɫ
        "}");
    //��ť����
    imageLabel = new QLabel(this);
    QPixmap image;
    image.load(":/IceFire/re/back.jpg");
    imageLabel->setPixmap(image);
    imageLabel->setScaledContents(true);
    imageLabel->lower();
    //ͼƬ����
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
}
