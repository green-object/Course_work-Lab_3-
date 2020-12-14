#include "media.h"

//селектор кол-во просмотров на видео
int Media::getNCountViewVideo() const
{
    return nCountViewVideo;
}
//модификатор кол-во просмотров на видео
void Media::setNCountViewVideo(int value)
{
    nCountViewVideo = value;
}

int Media::calculateFinishBalls() const
{
    if (nCountViewVideo < 500) return 0;
    else if (nCountViewVideo >= 500 && nCountViewVideo < 1500) return 1;
    else if (nCountViewVideo >= 1500 && nCountViewVideo < 10000) return 4;
    else return 10;// >=10000
}

QString Media::className() const
{
    return "Media";
}

Media::Media()
{
    setTrend(className());
}
