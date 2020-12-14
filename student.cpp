#include "student.h"
//селектор ФИО
QString Student::getFio() const
{
    return fio;
}
//модификатор ФИО
void Student::setFio(const QString &value)
{
    fio = value;
}
//селектор курс
int Student::getCourse() const
{
    return course;
}
//модификатор курс
void Student::setCourse(int value)
{
    course = value;
}

int Student::getRatingVolunteer() const
{
    return ratingVolunteer;
}

void Student::setRatingVolunteer(int value)
{
    ratingVolunteer = value;
}

int Student::getRatingEvent() const
{
    return ratingEvent;
}

void Student::setRatingEvent(int value)
{
    ratingEvent = value;
}

int Student::getRatingMedia() const
{
    return ratingMedia;
}

void Student::setRatingMedia(int value)
{
    ratingMedia = value;
}

QList<Activity*> Student::getActivities() const
{
    return activities;
}

void Student::setActivities(const QList<Activity*> &value)
{
    activities = value;
}

void Student::addActivity(Activity* value)
{
    activities<<value;
}

Student::Student()
{

}
//подсчет общего балла
int Student::getRating()
{
    int rating = 0;
    foreach (Activity *activity, activities)
    {
        rating += activity->calculateFinishBalls();
        //распределение по полям соответстующих деятельностей
        if (activity->className()=="Event")//руководство проектом
        {
            ratingEvent = activity->calculateFinishBalls();
        }
        if (activity->className()=="Media")//студенческие медиа
        {
            ratingMedia = activity->calculateFinishBalls();
        }
        if (activity->className()=="Volunteer")//волонтерство
        {
            ratingVolunteer = activity->calculateFinishBalls();
        }
    }
    return rating;
}
