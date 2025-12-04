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
void deleteTrack(Playlist &L, string kode, adrTrack p);
void deleteLast_103052400078(Playlist &L, adrTrack p);
void addTrack(Playlist &L, adrTrack p);
adrTrack searchTrack(Playlist L, string kode);
adrTrack updateDataTrack(Playlist L, string kode);

#endif // PLAYLIST_H

