#include "music.h"

Music::Music()
{
    player = new QMediaPlayer;
    playlist[0] = new QMediaPlaylist;
    playlist[1] = new QMediaPlaylist;
    playlist[2] = new QMediaPlaylist;

    playlist[0]->addMedia(QUrl("qrc:/music/Saxophone.mp3"));
    playlist[0]->setPlaybackMode(QMediaPlaylist::Random);
    playlist[1]->addMedia(QUrl("qrc:/music/BGmusic2.mp3"));
    playlist[1]->setPlaybackMode(QMediaPlaylist::Random);
    playlist[2]->addMedia(QUrl("qrc:/music/xiaochu.MP3"));
    playlist[2]->setPlaybackMode(QMediaPlaylist::CurrentItemOnce);
}
void Music::playmusic(int type)
{



    player->setPlaylist(playlist[type]);
    player->setVolume(100);

    player->play();
}

void Music::pausemusic()
{
    player->pause();
}

void Music::continuemusic()
{
    player->play();
}
