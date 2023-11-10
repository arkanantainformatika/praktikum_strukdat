#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <windows.h>
#include <bits/stdc++.h>

using namespace std;

string adminnya[] = {"Arka", "Bosco", "Agil"};
string admin, user, username;
int PW[] = {85, 80, 75};
long long passAdmin, password,  konfirmasiPass;

struct sepatu
    {
        string brand, jenis, idSepatu, warna;
        int ukuran, stok;
        long long harga;

        sepatu *next = NULL;
    };


struct Pelanggan
    {
        sepatu data;
        string nama, brandBuy, jenisBuy, warnaBuy;
        int jumlah;
        long long hatot;

        Pelanggan *next;
    };

sepatu *head = NULL;
Pelanggan *Front = NULL;
Pelanggan *Rear = NULL;
void tampil(sepatu *head);
void dataketxtfile(sepatu *&head);
void txtfilekedata(sepatu *head);
void riwayatpesanan(sepatu *head, Pelanggan *front);
int masuk();
int main();
sepatu *newsepatu()
    {
        sepatu *dataSepatu = new sepatu;

        cout << "Masukkan Brand Sepatu    : "; 
        fflush(stdin); getline(cin, dataSepatu->brand);
        cout << "Masukkan Jenis Sepatu    : ";
        fflush(stdin); getline(cin, dataSepatu->jenis);
        cout << "Masukkan Warna Sepatu    : ";
        fflush(stdin); getline(cin, dataSepatu->warna);
        cout << "Masukkan Ukuran Sepatu   : ";
        while (!(cin >> dataSepatu->ukuran))
            {
                cout << "Input tidak valid, silahkan masukkan angka!" << endl;
                cin.clear();
                cin.ignore(1000, '\n');
                cout << "Masukkan Ukuran Sepatu  : ";
            }
        cout << "Masukkan Stok Sepatu     : ";
        while (!(cin >> dataSepatu->stok))
            {
                cout << "Input tidak valid, silahkan masukkan angka!" << endl;
                cin.clear();
                cin.ignore(1000, '\n');
                cout << "Masukkan Stok Sepatu    : ";
            }
        cout << "Masukkan Harga Sepatu     : ";
        while (!(cin >> dataSepatu->harga))
            {
                cout << "Input tidak valid, silahkan masukkan angka!" << endl;
                cin.clear();
                cin.ignore(1000, '\n');
                cout << "Masukkan Harga Sepatu   : ";
            }
        cout << "Masukkan ID Sepatu       : ";
        while (!(cin >> dataSepatu->idSepatu))
            {
                cout << "Input tidak valid, silahkan masukkan angka!" << endl;
                cin.clear();
                cin.ignore(1000, '\n');
                cout << "Masukkan ID Sepatu      : ";
            }
        return dataSepatu;
    };



Pelanggan *newPelanggan()
    {
        Pelanggan *dataPelanggan = new Pelanggan();
        cout << "Masukkan Nama Anda : " << endl;
        cout << ">>> ";
        fflush(stdin);getline(cin, dataPelanggan->nama);
        cout << "Masukkan Brand Sepatu Yang Ingin Anda Beli :" << endl;
        cout << ">>> ";
        fflush(stdin);getline(cin, dataPelanggan->brandBuy);
        cout << "Masukkan Jenis Sepatu Yang Ingin Anda Beli :" << endl;
        cout << ">>> ";
        fflush(stdin);getline(cin, dataPelanggan->jenisBuy);
        cout << "Masukkan Warna Sepatu Yang Ingin Anda Beli :" << endl;
        cout << ">>> ";
        fflush(stdin);getline(cin, dataPelanggan->warnaBuy);
        cout << "Masukkan Id Sepatu Yang Ingin Anda Beli : " << endl;
        cout << ">>> ";
         fflush(stdin);(cin >> dataPelanggan->data.idSepatu);
        cout << "Masukkan Jumlah Sepatu Yang Ingin Anda Beli : " << endl;
        cout << ">>> ";

        while (!(cin >> dataPelanggan->jumlah))
            {
                cout << "Input tidak valid, silahkan masukkan angka!" << endl;
                cin.clear();
                cin.ignore(1000, '\n');
                cout << "Masukkan Jumlah Yang Ingin Anda Beli : ";
            }
        dataPelanggan->hatot = 0;
        return dataPelanggan;
    };

void tampil(sepatu *head) {
    sepatu *temp = head;
    int i = 0;

    if (head != NULL) {
        cout << "-----------------------------------------------------------------------------------------------------------------" << endl;
        cout << "| " << setw(4) << left << "N0" << " | " << setw(5) << "ID" << " | " << setw(15) << "BRAND" << " | " << setw(15) << "JENIS" << " | " << setw(15) << "WARNA" << " |" << setw(15) << "UKURAN" << " | " << setw(5) << "STOK" << " | " << setw(15) << "HARGA" << " |" << endl;
        cout << "-----------------------------------------------------------------------------------------------------------------" << endl;

        while (temp != NULL) {
            cout << "| " << setw(4) << i + 1 << " | " << setw(5) << temp->idSepatu << " | " << setw(15) << temp->brand << " | " << setw(15) << temp->jenis << " | " << setw(15) << temp->warna << " |" << setw(15) << temp->ukuran << " | " << setw(5) << temp->stok << " | " << setw(15) << temp->harga << " |" << endl;
            temp = temp->next;
            i++;

            if (temp != NULL) {
                cout << "-----------------------------------------------------------------------------------------------------------------" << endl;
            }
        }
    } else {
        cout << "Data Sepatu Kosong" << endl;
    }
}


