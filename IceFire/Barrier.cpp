#include "Barrier.h"
#include <QApplication>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsRectItem>
Barrier::Barrier(QObject *parent)
	: QObject(parent)
{
	QApplication a(int argc,char*argv[]);
	QGraphicsScene scene01;//������һ����ͼ�γ���
	scene01.addItem(fence1);
	scene01.addItem(fence2);
	scene01.addItem(fence3);
	scene01.addItem(fence4);
	//��ǽ����ӵ�����

	QGraphicsView view(&scene01);//����ͼ�β����ó���
	view.show();
	
}

Barrier::~Barrier()
{
	delete fence1;
	delete fence2;
	delete fence3;
	delete fence4;//����������deleteΧǽָ���ֹ�ڴ�й©
}

