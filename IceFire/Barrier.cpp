#include "Barrier.h"

void Barrier::add(int x, int y, int w, int h)
{
    a[NowBarrier].setRect(x, y, w, h);
    NowBarrier++;
}

void Barrier::show(QGraphicsScene* s, const QString& imagePath)
{
    for (int i = 0; i < NowBarrier; i++)
    {
        // 创建一个绘图对象，并将其指向barrier的rect
        QPixmap originalPixmap(imagePath);
        QSize rectSize = a[i].rect().size().toSize();
        QPixmap tiledPixmap(rectSize);
        tiledPixmap.fill(Qt::transparent);
        QPainter painter(&tiledPixmap);

        // 在barrier的rect内循环绘制图像
        for (int x = 0; x < rectSize.width(); x += originalPixmap.width()) {
            for (int y = 0; y < rectSize.height(); y += originalPixmap.height()) {
                painter.drawPixmap(x, y, originalPixmap);
            }
        }

        // 创建并设置图像项
        QGraphicsPixmapItem* pixmapItem = new QGraphicsPixmapItem(tiledPixmap);
        pixmapItem->setPos(a[i].rect().topLeft());

        // 将pixmapItem添加到barrier的rect之上，以确保它们关联在一起
        s->addItem(pixmapItem);
        s->addItem(&a[i]);
    }
}


Barrier::Barrier()
{
    NowBarrier = 0;
    a = new QGraphicsRectItem[MAXBARRIER];
}

Barrier::~Barrier()
{
    delete[] a;
}
