#ifndef ANALOGCLOCK_H
#define ANALOGCLOCK_H

#include <QWidget>

class AnalogClock : public QWidget
{
    Q_OBJECT

public:
    AnalogClock(QWidget *parent = 0);

protected:
    void paintEvent(QPaintEvent *event);
    virtual void enterEvent(QEvent *event)
    {
        setBackgroundRole(QPalette::Light);

    }

    virtual void leaveEvent(QEvent *event)
    {
        setBackgroundRole(QPalette::Midlight);

    }

};

#endif // ANALOGCLOCK_H
