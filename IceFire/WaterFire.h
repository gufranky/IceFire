#pragma once
#include "Person.h"
#include "Spirit.h"
#include "IFaccomplish.h"
const int amplitude = 15;
const int wavelength = 40;
class WaterFire :
    public SpiritBase
{
public:
    WaterFire(int x, int y, int w, int h, bool fire, IFaccomplish* p1, IFaccomplish* p2);
    ~WaterFire();
    void interaction() override;
    void paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget = nullptr) override;
    void Show(QGraphicsScene* s)override { s->addItem(this); };
    bool fire, here;
    int  x, y, w, h;
    IFaccomplish* p1, * p2;
private:
    QGraphicsRectItem* Shadow;

};