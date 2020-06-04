#include "music.h"

Music::Music()
{
    player = new QMediaPlayer;
    playlist = new QMediaPlaylist;
}
void Music::playmusic()
{
    playlist->addMedia(QUrl("qrc:/music/Saxophone.mp3"));
    playlist->setPlaybackMode(QMediaPlaylist::Random);
    player->setPlaylist(playlist);
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
