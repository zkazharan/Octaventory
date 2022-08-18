/*
	+------------------------------------------------+
    |    PROGRAM TUGAS STRUKTUR DATA DAN ALGORITMA   |
	|      KELOMPOK 4 2A RPL - Inventaris Produk     |
	+------------------------------------------------+
	|     Azka Ahmad Azharan   -   2101284           |         
	|   Devalino C. Syambara   -   2102325           |
	|          Muhamad Talim   -   2101980           |
	+------------------------------------------------+
*/

#include <iostream>
#include <conio.h>
#include <string>
#include <cstring>
#include "algo.cpp"
#include "header.h"
#include "method.cpp"

using namespace std;

// Prototype Function
int main();
void category();
void edit_item_per_category(int, string);
void item_in_category(int); 
void warehouse();
void edit_item_stock();
void edit_item_stock_page2(int index);
void sales();
void sell_items();

// > 1.1.1.3.1
void add_amount(int index){
	system("cls");

	string add;
	int int_add;

	title("Add Amount", 50);

	print_name_and_amount_with_position(index);

	border(50);

	cout << " Additional Amount : ";
	getline(cin, add);

	try{
		int_add = stoi(add);
	}
	catch(exception &err){
		notification("Input must be an integer", 50, 1500);
		add_amount(index);
		return;
	}

	if(int_add == 0){
		edit_item_stock_page2(index);
		return;
	}

	if(int_add < 0){
		notification("Input incorrect", 50, 1500);
		edit_item_stock();
		return;
	}

	add_amount_method(index, int_add);
	save_data();
	save_history();
	q_add_with_index(index, int_add);
	notification("Amount Updated !", 50, 1500);
	edit_item_stock();
	return;
}

// > 1.1.1.3.2
void reduce_amount(int index){
	system("cls");

	string min;
	int int_min;

	title("Reduce Amount", 50);

	print_name_and_amount_with_position(index);

	border(50);

	cout << " Reduction Amount : ";
	getline(cin, min);

	try{
		int_min = stoi(min);
	}
	catch(exception &err){
		notification("Input must be an integer", 50, 1500);
		reduce_amount(index);
		return;
	}

	if(int_min == 0){
		edit_item_stock_page2(index);
		return;
	}

	if(int_min < 0){
		notification("Input incorrect", 50, 1500);
		edit_item_stock();
		return;
	}

	reduce_amount_method(index, int_min);
	save_data();
	edit_item_stock();
	return;
}

// > 1.1.1.3.3
void remove_item(){
	system("cls");

	string pos;
	int int_pos;

	title("Remove Items", 50);

	if(empty()){
		notification("Empty Data !", 50, 1500);
		main();
		return;
	}

	print_name_list();

	cout << endl << " [0] Back" << endl;

	border(50);

	cout << " Input Number to Delete : ";
	getline(cin, pos);

	try{
		int_pos = stoi(pos);
	}
	catch(exception &err){
		notification("Input must be an integer", 50, 1500);
		remove_item();
		return;
	}

	if(int_pos == 0){
		main();
		return;
	}
	if(int_pos < 0 || int_pos > length()){
		notification("Item not found", 50, 1500);
		remove_item();
		return;
	}

	remove(int_pos);
	save_data();

	notification("Item Removed", 50, 1500);

	main();
	return;
}

// > 1.1.3.1
void edit_item_stock_page2(int index){
	system("cls");

	title("Edit Item Stock", 50);

	print_detail_item_with_position(index);

	border(50);

	cout << " [1] Add Amount" << endl;
	cout << " [2] Reduce Amount" << endl;
	cout << " [3] Delete Item" << endl;
	cout << " [0] Back" << endl;

	border(50);

	cout << " Choose Menu : ";
	getline(cin, menu);

	if(menu == "1"){
		add_amount(index);
		return;
	}
	else if(menu == "2"){
		reduce_amount(index);
		return;
	}
	else if(menu == "3"){
		remove(index);
		save_data();
		notification("Item Removed !", 50, 1500);
		edit_item_stock();
		return;
	}
	else if(menu == "0"){
		edit_item_stock();
		return;
	}
	else{
		notification("Wrong Menu Input !", 50, 1500);
		edit_item_stock_page2(index);
		return;
	}
}

