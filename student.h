#ifndef STUDENT_H
#define STUDENT_H
#include <QString>
#include <QList>
#include "activity.h"
//Класс студент
class Student
{
    //ФИО
    QString fio;
    //курс
    int course;
    //баллы по трём направлениям
    int ratingVolunteer;
    int ratingEvent;
    int ratingMedia;
    //список направлений
    QList<Activity*> activities;
public:
    Student();
    QString getFio() const;
    void setFio(const QString &value);
    int getCourse() const;
    void setCourse(int value);
    int getRatingVolunteer() const;
    void setRatingVolunteer(int value);
    int getRatingEvent() const;
    void setRatingEvent(int value);
    int getRatingMedia() const;
    void setRatingMedia(int value);
    QList<Activity*> getActivities() const;
    void setActivities(const QList<Activity*> &value);
    void addActivity(Activity *value);
    //получение общего балла
    int getRating();
    //для использования в map
    bool operator< ( const Student & other ) const
    {
        return this->getFio() < other.getFio();
    }
};

#endif // STUDENT_H
