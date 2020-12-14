#include "event.h"
//селектор экспертной оценки
int Event::getExpertMark() const
{
    return expertMark;
}
//модификатор экспертной оценки
void Event::setExpertMark(int value)
{
    expertMark = value;
}

int Event::calculateFinishBalls() const
{
    return expertMark;
}

QString Event::className() const
{
    return "Event";
}

Event::Event()
{
    setTrend(className());
}