void dataketxtfile(sepatu *&head)
    {
        sepatu *tail = NULL;
        string line, ukuran_string, stok_string, harga_string;
        ifstream file("DataSepatu.txt");
        if (file.is_open())
        {
            while (getline(file, line))
            {
                istringstream iss(line);

                // Membuat simpul baru untuk setiap baris
                sepatu *dataSepatu = new sepatu;

                getline(iss >> ws, dataSepatu->brand, '-');
                getline(iss >> ws, dataSepatu->jenis, '-');
                getline(iss >> ws, dataSepatu->warna, '-');
                getline(iss >> ws, dataSepatu->idSepatu, '-');
                getline(iss >> ws, ukuran_string, '-');
                stringstream(ukuran_string) >> dataSepatu->ukuran;
                getline(iss >> ws, stok_string, '-');
                stringstream(stok_string) >> dataSepatu->stok;
                getline(iss >> ws, harga_string, '-');
                stringstream(harga_string) >> dataSepatu->harga;

                dataSepatu->next = NULL;

                if (head == NULL)
                {
                    // Jika ini adalah simpul pertama, atur kepala ke simpul pertama
                    head = dataSepatu;
                    tail = dataSepatu;
                }
                else
                {
                    // Jika bukan simpul pertama, tambahkan ke akhir linked list
                    tail->next = dataSepatu;
                    tail = dataSepatu;
                }
            }
            file.close();
        }
    }

void txtfilekedata(sepatu *head)
    {
        ofstream file("DataSepatu.txt");
        if (file.is_open())
        {
            sepatu *dataSepatu = head;
            while (dataSepatu != NULL)
            {
                file << dataSepatu->brand << "-";
                file << dataSepatu->jenis << "-";
                file << dataSepatu->warna << "-";
                file << dataSepatu->idSepatu << "-";
                file << dataSepatu->ukuran << "-";
                file << dataSepatu->stok << "-";
                file << dataSepatu->harga << endl;
                dataSepatu = dataSepatu->next;
            }
            file.close();
        }
        else
        {
            cout << "Gagal membuka file." << endl;
        }
    }


void addFirst(sepatu **head)
    {
        sepatu *dataSepatu = newsepatu();
        dataSepatu->next = *head;
        *head = dataSepatu;
    }

void addLast(sepatu **head)
    {
        if (*head == NULL)
        {
            addFirst(head);
        }
        else
        {
            sepatu *temp = *head;
            sepatu *sepatuBaru = newsepatu();
            while (temp->next != NULL)
            {
                temp = temp->next;
            }
            temp->next = sepatuBaru;
        }
    }

void addMiddle(sepatu **head, int index)
    {
        if (*head == NULL)
        {
            addFirst(head);
        }
        else
        {
            sepatu *temp = *head;
            sepatu *sepatuBaru = newsepatu();
            for (int i = 1; i < index; i++)
            {
                temp = temp->next;
            }
            sepatuBaru->next = temp->next;
            temp->next = sepatuBaru;
        }
    }

void update(sepatu **head)
    {
        if (*head == NULL)
        {
            cout << "Data sepatu Masih Kosong" << endl;
            return;
        }
        string change;
        cout << "Masukkan Id sepatu yang ingin di ubah : ";
        cin >> change;
        sepatu *temp = (*head);
        while (temp != NULL)
        {
            if (temp->idSepatu == change)
                {
                    cout << "" << endl;
                    cout << "================================================================" << endl;
                    cout << "|| Masukkan Brand Sepatu Yang Baru    : "; fflush(stdin); getline(cin, temp->brand);
                    cout << "|| Masukkan Jenis Sepatu Baru         : "; fflush(stdin);getline(cin, temp->jenis);
                    cout << "|| Masukkan Warna Sepatu Baru         : "; fflush(stdin);getline(cin, temp->warna);
                    cout << "|| Masukkan Ukuran Sepatu Baru        : ";
                    while (!(cin >> temp->ukuran))
                    {
                        cout << "Input tidak valid, silahkan masukkan angka!" << endl;
                        cin.clear();
                        cin.ignore(1000, '\n');
                        cout << "Masukkan Ukuran Sepatu Baru    : ";
                    }
                    cout << "|| Masukkan Stok Sepatu Baru          : ";
                    while (!(cin >> temp->stok))
                    {
                        cout << "Input tidak valid, silahkan masukkan angka!" << endl;
                        cin.clear();
                        cin.ignore(1000, '\n');
                        cout << "Masukkan Stok Sepatu Baru      : ";
                    }
                    cout << "|| Masukkan Harga Sepatu Baru         : ";
                    while (!(cin >> temp->harga))
                    {
                        cout << "Input tidak valid, silahkan masukkan angka!" << endl;
                        cin.clear();
                        cin.ignore(1000, '\n');
                        cout << "Masukkan Harga Sepatu Baru     : ";
                    }
                    cout << "================================================================" << endl;
                    cout << "Data Berhasil Di Ubah!!!" << endl;
                    cout << "" << endl;
                    system("pause");
                    return;
                }
            temp = temp->next;
        }
    }

void deleteFirst(sepatu **head)
    {
        sepatu *hapus = *head;
        *head = (*head)->next;
        delete hapus;
    }

void deleteLast(sepatu **head)
    {
        if ((*head)->next == NULL)
        {
            deleteFirst(head);
        }
        else
        {
            sepatu *temp = *head;
            while (temp->next->next != NULL)
            {
                temp = temp->next;
            }
            sepatu *hapus = temp->next;
            temp->next = NULL;
            delete hapus;
        }
    }