// > 1.1.3
void edit_item_stock(){
	system("cls");

	title("Edit Item Stock", 50);

	if(empty()){
		notification("Empty data !", 50, 1500);
		warehouse();
		return;
	}

	string item;
	int int_item;

	print_name_and_amount();

	cout << " [0] Back" << endl;

	border(50);

	cout << " Choose Item : ";
	getline(cin, item);

	try{
		int_item = stoi(item);
	}
	catch(exception &err){
		notification("Input must be an integer", 50, 1500);
		edit_item_stock();
		return;
	}

	if(int_item == 0){
		warehouse();
		return;
	}

	if(int_item < 0){
		notification("Position input incorrect", 50, 1500);
		edit_item_stock();
		return;
	}

	if(int_item > length()){
		notification("Position input incorrect", 50, 1500);
		edit_item_stock();
		return;
	}

	edit_item_stock_page2(int_item);
	return;
}

// > 1.1.2.7
void input(int pos, string id, string name, string type, int amount, int buy_price, int sell_price){
	system("cls");

	title("Add Items", 50);

	cout << " ID      : " << id << endl;
	cout << " Name    : " << name << endl;
	cout << " Type    : " << type << endl;
	cout << " Amount  : " << amount << endl;
	cout << " Buy     : " << price_formatting(buy_price) << endl;
	cout << " Sell    : " << price_formatting(sell_price) << endl;

	border(50);

	insert(id, name, type, amount, buy_price, sell_price, pos);
	q_add(id, name, type, amount, buy_price);
	s_input(id, to_string(buy_price));
	save_data();
	save_history();
	save_price_item();
	
	notification("Item Added", 50, 1500);
	warehouse();
	return;
}

// > 1.1.2.6
void input_sell(int pos, string id, string name, string type, int amount, int buy_price){
	system("cls");

	string sell;
	int int_sell;

	title("Add Items", 50);

	cout << " ID      : " << id << endl;
	cout << " Name    : " << name << endl;
	cout << " Type    : " << type << endl;
	cout << " Amount  : " << amount << endl;
	cout << " Buy     : " << price_formatting(buy_price) << endl;
	cout << " Sell    : " << endl;

	border(50);

	cout << " Input Sell Price : ";
	getline(cin, sell);

	try{
		int_sell = stoi(sell);
	}
	catch(exception &err){
		notification("Input must be an integer", 50, 1500);
		input_sell(pos, id, name, type, amount, buy_price);
		return;
	}

	if(int_sell < 1){
		notification("Input must be greater than 0", 50, 1500);
		input_sell(pos, id, name, type, amount, buy_price);
		return;
	}

	input(pos, id, name, type, amount, buy_price, int_sell);
	return;
}

// > 1.1.2.5
void input_buy(int pos, string id, string name, string type, int amount){
	system("cls");

	string buy;
	int int_buy;

	title("Add Items", 50);

	cout << " ID      : " << id << endl;
	cout << " Name    : " << name << endl;
	cout << " Type    : " << type << endl;
	cout << " Amount  : " << amount << endl;
	cout << " Buy     : " << endl;
	cout << " Sell    : " << endl;

	border(50);

	cout << " Input Buy Price : ";
	getline(cin, buy);

	try{
		int_buy = stoi(buy);
	}
	catch(exception &err){
		notification("Input must be an integer", 50, 1500);
		input_buy(pos, id, name, type, amount);
		return;
	}

	if(int_buy < 1){
		notification("Input must be greater than 0", 50, 1500);
		input_buy(pos, id, name, type, amount);
		return;
	}

	input_sell(pos, id, name, type, amount, int_buy);
	return;
}

