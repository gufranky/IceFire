#include "Barrier.h"
#include <QApplication>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsRectItem>
Barrier::Barrier(QObject *parent)
	: QObject(parent)
{
	fence1 = new QGraphicsRectItem(0, 0, 100, 10);
	fence2 = new QGraphicsRectItem(0, 0, 10, 100);
	fence3 = new QGraphicsRectItem(90, 0, 10, 100);
	fence4 = new QGraphicsRectItem(0, 90, 100, 10);
	scene01=new QGraphicsScene(parent);//������һ����ͼ�γ���
	scene01->addItem(fence1);
	scene01->addItem(fence2);
	scene01->addItem(fence3);
	scene01->addItem(fence4);
	//��ǽ����ӵ�����

	view=new QGraphicsView(scene01);//����ͼ�β����ó���
	view->show();
	
}

Barrier::~Barrier()
{
	delete view;
	delete scene01;
	delete fence1;
	delete fence2;
	delete fence3;
	delete fence4;//����������deleteΧǽָ���ֹ�ڴ�й©
}