void deleteMiddle(sepatu *head, int index)
    {
        sepatu *temp = head;
        for (int i = 1; i < index - 1; i++)
        {
            temp = temp->next;
        }
        sepatu *hapus = temp->next;
        temp->next = hapus->next;
        delete hapus;
    }

int hitungPanjangData(sepatu *head)
    {
        int hitung = 0;
        sepatu *datasepatu = head;
        while (datasepatu != NULL)
        {
            hitung++;
            datasepatu = datasepatu->next;
        }
        return hitung;
    }

sepatu *carisepatu(sepatu *head, int idx)
    {
        sepatu *datasepatu = head;
        for (int i = 0; i < idx; i++)
        {
            datasepatu = datasepatu->next;
        }
        return datasepatu;
    }

struct sepatu *getTail(struct sepatu *datasepatu)
    {
        while (datasepatu != NULL && datasepatu->next != NULL)
            datasepatu = datasepatu->next;
        return datasepatu;
    }

sepatu *partisi(struct sepatu *head, struct sepatu *end, struct sepatu **newHead, struct sepatu **newEnd, bool ascending, int idVoucher)
    {
        struct sepatu *pivot = end;
        struct sepatu *prev = NULL, *cur = head, *tail = pivot;

        while (cur != pivot)
        {
            if (idVoucher == 1)
            {
                if (ascending)
                {
                    if (cur->idSepatu < pivot->idSepatu)
                    {
                        if ((*newHead) == NULL)
                            (*newHead) = cur;
                        prev = cur;
                        cur = cur->next;
                    }
                    else
                    {
                        if (prev)
                            prev->next = cur->next;
                        struct sepatu *tmp = cur->next;
                        cur->next = NULL;
                        tail->next = cur;
                        tail = cur;
                        cur = tmp;
                    }
                }
                else
                {
                    if (cur->idSepatu > pivot->idSepatu)
                    {
                        if ((*newHead) == NULL)
                            (*newHead) = cur;
                        prev = cur;
                        cur = cur->next;
                    }
                    else
                    {
                        if (prev)
                            prev->next = cur->next;
                        struct sepatu *tmp = cur->next;
                        cur->next = NULL;
                        tail->next = cur;
                        tail = cur;
                        cur = tmp;
                    }
                }
            }
            else
            {
                if (ascending)
                {
                    if (cur->brand < pivot->brand)
                    {
                        if ((*newHead) == NULL)
                            (*newHead) = cur;
                        prev = cur;
                        cur = cur->next;
                    }
                    else
                    {
                        if (prev)
                            prev->next = cur->next;
                        struct sepatu *tmp = cur->next;
                        cur->next = NULL;
                        tail->next = cur;
                        tail = cur;
                        cur = tmp;
                    }
                }
                else
                {
                    if (cur->brand > pivot->brand)
                    {
                        if ((*newHead) == NULL)
                            (*newHead) = cur;
                        prev = cur;
                        cur = cur->next;
                    }
                    else
                    {
                        if (prev)
                            prev->next = cur->next;
                        struct sepatu *tmp = cur->next;
                        cur->next = NULL;
                        tail->next = cur;
                        tail = cur;
                        cur = tmp;
                    }
                }
            }
        }
        if ((*newHead) == NULL)
            (*newHead) = pivot;
        (*newEnd) = tail;
        return pivot;
    }

sepatu *quickSortRecursive(struct sepatu *head, struct sepatu *end, bool ascending, int jenis)
    {
        if (!head || head == end)
            return head;
        sepatu *newHead = NULL, *newEnd = NULL;
        struct sepatu *pivot = partisi(head, end, &newHead, &newEnd, ascending, jenis);
        if (newHead != pivot)
        {
            struct sepatu *tmp = newHead;
            while (tmp->next != pivot)
                tmp = tmp->next;
            tmp->next = NULL;
            newHead = quickSortRecursive(newHead, tmp, ascending, jenis);
            tmp = getTail(newHead);
            tmp->next = pivot;
        }
        pivot->next = quickSortRecursive(pivot->next, newEnd, ascending, jenis);
        return newHead;
    }

// Fungsi rekursif untuk mengurutkan linked list menggunakan algoritma Quick Sort
void quickSort(sepatu **low, bool ascending, int jenis)
    {
        (*low) = quickSortRecursive(*low, getTail(*low), ascending, jenis);
        return;
    }


const int NUMBER_CHAR = 256;

void badCharHeuristic(string str, int size, int badChar[NUMBER_CHAR])
    {
        // Inisialisasi semua nilai di badChar sebagai -1
        for (int i = 0; i < NUMBER_CHAR; i++)
        {
            badChar[i] = -1;
        }
        // Isi nilai aktual dari badChar untuk karakter yang ada
        for (int i = 0; i < size; i++)
        {
            badChar[(int)str[i]] = i;
        }
    }

