#include "playlist.h"
#include <iostream>

using namespace std;
adrTrack currentTrack = nullptr;
Playlist playlistFavorit;
Playlist musicLibrary;
Playlist userPlaylist;
void displayMainMenu() {
    system("cls");
    cout << "\n";
    cout << "========================================\n";
    cout << "   APLIKASI PEMUTAR MUSIK\n";
    cout << "========================================\n";
    cout << "   Tugas Besar Struktur Data\n";
    cout << "========================================\n";
    cout << "\n";
    cout << "1. Menu Admin\n";
    cout << "2. Menu User\n";
    cout << "0. Keluar\n";
    cout << "\n";
    cout << "========================================\n";
}

void displayAdminMenu() {
    system("cls");
    cout << "\n";
    cout << "========================================\n";
    cout << "        MENU ADMIN\n";
    cout << "========================================\n";
    cout << "\n";
    cout << "1. Tambah Lagu Baru\n";
    cout << "2. Lihat Semua Lagu\n";
    cout << "3. Cari Lagu\n";
    cout << "4. Update Data Lagu\n";
    cout << "5. Hapus Lagu\n";
    cout << "0. Kembali ke Menu Utama\n";
    cout << "\n";
    cout << "========================================\n";
}

void displayUserMenu() {
    system("cls");
    cout << "\n";
    cout << "========================================\n";
    cout << "        MENU USER\n";
    cout << "========================================\n";
    cout << "\n";
    cout << "1. Lihat Semua Lagu\n";
    cout << "2. Cari Lagu\n";
    cout << "3. Buat Playlist\n";
    cout << "4. Lihat Playlist Saya\n";
    cout << "5. Putar Lagu\n";
    cout << "6. Next Lagu\n";
    cout << "7. Previous Lagu\n";
    cout << "8. Tampilkan Most Played\n";
    cout << "9. Putar Playlist\n";
    cout << "10. Like Lagu\n";
    cout << "11. Lagu Paling Banyak Disukai\n";
    cout << "0. Kembali ke Menu Utama\n";
    cout << "\n";
    cout << "========================================\n";
}

void adminAuthentication(Playlist &p) {
    int pilihan;
    bool inAdminMenu = true;

    while (inAdminMenu) {
        displayAdminMenu();
        cout << "Masukkan Pilihan: ";
        cin >> pilihan;

        switch (pilihan) {
            case 1: {
                string nama, artist, album, genre, kode;
                int tahun, durasi;

                cin.ignore();
                cout << "Nama Lagu   : "; getline(cin, nama);
                cout << "Artist      : "; getline(cin, artist);
                cout << "Album       : "; getline(cin, album);
                cout << "Genre       : "; getline(cin, genre);
                cout << "Kode Lagu   : "; getline(cin, kode);
                cout << "Tahun       : "; cin >> tahun;
                cout << "Durasi (dtk): "; cin >> durasi;

                adrTrack t = allocate(nama, artist, album, kode, genre, tahun, durasi);
                addOrdered(p, t);
                system("pause");
                break;
            }

            case 2:
                showPlaylist(p);
                system("pause");
                break;

            case 3: {
                string kode;
                cout << "Masukkan kode lagu: ";
                cin >> kode;
                adrTrack t = searchTrack(p, kode);
                if (t)
                    cout << "Ditemukan: " << t->info.nama << " - " << t->info.artist << endl;
                else
                    cout << "Lagu tidak ditemukan\n";
                system("pause");
                break;
            }
            case 4: {
                string kode;
                cout << "Masukkan kode lagu yang akan diupdate: ";
                cin >> kode;
                cout << "Masukkan data baru untuk lagu tersebut:\n";
                cout << "Nama Lagu   : "; string nama; cin >> ws; getline(cin, nama);
                cout << "Artist      : "; string artist; getline(cin, artist);
                cout << "Album       : "; string album; getline(cin, album);
                cout << "Genre       : "; string genre; getline(cin, genre);
                cout << "Tahun       : "; int tahun; cin >> tahun;
                cout << "Durasi (dtk): "; int durasi; cin >> durasi;
                adrTrack t = allocate(nama, artist, album, kode, genre, tahun, durasi);
                updateDataTrack(musicLibrary , t, kode);
                system("pause");
                break;
                }
            case 5: {
                string kode;
                cout << "Masukkan kode lagu yang akan dihapus: ";
                cin >> kode;
                deleteTrack(p, kode);
                system("pause");
                break;
            }

            case 0:
                inAdminMenu = false;
                break;

            default:
                cout << "Pilihan tidak valid!\n";
                system("pause");
        }
    }
}

void userAuthentication(Playlist &p) {
    int pilihan;
    bool inUserMenu = true;

    while (inUserMenu) {
        displayUserMenu();
        cout << "Masukkan Pilihan: ";
        cin >> pilihan;

        switch (pilihan) {

        case 1:
            showPlaylist(p);
            system("pause");
            break;

        case 2: {
            string kode;
            cout << "Masukkan kode lagu: ";
            cin >> kode;
            adrTrack t = searchTrack(p, kode);
            if (t)
                cout << "Ditemukan: " << t->info.nama << " - " << t->info.artist << endl;
            else
                cout << "Lagu tidak ditemukan\n";
            system("pause");
            break;
        }

        case 3: {
            if (isEmpty(userPlaylist)) {
                cout << "Playlist user masih kosong.\n";
            }

            char pilih;
            cout << "Tambah lagu ke playlist? (y/n): ";
            cin >> pilih;

            if (pilih == 'y' || pilih == 'Y') {
                string kode;
                cout << "Masukkan kode lagu dari MusicLibrary: ";
                cin >> kode;

                adrTrack t = searchTrack(p, kode);
                if (t != nullptr) {
                    addTrack(userPlaylist, t);
                    cout << "Lagu berhasil ditambahkan.\n";
                } else {
                    cout << "Lagu tidak ditemukan.\n";
                }
            }

            cout << "\n=== Playlist Saya ===\n";
            showPlaylist(userPlaylist);

            system("pause");
            break;
        }

        case 4:
            showPlaylist(userPlaylist);
            system("pause");
            break;

        case 5: {
            if (isEmpty(p)) {
                cout << "MusicLibrary kosong.\n";
            } else {
                currentTrack = p.first;
                playTrack(currentTrack);
            }
            system("pause");
            break;
        }

        case 6:
            nextTrack(currentTrack);
            system("pause");
            break;

        case 7:
            previousTrack(currentTrack);
            system("pause");
            break;

        case 8:
            showMostPlayed(p);
            system("pause");
            break;

        case 9:
            playPlaylist(p);
            system("pause");
            break;

        case 10: {
            string kode;
            cout << "Masukkan kode lagu yang ingin dilike: ";
            cin >> kode;
            likeTrack(p, kode);
            system("pause");
            break;
        }

        case 11:
            ShowMostLiked(p);
            system("pause");
            break;

        case 0:
            inUserMenu = false;
            break;

        default:
            cout << "Pilihan tidak valid!\n";
            system("pause");
            break;
        }
    }
}


int main() {
    createPlaylist(musicLibrary);
    int pilihan;
    bool jalan = true;
    while (jalan) {
        displayMainMenu();
        cout << "Masukkan Pilihan: ";
        cin >> pilihan;

        switch (pilihan) {
        case 1:
            adminAuthentication(musicLibrary);
            break;
        case 2:
            userAuthentication(musicLibrary);
            break;
            case 0:
                jalan = false;
                break;
            default:
                cout << "Pilihan tidak valid! Silakan coba lagi.\n";
                system("pause");
                break;
        }
    }
    return 0;
}
