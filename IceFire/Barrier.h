#pragma once
#ifndef BARRIER_H
#define BARRIER_H
#include <QObject>
#include <QApplication>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsRectItem>

class Barrier  : public QObject
{
	Q_OBJECT
		
public:
	friend class Fence;
	Barrier(QObject *parent);
	~Barrier();
	QGraphicsScene *scene01;
	QGraphicsRectItem* fence1;
	QGraphicsRectItem* fence2;
	QGraphicsRectItem* fence3;
	QGraphicsRectItem* fence4;
	QGraphicsView* view;
	//创建四周围栏
	
};


#endif//BARRIER_H