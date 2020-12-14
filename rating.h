#ifndef RATING_H
#define RATING_H
#include <QList>
#include <QMap>
#include "student.h"

//Класс-контейнер для хранения рейтинга.
class Rating
{
    //контейнер
    QList<QMap<Student, int> > ratings;
public:
    Rating();
    void calculate();
    QList<QMap<Student, int> > getRatings() const;
    void setRatings(const QList<QMap<Student, int> > &value);
    void clearRatings() { ratings.clear();}
};

#endif // RATING_H
