#pragma once

#include <QObject>

class Person  : public QObject
{
public:
	Person(QObject *parent);
	~Person();
};
