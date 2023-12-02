#pragma once
#ifndef BARRIER_H
#define BARRIER_H
#include <QObject>
#include <QApplication>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsRectItem>
#include <qstring.h>
const int MAXBARRIER = 100;//每一关最多支持100个非移动型障碍物
class Barrier 
{
public:
	void add(int x, int y, int w, int h);
	void show(QGraphicsScene* s);
	Barrier();
	~Barrier();
	int NowBarrier;
	QGraphicsRectItem* a;
private:
};


#endif//BARRIER_H barrier作为所有非移动型障碍物的集合，包括墙壁、地面