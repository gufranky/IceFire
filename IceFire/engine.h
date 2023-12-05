#ifndef ENGINE_H
#define ENGINE_H
#include <QObject>
#include <QWidget>
#include "Barrier.h"
#include "Person.h"
#include <QVBoxLayout>
#include <QKeyEvent>
#include "IFaccomplish.h"
#include "Spirit.h"
class engine  : public QWidget
{
	Q_OBJECT

public:
	engine(QWidget *parent=nullptr);
	~engine();
	IFaccomplish*p1;
	IFaccomplish* p2;
	QVBoxLayout* layout;
	QGraphicsScene* scene;
	QGraphicsView* view;
	SpiritBase* spirit;
	Spirit* sp;
	Door* d;
	Barrier* barrier;
	void keyPressEvent(QKeyEvent* event) override;
	void keyReleaseEvent(QKeyEvent* event) override;
	void Update();
	void LoadGame();

private:
	int p1x, p1y,p2x,p2y;
	QTimer timer;
signals:
	void signalA(int value);

};
#endif