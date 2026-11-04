#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Fungsi untuk membersihkan buffer input
void clearBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

// 1 & 3. Membuat/Menulis file awal dan Menambah Data baru (Append Mode)
void tambahData() {
    // Menggunakan mode "a+" agar otomatis membuat file jika belum ada, 
    // dan menambahkan data baru di akhir file tanpa menghapus data lama.
    FILE *file = fopen("mahasiswa.txt", "a+");
    if (file == NULL) {
        printf("Gagal membuka atau membuat file!\n");
        return;
    }

    char nama[50];
    char nim[20];
    float ipk;

    printf("\n--- Tambah Data Mahasiswa ---\n");
    printf("Masukkan Nama : ");
    clearBuffer();
    fgets(nama, sizeof(nama), stdin);
    nama[strcspn(nama, "\n")] = 0; // Menghapus karakter newline di akhir

    printf("Masukkan NIM  : ");
    scanf("%s", nim);

    printf("Masukkan IPK  : ");
    scanf("%f", &ipk);

    // Menyimpan data dengan format sesuai spesifikasi
    fprintf(file, "Nama: %s\n", nama);
    fprintf(file, "NIM : %s\n", nim);
    fprintf(file, "IPK : %.2f\n", ipk);
    fprintf(file, "-----------------\n");

    fclose(file);
    printf("Data mahasiswa berhasil disimpan secara permanen!\n");
}

// 2. Menampilkan isi file
void tampilkanData() {
    FILE *file = fopen("mahasiswa.txt", "r");
    if (file == NULL) {
        printf("\nFile 'mahasiswa.txt' belum ada atau belum ada data yang dimasukkan.\n");
        return;
    }

    printf("\n=== ISI FILE MAHASISWA ===\n");
    char baris[256];
    while (fgets(baris, sizeof(baris), file) != NULL) {
        printf("%s", baris);
    }

    fclose(file);
}

// 4. Menghitung Jumlah Mahasiswa
void hitungMahasiswa() {
    FILE *file = fopen("mahasiswa.txt", "r");
    if (file == NULL) {
        printf("\nFile 'mahasiswa.txt' belum ada. Jumlah mahasiswa: 0\n");
        return;
    }

    char baris[256];
    int jumlah = 0;
    
    // Menghitung berdasarkan kemunculan teks "Nama:" di dalam file
    while (fgets(baris, sizeof(baris), file) != NULL) {
        if (strncmp(baris, "Nama:", 5) == 0) {
            jumlah++;
        }
    }

    fclose(file);
    printf("\nJumlah Mahasiswa saat ini: %d orang\n", jumlah);
}

int main() {
    int pilihan;

    do {
        printf("\n========================================\n");
        printf("       PENGELOLAAN DATA MAHASISWA   \n");
        printf("========================================\n");
        printf("1. Tambah / Buat Data Mahasiswa\n");
        printf("2. Tampilkan Isi File Mahasiswa\n");
        printf("3. Hitung Jumlah Mahasiswa\n");
        printf("4. Keluar\n");
        printf("Pilihan Anda (1-4): ");
        scanf("%d", &pilihan);

        switch (pilihan) {
            case 1:
                tambahData();
                break;
            case 2:
                tampilkanData();
                break;
            case 3:
                hitungMahasiswa();
                break;
            case 4:
                printf("\nKeluar dari program. Terima kasih!\n");
                break;
            default:
                printf("\nPilihan tidak valid! Silakan masukkan angka 1-4.\n");
        }
    } while (pilihan != 4);

    return 0;
}