void boyermoore(sepatu *head, string pat)
    {
        int m = pat.size();
        sepatu *temp = head;
        int count = 0;
        while (temp != NULL)
        {
            int n = temp->idSepatu.size();
            int badChar[NUMBER_CHAR];
            badCharHeuristic(pat, m, badChar);
            int s = 0; // s adalah shift dari pola sehubungan

            while (s <= (n - m))
            {
                int j = m - 1;
                // Kurangi indeks j dari pola sampai karakter dari

                while (j >= 0 && pat[j] == temp->idSepatu[s + j])
                {
                    j--;
                }
                if (j < 0)
                {
                    cout << "___________________________________" << endl;
                    cout << "|" << endl;
                    cout << "|Brand Sepatu       : " << temp->brand << endl;
                    cout << "|Jenis Sepatu       : " << temp->jenis << endl;
                    cout << "|Warna Sepatu       : " << temp->warna << endl;
                    cout << "|Ukuran Sepatu      : " << temp->ukuran << endl;
                    cout << "|Stok Sepatu        : " << temp->stok << endl;
                    cout << "|Harga Sepatu       : " << temp->harga << endl;
                    cout << "|ID Sepatu          : " << temp->idSepatu << endl;
                    cout << "|__________________________________" << endl;
                    count++;
                    break;
                }
                else
                {
                    // Geser pola sehingga karakter yang tidak
                    s += max(1, j - badChar[temp->idSepatu[s + j]]);
                }
            }
            temp = temp->next;
        }
        if (count == 0)
        {
            cout << "data tidak ditemukan" << endl;
        }
    }

int sortingIdsepatu(sepatu *head)
    {
        int pilihan;
        string input;
        hitungPanjangData(head);
        while (pilihan != 3)
        {
            system("cls");
            system("color 02");
            cout << " ___________________________" << endl;
            cout << "|                           |" << endl;
            cout << "|     SORTING ID SEPATU     |" << endl;
            cout << "|___________________________|" << endl;
            cout << "|                           | " << endl;
            cout << "|       1. ASCENDING        |" << endl;
            cout << "|       2. DESCENDING       |" << endl;
            cout << "|       3. KEMBALI          |" << endl;
            cout << "|___________________________|" << endl;
            cout << "Pilihan Anda: ";
            fflush(stdin);
            getline(cin, input);
            stringstream ss(input);
            if (!(ss >> pilihan))
            {
                cout << "Input tidak valid. Masukkan angka dari 1 hingga 3." << endl;
                continue;
            }
            if (pilihan < 1 || pilihan > 3)
            {
                cout << "Pilihan Tidak Ada, Silahkan Masukkan Pilihan 1, 2 atau 3" << endl;
                continue;
            }
            switch (pilihan)
            {
            case 1:
                quickSort(&head, true, 1);
                // dataketxtfile(head);
                tampil(head);
                cout << "Data sepatu telah diurutkan secara Ascending berdasarkan ID sepatu." << endl;
                system("pause");
                break;
            case 2:
                quickSort(&head, false, 1);
                // dataketxtfile(head);
                tampil(head);
                cout << "Data sepatu telah diurutkan secara Descending berdasarkan ID sepatu." << endl;
                system("pause");
                break;
            case 3:
                cout << "Kembali ke Menu Utama" << endl;
                break;
            default:
                cout << "Pilihan tidak valid. Silakan coba lagi." << endl;
            }
        }
        return 0;
    }

int sortingBrand(sepatu *head)
    {
        int pilihan;
        string input;
        hitungPanjangData(head);
        while (pilihan != 3)
        {
            system("cls");
            system("color 02");
            cout << " ___________________________" << endl;
            cout << "|                           |" << endl;
            cout << "|       URUTKAN SEPATU      |" << endl;
            cout << "|___________________________|" << endl;
            cout << "|                           | " << endl;
            cout << "|      1. ASCENDING         |" << endl;
            cout << "|      2. DESCENDING        |" << endl;
            cout << "|      3. KEMBALI           |" << endl;
            cout << "|__________________________ |" << endl;
            cout << "Pilihan Anda: ";
            fflush(stdin);
            getline(cin, input);
            stringstream ss(input);
            if (!(ss >> pilihan))
            {
                cout << "Input tidak valid. Masukkan angka dari 1 hingga 3." << endl;
                continue;
            }
            if (pilihan < 1 || pilihan > 3)
            {
                cout << "Pilihan Tidak Ada, Silahkan Masukkan Pilihan 1, 2 atau 3" << endl;
                continue;
            }
            switch (pilihan)
            {
            case 1:
                quickSort(&head, true, 2);
                // dataketxtfile(head);
                tampil(head);
                cout << "Data sepatu telah diurutkan secara Ascending berdasarkan Umur Sepatu." << endl;
                system("pause");
                break;
            case 2:
                quickSort(&head, false, 2);
                // dataketxtfile(head);
                tampil(head);
                cout << "Data sepatu telah diurutkan secara Descending berdasarkan Umur Sepatu." << endl;
                system("pause");
                break;
            case 3:
                cout << "Kembali ke Menu Utama" << endl;
                break;
            default:
                cout << "Pilihan tidak valid. Silakan coba lagi." << endl;
            }
        }
        return 0;
    }

void Order(Pelanggan **Front, Pelanggan **Rear ,sepatu* &head) 
    {
        tampil(head);
        Pelanggan *dataPelanggan = newPelanggan();
        sepatu* datasepatu = head;
        while (datasepatu != NULL) 
            {
                if (datasepatu->idSepatu == dataPelanggan->data.idSepatu) 
                    {
                        if (datasepatu->stok >= dataPelanggan->jumlah) 
                            {
                                // Sepatu ditemukan dan jumlah yang dibeli masih tersedia dalam stok
                                datasepatu->stok -= dataPelanggan->jumlah;
                                dataPelanggan->hatot = datasepatu->harga * dataPelanggan->jumlah;
                                if (*Front == NULL)
                                    {
                                        *Front = dataPelanggan;
                                    }
                                else
                                    {
                                        (*Rear)->next = dataPelanggan;
                                    }
                                *Rear = dataPelanggan;
                                cout << "Pesanan Diterima. Stok Tersisa : " << datasepatu->stok << endl;
                                system("pause");
                            } 
                        else if (datasepatu->stok > 0) 
                            {
                                cout << "Stok Sepatu " << datasepatu->brand << " tidak cukup untuk memenuhi permintaan. Stok tersisa: " << datasepatu->stok << endl;
                                system("pause");
                            }  
                        else 
                            {
                                cout << "Stok Sepatu " << datasepatu->brand << " telah habis." << endl;
                                system("pause");
                            }
                        return;
                    }
                datasepatu = datasepatu->next;
            }
    

    // Jika Sepatu tidak ditemukan berdasarkan ID
        cout << "Sepatu dengan ID " << dataPelanggan->data.idSepatu << " tidak ditemukan dalam stok." << endl;
        system("pause");
        }




