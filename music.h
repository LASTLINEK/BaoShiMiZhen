#pragma once

#include <QMediaPlaylist>
#include <QMediaPlayer>

class Music
{
public:
    Music();
    void playmusic(int type);
    void pausemusic();
    void continuemusic();
private:
    QMediaPlayer *player;
    QMediaPlaylist* playlist[3];
};
