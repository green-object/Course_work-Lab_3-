#include "volunteer.h"
//селектор кол-во часов, задействованных на мероприятии
int Volunteer::getNHours() const
{
    return nHours;
}

int Volunteer::calculateFinishBalls() const
{
    return (int)(0.5 * nHours);
}

QString Volunteer::className() const
{
    return "Volunteer";
}
//модификатор кол-во часов, задействованных на мероприятии
void Volunteer::setNHours(int value)
{
    nHours = value;
}

Volunteer::Volunteer()
{
    setTrend(className());
}
