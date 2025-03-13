#include <iostream> 
using namespace std;

// function untuk menampilkan matriks
void tampilMatriks(int matriks[3][3]) {
    cout << "+---+---+---+" << endl; // baris bagian atas tabel (pemanis saja hehe)
    for (int i = 0; i < 3; i++) { // perulangan untuk baris
        cout << "|"; // Awal baris
        for (int j = 0; j < 3; j++) { // perulangan untuk kolom

            // mencetak angka dengan spasi biar rata, tambahkan garis pemisah antar elemen
            if (matriks[i][j] < 10) cout << " " << matriks[i][j] << " |"; // jika elemen matriksnya 1 digit doang, tambah spasi (biar tabelnya rapih)
            else cout << matriks[i][j] << " |"; // jika elemen matriksnya 2 digit langsung cout in saja
        }
        cout << endl;
        cout << "+---+---+---+" << endl; // baris bagian bawah tabel
    }
}

int main() {
    int matriks[3][3]; // deklarasi matriks ukuran 3x3 
    int i, j; 

    // tampilan awal program untuk meminta user meng input elemen matriks
    cout << "|-------------------------------------------|" << endl;
    cout << "|    INPUT ELEMEN MATRIKS 3X3 DIBAWAH INI   |" << endl;
    cout << "|-------------------------------------------|" << endl << endl;

    // input elemen-elemen matriks dari user
    for (i = 0; i < 3; i++) { // perulangan utk baris
        for (j = 0; j < 3; j++) { // perulangan utk kolom
            cout << "Matriks[" << i << "][" << j << "] = "; 
            cin >> matriks[i][j]; // simpan inputan user kedalam array matriks
        }
    }

    // output matriks sebelum diputar (inputan dari user diatas tadi ya)
    cout << "\nOutput matriks sebelum diputar:\n";
    tampilMatriks(matriks); // panggil function utk menampilkan matriks

    // lanjut menggunakan nested loop untuk melakukan TRANSPOSE matriks (menukarr baris menjadi kolom)
    for (i = 0; i < 3; i++) { // perulangan baris
        for (j = i + 1; j < 3; j++) { // Loop kolom, mulai dari indeks setelah i (j = i + 1 hanya menukar bagian atas diagonal utama)
            swap(matriks[i][j], matriks[j][i]); // tukarr elemen simetris terhadap diagonal utama
        }
    }

    // lanjut membalik tiap baris menggunakan perulangan lagi, untuk rotasi searah jarum jam
    for (i = 0; i < 3; i++) { // loop baris
        swap(matriks[i][0], matriks[i][2]); // tukar elemen pertama dan terakhir pada tiap baris
        // yang tengah tidak perlu ditukar karena tidak berubah
    }

    // output matriks setelah diputar
    cout << "\nOutput matriks setelah diputar 90 derajat searah jarum jam:\n";
    tampilMatriks(matriks); // panggil function utk menampilkan matriks hasil rotasi

    cout << endl << endl; 
    return 0;
}