#include <iostream>
#include "playlist.h"

using namespace std;

void showPlaylist(Playlist p) {
    if (isEmpty(p)) {
        cout << "Playlist kosong." << endl;
        return;
    }

    adrTrack current = p.first;
    int nomor = 1;

    cout << "======= DAFTAR PLAYLIST =======" << endl;

    while (current != NULL) {
        cout << nomor << ". " << current->info.nama << endl;
        cout << "   Artist : " << current->info.artist << endl;
        cout << "   Album  : " << current->info.album << endl;
        cout << "   Genre  : " << current->info.genre << endl;
        cout << "   Kode   : " << current->info.kode << endl;
        cout << "   Durasi : " << current->info.durasi << " detik" << endl;
        cout << "   Tahun  : " << current->info.tahun << endl;
        cout << "   Like   : " << current->info.like << endl;
        cout << "   Favorit: " << (current->info.favorit ? "Ya" : "Tidak") << endl;
        cout << "---------------------------------" << endl;

        current = current->next;
        nomor++;
    }
}

