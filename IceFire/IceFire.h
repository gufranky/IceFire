#pragma once

#include <QtWidgets/QWidget>
#include "ui_IceFire.h"

class IceFire : public QWidget
{
    Q_OBJECT

public:
    IceFire(QWidget *parent = nullptr);
    ~IceFire();

private:
    Ui::IceFireClass ui;
};
