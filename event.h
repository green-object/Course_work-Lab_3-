#ifndef EVENT_H
#define EVENT_H
#include "activity.h"
//Класс руководство проектом
class Event : public Activity
{
    //оценка экспертов
    int expertMark;
public:
    Event();
    //расчет итоговых баллов
    virtual int calculateFinishBalls() const;
    virtual QString className() const;
    int getExpertMark() const;
    void setExpertMark(int value);
};

#endif // EVENT_H
