#include <fstream> // digunakan pada fungsi save_data() dan load_data()

using namespace std;

/*
    ============================ LINKED LIST =============================
    =========================== ARRAY DINAMIS ============================
*/

// mengecek keberadaan linked-list
bool empty(){
    if(head == NULL){
        return true;
    }
    return false;
}

// mendeteksi jika terdapat id yang sama
bool check_id(string id){
    cur = head;

    while(cur != NULL){
        if(id == cur->id){
            return true;
        }
        cur = cur->next;
    }
    return false;
}

// mendeteksi jika terdapat type yang sama
bool check_type(string type){
    cur = head;

    while(cur != NULL){
        if(type == cur->type){
            return true;
        }
        cur = cur->next;
    }
    return false;
}

// mengecek apakah id ada atau tidak
bool check_available_id(string id){
    cur = head;

    while(cur != NULL){
        if(id == cur->id){
            return true;
        }
        cur = cur->next;
    }

    return false;
}

// mengecek dan menginput ctg ke dalam array dinamis
void cin_ctg(){
    string temp_ctg[15];
    limit = 0;

    cur = head;

    while(cur != NULL){
        for(int i = 0; i < 15; i++){
            if(cur->type == temp_ctg[i]){
                break;
            }
            else if(temp_ctg[i] == ""){
                temp_ctg[i] = cur->type;
                limit++;
                break;
            }
        }
        cur = cur->next;
    }

    for(int i = 0; i < 15; i++){
            ctg[i] = temp_ctg[i];
    }
}

// menghitung panjang dari linked-list
int length(){
    cur = head;
    
    int len = 0;

    while(cur != NULL){
        cur = cur->next;
        len++;
    }

    return len;
}

// mendapat kan jumlah amount dengan id
int get_amount_with_id(string id){
    cur = head;

    while(cur != NULL){
        if(id == cur->id){
            return cur->amount;
        }
        cur = cur->next;
    }
    return -1;
}

// membuat linked-list
void create(string id, string name, string type, int amount, int buy_price, int sell_price){
    newn = new Inventory();

    newn->id = id;
    newn->name = name;
    newn->type = type;
    newn->amount = amount;
    newn->buy_price = buy_price;
    newn->sell_price = sell_price;
    newn->next = NULL;
    newn->prev = NULL;

    head = newn;
    tail = newn;

    cin_ctg();
}

// menambah node pada awal linked-list
void pop(string id, string name, string type, int amount, int buy_price, int sell_price){

    if(empty()){
        create(id, name, type, amount, buy_price, sell_price);
        return;
    }
    
    newn = new Inventory();

    newn->id = id;
    newn->name = name;
    newn->type = type;
    newn->amount = amount;
    newn->buy_price = buy_price;
    newn->sell_price = sell_price;
    newn->next = head;
    newn->prev = NULL;

    head->prev = newn;
    head = newn;

    cin_ctg();
}

// menambah node pada akhir linked-list
void push(string id, string name, string type, int amount, int buy_price, int sell_price){

    if(empty()){
        create(id, name, type, amount, buy_price, sell_price);
        return;
    }

    newn = new Inventory();

    newn->id = id;
    newn->name = name;
    newn->type = type;
    newn->amount = amount;
    newn->buy_price = buy_price;
    newn->sell_price = sell_price;
    newn->next = NULL;
    newn->prev = tail;

    tail->next = newn;
    tail = newn;

    cin_ctg();
}

// menambah node pada linked-list dengan paramater posisi
void insert(string id, string name, string type, int amount, int buy_price, int sell_price, int position){

    if(position == 1){
        pop(id, name, type, amount, buy_price, sell_price);
        return;
    }

    if(position > length()){
        push(id, name, type, amount, buy_price, sell_price);
        return;
    }

    newn = new Inventory();

    newn->id = id;
    newn->name = name;
    newn->type = type;
    newn->amount = amount;
    newn->buy_price = buy_price;
    newn->sell_price = sell_price;

    cur = head;

    int loop = 1;

    while(loop < position-1){
        cur = cur->next;
        loop++;
    }

    after = cur->next;

    newn->next = after;
    newn->prev = cur;

    cur->next = newn;
    after->prev = newn;

    cin_ctg();
}

