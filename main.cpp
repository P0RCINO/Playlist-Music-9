#include "playlist.h"
#include <iostream>

using namespace std;

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
    cout << "0. Kembali ke Menu Utama\n";
    cout << "\n";
    cout << "========================================\n";
}

void adminAuthentication() {
    int pilihan;
    bool inAdminMenu = true;
    
    while (inAdminMenu) {
        displayAdminMenu();
        cout << "Masukkan Pilihan: ";
        cin >> pilihan;
        
        switch (pilihan) {
            case 1:
                cout << "\n>>> Fitur: Tambah Lagu Baru <<<\n";
                system("pause");
                break;
            case 2:
                cout << "\n>>> Fitur: Lihat Semua Lagu <<<\n";
                system("pause");
                break;
            case 3:
                cout << "\n>>> Fitur: Cari Lagu <<<\n";
                system("pause");
                break;
            case 4:
                cout << "\n>>> Fitur: Update Data Lagu <<<\n";
                system("pause");
                break;
            case 5:
                cout << "\n>>> Fitur: Hapus Lagu <<<\n";
                system("pause");
                break;
            case 0:
                inAdminMenu = false;
                break;
            default:
                cout << "Pilihan tidak valid! Silakan coba lagi.\n";
                system("pause");
                break;
        }
    }
}

void userAuthentication() {
    int pilihan;
    bool inUserMenu = true;
    
    while (inUserMenu) {
        displayUserMenu();
        cout << "Masukkan Pilihan: ";
        cin >> pilihan;
        
        switch (pilihan) {
            case 1:
                cout << "\n>>> Fitur: Lihat Semua Lagu <<<\n";
                system("pause");
                break;
            case 2:
                cout << "\n>>> Fitur: Cari Lagu <<<\n";
                system("pause");
                break;
            case 3:
                cout << "\n>>> Fitur: Buat Playlist <<<\n";
                system("pause");
                break;
            case 4:
                cout << "\n>>> Fitur: Lihat Playlist Saya <<<\n";
                system("pause");
                break;
            case 5:
                cout << "\n>>> Fitur: Putar Lagu <<<\n";
                system("pause");
                break;
            case 6:
                cout << "\n>>> Fitur: Next Lagu <<<\n";
                system("pause");
                break;
            case 7:
                cout << "\n>>> Fitur: Previous Lagu <<<\n";
                system("pause");
                break;
            case 8:
                cout << "\n>>> Fitur: Tampilkan Most Played <<<\n";
                showMostPlayed();   
                system("pause");
                break;
            case 9:
                cout << "\n>>> Fitur: Putar Playlist <<<\n";
                playPlaylist();     
                system("pause");
                break;
            case 0:
                inUserMenu = false;
                break;
            default:
                cout << "Pilihan tidak valid! Silakan coba lagi.\n";
                system("pause");
                break;
        }
    }
}

int main() {
    int pilihan;
    bool jalan = true;
    while (jalan) {
        displayMainMenu();
        cout << "Masukkan Pilihan: ";
        cin >> pilihan;

        switch (pilihan) {
            case 1:
                adminAuthentication();
                break;
            case 2:
                userAuthentication();
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
