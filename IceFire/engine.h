#ifndef ENGINE_H
#define ENGINE_H
#include <QObject>
#include <QWidget>
class engine  : public QWidget
{
public:
	engine(QWidget *parent=nullptr);
	~engine();
};
#endif