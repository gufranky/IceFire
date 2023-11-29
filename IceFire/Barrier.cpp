#include "Barrier.h"
#include <QApplication>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsRectItem>
Barrier::Barrier(QObject *parent)
	: QObject(parent)
{
	QApplication a(int argc,char*argv[]);
	QGraphicsScene scene01;//创建第一个主图形场景
	scene01.addItem(fence1);
	scene01.addItem(fence2);
	scene01.addItem(fence3);
	scene01.addItem(fence4);
	//将墙壁添加到场景

	QGraphicsView view(&scene01);//创建图形并设置场景
	view.show();
	
}

Barrier::~Barrier()
{
	delete fence1;
	delete fence2;
	delete fence3;
	delete fence4;//析构函数中delete围墙指针防止内存泄漏
}

