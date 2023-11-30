#include "mywidget.h"
#include <QDebug>
MyWidget::MyWidget(QWidget* parent)
    : QWidget(parent)
{
    // ������ť
    button1 = new QPushButton("Button 1", this);
    button2 = new QPushButton("Button 2", this);

    // ���ð�ť��λ��
    button1->setGeometry(50, 50, 100, 30);
    button2->setGeometry(50, 100, 100, 30);

    // ���Ӱ�ť�ĵ���ź���ۺ���
    connect(button1, SIGNAL(clicked()), this, SLOT(onButton1Clicked()));
    connect(button2, SIGNAL(clicked()), this, SLOT(onButton2Clicked()));
}

MyWidget::~MyWidget()
{
    // �������ͷ���Դ
}

// ��ť1���ʱ�Ĳۺ���
void MyWidget::onButton1Clicked()
{
    qDebug() << "Button 1 Clicked!";
}

// ��ť2���ʱ�Ĳۺ���
void MyWidget::onButton2Clicked()
{
    qDebug() << "Button 2 Clicked!";
}