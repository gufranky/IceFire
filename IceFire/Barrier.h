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

const int MAXBARRIER = 100;//ÿһ�����֧��100�����ƶ����ϰ���
class Barrier
{
public:
	void add(int x, int y, int w, int h);//����һ���ϰ���
	void show(QGraphicsScene* s, const QString& imagePath);//�������ϰ�����ʾ�ڳ�����
	Barrier();
	~Barrier();
	int NowBarrier;//��ǰ�ϰ�������
	QGraphicsRectItem* a;
private:

};


#endif//BARRIER_H barrier��Ϊ���з��ƶ����ϰ���ļ��ϣ�����ǽ�ڡ�����