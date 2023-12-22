#pragma once
#include "Person.h"
#include <QMediaPlayer>
#include "Spirit.h"
#include "IFaccomplish.h"
class Diamond :
	public SpiritBase
{
public:
	Diamond(int x, int y, int w, int h, bool fire, IFaccomplish* p1, IFaccomplish* p2);
	~Diamond();
	void interaction() override;
	void paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget = nullptr) override;
	void Show(QGraphicsScene* s)override;
	void Reload()override;
	bool fire, get;
	QMediaPlayer* player;
	int  x, y, w, h;
	IFaccomplish* p1, * p2;
private:
	QGraphicsRectItem* Shadow;
};