void nota(sepatu *head, Pelanggan *front) 
    {
        Pelanggan *dataPelanggan = front;
        if (dataPelanggan == NULL) 
            {
                cout << "Data pelanggan kosong." << endl;
                system("pause");
                return;
            }
        sepatu *datasepatu = head;
        cout << " ________________________________" << endl;
        cout << "|                                |" << endl;
        cout << "|        Brother's sepatu        |" << endl;
        cout << "|________________________________|" << endl;
        cout << "| Nama Pembeli  : " << setw(14) << left << dataPelanggan->nama << " " << "|" << endl;
        cout << "| Brand Sepatu  : " << setw(14) << left << datasepatu->brand << " " << "|" << endl;
        cout << "| Jenis Sepatu  : " << setw(14) << left << datasepatu->jenis << " " << "|" << endl;
        cout << "| Warna Sepatu  : " << setw(14) << left << datasepatu->warna << " " << "|" << endl;
        cout << "| Ukuran Sepatu : " << setw(14) << left << datasepatu->ukuran << " " << "|" << endl;
        cout << "| Stok Sepatu   : " << setw(14) << left << datasepatu->stok << " " << "|" << endl;
        cout << "| Harga Sepatu  : " << setw(14) << left << datasepatu->harga << " " << "|" << endl;
        cout << "| Jumlah Dibeli : " << setw(14) << left << dataPelanggan->jumlah << " " << "|" <<  endl;
        cout << "| Total Harga   : " << setw(14) << left << dataPelanggan->hatot << " " << "|" <<  endl;
        cout << "__________________________________" << endl;
    }

void TakeOrder(Pelanggan **Front, Pelanggan **Rear, sepatu *head)
    {
        if(*Front == NULL){
            cout << "Tidak Ada Orderan" << endl;
            return;
        }
        Pelanggan *temp = *Front;
        *Front = (*Front)->next;
        nota(head, temp);
        delete temp;
    }

void LihatAntrian(sepatu *head, Pelanggan *Front, Pelanggan *Rear)
    {
        Pelanggan *dataPelanggan = Front;
        sepatu *datasepatu = head;
        int i = 1;
        if (dataPelanggan == NULL)
            {
                cout << "Tidak Ada Antrian" << endl;
                return;
            }
                cout << " ________________________________" << endl;
                cout << "|                                |" << endl;
                cout << "|        Brother's sepatu        |" << endl;
                cout << "|________________________________|" << endl;
                cout << "|                                |" << endl;
                cout << "| Nama Pembeli  : " << setw(14) << left << dataPelanggan->nama << " " << "|" << endl;
                cout << "| Brand Sepatu  : " << setw(14) << left << dataPelanggan->brandBuy << " " << "|" << endl;
                cout << "| Jenis Sepatu  : " << setw(14) << left << dataPelanggan->jenisBuy << " " << "|" << endl;
                cout << "| Warna Sepatu  : " << setw(14) << left << dataPelanggan->warnaBuy << " " << "|" << endl;
                cout << "| Ukuran Sepatu : " << setw(14) << left << datasepatu->ukuran << " " << "|" << endl;
                // cout << "| Stok Sepatu   : " << setw(14) << left << datasepatu->stok << " " << "|" << endl;
                cout << "| Harga Sepatu  : " << setw(14) << left << datasepatu->harga << " " << "|" << endl;
                cout << "| Jumlah Dibeli : " << setw(14) << left << dataPelanggan->jumlah << " " << "|" <<  endl;
                cout << "| Total Harga   : " << setw(14) << left << dataPelanggan->hatot << " " << "|" <<  endl;
                cout << "__________________________________" << endl;
                    dataPelanggan = dataPelanggan->next;
                    datasepatu = datasepatu->next;
                    i++;
            }
    

int sorting(sepatu *head)
    {
        int pilihan;
        string input;
        hitungPanjangData(head);
        while (pilihan != 3)
            {
                system("cls");
                system("color 02");
                cout << " ________________________" << endl;
                cout << "|                        |" << endl;
                cout << "|      MENU SORTING      |" << endl;
                cout << "|________________________|" << endl;
                cout << "|                        | " << endl;
                cout << "|     1. ID Sepatu       | " << endl;
                cout << "|     2. Brand Sepatu    |" << endl;
                cout << "|     3. KEMBALI         |" << endl;
                cout << "|________________________|" << endl;
                cout << "Pilihan Anda: "; fflush(stdin); getline(cin, input);
                stringstream ss(input);
                if (!(ss >> pilihan))
                    {
                        cout << "Input tidak valid. Masukkan angka dari 1 hingga 3." << endl;
                        continue;
                    }
                if (pilihan < 1 || pilihan > 3)
                    {
                        cout << "Pilihan Tidak Ada, Silahkan Masukkan Pilihan 1, 2 atau 3" << endl;
                        continue;
                    }
                switch (pilihan)
                    {
                    case 1:
                        sortingIdsepatu(head);
                        system("pause");
                        break;
                    case 2:
                        sortingBrand(head);
                        system("pause");
                        break;
                    case 3:
                        cout << "Kembali ke Menu Utama" << endl;
                        break;
                    default:
                        cout << "Pilihan tidak valid. Silakan coba lagi." << endl;
                    }
            }
        return 0;
    }


