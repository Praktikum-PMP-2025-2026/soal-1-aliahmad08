/** EL2008 Praktikum Pemecahan Masalah dengan Pemrograman 2024/2025
 *   Modul               : 02
 *   Hari dan Tanggal    : Senin, 20 April 2026
 *   Nama /NIM           : Ali Ahmad Izza Wahyudi / 13224064
 *   Nama File           : soal1.c
 *   Deskripsi           : File ini berisi solusi untuk soal nomor 1. Kode dalam file ini berfungsi untuk mengatasi test case dengan alokasi memori kontigu. 
 *                         Problem yang ada adalah ada sebagian data yang hilang dalam array, untuk mengatasi masalah tersebut solusi yang digunakan adalah mengecek data dalam array sebelahnya (terdekat) yang valid,
 *                         untuk memperoleh perkiraan nilai untuk mengisi data yang hilang tersebut. 
 *
 * 
 */

#include <stdio.h>
#include <math.h>

int main() {
    int n;
    
    
    if (scanf("%d", &n) != 1) {
        return 1;
    }

    int arr[n];
    
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    for (int i = 0; i < n; i++) {
        if (arr[i] == -1) {
            int kiri = -1, kanan = -1;
            int cekkiri = 0, cekkanan = 0;

            
            for (int j = i - 1; j >= 0; j--) {
                if (arr[j] != -1) {
                    kiri = arr[j];
                    cekkiri= 1;
                    break;
                }
            }

            for (int m = i + 1; m < n; m++) {
                if (arr[m] != -1) {
                    kanan = arr[m];
                    cekkanan = 1;
                    break;
                }
            }

            
            if (cekkiri && cekkanan) {
                arr[i] = (int) floor ((kiri + kanan) / 2); 
            } else if (cekkiri) {
                arr[i] = kiri;
            } else if (cekkanan) {
                arr[i] = kanan;
            } else {
                arr[i] = 0;
            }
        }
    }

    
    printf("RECOVERED");
    for (int i = 0; i < n; i++) {
        printf(" %d", arr[i]);
    }
    printf("\n");

    int totalmax = arr[0];
    int  max = arr[0];

    for (int i = 1; i < n; i++) {
        if (max + arr[i] > arr[i]) {
            max = max + arr[i];
        } else {
            max = arr[i];
        }

        
        if (max > totalmax) {
            totalmax = max;
        }
    }

    printf("MAX_SUM %d", totalmax);

    return 0;
}
