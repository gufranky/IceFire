#include "PersonChoose.h"

PersonChoose::PersonChoose(QWidget *parent)
	: QWidget(parent)
{
    player = new QMediaPlayer(this);
    playlist = new QMediaPlaylist(this);
    playlist->addMedia(QUrl("qrc:/IceFire/re/menu.mp3"));
    playlist->setPlaybackMode(QMediaPlaylist::Loop);
    player->setPlaylist(playlist);
    player->play();//播放音乐
    iceButton = new QPushButton("ice", this);
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
    fireButton = new QPushButton("Fire", this);
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
}
