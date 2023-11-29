#ifndef ENGINE_H
#define ENGINE_H
#include <QObject>
#include <QWidget>
#include "Barrier.h"
#include "Person.h"
#include <QVBoxLayout>
#include <QKeyEvent>
#include "IFaccomplish.h"
class engine  : public QWidget
{
	Q_OBJECT
public:
	engine(QWidget *parent=nullptr);
	~engine();
	IFaccomplish*p;
	QVBoxLayout* layout;
	QGraphicsScene* scene;
	QGraphicsView* view;
	void keyPressEvent(QKeyEvent* event) override;
private:
	int x, y;
signals:
	void signalA(int value);

};
#endif