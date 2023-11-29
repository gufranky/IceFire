#ifndef ENGINE_H
#define ENGINE_H
#include <QObject>
#include <QWidget>
#include "Barrier.h"

class engine  : public QWidget
{
public:
	engine(QWidget *parent=nullptr);
	~engine();
	Barrier *p;
};
#endif