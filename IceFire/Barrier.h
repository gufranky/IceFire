#pragma once
#ifndef BARRIER_H
#define BARRIER_H
#include <QObject>
#include <QApplication>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsRectItem>
#include <qstring.h>
const int MAXBARRIER = 100;//ÿһ�����֧��100�����ƶ����ϰ���
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


#endif//BARRIER_H barrier��Ϊ���з��ƶ����ϰ���ļ��ϣ�����ǽ�ڡ�����