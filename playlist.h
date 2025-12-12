#ifndef PLAYLIST_H
#define PLAYLIST_H
#include <string>
using namespace std;

typedef struct elemenTrack *adrTrack;

struct track{
    string nama, artist, album, genre, kode;
    int durasi, like, tahun, totalPlayed;
    bool favorit;
};

struct elemenTrack{
    track info;
    adrTrack next, prev;
};

struct Playlist{
    adrTrack first, last;
};

void createPlaylist(Playlist &p);
bool isEmpty(Playlist p);
adrTrack allocate(string nama, string artist, string album, string kode, string genre, int tahun, int durasi);
void showPlaylist(Playlist p);
void deleteTrack(Playlist &p, string kode);
void addTrack(Playlist &p, adrTrack t);
adrTrack searchTrack(Playlist p, string kode);
void updateDataTrack(Playlist &p, string kode);
void addFavorite(Playlist &f, Playlist p, adrTrack t);
void likeTrack(Playlist &p, string kode);
void playPlaylist(Playlist p);
void playTrack(adrTrack p);
void nextTrack(adrTrack &t);
void previousTrack(adrTrack &t);
void showMostPlayed(Playlist p);
void addOrdered(Playlist &p, adrTrack t);
int genreRank(string genre);

#endif // PLAYLIST_H

