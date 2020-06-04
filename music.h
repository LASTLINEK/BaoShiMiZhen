#pragma once

#include <QMediaPlaylist>
#include <QMediaPlayer>

class Music
{
public:
    Music();
    void playmusic();
    void pausemusic();
    void continuemusic();
private:
    QMediaPlayer *player;
    QMediaPlaylist *playlist;
};
