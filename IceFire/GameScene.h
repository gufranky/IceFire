#pragma once

#include <QObject>
#include <QGraphicsItem>
#include <QPainter>
#include <QGraphicsScene>
#include <QGraphicsView>
class CustomGraphicsView : public QGraphicsView {
public:
    CustomGraphicsView(QWidget* parent = nullptr)
        : QGraphicsView(parent) {
    }

protected:
    void drawBackground(QPainter* painter, const QRectF& rect) override {
        QImage backgroundImage(":/IceFire/re/back1.png");
        painter->drawImage(rect,backgroundImage);
    }
};   