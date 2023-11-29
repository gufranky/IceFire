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

	QGraphicsRectItem* fence1 = new QGraphicsRectItem(0, 0, 100, 10);
	QGraphicsRectItem* fence2 = new QGraphicsRectItem(0, 0, 10, 100);
	QGraphicsRectItem* fence3 = new QGraphicsRectItem(90, 0, 10, 100);
	QGraphicsRectItem* fence4 = new QGraphicsRectItem(0, 90, 100, 10);
	//创建四周围栏
	
};


#endif//BARRIER_H