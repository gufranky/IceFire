#ifndef ENGINE_H
#define ENGINE_H
#include <QObject>
#include <QWidget>
#include "Barrier.h"
#include "Person.h"
#include <QVBoxLayout>
#include <QKeyEvent>
class engine  : public QWidget
{
public:
	engine(QWidget *parent=nullptr);
	~engine();
	Person *p;
	QVBoxLayout* layout;
	QGraphicsScene* scene;
	QGraphicsView* view;
	void keyPressEvent(QKeyEvent* event) override;
private:
	int x, y;
};
#endif