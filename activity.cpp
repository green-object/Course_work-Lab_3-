#include "activity.h"

//селектор наименования
QString Activity::getName() const
{
    return name;
}
//модификатор наименования
void Activity::setName(const QString &value)
{
    name = value;
}
//селектор направление
QString Activity::getTrend() const
{
    return trend;
}
//модификатор направление
void Activity::setTrend(const QString &value)
{
    trend = value;
}

Activity::Activity()
{

}
