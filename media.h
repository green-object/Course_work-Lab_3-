#ifndef MEDIA_H
#define MEDIA_H
#include "activity.h"

//Класс студенческие медиа
class Media : public Activity
{
    //кол-во просмотров на видео
    int nCountViewVideo;
public:
    Media();
    //расчет итоговых баллов
    virtual int calculateFinishBalls() const;
    virtual QString className() const;
    int getNCountViewVideo() const;
    void setNCountViewVideo(int value);
};

#endif // MEDIA_H