// menghapus sebuah node pada awal linked-list
void shift(){
    del = head;
    
    head = head->next;
    head->prev = NULL;

    delete del;
}

// menghapus sebuah node pada akhir linked-list
void wipe(){
    del = tail;

    tail = tail->prev;
    tail->next = NULL;
    delete del;

}

// hapus sebuah node pada linked-list dengan paramater posisi
void remove(int position){

    if(position == 1 && position == length()){
        head = NULL;
        delete head;
        cin_ctg();
        return;
    }

    if(position == 1){
        shift();
        cin_ctg();
        return;
    }

    if(position == length()){
        wipe();
        cin_ctg();
        return;
    }

    cur = head;

    int loop = 1;

    if(loop < position-1){
        cur = cur->next;
        loop++;
    }

    del = cur->next;
    after = del->next;
    cur->next = after;
    after->prev = cur;

    delete del;

    cin_ctg();
}

// mencetak seluruh nama dan kategori dalam linked-list
void print_name_list(){
    cur = head;

    for(int i = 1; cur != NULL; i++){
        cout << " [" << i << "] " << cur->name << " (" << cur->type << ")" << endl;
        cur = cur->next;
    }
}

// mencetak seluruh nama,kategori dan amount dalam linked-list
void print_name_and_amount(){
    cur = head;

    for(int i = 1; cur != NULL; i++){
        cout << " [" << i << "] " << cur->name << " (" << cur->type << ")" << endl;
        cout << "     Amount : " << cur->amount << endl << endl;
        cur = cur->next;
    }
}

// mencetak sebuah nama, kategori dan amount dalam linked-list dengan parameter posisi
void print_name_and_amount_with_position(int pos){
    cur = head;

    int loop = 1;

    while(loop != pos){
        cur = cur->next;
        loop++;
    }

    cout << " [:] " << cur->name << " (" << cur->type << ")" << endl;
    cout << "     Amount : " << cur->amount << endl << endl;

    return;
}

// mencetak detil dari sebuah item
void print_detail_item_with_position(int pos){
    cur = head;

    int loop = 1;

    while(loop != pos){
        cur = cur->next;
        loop++;
    }

    cout << " ID     : " << cur->id << endl;
    cout << " Name   : " << cur->name << endl;
    cout << " Type   : " << cur->type << endl;
    cout << " Amount : " << cur->amount << endl;
    cout << " Buy    : " << price_formatting(cur->buy_price) << endl;
    cout << " Sell   : " << price_formatting(cur->sell_price) << endl;
}

// mencetak seluruh kategori pada linked-list
void print_ctg(){
    for(int i = 0; i < 15; i++){
        if(ctg[i] == ""){
            continue;
        }
        cout << " [" << i+1 << "] " << ctg[i] << endl;
    }
    cout << endl;
}

// mencetak item didalam kategori dengan parameter type
string * print_item_in_category(string type){
    cur = head;
    int key = 0;
    int index = 0;
    while(cur != NULL){
        if(type == cur->type){
            cout << " [" << (index + 1) << "] ID     : " << cur->id << endl;
            cout << "     Name   : " << cur->name << endl;
            cout << "     Amount : " << cur->amount << endl;
            cout << "     Buy    : " << price_formatting(cur->buy_price) << endl;
            cout << "     Sell   : " << price_formatting(cur->sell_price) << endl << endl;
            
            index++;
        }
        cur = cur->next;
    }
    string * items_id = new string[index];

    cur = head;
    while(cur != NULL){
        if(type == cur->type){
            items_id[key] = cur->id;
            key++;
        }
        cur = cur->next;
    }
    return items_id;
}

// mencetak id dan nama untuk menu sales
void print_sales(){
    cur = head;

    while(cur != NULL){
        cout << " [" << cur->id << "] " << cur->name << endl;
        cur = cur->next;
    }
}

// mencetak detail pada menu sales 2 dengan parameter id
void print_sales_detail_with_id(string id){
    cur = head;

    while(cur != NULL){
        if(id == cur->id){
            cout << " [:] ID        : " << cur->id << endl;
            cout << "     Name      : " << cur->name << endl;
            cout << "     Available : " << cur->amount << endl;
            cout << "     Price     : " << price_formatting(cur->sell_price) << endl;
        }
        cur = cur->next;
    }
}

