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

void deleteTrack(Playlist &p, string kode){ // delete track pada playlist sesuai kode
    if(isEmpty(p)){ // kalau playlist empty
        cout << "Playlist kosong, tidak ada track untuk di delete" << endl;
        return;
    } 
    
    adrTrack t = searchTrack(p, kode);

    if (t == nullptr) {
        cout << "track tidak ditemukan" << endl;
        return;
    }

    if (t == p.first && t == p.last){
        p.first = nullptr;
        p.last = nullptr;
    } else if (t == p.first){
        p.first = t -> next;
        p.first -> prev = nullptr;
        t -> next = nullptr;
    } else if (t == p.last){
            p.last = t -> prev;
            p.last -> next = nullptr;
            t -> prev = nullptr;
    } else {
        t -> prev -> next = t -> next;
        t -> next -> prev = t -> prev;
        t -> next = nullptr;
        t -> prev = nullptr;
    }

        delete t;
        cout << "Track berhasil dihapus dari playlist" << endl;
}

adrTrack searchTrack(Playlist p, string kode){
    adrTrack t = p.first;
    while (t != nullptr && t -> info.kode != kode){
        t = t -> next;
    }
    return t;
}

void addFavorite(Playlist &f, Playlist p, string kode){
    adrTrack t =searchTrack(p, kode);
    if (t == nullptr){
        cout << "Track tidak ditemukan" << endl;
    } else {
        t -> info.favorit = true;
        addTrack(f,t);
        cout << "track sudah dimasukkan playlist favorit" << endl;
    }
}

void addTrack(Playlist &p, adrTrack t) {
    if (t == NULL) {
        cout << "Gagal menambah lagu: data tidak valid.\n";
        return;
    }

    if (isEmpty(p)) {
        p.first = t;
        p.last = t;
        t->next = NULL;
        t->prev = NULL;
    } else {
        t->prev = p.last;
        t->next = NULL;
        p.last->next = t;
        p.last = t;
    }

    cout << "Lagu \"" << t->info.nama << "\" berhasil ditambahkan ke playlist\n";
}

void createPlaylist(Playlist &p){
    p.first = nullptr;
    p.last = nullptr;
}

bool isEmpty(Playlist p){ //cek playlist kosong
    return p.first == nullptr && p.last == nullptr;
}

adrTrack allocate(string nama, string artist, string album, string kode, string genre, int tahun, int durasi){ //taro info ke elemenTrack
    adrTrack t;
    t = new elemenTrack;
    t -> info.nama = nama;
    t -> info.artist = artist;
    t -> info.album = album;
    t -> info.kode = kode;
    t -> info.tahun = tahun;
    t -> info.durasi = durasi;
    t -> info.like = 0;
    t -> info.genre = genre;
    t -> info.favorit = false;
    t -> info.total_played = 0;
    t -> next = nullptr;
    t -> prev = nullptr;

    return t;
}

void playPlaylist(adrTrack &t) {
    if (t == nullptr) {
        cout << "Tidak ada lagu untuk diputar." << endl;
        return;
    }

    string pilihan;

    do {
        cout << "\n=== Memulai Playlist ===\n";

        adrTrack current = t;

        while (current != nullptr) {
            playTrack(current);   // ✔ Call playTrack here
            current = current->next;
        }

        cout << "\nPlaylist telah selesai." << endl;
        cout << "Ingin memutar lagi? (yes/no): ";
        cin >> pilihan;

    } while (pilihan == "yes");

    cout << "Kembali ke menu..." << endl;
}


void playTrack(adrTrack &p, string kode){
    adrTrack t = searchTrack(p, kode);
    if (t == nullptr){
        cout << "Track tidak ditemukan" << endl;
    } else {
        cout << "Memutar lagu: " << t -> info.nama << " oleh " << t -> info.artist << endl;
        t -> info.total_played += 1;
    }
}

void nextTrack(adrTrack &t){
    if (t == nullptr){
        cout << "Tidak ada track yang sedang diputar" << endl;
    } else if (t -> next == nullptr){
        cout << "Ini adalah track terakhir, tidak ada track selanjutnya" << endl;
    } else {
        t = t -> next;
        cout << "Memutar lagu: " << t -> info.nama << " oleh " << t -> info.artist << endl;
        t -> info.total_played += 1;
    }
}

void previousTrack(adrTrack &t){
    if (t == nullptr){
        cout << "Tidak ada track yang sedang diputar" << endl;
    } else if (t -> prev == nullptr){
        cout << "Ini adalah track pertama, tidak ada track sebelumnya" << endl;
    } else {
        t = t -> prev;
        cout << "Memutar lagu: " << t -> info.nama << " oleh " << t -> info.artist << endl;
        t -> info.total_played += 1;
    }
