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
				"    border-radius: 20px;"  // ����Բ�ǰ뾶�����Ը�����Ҫ����
				"    background-color:rgb(0, 128, 255);"
				"    color: white;"
				"    border: none;"
				"    font-size: 28px;"
				"    background-image: url(:/IceFire/re/button.png);"
				"    background-position: center;"
				"}"
				"QPushButton:hover {"
				"    background-image: url(:/IceFire/re/buttonpush.png);" // �����ͣʱ�ı���ͼ��·��
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
	QPixmap backgroundImage(":/IceFire/re/back2.png"); // ��.qrc�ļ�����ӵı���ͼ���ļ���·��
	painter.drawPixmap(0, 0, width(), height(), backgroundImage);
}

LevelChoose::~LevelChoose()
{
	delete[] LevelButton;

}

void LevelChoose::handleLevelButtonClick(int Level)
{

	// �������Ĺؿ�С�ڵ�ǰ�ؿ��������
	if (Level <= currentLevel)
	{
		emit level(Level);
		levelCompleted = std::max(levelCompleted, Level);
		// ������һ��
		if (Level == currentLevel)
			unlockNextLevel();
	}
	else
	{		// �����ı��ͼ�γ����ͼ�ʱ��
		textItem = new QLabel("Please complete the pre-level from the first level", p);

		// �����ı�������
		QFont font("KaiTi", 35, QFont::Bold);  // ѡ�����塢��С�ʹ�ϸ
		textItem->setFont(font);

		// �����ı����������ɫΪ��ɫ
		QPalette palette = textItem->palette();
		palette.setColor(QPalette::WindowText, Qt::blue);
		textItem->setPalette(palette);

		// �����ı����λ��
		textItem->setGeometry(100, 410, 5000, 300);  // ���� x, y, width, height

		// ���ı�����ӵ�ͼ�γ�����
		textItem->show();
		fadeAnimation = new QPropertyAnimation(textItem, "windowOpacity");
		textItem->setWindowOpacity(0.0);
		fadeAnimation->setDuration(1000);
		fadeAnimation->setStartValue(0.0);
		fadeAnimation->setEndValue(1.0);

		// ������ʱ������ʼ��ʾ�ı���
		fadeAnimation->start();
		QObject::disconnect(&timer, &QTimer::timeout, nullptr, nullptr);//�Ͽ�֮ǰ�����ӣ������δ���
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
		// ������һ��
		currentLevel++;

		// ���°�ť״̬
		for (int i = 0; i < 4; i++)
			for (int j = 0; j < 5; j++)
			{
				int level = i * 5 + j + 1;
				LevelButton[i * 5 + j].setEnabled(level <= currentLevel);
				//ֻ�е�ǰ�����Ĺؿ���֮ǰ�Ĺؿ��İ�ť���ǿɵ���ģ���δ�����Ĺؿ��İ�ť�����Ч
			}
	}

