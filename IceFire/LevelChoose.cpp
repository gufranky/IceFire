#include "LevelChoose.h"
#include"start.h"
int LevelChoose::currentLevel = 1;
int LevelChoose::levelCompleted = 0;
int temp = 0;
LevelChoose::LevelChoose(int p, QWidget* parent) :
	QWidget(parent)
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
	connect(BackButton, &QPushButton::clicked, this, &LevelChoose::onBackButtonClicked);

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

			if (p == 2)
			{
				LevelButton[i * 5 + j].setEnabled(false);
			}

			QObject::connect(&LevelButton[i * 5 + j], &QPushButton::clicked, this, [=]()
				{
					handleLevelButtonClick(i * 5 + j + 1);

				});
		}
}

void LevelChoose::onBackButtonClicked()
{
	emit p2backClicked(); // 发出信号通知MainWindow
}

void LevelChoose::paintEvent(QPaintEvent* event)
{
	QWidget::paintEvent(event);

	QPainter painter(this);
	QPixmap backgroundImage(":/IceFire/re/back2.png"); // 在.qrc文件中添加的背景图像文件的路径

	painter.drawPixmap(0, 0, width(), height(), backgroundImage);
}

LevelChoose::~LevelChoose()
{
	delete[] LevelButton;
	delete BackButton;
}

void LevelChoose::handleLevelButtonClick(int Level)
{

	// 如果点击的关卡小于当前关卡(已完成)
	if (Level <= currentLevel)
	{
		emit level(Level);
		levelCompleted = std::max(levelCompleted, Level);
		temp = Level;
	}
	else
	{
		// 创建文本项、图形场景和计时器
		textItem = new QLabel("Please complete the pre-level from the first level", this);

		// 设置文本的字体
		QFont font("KaiTi", 35, QFont::Bold);  // 选择字体、大小和粗细
		textItem->setFont(font);

		// 设置文本项的字体颜色为白色
		QPalette palette = textItem->palette();
		palette.setColor(QPalette::WindowText, Qt::Key_LightBulb);
		textItem->setPalette(palette);

		// 设置文本项的位置
		textItem->setGeometry(100, 410, 5000, 300);  // 设置 x, y, width, height

		// 将文本项添加到图形场景中
		textItem->show();
		fadeAnimation = new QPropertyAnimation(textItem, "windowOpacity");
		textItem->setWindowOpacity(0.0);
		fadeAnimation->setDuration(1000);
		fadeAnimation->setStartValue(0.0);
		fadeAnimation->setEndValue(1.0);

		// 启动定时器，开始显示文本项
		fadeAnimation->start();
		QObject::disconnect(&timer, &QTimer::timeout, nullptr, nullptr);//断开之前的连接，以免多次触发
		connect(&timer, &QTimer::timeout, this, [this]() {
			timer.stop();
			fadeAnimation->stop();
			delete textItem;
			textItem = nullptr;
			delete fadeAnimation;
			fadeAnimation = nullptr;
			});
		timer.start(1500);
		

	}
}

	void LevelChoose::unlockNextLevel()
	{
		// 解锁下一关
		currentLevel = temp + 1;

		// 更新按钮状态
		for (int i = 0; i < 4; i++)
			for (int j = 0; j < 5; j++)
			{
				int level = i * 5 + j + 1;
				LevelButton[i * 5 + j].setEnabled(level <= currentLevel);
				//只有当前解锁的关卡及之前的关卡的按钮才是可点击的，而未解锁的关卡的按钮点击无效
			}
	}

