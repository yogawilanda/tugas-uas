#include <iostream>
#include <cstdlib>

using namespace std;

enum JenisUser
{
    premium,
    reguler,
    gratisan
};

struct DataUser
{
    int uniqueID;
    string UserName;
    JenisUser jenisUser;
    DataUser *NodeSelanjutnya;
};

DataUser *awal, *akhir, *sekarang, *nodeBaru, *hapusNode;


void menuUtama();
void postDummy(string, int, JenisUser);
void addNodeFirst(string, JenisUser, int);
void readList();

int IDuserController = rand() % 10;
int  pilihanMenu;
string UsernameController;
int main()
{
    menuUtama();
}

void menuUtama()
{
    cout << "1. Lihat daftar menu hosting\n"
         << "2. Pesan Hosting\n"
         << "3. Hapus Pesanan\n"
         << "4. Cari Pesanan Terbaru\n"
         << "5. Checkout Barang\n"
         << "6. Keluar Dari Aplikasi\n";

    cin >> pilihanMenu;

    switch (pilihanMenu)
    {
    case 1:
        readList();
        main();

        break;
    case 2:
        // postDummy(UsernameController, IDuserController, JenisUser(pilihanMenu));
        // addNodeFirst(UsernameController, JenisUser(pilihanMenu), IDuserController);
        addNodeFirst(UsernameController,  JenisUser(pilihanMenu), IDuserController);
        main();
        break;
    case 3:

        break;
    case 4:

        break;
    case 5:
        break;

    default:
        break;
    }
}

void postDummy(string namaUser, int uniqueID, enum JenisUser)
{
    cin >> namaUser;
    awal = new DataUser;
    // assign user ke DataUser yang diberi nama awal
    awal->UserName = namaUser;
    awal->uniqueID = uniqueID;
    awal->jenisUser = JenisUser(3);
    // awal akan diberikan ruang yang tidak 
    // memiliki kemungkinan untuk membuat node baru setelahnya
    awal->NodeSelanjutnya = NULL;
    akhir = awal;
}

void addNodeFirst(string namaUser,enum JenisUser, int uniqueID )
{
    cin >> namaUser;
    nodeBaru = new DataUser;
    nodeBaru->UserName = namaUser;
    nodeBaru->uniqueID = uniqueID;
    nodeBaru->NodeSelanjutnya = awal;
    awal = nodeBaru;
}

void readList()
{
    sekarang = awal;

    if (sekarang == NULL)
    {
        cout << "Database masih kosong\n";
    }
    
    if (sekarang != NULL)
    {
        while (sekarang != NULL)
        {
            cout << "Nama User: " << sekarang->UserName << endl;
            cout << "UniqueID: " << sekarang->uniqueID  << endl;
            cout << "NIM: " << sekarang->jenisUser << endl
                 << endl;
            sekarang = sekarang->NodeSelanjutnya;
        }
    }
}