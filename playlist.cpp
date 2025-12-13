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
    t -> info.totalPlayed = 0;
    t -> next = nullptr;
    t -> prev = nullptr;

    return t;
}

void playPlaylist(playlist p) {
    if (t == nullptr) {
        cout << "Tidak ada lagu untuk diputar." << endl;
        return;
    }

    string pilihan;

    do {
        cout << "\n=== Memulai Playlist ===\n";

        adrTrack current = t;

        while (current != nullptr) {
            playTrack(current);
            current = current->next;
        }

        cout << "\nPlaylist telah selesai." << endl;
        cout << "Ingin memutar lagi? (yes/no): ";
        cin >> pilihan;

    } while (pilihan == "yes");

    cout << "Kembali ke menu..." << endl;
}

void playTrack(adrTrack p){
    if (p == nullptr){
        cout << "Track tidak ditemukan" << endl;
        return;
    }
    cout << "Memutar lagu: " << p->info.nama << " oleh " << p->info.artist << endl;
    p->info.totalPlayed += 1;
}

void nextTrack(adrTrack &t){
    if (t == nullptr){
        cout << "Tidak ada track yang sedang diputar" << endl;
    } else if (t -> next == nullptr){
        cout << "Ini adalah track terakhir, tidak ada track selanjutnya" << endl;
    } else {
        t = t -> next;
        cout << "Memutar lagu: " << t -> info.nama << " oleh " << t -> info.artist << endl;
        t -> info.totalPlayed += 1;
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
        t -> info.totalPlayed += 1;
    }
}


void showMostLiked(Playlist p) {
    if (p.first == NULL) {
        cout << "\nTidak ada lagu dalam playlist.\n";
        return;
    }

    adrTrack firstMax = NULL;
    adrTrack secondMax = NULL;
    adrTrack thirdMax = NULL;

    adrTrack q = p.first;
    while (q != NULL) {
        if (firstMax == NULL || q->info.like > firstMax->info.like) {
            thirdMax = secondMax;
            secondMax = firstMax;
            firstMax = q;
        } else if (secondMax == NULL || q->info.like > secondMax->info.like) {
            thirdMax = secondMax;
            secondMax = q;
        } else if (thirdMax == NULL || q->info.like > thirdMax->info.like) {
            thirdMax = q;
        }
        q = q->next;
    }

    cout << "\n========================================\n";
    cout << "  3 Lagu yang Paling Disukai\n";
    cout << "========================================\n";

    int rank = 1;
    if (firstMax != NULL) {
        cout << rank++ << ". " << firstMax->info.nama << " (" << firstMax->info.totalPlayed << "x diputar)\n";
    }
    if (secondMax != NULL) {
        cout << rank++ << ". " << secondMax->info.nama << " (" << secondMax->info.totalPlayed << "x diputar)\n";
    }
    if (thirdMax != NULL) {
        cout << rank++ << ". " << thirdMax->info.nama << " (" << thirdMax->info.totalPlayed << "x diputar)\n";
    }

    cout << "========================================\n";
}

void showMostPlayed(Playlist p) {
    if (p.first == NULL) {
        cout << "\nTidak ada lagu dalam playlist.\n";
        return;
    }

    adrTrack firstMax = NULL;
    adrTrack secondMax = NULL;
    adrTrack thirdMax = NULL;

    adrTrack q = p.first;
    while (q != NULL) {
        if (firstMax == NULL || q->info.totalPlayed > firstMax->info.totalPlayed) {
            thirdMax = secondMax;
            secondMax = firstMax;
            firstMax = q;
        } else if (secondMax == NULL || q->info.totalPlayed > secondMax->info.totalPlayed) {
            thirdMax = secondMax;
            secondMax = q;
        } else if (thirdMax == NULL || q->info.totalPlayed > thirdMax->info.totalPlayed) {
            thirdMax = q;
        }
        q = q->next;
    }

    cout << "\n========================================\n";
    cout << "  3 Lagu yang Paling Sering Diputar\n";
    cout << "========================================\n";

    int rank = 1;
    if (firstMax != NULL) {
        cout << rank++ << ". " << firstMax->info.nama << " (" << firstMax->info.totalPlayed << "x diputar)\n";
    }
    if (secondMax != NULL) {
        cout << rank++ << ". " << secondMax->info.nama << " (" << secondMax->info.totalPlayed << "x diputar)\n";
    }
    if (thirdMax != NULL) {
        cout << rank++ << ". " << thirdMax->info.nama << " (" << thirdMax->info.totalPlayed << "x diputar)\n";
    }

    cout << "========================================\n";
}

