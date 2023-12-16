#ifndef ENGINE_H
#define ENGINE_H
#include <QObject>
#include <QWidget>
#include "Barrier.h"
#include "Person.h"
#include <QVBoxLayout>
#include <QKeyEvent>
#include "IFaccomplish.h"
#include <qlabel.h>
#include "Spirit.h"
#include"MoveBarrier.h"
#include <qpushbutton.h>
#include <QtWidgets>
#include <QtNetwork>
#include <QMediaPlayer>
#include <QMediaPlaylist>
class engine  : public QWidget
{
	Q_OBJECT
	
public:
	engine(int p,QWidget *parent=nullptr, QTcpSocket* s=nullptr);
	~engine();
	IFaccomplish*p1;
	IFaccomplish* p2;
	QVBoxLayout* layout;
	QGraphicsScene* scene;
	QGraphicsView* view;
	SpiritBase* spirit;
	QLabel* Gameover;
	Spirit* sp;
	MoveBarrier* m;
	Door* d;
	QTcpSocket* socket;
	Barrier* barrier;
	QMediaPlayer* mplayer;
	QMediaPlaylist* playlist;
	QLabel* imageLabel;
	int signal[10];
	int player;
	int more;
	void keyPressEvent(QKeyEvent* event) override;
	void keyReleaseEvent(QKeyEvent* event) override;
	void Update();
	void reload();
	void Win();
	void gameover();
	void LoadGame(); 
	void receiveData();
	void Background();
private:
	int p1x, p1y,p2x,p2y;
	QTimer timer;
	QWidget* parent;
	QPushButton* back;
signals:
	void signalA(int value);
	void winnew();
	void BackMenu();
};
#endif