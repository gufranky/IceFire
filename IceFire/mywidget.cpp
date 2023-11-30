#include "mywidget.h"
#include <QDebug>
MyWidget::MyWidget(QWidget* parent)
    : QWidget(parent)
{
    // 创建按钮
    button1 = new QPushButton("Button 1", this);
    button2 = new QPushButton("Button 2", this);

    // 设置按钮的位置
    button1->setGeometry(50, 50, 100, 30);
    button2->setGeometry(50, 100, 100, 30);

    // 连接按钮的点击信号与槽函数
    connect(button1, SIGNAL(clicked()), this, SLOT(onButton1Clicked()));
    connect(button2, SIGNAL(clicked()), this, SLOT(onButton2Clicked()));
}

MyWidget::~MyWidget()
{
    // 在这里释放资源
}

// 按钮1点击时的槽函数
void MyWidget::onButton1Clicked()
{
    qDebug() << "Button 1 Clicked!";
}

// 按钮2点击时的槽函数
void MyWidget::onButton2Clicked()
{
    qDebug() << "Button 2 Clicked!";
}