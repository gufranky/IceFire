#include "LevelChoose.h"
#include <QPixmap>
#include <QPainter>
#include <QGraphicsScene>
#include <QGraphicsTextItem>
#include <QFont>
#include <QTimer>
#include <QPropertyAnimation>
int LevelChoose::currentLevel = 1;
int LevelChoose::levelCompleted = 0;
LevelChoose::LevelChoose(QWidget* parent) :
	QWidget(parent)

{
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
	QPixmap backgroundImage(":/IceFire/re/back20.png"); // ��.qrc�ļ�����ӵı���ͼ���ļ���·��
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
    {
        // �����ı��ͼ�γ����ͼ�ʱ��
        QGraphicsTextItem* textItem = new QGraphicsTextItem("�������ǰ�ùؿ�");
        QGraphicsScene* scene = new QGraphicsScene();
        QTimer timer;

        // �����ı���ʽ��λ��
        QFont font("Arial", 16);
        textItem->setFont(font);
        textItem->setDefaultTextColor(Qt::black);
        QPointF sceneCenter = scene->sceneRect().center();
        textItem->setPos(sceneCenter.x() - textItem->boundingRect().width() / 2,
                         sceneCenter.y() - textItem->boundingRect().height() / 2);
        textItem->setZValue(1);  // ���ýϸߵ�Z����ֵ

        // ����͸���ȶ���
        QPropertyAnimation* fadeAnimation = new QPropertyAnimation(textItem, "opacity");
        fadeAnimation->setDuration(1500);
        fadeAnimation->setStartValue(0.0);
        fadeAnimation->setEndValue(1.0);

        // ���ı�����ӵ�ͼ�γ�����
        scene->addItem(textItem);
        // ������ʱ������ʼ��ʾ�ı���
        timer.start(50);  
        // �ۺ���������ʱ����ʱ�ź�
        QObject::connect(&timer, &QTimer::timeout, [=]() {
            // ����͸���ȶ���
            fadeAnimation->start();

            // ���ı���ӳ������Ƴ�
            scene->removeItem(textItem);

            // ɾ���������ı���
            delete fadeAnimation;
            delete textItem;
            });
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