// mencetak detail pada menu paymnet method dengan parameter id
void print_detail_payment_method(string id, int qty){
    cur = head;

    while(cur != NULL){
        if(id == cur->id){
            cout << " [:] ID          : " << cur->id << endl;
            cout << "     Name        : " << cur->name << endl;
            cout << "     Quantity    : " << qty << endl;
            cout << "     Total Price : " << price_formatting(cur->sell_price * qty) << endl;
        }
        cur = cur->next;
    }
}

// menambah amount pada suatu item di linked-list
void add_amount_method(int pos, int add){
    cur = head;

    int loop = 1;

    while(loop != pos){
        cur = cur->next;
        loop++;
    }

    cur->amount = cur->amount + add;
    return;
}

// mengurangi amount pada suatu item di linked-list
void reduce_amount_method(int pos, int min){
    cur = head;

    int loop = 1;

    while(loop != pos){
        cur = cur->next;
        loop++;
    }

    if(min >= cur->amount){
        notification("Input Incorrect !", 50, 1500);
        return;
    }

    cur->amount = cur->amount - min;
    notification("Amount Updated !", 50, 1500);
    return;
}

// mengurangi amount pada linked list dengan parameter id
void reduce_amount_method_with_id(string id, int min){
    cur = head;

    while(cur != NULL){
        if(id == cur->id){
            cur->amount = cur->amount - min;
            return;
        }
        cur = cur->next;
    }
}

// menghapus sebuah node pada linked-list dengan parameter id
void delete_with_id(string id){
    cur = head;
    
    int pos = 1;

    while(cur != NULL){
        if(id == cur->id){
            remove(pos);
            return;
        }
        pos++;
        cur = cur->next;
    }
}

// mengubah amount item pada linked-list dengan jumlah yang sudah ditentukan
void edit_item_amount(string id, int amount) {
    cur = head;

    while(cur != NULL) {
        if(cur->id == id) {
            break;
        }
        
        cur = cur->next;
    }

    if(cur != NULL) {
        cur->amount = amount;
    }
    return;
}

// menghitung jumlah item dalam sebuah kategori pada linked-list
int total_item_in_category(string type){
    cur = head;

    int count = 0;

    while(cur != NULL){
        if(type == cur->type){
            count++;
        }
        cur = cur->next;
    }

    return count;
}

// save database linked list dengan format txt
void save_data(){
    cur = head;
    ofstream data;
    int count = 1;

    data.open("database/data.txt", ios::trunc);
    while(cur != NULL){
        if(count < 10){
            data << "--------------------------------------------------" << endl;
            data << " [" << count << "] ID     : " << cur->id << endl;
            data << "     Name   : " << cur->name << endl;
            data << "     Type   : " << cur->type << endl;
            data << "     Amount : " << cur->amount << endl;
            data << "     Buy    : " << price_formatting(cur->buy_price) << endl;
            data << "     Sell   : " << price_formatting(cur->sell_price) << endl;
        }
        else{
            data << "--------------------------------------------------" << endl;
            data << " [" << count << "] ID     : " << cur->id << endl;
            data << "      Name   : " << cur->name << endl;
            data << "      Type   : " << cur->type << endl;
            data << "      Amount : " << cur->amount << endl;
            data << "      Buy    : " << price_formatting(cur->buy_price) << endl;
            data << "      Sell   : " << price_formatting(cur->sell_price) << endl;
        }

        cur = cur->next;
        count++;
    }
    data << "-------------------------------------------------- ";
    data.close();
}

// load database linked list dengan format txt
void load_data(){
    ifstream data;
    string id, name, type, temp;
    int amount, buy_price, sell_price, eraselen, count = 1;

    data.open("database/data.txt");
    if(data.fail()){
        return;
    }
    while(!data.eof()){
        getline(data, temp);
        if(temp == "--------------------------------------------------"){
            if(count < 10){
                eraselen = 14;
            }
            else{
                eraselen = 15;
            }
            getline(data, temp);
            temp.erase(0, eraselen);
            id = temp;

            getline(data, temp);
            temp.erase(0, eraselen);
            name = temp;

            getline(data, temp);
            temp.erase(0, eraselen);
            type = temp;

            getline(data, temp);
            temp.erase(0, eraselen);
            amount = stoi(temp);

            getline(data, temp);
            temp.erase(0, eraselen);
            buy_price = anti_price(temp);

            getline(data, temp);
            temp.erase(0, eraselen);
            sell_price = anti_price(temp);

            push(id, name, type, amount, buy_price, sell_price);

            count++;
        }
    }
    data.close();
}

