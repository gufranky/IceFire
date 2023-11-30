#ifndef MYWIDGET_H
#define MYWIDGET_H

#include <QWidget>
#include <QPushButton>

class MyWidget : public QWidget
{
    Q_OBJECT

public:
    MyWidget(QWidget* parent = nullptr);
    ~MyWidget();

private slots:
    void onButton1Clicked();
    void onButton2Clicked();

private:
    QPushButton* button1;
    QPushButton* button2;
};

#endif // MYWIDGET_H