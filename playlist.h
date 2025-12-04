#ifndef PLAYLIST_H
#define PLAYLIST_H

using namespace std;

typedef struct elemenTrack *adrTrack;

struct track{
    string nama, artist, album, genre, kode;
    int durasi, like, tahun;
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
adrTrack allocate(track t);
void showPlaylist(Playlist p);
void deleteTrack(Playlist &p, string kode, adrTrack t);
void deleteLast(Playlist &p, adrTrack t);
void addTrack(Playlist &p, adrTrack t);
adrTrack searchTrack(Playlist p, string kode);
void updateDataTrack(Playlist &p, string kode);
void addFavorite(adrTrack t);
void likeTrackvoid(adrTrack t);
#endif // PLAYLIST_H