/*
    ============================ QUEUE =============================
*/

// menginputkan parameter data kedalam queue
void q_input(string id, string name, string type, int amount, int buy_price, int top){
    queue[top][0] = id;
    queue[top][1] = name;
    queue[top][2] = type;
    queue[top][3] = to_string(amount);
    queue[top][4] = to_string(buy_price);
    queue[top][5] = to_string(amount * buy_price);
}

// mengecek apakah queue kosong atau tidak
bool q_empty(){
    if(queue[0][0] == ""){
        return true;
    }
    return false;
}

// mengecek apakah queue penuh atau tidak
bool q_full(){
    if(queue[99][0] != ""){
        return true;
    }
    return false;
}

// membuat dan memasukan data pertama pada queue
void q_create(string id, string name, string type, int amount, int buy_price){
    q_top = 0;

    q_input(id, name, type, amount, buy_price, q_top);

    return;
}

// memasukan data pada awal queue
void q_add(string id, string name, string type, int amount, int buy_price){
    if(q_empty()){
        q_create(id, name, type, amount, buy_price);
        return;
    }

    if(q_full()){
        for(int i = 0; i < q_max; i++){
            for(int j = 0; j < q_row; j++){
                queue[i][j] = queue[i+1][j];
            }
        }

        q_input(id, name, type, amount, buy_price, q_top);

        return;
    }

    q_top++;

    q_input(id, name, type, amount, buy_price, q_top);

    return;
}

// mencetak nama, jumlah dan total pada queue
void q_print(){
    int loop = 1;
    for(int i = q_max-1; i >=0; i--){
        if(queue[i][0] != ""){
            cout << " [" << loop << "] " << queue[i][1] << " (" << queue[i][3] << ") = " << price_formatting(stoi(queue[i][5])) << endl;
            loop++;
        }
    }
}

// menambahkan queue dengan parameter position dalam linked list
void q_add_with_index(int pos, int add){
    cur = head;

    int loop = 1;

    while(loop != pos){
        cur = cur->next;
        loop++;
    }

    q_add(cur->id, cur->name, cur->type, add, cur->buy_price);
    
    return;
}

// menghitung jumlah total dari barang yang dibeli
void q_count_total_price(){
    for(int i = 0; i < q_max; i++){
        if(queue[i][0] != ""){
            q_total_purchase += stoi(queue[i][5]);
        }
    }
}

// save database history pembelian dengan format txt
void save_history(){
    cur = head;
    ofstream data;
    int loop = q_top;

    data.open("database/purchase_history.txt", ios::trunc);
    while(loop >= 0){
        if(queue[loop][0] != ""){
            data << "--------------------------------------------------" << endl;
            data << "[-] " << queue[loop][1] << " (" << queue[loop][3] << ") = " << price_formatting(stoi(queue[loop][5])) << endl;
            loop--;
        }
    }
    data << "-------------------------------------------------- " << endl;
}

// memasukkan data txt kedalam queue pada load
void q_load(string name, int amount, int buy_price){
    queue[q_count][0] = "N/A";
    queue[q_count][1] = name;
    queue[q_count][2] = "N/A";
    queue[q_count][3] = to_string(amount);
    queue[q_count][4] = to_string(buy_price);
    queue[q_count][5] = to_string(amount * buy_price);
    
    q_count--;
}