void searchBoyerMoore(sepatu *head)
    {
        string cari;
        hitungPanjangData(head);
        system("cls");
        system("color 02");
        tampil(head);
        cout << " ________________________" << endl;
        cout << "|                        |" << endl;
        cout << "|        PENCARIAN       |" << endl;
        cout << "|________________________|" << endl;
        cout << "|                        |" << endl;
        cout << "| Keterangan:            |" << endl;
        cout << "|    Cari Berdasarkan    |" << endl;
        cout << "|    ID Sepatu           |" << endl;
        cout << "|________________________|" << endl;
        cout << "Masukkan  ID Sepatu Yang Ingin Di Cari : " << endl;
        cout << ">>> ";
        fflush(stdin); getline(cin, cari);
        boyermoore(head, cari);
    }

int searching(sepatu *head) {
    int pilihan = 0; // Menginisialisasi pilihan
    string input;

    hitungPanjangData(head);

    while (pilihan != 2) { // Ubah kondisi agar sesuai dengan opsi yang tersedia
        system("cls");
        system("color 02");
        cout << " _______________________" << endl;
        cout << "|                       |  "<< endl;
        cout << "|     MENU SEARCHING    |  "<< endl;
        cout << "|_______________________|" << endl;
        cout << "|    1. Cari Sepatu     |" << endl;
        cout << "|    2. Kembali         |" << endl;
        cout << "|_______________________|" << endl;
        cout << "Pilihan Anda: " << endl;
        cout << ">>> ";
        
        fflush(stdin);
        getline(cin, input);
        stringstream ss(input);
        
        if (!(ss >> pilihan)) {
            cout << "Input tidak valid. Masukkan angka dari 1 / 2." << endl;
            continue;
        }

        if (pilihan < 1 || pilihan > 2) {
            cout << "Pilihan Tidak Ada, Silahkan Masukkan Pilihan 1 / 2" << endl;
            continue;
        }

        switch (pilihan) {
            case 1:
                searchBoyerMoore(head);
                system("pause");
                break;
            case 2:
                // cout << "Kembali ke Menu Utama" << endl;
                system("pause");
                break;
            default:
                cout << "Pilihan tidak valid. Silakan coba lagi." << endl;
        }
    }
    
    return 0; // Sesuaikan dengan kebutuhan logika program.
}


bool userTxt(string &username, long long &password) 
    {
        ifstream file("users.txt");
        string user;
        long long pass;
        while (file >> user >> pass) 
            {
                if (user == username && pass == password) 
                    {
                        return true;
                    }
            }
        return false;
    }

void txtUser(string &username, long long &password){ //Fungsi untuk melakukan pendaftaran user baru
        ofstream file("users.txt", ios_base::app);
        file << username << " " << password << endl;
}

int menuAdmin()
    {
        int pilihan;
        string input;
        int index;
        while (pilihan != 12){
            system("cls");
            system("color 02");
            cout << " _______________________________" << endl;
            cout << "|                               | " << endl;
            cout << "|         Brother's sepatu      | " << endl;
            cout << "|_______________________________|" << endl;
            cout << "|                               |" << endl;
            cout << "|        1. Tambah Item         |" << endl;
            cout << "|        2. Tampilkan           |" << endl;
            cout << "|        3. Ubah Data           |" << endl;
            cout << "|        4. Hapus Item          |" << endl;
            cout << "|        5. Searching           |" << endl;
            cout << "|        6. Take Order          |" << endl;
            cout << "|        9. Kembali             |" << endl;
            cout << "|_______________________________|" << endl;
            cout << "Pilihan Anda: " << endl;
            cout << ">>> ";
            fflush(stdin);
            getline(cin, input);
            stringstream ss(input);
            if (!(ss >> pilihan))
            {
                cout << "Input tidak valid. Masukkan angka dari 1 hingga 6 dan 9." << endl;
                continue;
            }
            if (pilihan < 1 || pilihan > 10)
            {
                cout << "Pilihan Tidak Ada, Silahkan Masukkan Pilihan 1, 2, 3, 4, 5, 6, dan 9" << endl;
                continue;
            }

            switch (pilihan){
            case 1:
                addFirst(&head);
                txtfilekedata(head);
                system("pause");
                break;
            case 2:
                do {
                    tampil(head);
                    cout << "----------------------------------------------------------------------------------------------------------------- " << endl;
                    cout << "_________________________________________________________________________________________________________________ " << endl;
                    cout << "Urutkan Data Tekan ===>(y/Y)" << endl;
                    cout << "Kembali Tekan ========>(n/N)" << endl;
                    cout << ">>> ";
                    char pilihsort;
                    cin >> pilihsort;
                    if (pilihsort == 'y' || pilihsort == 'Y') {
                        sorting(head);
                        system("pause");
                    } else if (pilihsort == 'n' || pilihsort == 'N') {
                        break;
                    } else {
                        cout << "Input tidak valid. Pilihan yang tersedia hanya: (y/n)" << endl;
                        system("pause");
                        system("cls");
                    }
                } while (true);
                break;
            case 3:
                tampil(head);
                update(&head);
                // dataToTxt(head);
                break;
            case 4:
                if (head != NULL)
                {
                    tampil(head);
                    cout << "Hapus data nomor : ";
                    cin >> index;
                    if (index == 1)
                    {
                        deleteFirst(&head);
                    }
                    else if (index == hitungPanjangData(head))
                    {
                        deleteLast(&head);
                    }
                    else if (index > 1 && index < hitungPanjangData(head))
                    {
                        deleteMiddle(head, index);
                    }
                    else
                    {
                        cout << "Nomor tidak valid!" << endl;
                    }
                    // dataToTxt(head);
                }
                else
                {
                    cout << "Data sepatu Kosong!" << endl;
                }
                break;
            case 5:
                searching(head);
                // dataToTxt(head);
                break;
            case 6:
                char relog;
                LihatAntrian(head, Front, Rear);
                cout << "Konfirmasi Pesanan Pertama? (Y/N): ";
                cin >> relog;
                if (relog == 'y' || relog == 'Y')
                {
                    TakeOrder(&Front, &Rear, head);
                    system("pause");
                } else {
                    break;
                }
                break;
            case 9:
                cout << "Kembali ke Menu Utama" << endl;
                system("pause");
                return 1;
                return 0;
            default:
                cout << "Pilihan tidak valid. Silakan coba lagi." << endl;
            }
        }
        return 0;
    }

