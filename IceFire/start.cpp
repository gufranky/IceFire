#include "start.h"
start::start(QWidget* parent) :

    QWidget(parent)
{
    player = new QMediaPlayer(this);
    playlist = new QMediaPlaylist(this);
    playlist->addMedia(QUrl("qrc:/re/start.mp3"));
    playlist->setPlaybackMode(QMediaPlaylist::Loop);
    player->setPlaylist(playlist);
    player->play();//播放音乐
    startButton = new QPushButton("Start", this);
    startButton->move(760, 900);
    startButton->setFixedSize(400, 100);
    startButton->show();
    startButton->setStyleSheet("QPushButton {"
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
    QPixmap image(":/re/back.jpg");
    imageLabel->setPixmap(image);
    imageLabel->setScaledContents(true);
    imageLabel->lower();
    //图片生成
    connect(startButton, &QPushButton::clicked, this, &start::buttonClicked);
    connect(startButton, &QPushButton::clicked, this, [=]()
        {
            player->stop();
        }
    );
}

start::~start()
{
    delete player;
    delete playlist;
    delete startButton;
    delete imageLabel;
}
