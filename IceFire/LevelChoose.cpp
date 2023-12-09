#include "LevelChoose.h"
LevelChoose::LevelChoose(QWidget* parent) :
	QWidget(parent)
{
	LevelButton = new QPushButton[20];
	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 5; j++)
		{
			LevelButton[i * 5 + j].setParent(this);
			LevelButton[i * 5 + j].move(100 + 200 * j, 100 + 200 * i);
			LevelButton[i * 5 + j].setFixedSize(100, 100);
			LevelButton[i * 5 + j].setText(QString::number(i * 5 + j + 1));
			LevelButton[i * 5 + j].show();
			LevelButton[i * 5 + j].setStyleSheet("QPushButton {"
				"    border-radius: 20px;"  // 控制圆角半径，可以根据需要调整
				"    background-color:rgb(0, 128, 255);"
				"    color: white;"
				"    border: none;"
				"    font-size: 28px;"
				"}"
				"QPushButton:hover {"
				"    background-color: lightblue;"  // 鼠标悬停时的背景色
				"}");
			
			QObject::connect(&LevelButton[i * 5 + j], &QPushButton::clicked, this, [=]()
				{
					emit level(i * 5 + j + 1);
				}
			);
		}
}
LevelChoose::~LevelChoose()
{
	delete[] LevelButton;
}