// load database history pembelian dengan format txt
void load_history(){
    ifstream data;
    string name = "", amount = "", total = "", temp;
    int int_amount, int_total, buy_price, index = 4;

    data.open("database/purchase_history.txt");

    if(data.fail()){
        return;
    }
    while(!data.eof()){
        getline(data, temp);
        if(temp == "--------------------------------------------------"){
            q_count += 1;
        }
    }
    q_count--;
    q_top = q_count;
    data.close();

    data.open("database/purchase_history.txt");
    if(data.fail()){
        return;
    }
    while(!data.eof()){
        getline(data, temp);
        if(temp == "--------------------------------------------------"){
            getline(data, temp);
            while(temp[index] != '('){
                index++;
            }
            index--;
            for(int i = 4; i < index; i++){
                name += temp[i];
            }

            index += 2;
            int first_amount = index;
            while(temp[index] != ')'){
                index++;
            }
            for(int i = first_amount; i < index; i++){
                amount += temp[i];
            }

            index += 4;
            int first_total = index;

            for(int i = first_total; i <= temp.length()-1; i++){
                total += temp[i];
            }

            int_amount = stoi(amount);
            int_total = (anti_price(total));
            buy_price = int_total / int_amount;

            q_load(name, int_amount, buy_price);

            name = "";
            amount = "";
            total = "";
            index = 4;
        }
    }
    data.close();
}

/*
    ============================ STACK =============================
*/

// mengecek apakah stack kosong atau tidak
bool s_empty(){
    if(stack[0][0] == ""){
        return true;
    }
    return false;
}

// membuat dan memasukan data pertama kedalam stack
void s_create(string id, string buy_price){
    s_top = 0;

    stack[s_top][0] = id;
    stack[s_top][1] = buy_price;

    return;
}

// memasukan data kedalam stack
void s_input(string id, string buy_price){
    if(s_empty()){
        s_create(id, buy_price);
        return;
    }

    s_top += 1;

    stack[s_top][0] = id;
    stack[s_top][1] = buy_price;

    return;
}

// menghitung jumlah total dari barang yang terjual
void s_count_total_sold(string id, int qty){
    int loop = 0;

    while(loop < s_max){
        if(stack[loop][0] == id){
            int total = stoi(stack[loop][1]) * qty;
            t_total_sold += total;
            return;
        }
        loop++;
    }
}

// save database harga pembelian dengan format txt
void save_price_item(){
    ofstream data;
    int loop = 0;

    data.open("database/db_price_item.txt", ios::trunc);
    while(loop <= s_top){
        if(stack[loop][0] != ""){
            data << "<data>" << endl;
            data << "    <id>" << endl;
            data << "        " << stack[loop][0] << endl;
            data << "    </id>" << endl;
            data << "    <price>" << endl;
            data << "        " << stack[loop][1] << endl;
            data << "    </price>" << endl;
            data << "</data>" << endl;

            loop += 1;
        }
    }
    data.close();
}

// load database harga pembelian dengan format txt
void load_price_item(){
    ifstream data;
    string buy_price;
    string temp, id;

    data.open("database/db_price_item.txt");
    if(data.fail()){
        return;
    }
    while(!data.eof()){
        getline(data, temp);
        if(temp  == "<data>"){
            getline(data, temp);

            getline(data, temp);
            temp.erase(0, 8);
            id = temp;
            getline(data, temp);

            getline(data, temp);

            getline(data, temp);
            temp.erase(0, 8);
            buy_price = temp;
            getline(data, temp);

            getline(data, temp);

            s_input(id, buy_price);
        }
    }
}

/*
    ============================ TREE ==============================
*/

// memasukkan data kedalam node baru pada tree dan mereturn node
Tree* t_newNode(int sell_id, int qty, string item_id, string payment_method, int order){
	Tree* temp = new Tree;

	temp->sell_id = sell_id;
	temp->item_id = item_id;
    temp->qty = qty;
    temp->order = order;
	temp->payment_method = payment_method;

	temp->left = NULL;
	temp->right = NULL;

	return temp;
}

// konsidi untuk menentukan posisi node baru pada tree dengan fungsi rekursi
Tree* t_insert(Tree* root, int sell_id, int qty, string item_id, string payment_method, int order){
	Tree* newnode = t_newNode(sell_id, qty, item_id, payment_method, order);

	Tree* x = root;

	Tree* y = NULL;

	while (x != NULL) {
		y = x;
		if (sell_id < x->sell_id)
			x = x->left;
		else
			x = x->right;
	}

	if (y == NULL)
		y = newnode;

	else if (sell_id < y->sell_id)
		y->left = newnode;

	else
		y->right = newnode;

	return y;
}

