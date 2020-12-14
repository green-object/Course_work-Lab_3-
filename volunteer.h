#ifndef VOLUNTEER_H
#define VOLUNTEER_H
#include "activity.h"
//Класс волонтерство
class Volunteer : public Activity
{
    //кол-во часов, задействованных на мероприятии
    int nHours;
public:
    Volunteer();
    //расчет итоговых баллов
    virtual int calculateFinishBalls() const;
    virtual QString className() const;
    int getNHours() const;
    void setNHours(int value);
};

#endif // VOLUNTEER_H