int genreRank(string g) {
    if (g == "Classical") return 1;
    if (g == "Folk") return 2;
    if (g == "Jazz") return 3;
    if (g == "R&B") return 4;
    if (g == "Blues") return 5;
    if (g == "Reggae") return 6;
    if (g == "Indie") return 7;
    if (g == "Pop") return 8;
    if (g == "Latin") return 9;
    if (g == "Electronic") return 10;
    if (g == "Hip-Hop") return 11;
    if (g == "Rock") return 12;
    if (g == "Country") return 13;
    if (g == "Metal") return 14;

    return 100; //Genre jika tidak dikenali
}


void likeTrack(Playlist &p, string kode){
    adrTrack t =searchTrack(p, kode);
    if (t == nullptr){
        cout << "Track tidak ditemukan" << endl;
    } else {
        t -> info.like += 1;
        cout << "Anda menyukai lagu: " << t -> info.nama << endl;
    }
}

void AddLastOrdered(Playlist &p, adrTrack t) {
    if (t == NULL) {
        cout << "Gagal menambah lagu: data tidak valid.\n";
        return;
    }

    // Jika playlist kosong lagu langsung dimasukkan
    if (isEmpty(p)) {
        p.first = t;
        p.last = t;
        t->next = NULL;
        t->prev = NULL;

        cout << "Lagu \"" << t->info.nama << "\" berhasil ditambahkan ke playlist\n";
        return;
    }

    // Cari posisi berdasarkan genre
    adrTrack curr = p.first;
    int rNew = genreRank(t->info.genre);

    while (curr != NULL && genreRank(curr->info.genre) <= rNew) {
        curr = curr->next;
    }

    // -------- CASE 1: Masuk di akhir --------
    if (curr == NULL) {
        t->prev = p.last;
        t->next = NULL;
        p.last->next = t;
        p.last = t;
    }
    // -------- CASE 2: Masuk di paling depan --------
    else if (curr == p.first) {
        t->next = p.first;
        t->prev = NULL;
        p.first->prev = t;
        p.first = t;
    }
    // -------- CASE 3: Masuk di tengah --------
    else {
        adrTrack before = curr->prev;
        t->next = curr;
        t->prev = before;
        before->next = t;
        curr->prev = t;
    }

    cout << "Lagu \"" << t->info.nama << "\" berhasil ditambahkan ke playlist\n";
}

void updateLagu(string id, Lagu* newData) {
    Lagu* lagu = cariLaguById(id);
    if (lagu != nullptr) {
        lagu->judul = newData->judul;
        lagu->penyanyi = newData->penyanyi;
        lagu->genre = newData->genre;
        lagu->album = newData->album;
        lagu->tahun = newData->tahun;
        lagu->durasi = newData->durasi;
        cout << "Data lagu berhasil diupdate.\n";
    } else {
        cout << "Lagu dengan ID " << id << " tidak ditemukan.\n";
    }
}

void showMostLiked(Playlist p) {
    if (p.first == nullptr) {
        cout << "Playlist kosong.\n";
        return;
    }

    adrTrack first = nullptr;
    adrTrack second = nullptr;
    adrTrack third = nullptr;

    adrTrack cur = p.first;
    while (cur != nullptr) {
        if (first == nullptr || cur->info.like > first->info.like) {
            third = second;
            second = first;
            first = cur;
        } 
        else if (second == nullptr || cur->info.like > second->info.like) {
            third = second;
            second = cur;
        } 
        else if (third == nullptr || cur->info.like > third->info.like) {
            third = cur;
        }
        cur = cur->next;
    }

    cout << "\n========================================\n";
    cout << "   3 Lagu Paling Banyak Disukai ❤️\n";
    cout << "========================================\n";

    int rank = 1;
    if (first && first->info.like > 0)
        cout << rank++ << ". " << first->info.nama 
             << " (" << first->info.like << " like)\n";

    if (second && second->info.like > 0)
        cout << rank++ << ". " << second->info.nama 
             << " (" << second->info.like << " like)\n";

    if (third && third->info.like > 0)
        cout << rank++ << ". " << third->info.nama 
             << " (" << third->info.like << " like)\n";

    if (rank == 1)
        cout << "Belum ada lagu yang disukai.\n";

    cout << "========================================\n";
}