// mengecek apakah parameter sell_id terdapat pada tree atau tidak
Tree *t_search(Tree *root, int sell_id){
	if(root == NULL || root->sell_id == sell_id){
	    return root;
    }
	
	if(root->sell_id < sell_id){
	    return t_search(root->right, sell_id);
    }

	return t_search(root->left, sell_id);
}

// mendapatkan item id dengan parameter sell id
string t_get_item_id(int sell_id){
    return t_search(root, sell_id)->item_id;
}

// mendapatkan method payment dengan parameter sell id
string t_get_method_payment(int sell_id){
    return t_search(root, sell_id)->payment_method;
}

// mendapatkan method payment dengan parameter sell id
int t_get_qty(int sell_id){
    return t_search(root, sell_id)->qty;
}

// mendapatkan harga total dengan parameter sell id
int t_get_total_price_with_id(int sell_id){
    string id = t_search(root, sell_id)->item_id;
    int qty = t_search(root, sell_id)->qty;
    int price;

    cur = head;

    while(cur != NULL){
        if(cur->id == id){
            price = cur->buy_price;
            break;
        }
        cur = cur->next;
    }

    return qty * price;
}

// mencetak detail transaksi dengan parameter sell id
void print_transaction_detail_with_id(int sell_id){
    cout << " [:] Transaction ID     : " << add_zero_in_front_id(sell_id) << endl;
    cout << "     Items ID           : " << t_get_item_id(sell_id) << endl;
    cout << "     Quantity           : " << t_get_qty(sell_id) << endl;
    cout << "     Total Paid         : " << price_formatting(t_get_total_price_with_id(sell_id)) << endl;
    cout << "     Payment Method     : " << t_get_method_payment(sell_id) << endl;
}

// melempar variabel price dan qty pada tree ke dalam stack untuk menghitung total penjualan
void t_count_total_sold(Tree *root){
    if(root == NULL){
        return;
    }
    else{
        t_count_total_sold(root->left);
        s_count_total_sold(root->item_id, root->qty);
        t_count_total_sold(root->right);
    }
}

// mengecek data order(urutan) pada tree
Tree *t_search_order(Tree *root, int order){
	if(root == NULL || root->order == order){
	    return root;
    }
	
	if(root->order < order){
	    return t_search(root->right, order);
    }

	return t_search(root->left, order);
}

// fungsi tranversal tree dengan metode in-order
void Inorder(Tree *root, int order){
	if(root == NULL){
		return;
    }
	else{
		Inorder(root->left, order);

		if(root->order == order){
			temp = root;
		}
		Inorder(root->right, order);
	}
}

// save database tree pembelian dengan format txt
void save_data_tree(){
    ofstream data;
    int count = 1;

    data.open("database/db_tree.txt", ios::trunc);
    while(count <= t_order){
        data << "+------------------------------------------------+" << endl;
        Inorder(root, count);
        data << " " << add_zero_in_front_id(temp->sell_id) << endl;
        data << " " << temp->qty << endl;
        data << " " << temp->item_id << endl;
        data << " " << temp->payment_method << endl;
        data << " " << temp->order << endl;

        count++;
    }
    data << "+------------------------------------------------+ ";
    data.close();
}

// load database tree pembelian dengan format txt
void load_data_tree(){
    ifstream data;
    string temp, item_id, method_payment;
    int sell_id, qty, order, count = 1;

    data.open("database/db_tree.txt");

    if(data.fail()){
        return;
    }

    while(!data.eof()){
        getline(data, temp);
        if(temp == "+------------------------------------------------+"){
            getline(data, temp);
            temp.erase(0, 1);
            sell_id = stoi(temp);

            getline(data, temp);
            temp.erase(0, 1);
            qty = stoi(temp);

            getline(data, temp);
            temp.erase(0, 1);
            item_id = temp;

            getline(data, temp);
            temp.erase(0, 1);
            method_payment = temp;

            getline(data, temp);
            temp.erase(0, 1);
            order = stoi(temp);

            if(count == 1){
                root = t_insert(root, sell_id, qty, item_id, method_payment, order);
                t_first = false;
                count++;
            }
            else{
                t_insert(root, sell_id, qty, item_id, method_payment, order);
            }
        }
    }
    data.close();
}