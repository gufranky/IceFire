#pragma once

#include <QObject>

class Barrier  : public QObject
{
	Q_OBJECT

public:
	Barrier(QObject *parent);
	~Barrier();
};
