#include "playlist.h"
#include <iostream>

using namespace std;
adrTrack currentTrack = nullptr;
Playlist playlistFavorit;
Playlist musicLibrary;
Playlist userPlaylist;
adrTrack t;
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
    cout << "9. Add lagu favorit\n";
    cout << "10. Delete lagu favorit\n";
    cout << "11. Lihat Playlist favorit\n";
    cout << "12. Putar Playlist\n";
    cout << "13. Putar Playlist Favorit\n";
    cout << "14. Like Lagu\n";
    cout << "15. Lagu Paling Banyak Disukai\n";
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
                adrTrack t1 = searchTrack(musicLibrary, kode);

                if (t1 == nullptr){
                    cout << "Track tidak ditemukan\n";
                    system("pause");
                    break;
                } else {
                    cin.ignore();
                    cout << "Nama Lagu   : "; getline(cin, t1->info.nama);
                    cout << "Artist      : "; getline(cin, t1->info.artist);
                    cout << "Album       : "; getline(cin, t1->info.album);
                    cout << "Genre       : "; getline(cin, t1->info.genre);
                    cout << "Tahun       : "; cin >> t1->info.tahun;
                    cout << "Durasi (dtk): "; cin >> t1->info.durasi;
                    string nama = t1 -> info.nama;
                    string artist = t1 -> info.artist;
                    string album = t1 -> info.album;
                    string genre = t1 -> info.genre;
                    int tahun = t1 -> info.tahun;
                    int durasi = t1 -> info.durasi;

                    cout << "Status track dalam music library: ";
                    updateDataTrack(p, kode, nama, artist, album, genre, tahun, durasi);
                    cout << "Status track dalam playlist user: ";
                    updateDataTrack(userPlaylist, kode, nama, artist, album, genre, tahun, durasi);
                    cout << "Status track dalam playlist favorit: ";
                    updateDataTrack(playlistFavorit,kode, nama, artist, album, genre, tahun, durasi);
                    system("pause");
                    break;
                }
                }
            case 5: {
                string kode;
                cout << "Masukkan kode lagu yang akan dihapus: ";
                cin >> kode;
                cout << "Status track dalam music library: ";
                deleteTrack(p, kode);
                cout << "Status track dalam playlist user: ";
                deleteTrack(userPlaylist, kode);
                cout << "Status track dalam playlist favorit: ";
                deleteTrack(playlistFavorit, kode);
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
                    adrTrack copy = cloneTrack(t);
                    addTrack(userPlaylist, copy);
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
                cout << "Masukkan lagu yang ingin diputar: ";
                string kode;
                cin >> kode;
                currentTrack = searchTrack(p, kode);
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

        case 9:{
            string kode;
            cout << "Masukkan kode lagu yang ingin difavoritkan: ";
            cin >> kode;

            adrTrack t = searchTrack(p, kode);   // search dalam MusicLibrary

            if (t != nullptr) {
                adrTrack copy = cloneTrack(t);   // IMPORTANT: clone
                addFavorite(playlistFavorit, musicLibrary, kode);
                adrTrack t1 = searchTrack(userPlaylist, kode);
                if (t1 != nullptr){
                    t1 ->info.favorit = true;
                }

            } else {
                cout << "Lagu tidak ditemukan di MusicLibrary.\n";
            }

            system("pause");
            break;
        }

        case 10:{
            string kode;
            cout << "Masukkan kode lagu yang ingin di-unfavorit: ";
            cin >> kode;

            adrTrack t = searchTrack(p, kode);   // search dalam MusicLibrary

            if (t != nullptr) {
                removeFavorite(playlistFavorit,userPlaylist, kode);
            } else {
                cout << "Lagu tidak ditemukan di MusicLibrary.\n";
            }

            system("pause");
            break;
        }

        case 11:
            showPlaylist(playlistFavorit);
            system("pause");
            break;

        case 12:
            playPlaylist(p);
            system("pause");
            break;

        case 13:
            playPlaylist(playlistFavorit);
            system("pause");
            break;

        case 14: {
            string kode;
            cout << "Masukkan kode lagu yang ingin dilike: ";
            cin >> kode;
            likeTrack(p, kode);
            system("pause");
            break;
        }

        case 15:
            showMostLiked(p);
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
    createPlaylist(playlistFavorit);
    int pilihan;
    bool jalan = true;
    t = allocate("Not Allowed","TV Girl","Who Really Cares","0001","Indie",2016,167);
    addOrdered(musicLibrary,t);
    likeTrack(musicLibrary,"0001");
    likeTrack(musicLibrary,"0001");
    likeTrack(musicLibrary,"0001");
    likeTrack(musicLibrary,"0001");
    likeTrack(musicLibrary,"0001");
    likeTrack(musicLibrary,"0001");
    addFavorite(playlistFavorit,musicLibrary,"0001"); t = allocate("Not Allowed","TV Girl","Who Really Cares","0001","Indie",2016,167);
    t = allocate("Smells like Teen Spirit","Nirvana","Nevermind","0002","Rock",1991,301);
    addOrdered(musicLibrary,t);
    likeTrack(musicLibrary,"0002");
    likeTrack(musicLibrary,"0002");
    likeTrack(musicLibrary,"0002");
    t = allocate("Deep in it","berlioz","Deep in it","0003","Jazz",2023,154);
    addOrdered(musicLibrary,t);
    likeTrack(musicLibrary,"0003");
    likeTrack(musicLibrary,"0003");
    likeTrack(musicLibrary,"0003");
    likeTrack(musicLibrary,"0003");

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
