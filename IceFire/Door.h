#pragma once
#include "Person.h"
#include "Spirit.h"
#include "IFaccomplish.h"
class Door :
    public SpiritBase
{
public:
    Door(int x, int y, int w, int h,bool fire, IFaccomplish* p1, IFaccomplish*p2);
    ~Door();
    void interaction() override;
    void paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget = nullptr) override;
    void Show(QGraphicsScene* s)override;
    void CanOpen()override;
    void Reload()override;
    bool fire, here,Open;
    int  x, y, w, h;
    IFaccomplish* p1, * p2;
    private:
        QGraphicsRectItem* Shadow;
};

