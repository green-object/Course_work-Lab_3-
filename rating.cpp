#include "rating.h"

QList<QMap<Student, int> > Rating::getRatings() const
{
    return ratings;
}

void Rating::setRatings(const QList<QMap<Student, int> > &value)
{
    ratings = value;
}

Rating::Rating()
{

}
//правило сортировки по объектам map студентов по убыванию
bool itemGraterThan(const QMap<Student, int> &v1, const QMap<Student, int> &v2)
{
    Student item1 = v1.firstKey();
    Student item2 = v2.firstKey();
    return item1.getRating() > item2.getRating();
}
//алгоритм расчета рейтинга
void Rating::calculate()
{
    //сортировка по убыванию итогового балла
    qSort(ratings.begin(), ratings.end(), itemGraterThan);
    //список результатов
    QList<QMap<Student, int> > results;
    for (int i = 0; i < ratings.size(); i++)
    {
        //ставим рейтинг
        QMap<Student, int> item = ratings.at(i);
        Student st = item.firstKey();
        QMap<Student, int> map;
        map.insert(st, i+1);
        results<<map;
    }
    //обновляем список результатов
    setRatings(results);
}
