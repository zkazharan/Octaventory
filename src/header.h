/*
    File ini berisi data yang akan hanya di deklarasikan satu kali,
    oleh karena itu menggunakan ekstensi .h atau header
*/

// inisialisasi struct double linked-list
struct Inventory{
    string id, name, type;
    int amount, buy_price, sell_price;

    Inventory *next, *prev;
};

// deklarasi variabel operasi double linked-list
Inventory *head, *tail, *newn, *cur, *del, *after;

// deklarasi array dinamis
string *ctg = new string[15];

// variabel pembantu
string menu;
int int_menu;
int limit;

// variabel pembatas agar hanya load data 1 kali
bool isstarted = false;

// deklarasi jumlah maksimal data secara konstan pada queue
const int q_max = 100;
const int q_row = 6;

// inisialisasi queue
string queue[q_max][q_row];

// deklarasi top pada queue
int q_top;

// variabel pembantu untuk fungsi load history
int q_count = 0;

// variabel untuk menghitung total pembelian
int q_total_purchase = 0;

// deklarasi jumlah masksimal data secara konstan pada stack
const int s_max = 100;
const int s_row = 2;

// inisialisasi stack
string stack[s_max][s_row];

// deklarasi top pada stack
int s_top;

// inisialisasi struct tree
struct Tree {
	int sell_id, qty, order;
	string item_id, payment_method;

	Tree *left, *right;
};

// deklarasi variabel operasi pada tree
Tree *root, *temp;

// variabel pembantu untuk load tree agar tetap berurutan
int t_order = 1;

// variabel untuk create tree
bool t_first = true;

// variabel untuk menghitung total penjualan
int t_total_sold = 0;