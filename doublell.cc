#include <iostream>

using namespace std;

struct UserData
{
    string userNameStruct, emailStruct, pwStruct;
    int idUser;

    UserData *prev, *next;
} *head, *tail, *cur, *newNode, *del;

// Printing Node pada Double LL
// cur merupakan istilah yang digunakan untuk node yang akan dituju sekarang.

// initiliaze Double Linked List (DLL)
void initDLL(string data[], int dataINT[])
{
    head = new UserData();
    head->userNameStruct = data[0];
    head->emailStruct = data[1];
    head->pwStruct = data[2];
    head->idUser = dataINT[0];
    head->prev = NULL;
    head->next = NULL;
    tail = head;
}

// Data yang sudah dibuat, bisa di print disini.
void printDLL()
{
    // node1 diganti menjadi head karena node awal merupakan head.
    cur = head;
    while (cur != NULL)
    {
        cout << "Nama User: " << cur->userNameStruct << endl;
        cout << "Email User: " << cur->emailStruct << endl;
        cout << "Password User: " << cur->pwStruct << endl;
        cout << "ID User: " << cur->idUser << endl;

        // step untuk printing selanjutnya
        cur = cur->next;
    }
}
// todo: tambahkan node ini ke fitur utama.
// karena ada kondisi percabangan yang dapat mengisi
void addnewHeadDLL(string newHeadString[], int newHeadINT[])
{
    if (head == NULL)
    {
        cout << "\nNode Pertama Belum dibuat!\n";
    }
    else
    {
        cout << "Isi data: \n";

        newNode = new UserData();
        newNode->userNameStruct = newHeadString[0];
        newNode->emailStruct = newHeadString[1];
        newNode->pwStruct = newHeadString[2];
        newNode->idUser = newHeadINT[0];
        newNode->prev = NULL;
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }
}

// todo: create a standalone DLL

// data awal
string newData[] = {
    "Helion Bambangsyah",
    "Dinomorphling",
    "Nedina Teja",
};

int newINTData[] =
    {
        121,
};

// data setelah ditambahkan ke head.
string newHeadData[] = {
    "Salomon",
    "Monsta",
    "Saryuja",
};

int newHeadINTData[] =
    {
        222,
};

int main()
{

    int ya;
    initDLL(newData, newINTData);

    printDLL();

    addnewHeadDLL(newHeadData, newHeadINTData);

    printDLL();

    cout << "create new node?\n";
    switch (ya)
    {
    case 1:

        
        break;

    default:
        break;
    }
}