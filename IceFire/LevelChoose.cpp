#include "LevelChoose.h"

int LevelChoose::currentLevel = 1;
int LevelChoose::levelCompleted = 0;
LevelChoose::LevelChoose(QWidget* parent) :
	QWidget(parent)

{
	p = parent;
	LevelButton = new QPushButton[20];
	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 5; j++)
		{
			LevelButton[i * 5 + j].setParent(this);
			LevelButton[i * 5 + j].move(460 + 200 * j, 100 + 200 * i);
			LevelButton[i * 5 + j].setFixedSize(100, 100);
			LevelButton[i * 5 + j].setText(QString::number(i * 5 + j + 1));
			LevelButton[i * 5 + j].show();
			LevelButton[i * 5 + j].setStyleSheet("QPushButton {"
				"    border-radius: 20px;"  // 控制圆角半径，可以根据需要调整
				"    background-color:rgb(0, 128, 255);"
				"    color: white;"
				"    border: none;"
				"    font-size: 28px;"
				"    background-image: url(:/IceFire/re/button.png);"
				"    background-position: center;"
				"}"
				"QPushButton:hover {"
				"    background-image: url(:/IceFire/re/buttonpush.png);" // 鼠标悬停时的背景图像路径
				"    background-position: center;"
				"}");


			QObject::connect(&LevelButton[i * 5 + j], &QPushButton::clicked, this, [=]()
				{
				 handleLevelButtonClick(i * 5 + j + 1);
				}
			);
		}
}


void LevelChoose::paintEvent(QPaintEvent* event)
{
	QWidget::paintEvent(event);

	QPainter painter(this);
	QPixmap backgroundImage(":/IceFire/re/back20.png"); // 在.qrc文件中添加的背景图像文件的路径
	painter.drawPixmap(0, 0, width(), height(), backgroundImage);
}

LevelChoose::~LevelChoose()
{
	delete[] LevelButton;
	delete scene;
	delete fadeAnimation;
}


void LevelChoose::handleLevelButtonClick(int Level)
{
    // 如果点击的关卡小于当前关卡，已完成
    if (Level <= currentLevel)
    {
        emit level(Level);
        levelCompleted = std::max(levelCompleted, Level);
        // 解锁下一关
        if (Level == currentLevel)
            unlockNextLevel();
    }
    else
    {
        // 创建文本项、图形场景和计时器
		textItem = new QLabel("请先完成前置关卡", p);


        textItem->show();
        fadeAnimation = new QPropertyAnimation(textItem, "windowOpacity");
		textItem->setWindowOpacity(0.0);
        fadeAnimation->setDuration(3000);
        fadeAnimation->setStartValue(0.0);
        fadeAnimation->setEndValue(1.0);
		
	   
        // 将文本项添加到图形场景中
        // 启动定时器，开始显示文本项
        timer.start(1500);   
		fadeAnimation->start();
        // 槽函数，处理定时器超时信号
        QObject::connect(&timer, &QTimer::timeout, [=]() {
            // 启动透明度动
			timer.stop();
			delete textItem;
            // 删除动画和文本项
            });
    }
}


void LevelChoose::unlockNextLevel()
{
	// 解锁下一关
	currentLevel++;

	// 更新按钮状态
	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 5; j++)
		{
			int level = i * 5 + j + 1;
			LevelButton[i * 5 + j].setEnabled(level <= currentLevel);
//只有当前解锁的关卡及之前的关卡的按钮才是可点击的，而未解锁的关卡的按钮点击无效
		}
}
