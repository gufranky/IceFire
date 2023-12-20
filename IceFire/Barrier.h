#pragma once
#ifndef BARRIER_H
#define BARRIER_H
#include <QObject>
#include <QApplication>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsRectItem>
#include <qstring.h>
#include <QPixmap>

const int MAXBARRIER = 100;//每一关最多支持100个非移动型障碍物
class Barrier
{
public:
	void add(int x, int y, int w, int h);//增加一个障碍物
	void show(QGraphicsScene* s, const QString& imagePath);//将所有障碍物显示在场景上
	Barrier();
	~Barrier();
	int NowBarrier;//当前障碍物数量
	QGraphicsRectItem* a;
private:

};


#endif//BARRIER_H barrier作为所有非移动型障碍物的集合，包括墙壁、地面