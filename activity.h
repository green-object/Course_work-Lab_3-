#ifndef ACTIVITY_H
#define ACTIVITY_H
#include <QString>

//Базовый класс, достижение
class Activity
{
    //Наименование
    QString name;
    //направление
    QString trend;
public:
    Activity();
    //расчет итоговых баллов
    virtual int calculateFinishBalls() const = 0;
    virtual QString className() const = 0;
    QString getName() const;
    void setName(const QString &value);
    QString getTrend() const;
    void setTrend(const QString &value);
};

#endif // ACTIVITY_H
