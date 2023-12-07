#pragma once
#include"button.h"
class StoneButton :
    public SpiritBase
{
public:
    StoneButton(int x, int y, int w, int h, IFaccomplish* p1, IFaccomplish* p2);
    ~StoneButton();
    void interaction() override;
    void paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget = nullptr) override;
    void Show(QGraphicsScene* s)override;
    void Reload()override;
    bool isPressed;
    bool cold;
    QTimer coldtimer;
    int  x, y, w, h;
    IFaccomplish* p1, * p2;
    QGraphicsRectItem* Shadow;
};