// > 1.1.2.4
void input_amount(int pos, string id, string name, string type){
	system("cls");

	string amount;
	int int_amount;

	title("Add Items", 50);

	cout << " ID      : " << id << endl;
	cout << " Name    : " << name << endl;
	cout << " Type    : " << type << endl;
	cout << " Amount  : " << endl;
	cout << " Buy     : " << endl;
	cout << " Sell    : " << endl;

	border(50);

	cout << " Input amount : ";
	getline(cin, amount);

	try{
		int_amount = stoi(amount);
	}
	catch(exception &err){
		notification("Input must be an integer", 50, 1500);
		input_amount(pos, id, name, type);
		return;
	}

	if(int_amount < 1){
		notification("Input must be greater than 0", 50, 1500);
		input_amount(pos, id, name, type);
		return;
	}

	input_buy(pos, id, name, type, int_amount);
	return;
}

// > 1.1.2.3
void input_type(int pos, string id, string name){
	system("cls");

	string type;

	title("Add Items", 50);

	cout << " ID      : " << id << endl;
	cout << " Name    : " << name << endl;
	cout << " Type    : " << endl;
	cout << " Amount  : " << endl;
	cout << " Buy     : " << endl;
	cout << " Sell    : " << endl;

	border(50);

	cout << " Input type : ";
	getline(cin, type);

	if(type == ""){
		notification("Input can't be empty", 50, 1500);
		input_type(pos, id, name);
		return;
	}

	type = capitalize_each_word(type);

	if(check_type(type) == false && limit == 15){
		notification("Type has reached the limit", 50, 1500);
		input_type(pos, id, name);
		return;
	}

	input_amount(pos, id, name, type);
	return;
}

// > 1.1.2.2
void input_name(int pos, string id){
	system("cls");

	string name;

	title("Add Items", 50);

	cout << " ID      : " << id << endl;
	cout << " Name    : " << endl;
	cout << " Type    : " << endl;
	cout << " Amount  : " << endl;
	cout << " Buy     : " << endl;
	cout << " Sell    : " << endl;

	border(50);

	cout << " Input name : ";
	getline(cin, name);

	if(name == ""){
		notification("Input can't be empty", 50, 1500);
		input_name(pos, id);
		return;
	}

	name = capitalize_each_word(name);

	input_type(pos, id, name);
	return;
}

// > 1.1.2.1
void input_ID(int pos){
	system("cls");

	string id;

	title("Add Items", 50);

	cout << " ID      : " << endl;
	cout << " Name    : " << endl;
	cout << " Type    : " << endl;
	cout << " Amount  : " << endl;
	cout << " Buy     : " << endl;
	cout << " Sell    : " << endl;

	border(50);

	cout << " Input ID : ";
	getline(cin, id);

	if(id == ""){
		notification("Input can't be empty", 50, 1500);
		input_ID(pos);
		return;
	}

	id = capitalize(id);

	if(check_id(id)){
		notification("ID already Exist", 50, 1500);
		input_ID(pos);
		return;
	}
	
	input_name(pos, id);
	return;
}

// > 1.1.2
void add_item(){
	system("cls");

	if(empty()){
		input_ID(1);
		return;
	}

	string pos;
	int int_pos;

	title("Add Items", 50);

	print_name_list();

	cout << endl << " [0] Back" << endl;

	border(50);

	cout << " Input Position Number : ";
	getline(cin, pos);

	try{
		int_pos = stoi(pos);
	}
	catch(exception &err){
		notification("Input must be an integer", 50, 1500);
		add_item();
		return;
	}

	if(int_pos == 0){
		warehouse();
		return;
	}

	if(int_pos < 0){
		notification("Position input incorrect", 50, 1500);
		add_item();
		return;
	}

	input_ID(int_pos);
	return;
}

// > 1.1.1.2
void item_in_category(int index){
	system("cls");

	if(empty() && ctg[0] == ""){
		main();
		return;
	}
	if(empty()){
		category();
		return;
	}

	title("Items in " + ctg[index], 50);

	string * items_id = print_item_in_category(ctg[index]);
	
	border(50);

	cout << " Press enter to back...";

	getline(cin, menu);
	category();
	return;
}

