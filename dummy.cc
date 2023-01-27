#include <iostream>
#include <sstream>

using namespace std;
// test

struct Database
{
    string nama, jenis;
    int harga, kuota;

    Database *Next;
};

struct NoDatabase
{
    int nimDB;
    Database *NextDB;
};

Database *head, *tail, *cur, *newNode, *del;
NoDatabase *headNDB, *tailNDB;
int harga, kuota;

string nama, jenis;
string tanggalLahir;
int NIM;

int pINT;
char isdone, isinsertLast;
int perhitungan = harga * kuota;

// void postSingleList(string nama, string jenis, int kuota, int NIM)
// {
//     headNDB = new NoDatabase;
//     head->nama = nama;
//     head->jenis = jenis;
//     head->tanggalLahir = tanggalLahir;
//     headNDB->nimDB = NIM;
//     head->Next = NULL;
//     tail = head;
// };

void defaultStock()
{
    head = new Database;

    head->nama = "pir";
    head->jenis = "buah";
    head->harga = 100;
    head->kuota = 10;
    head->Next = newNode;
    cout << "Nama Produk: " << cur->nama
         << "\tJenis Produk: " << cur->jenis
         << "\tJumlah Produk:\t" << cur->kuota
         << "\tHarga: \t" << cur->harga
         << endl;
    cur = cur->Next;
}

void addNodeFirst(string nama, string jenis, int harga, int kuota)
{
    newNode = new Database;
    newNode->nama = nama;
    newNode->jenis = jenis;
    newNode->kuota = kuota;
    newNode->harga = harga;
    newNode->Next = head;
    head = newNode;
}

void addNodeLast(string nama, string jenis, int kuota, int NIM)
{
    newNode = new Database;
    newNode->nama = nama;
    newNode->jenis = jenis;
    newNode->kuota = kuota;
    newNode->harga = NIM;
    tail->Next = NULL;
    tail = newNode;
}

void deleteNodeHead()
{
    del = head;
    head = head->Next;
    head = NULL;
    delete del;
}

void deleteNodeTail()
{
    del = tail;
    cur = head;
    while (cur->Next != tail)
    {
        cur = cur->Next;
    }
    tail = cur;
    tail->Next = NULL;

    delete del;
}

void readList()
{
    // current = head of Node
    cur = head;

    if (cur == NULL)
    {
        // cout << "Database masih kosong\n";
    }

    if (cur != NULL)
    {
        while (cur != NULL)
        {
            cout << "Nama Produk: " << cur->nama
                 << "\tJenis Produk: " << cur->jenis
                 << "\tJumlah Produk:\t" << cur->kuota
                 << "\tHarga: \t" << cur->harga
                 << endl;
            cur = cur->Next;
        }
    }
}

void searchAndUpdate()
{
    cur = head;

    if (cur == NULL)
    {
        cout << "User is not found or not yet created";
    };

    while (cur != NULL)
    {
        cin >> cur->nama;
        cout << "Nama User: " << cur->nama << "\t"
             << "Jurusan: " << cur->jenis << "\t"
             << "Tanggal Lahir: " << cur->kuota << endl;
        cout << "NIM: " << cur->harga << endl
             << endl;
        cur = cur->Next;
        cur->Next = cur;
    }
}

void transaksiBarang(Database *cur, string nama, int kuota)
{
    cout << "================= Transaksi ===================\n";
    cout << "Masukan Produk yang ingin dibeli\n";

    // cur->harga = harga;
    // cur->kuota = kuota;

    cin >> nama;
    cin >> kuota;
    // cin >> cur->kuota;

    // perhitungan;

    cout << "Harga totalnya adalah: " << cur;
}

void tambahBarangView()
{
    system("cls");
    cout << "================= Tambah Produk ===================\n"
         << "Masukan Nama Produk :\n";
    cin >> nama;
    cout << "Jenis Produk:\n";
    cin >> jenis;
    cout << "Harga Produk:\n";
    cin >> harga;
    cout << "Jumlah/Kuantitas Produk:\n";
    cin >> kuota;

    cout << "Ingin memasukan pada antrian awal? (y/n)";

    cin >> isinsertLast;

    switch (isinsertLast)
    {
    case 'y':
        addNodeFirst(nama, jenis, harga, kuota);
        break;
    case 'n':
        // addNodeLast(nama, jenis, harga, kuota);
        defaultStock();
        // main();
        // break;

    default:
        break;
    }
}
int main()
{
    system("cls");

    cout << "========================================\n";
    cout << "\t\tToko ATK\t\t\n";
    cout << "========================================\n";
    cout << "Daftar Barang\n";
    cout << "1. Daftar Barang\n"
         << "2. Tambah Barang\n"
         << "3. Hapus Barang\n"
         << "4. Cari Barang\n"
         << "5. Transaksi\n"
         << "6. Keluar\n";

    cin >> pINT;

    switch (pINT)
    {
    case 1:
        system("cls");
        cout << "================= Daftar Barang ===================\n";
        readList();
        cout << "Kembali ke menu utama?\n";
        cin >> isdone;
        (isdone == 'y') ? main() : main();
        // main();

        break;
    case 2:
        tambahBarangView();
        main();
        break;

    case 3:
        system("cls");
        cout << "================= Hapus Barang ===================\n";
        deleteNodeHead();
        main();
        break;

    case 4:
        system("cls");
        cout << "================= Cari & Perbarui Barang ===================\n";
        searchAndUpdate();
        main();
        break;
    case 5:
        transaksiBarang(cur, nama, kuota);
        // main();
        break;

    case 6:
        cout << "Tekan enter 2 kali untuk keluar\n";
        break;

    default:
        break;
    }
}