// Fungsi untuk menampilkan menu user
int menuUser()
    {
        int pilihan;
        string input;
        while (pilihan != 5){
            system("cls");
            system("color 02");
            cout << " _______________________________" << endl;
            cout << "|                               | " << endl;
            cout << "|           MENU USER           | " << endl;
            cout << "|_______________________________|" << endl;
            cout << "|                               | " << endl;
            cout << "|         1. Lihat Data         |" << endl;
            cout << "|         2. Pesan              |" << endl;
            cout << "|         3. Lihat Antrian      |" << endl;
            cout << "|         9. Logout             |" << endl;
            cout << "|_______________________________|" << endl;
            cout << "Pilihan Anda : "  << endl;
            cout << ">>> ";
            fflush(stdin);
            getline(cin, input);
            stringstream ss(input);
            if (!(ss >> pilihan))
            {
                cout << "Input tidak valid. Masukkan angka dari 1 hingga 4." << endl;
                continue;
            }
            if (pilihan < 1 || pilihan > 9)
            {
                cout << "Pilihan Tidak Ada, Silahkan Masukkan Pilihan 1, 2, 3, dan 9" << endl;
                continue;
            }
            switch (pilihan)
            {
            case 1:
                tampil(head);
                system("pause");
                break;
            case 2:
                Order(&Front, &Rear, head);
                // dataketxtfile(head);
                break;
            case 3:
                LihatAntrian(head, Front, Rear);
                system("pause");
                break;
            case 9:
                cout << "Kembali ke Menu Utama" << endl;
                system("pause");
                return 1;
            default:
                cout << "Pilihan tidak valid. Silakan coba lagi." << endl;
            }   
        }
        return 0;
    }

int signUp()
    {
        bool valid = false;
    // Meminta input username dari user, mengecek apakah username sudah terdaftar
        do 
            {
                system("cls");
                cout << " _____________________" << endl;
                cout << "|                     |" << endl;
                cout << "|       SIGN UP       |" << endl;
                cout << "|_____________________|" << endl;
                cout << "Masukkan Username : " << endl;
                cout << ">>> ";
                fflush(stdin);getline(cin, username);
                if (userTxt(username, password)) 
                    {
                        cout << "Username sudah terdaftar. Silahkan masukkan username lain." << endl;
                    } 
                else 
                    {
                        valid = true;
                    }
            } 
        while (!valid);
        
        // Meminta input password dari user dan konfirmasi password
        do 
            {
                cout << "Masukkan Password : " << endl;
                cout << ">>> ";
                while (!(cin >> password && password > 0))
                    {
                        cout << "Input tidak valid, silahkan masukkan angka!" << endl;
                        cin.clear();
                        cin.ignore(1000, '\n');
                        cout << "Masukkan Password : ";
                    }
                cout << "Konfirmasi Password : " << endl;
                cout << ">>> ";
                while (!(cin >> konfirmasiPass && konfirmasiPass > 0))
                    {
                        cout << "Input tidak valid, silahkan masukkan angka!" << endl;
                        cin.clear();
                        cin.ignore(1000, '\n');
                        cout << "Konfirmasi Password : ";
                    }
                    if (password != konfirmasiPass)
                        {
                            cout << "Password tidak cocok. Silahkan ulang dan masukkan password yang sama pada kedua kolom." << endl;
                            system("pause");
                            signUp();
                        } 
                    else 
                        {
                            valid = true;
                         }
            } 
        while (!valid);
        
        // Mendaftarkan user baru
        txtUser(username, password);
        cout << "Pendaftaran berhasil. Silahkan login dengan username dan password anda." << endl;
        system("pause");
        
        return 0;
    }