// > 1.1.1
void category(){
	system("cls");

	title("Category", 50);

	if(ctg[0] == ""){
		notification("Empty data !", 50, 1500);
		warehouse();
		return;
	}

	print_ctg();

	cout << " [0] Back" << endl;

	border(50);

	cout << " Choose category : ";
	getline(cin, menu);
	if(menu == ""){
		notification("Input can't be empty", 50, 1500);
		category();
		return;
	}
	
	if(menu == "0"){
		warehouse();
		return;
	}

	try{
		int_menu = stoi(menu);
	}
	catch(exception &err){
		notification("Input must be an integer", 50, 1500);
		category();
		return;
	}

	int_menu--;
	
	if(int_menu < 0){
		notification("Category not found", 50, 1500);
		category();
		return;
	}
	else if(ctg[int_menu] == ""){
		notification("Category not found", 50, 1500);
		category();
		return;
	}
	else if(int_menu >= 15){
		notification("Category not found", 50, 1500);
		category();
		return;
	}

	item_in_category(int_menu);
}

// > 1.1
void warehouse(){
	system("cls");
	
	title("Inventory Management", 50);

	cout << " [1] Category" << endl;
	cout << " [2] Add Items" << endl;
	cout << " [3] Edit Item Stock" << endl;
	cout << " [0] Back" << endl;

	border(50);

	cout << " Choose Menu : ";
	getline(cin, menu);
	if(menu == "1"){
		category();
		return;
	}
	else if(menu == "2"){
		add_item();
		return;
	}
	else if(menu == "3"){
		edit_item_stock();
		return;
	}
	else if(menu == "0"){
		main();
		return;
	}
	else{
		notification("Wrong Menu Input !", 50, 1500);
		warehouse();
		return;
	}
}

// > 1.2
void purchase_history(){
	system("cls");

	title("Recently Purchased", 50);

	if(q_empty()){
		notification("Empty data !", 50, 1500);
		main();
		return;
	}

	q_print();

	border(50);

	cout << " Press enter to back...";

	getline(cin, menu);

	main();
	return;
}

// > 1.3.1.2.2
void success_pay(string id, int qty, string method_payment){
	system("cls");

	title("Transaction Success!", 50);

	string sell_id = get_random_id();

	if(t_first == true){
		root = NULL;
		root = t_insert(root, stoi(sell_id), qty, id, method_payment, t_order);
		save_data_tree();
		t_first = false;
		t_order += 1;
	}
	else{
		t_insert(root, stoi(sell_id), qty, id, method_payment, t_order);
		save_data_tree();
		t_order += 1;
	}

	reduce_amount_method_with_id(id, qty);
	save_data();

	cout << " Transaction ID = " << sell_id << endl;

	border(50);

	cout << " Press enter to continue...";
	getline(cin, menu);

	sales();
	return;
}

// > 1.3.1.2.1
void choose_payment_method(string id, int qty){
	system("cls");

	title("Choose Payment Method", 50);

	print_detail_payment_method(id, qty);

	border(50);

	cout << " [1] Full Payment" << endl;
	cout << " [2] Installment Payment" << endl;
	cout << " [0] Cancel" << endl;

	border(50);
	cout << " Choose Menu : ";
	getline(cin, menu);

	if(menu == "1"){
		success_pay(id, qty, "Full Payment");
		return;
	}
	else if(menu == "2"){
		success_pay(id, qty, "Installment Payment");
		return;
	}
	else if(menu == "0"){
		sell_items();
		return;
	}
	else{
		notification("Wrong Menu Input !", 50, 1500);
		choose_payment_method(id, qty);
		return;
	}
}

// > 1.3.1.2
void sell_items_page2(string id){
	system("cls");

	title("Sell Items", 50);

	print_sales_detail_with_id(id);

	border(50);

	cout << " Input Quantity : ";
	getline(cin, menu);

	try{
		int_menu = stoi(menu);
	}
	catch(exception &err){
		notification("Input must be an integer", 50, 1500);
		sell_items_page2(id);
		return;
	}

	if(int_menu < 1){
		notification("Input must greater than 1", 50, 1500);
		sell_items_page2(id);
		return;
	}
	else if(int_menu > get_amount_with_id(id)){
		notification("Input must less than available", 50, 1500);
		sell_items_page2(id);
		return;
	}

	choose_payment_method(id, int_menu);
	return;
}