int loginAdmin(){
    int kesempatan = 3;
    int login = 0;
    while (kesempatan != 0)
        {
            system("cls");
            cout << " _____________________" << endl;
            cout << "|                     |" << endl;
            cout << "|        ADMIN        |" << endl;
            cout << "|_____________________|" << endl;
            cout << "Masukkan Username : " << endl;
            cout << ">>> ";
            fflush(stdin);getline(cin, admin);
            cout << "Masukkan Password : " << endl;
            cout << ">>> ";
            while (!(cin >> passAdmin && passAdmin > 0))
                {
                    cout << "Input tidak valid, silahkan masukkan angka!" << endl;
                    cin.clear();
                    cin.ignore(1000, '\n');
                    cout << "Masukkan Password : ";
                }
            int i = 0;
            bool found = false;
            while (i < 3 && !found) 
                {
                    if ((adminnya[i] == admin) && (PW[i] == passAdmin))
                        {
                            system("cls");
                            cout << "Anda Berhasil Login" << endl;
                            found = true;
                            cout << "Selamat datang, " << admin << "!" << endl;
                            system("pause");
                            login = menuAdmin();
                        }
                    i++;
                }
                if (login == 1) { // Jika nilai kembali adalah 1 (logout)
                        kesempatan = 0; // Hentikan loop
                    } else {
                        // Tambahkan logika jika ingin memberi kesempatan login kembali
                    }
            if (!found)
                {
                    cout << "Username atau Password yang anda masukkan salah" << endl;
                    system("pause");
                    loginAdmin();
                    kesempatan--;
                }   
        }
    return 0;
}

int loginUser()
    {
        int kesempatan = 3;
        int login = 0;
        while (kesempatan != 0)
            {
                system("cls");
                cout << " ____________________" << endl;
                cout << "|                    |" << endl;
                cout << "|         User       |" << endl;
                cout << "|____________________|" << endl;
                cout << "Masukkan Username : " << endl;
                cout << ">>> ";
                fflush(stdin);getline(cin, username);
                cout << "Masukkan Password : " << endl;
                cout << ">>> ";
                while (!(cin >> password && password > 0))
                    {
                        cout << "Input tidak valid, silahkan masukkan angka!" << endl;
                        cin.clear();
                        cin.ignore(1000, '\n');
                        cout << "Masukkan Password : " << endl;
                        cout << ">>> ";
                    }
                int i = 0;
                bool found = false;
                while (i < 100 && !found) 
                    {
                        if (userTxt(username, password))
                            {
                                cout << "Anda Berhasil Login" << endl;
                                found = true;
                                cout << "Selamat datang, " << username << "!" << endl;
                                system("pause");
                                login = menuUser();
                                // menuUser();
                            }
                        i++;
                    }
                    if (login == 1) { // Jika nilai kembali adalah 1 (logout)
                        char relog;
                        cout << "Anda telah Logout Apakah anda ingin login kembali? (Y/N): ";
                        cin >> relog;
                        if (relog == 'y' || relog == 'Y')
                        {
                            kesempatan = 3;
                            cout << "Silahkan Login Kembali " << endl;
                            system("pause");
                            login = loginUser();
                        } else {
                            return 1;
                            kesempatan = 0; // Hentikan loop
                        }
                    }
                if (!found)
                    {
                        cout << "Username atau Password yang anda masukkan salah" << endl;
                        kesempatan--;
                        system("pause");
                    }
            }
        return 0;
    }

int masuk(){
        int pilihan;
        string input;
        while (pilihan != 3) 
            {
                system("cls");
                cout << " ___________________________________" << endl;
                cout << "|                                   |" << endl;
                cout << "|           LOGIN SEBAGAI           |" << endl;
                cout << "|___________________________________|" << endl;
                cout << "|                                   |" << endl;
                cout << "|            1. ADMIN               |" << endl;
                cout << "|            2. USER                |" << endl;
                cout << "|            3. KEMBALI             |" << endl;
                cout << "|___________________________________|" << endl;
                cout << "Pilihan : " << endl;
                cout << ">>> ";
                fflush(stdin);getline(cin, input);
                stringstream ss(input);
                if (!(ss >> pilihan)) 
                    {
                        cout << "Input tidak valid. Masukkan angka dari 1 hingga 3." << endl;
                        continue;
                    }
                if (pilihan < 1 || pilihan > 3) 
                    {
                        cout << "Pilihan Tidak Ada, Silahkan Masukkan Pilihan 1, 2 atau 3" << endl;
                        continue;
                    }
                switch (pilihan) 
                    {
                        case 1:
                            loginAdmin();
                            break;
                        case 2:
                            loginUser();
                            break;
                        case 3:
                            return 3;
                            break;
                        default:
                            break;
                    }
        }
    return 0;
}

int main() 
    {
        dataketxtfile(head);
        int pilihan;
        string input;

        while (pilihan != 3) 
            {
                system("cls");
                system("color 02");
                cout << " ________________________________________________" << endl;
                cout << "|                                                |" << endl; 
                cout << "|        SELAMAT DATANG DI TOMPEL SHOES          |" << endl;
                cout << "|________________________________________________|" << endl;
                cout << "|                                                |" << endl;
                cout << "|            1. REGISTER (SIGN UP)               |" << endl;
                cout << "|            2. LOGIN    (SIGN IN)               |" << endl;
                cout << "|            3. KELUAR   (EXIT)                  |" << endl;
                cout << "|________________________________________________|" << endl;
                cout << "Pilihan : " << endl;
                cout << ">>> "; 
                fflush(stdin);getline(cin, input);
                stringstream ss(input);
                if (!(ss >> pilihan)) 
                    {
                        cout << "Input tidak valid. Masukkan angka dari 1 hingga 3." << endl; 
                        continue;
                    }
                if (pilihan < 1 || pilihan > 3) 
                    {
                        cout << "Pilihan Tidak Ada, Silahkan Masukkan Pilihan 1, 2 atau 3" << endl;
                        continue;
                    }
                switch (pilihan) 
                    { 
                        case 1:
                            signUp();
                            break;
                        case 2:
                            masuk();
                            break;
                        case 3:
                            cout << "Program Selesai, Terimakasih." << endl;
                            break;
                        default:
                            break;
                    }
            }
        return 0;
    }