// > 1.3.1
void sell_items(){
	system("cls");

	title("Sell Items", 50);

	if(head == NULL){
		notification("Empty data!", 50, 1500);
		sales();
		return;
	}

	print_sales();

	cout << endl << " [#] Back" << endl;

	border(50);

	cout << " Input ID Item : ";
	getline(cin, menu);

	if(menu == "#"){
		sales();
		return;
	}
	
	menu = capitalize(menu);

	if(check_available_id(menu)){
		sell_items_page2(menu);
		return;
	}
	else{
		notification("Wrong ID Input", 50, 1500);
		sell_items();
		return;
	}
}

// > 1.3.2.1
void sold_item_detail(int sell_id){
	system("cls");

	title("Sold Item Details", 50);

	print_transaction_detail_with_id(sell_id);

	border(50);

	cout << " Press enter to back..." << endl;
	getline(cin, menu);

	sales();
	return;
}

// > 1.3.2
void check_sold_items(){
	system("cls");

	title("Check Sold Items", 50);

	cout << " type [#] to back.." << endl;
	cout << " Input Transaction ID : ";
	getline(cin, menu);

	if(menu == "#"){
		sales();
		return;
	}

	try{
		int_menu = stoi(menu);
	}
	catch(exception &err){
		notification("Input must be an integer", 50, 1500);
		check_sold_items();
		return;
	}

	if(!(t_search(root, int_menu))){
		notification("ID not found!", 50, 1500);
		check_sold_items();
		return;
	}

	sold_item_detail(int_menu);
	return;
}

// > 1.3
void sales(){
	system("cls");

	title("Sales", 50);
	cout << " [1] Sell Items" << endl;
	cout << " [2] Check Sold Items" << endl;
	cout << " [0] Back" << endl;

	border(50);

	cout << " Choose Menu : ";
	getline(cin, menu);
	if(menu == "1"){
		sell_items();
		return;
	}
	else if(menu == "2"){
		check_sold_items();
		return;
	}
	else if(menu == "0"){
		main();
		return;
	}
	else{
		notification("Wrong Menu Input !", 50, 1500);
		sales();
		return;
	}
}

// > 1.4
void report(){
	system("cls");
	t_count_total_sold(root);
	q_count_total_price();

	title("Report", 50);

	cout << " Total Price Sold Item      = " << price_formatting(t_total_sold) << endl;
	cout << " Total Price Purchased Item = " << price_formatting(q_total_purchase) << endl;
	cout << " Balance                    = " << price_formatting(t_total_sold - q_total_purchase) << endl;

	border(50);

	cout << " Press enter to back...";
	getline(cin, menu);
	t_total_sold = 0;
	q_total_purchase = 0;
	main();
	return;
}	

// > 1
int main(){
	system("cls");

	if(isstarted == false){
		load_data();
		load_history();
		load_price_item();
		load_data_tree();
		isstarted = true;
	}
	
	title("Octaventory", 50);

	cout << " [1] Warehouse" << endl;
	cout << " [2] Purchase History" << endl;
	cout << " [3] Sales" << endl;
	cout << " [4] Report" << endl;
	cout << " [0] Exit" << endl;

	border(50);

	cout << " Choose Menu : ";
	getline(cin, menu);
	if(menu == "1"){
		warehouse();
		return 0;
	}
	else if(menu == "2"){
		purchase_history();
		return 0;
	}
	else if(menu == "3"){
		sales();
		return 0;
	}
	else if(menu == "4"){
		report();
		return 0;
	}
	else if(menu == "0"){
		return 0;
	}
	else{
		notification("Wrong Menu Input !", 50, 1500);
		main();
		return 0;
	}
}
