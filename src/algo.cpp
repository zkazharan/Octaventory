#include <chrono> // digunakan pada fungsi sleep()
#include <thread> // digunakan pada fungsi sleep()
#include <time.h> // digunakan pada fungsi get_random_id()

using namespace std;

// menampikan border berupa garis dengan panjang yang sudah ditentukan
void border(int len){
    string bord = "";
    for(int i = 0; i < len; i++){
        bord += 196;
    }
    cout << bord << endl;
}

// memformat parameter berupa string agar berada ditengah dengan panjang yang ditentukan
void center(string text, int len){
    int half_string_len = text.length() / 2;
    int half_output_len = len / 2;
    int spaces = half_output_len - half_string_len;

    for(int i = 0; i < spaces; i++){
        cout << " ";
    }

    cout << text << endl;
}

// menampilkan judul dan border dengan format yang sudah dibuat
void title(string text, int len){
    border(len);
    center(text, len);
    border(len);
}

// fungsi untuk menunggu (pause) agar kode dibawahnya tidak langsung dieksekusi
void sleep(int time){
    this_thread::sleep_for(chrono::milliseconds(time));
}

// menampilkan notifikasi dengan format yang sudah dibuat
void notification(string text, int len, int time){
    string notif = "";
    notif += 175;
    notif += " ";
    notif += text;
    notif += " ";
    notif += 174;
    
    cout << "\n";
    center(notif, len);

    sleep(time);
}

// mengubah parameter yang berupa string menjadi huruf kapital pada awal kata
string capitalize_each_word(string text){

    for(int x = 0; x < text.length(); x++){
        if(x == 0){
            text[x] = toupper(text[x]);
            continue;
        }
        if(text[x-1] == ' '){
            text[x] = toupper(text[x]);
            continue;
        }

        text[x] = tolower(text[x]);
    }

    return text;
}

// mengubah parameter yang berupa string menjadi huruf kapital seluruhnya
string capitalize(string text){

    for(int x = 0; x < text.length(); x++){
        text[x] = toupper(text[x]);
    }

    return text;
}

// mengubah -200000 -> Rp -200.000
string price_formatting_negative(int int_price){
    string str_price = to_string(int_price);
    if(str_price.length() == 5){
        str_price.insert(2, ".");
    }
    else if(str_price.length() == 6){
        str_price.insert(3, ".");
    }
    else if(str_price.length() == 7){
        str_price.insert(4, ".");
    }
    else if(str_price.length() == 8){
        str_price.insert(5, ".");
        str_price.insert(2, ".");
    }
    else if(str_price.length() == 9){
        str_price.insert(6, ".");
        str_price.insert(3, ".");
    }
    else if(str_price.length() == 10){
        str_price.insert(7, ".");
        str_price.insert(4, ".");
    }

    return str_price;
}

// mengubah 50000 -> Rp 50.000
string price_formatting(int int_price){
    string str_price = to_string(int_price);

    if(str_price[0] == '-'){
        str_price = price_formatting_negative(int_price);
        return "Rp " + str_price;
    }


    if(str_price.length() == 4){
        str_price.insert(1, ".");
    }
    else if(str_price.length() == 5){
        str_price.insert(2, ".");
    }
    else if(str_price.length() == 6){
        str_price.insert(3, ".");
    }
    else if(str_price.length() == 7){
        str_price.insert(4, ".");
        str_price.insert(1, ".");
    }
    else if(str_price.length() == 8){
        str_price.insert(5, ".");
        str_price.insert(2, ".");
    }
    else if(str_price.length() == 9){
        str_price.insert(6, ".");
        str_price.insert(3, ".");
    }

    return "Rp " + str_price;
}

// mengubah Rp 100.000 -> 100000
int anti_price(string str_price){
    str_price.erase(0, 3);

    if(str_price.length() == 5){
        str_price.erase(1, 1);
    }
    else if(str_price.length() == 6){
        str_price.erase(2, 1);
    }
    else if(str_price.length() == 7){
        str_price.erase(3, 1);
    }
    else if(str_price.length() == 9){
        str_price.erase(5, 1);
        str_price.erase(1, 1);
    }
    else if(str_price.length() == 10){
        str_price.erase(6, 1);
        str_price.erase(2, 1);
    }
    else if(str_price.length() == 11){
        str_price.erase(7, 1);
        str_price.erase(3, 1);
    }

    return stoi(str_price);
}

// mendapatkan random angka untuk id transaksi 
string get_random_id(){
    string numeric[10] = {"0", "1", "2", "3", "4", "5", "6", "7", "8", "9"};
    string id = "";
    srand(int(time(NULL)));

    for(int i = 1; i <= 4; i++){
        int temp = rand() % 10;
        id += numeric[temp];

        if(i == 4 && id.length() != 4){
            i = 0;
            id = "";
        }
    }
    return id;
}

// memformat int yang berubah menjadi string agar memiliki 0 didepan
string add_zero_in_front_id(int id){
    string str_id = to_string(id);

    if(str_id.length() == 3){
        str_id.insert(0, "0");
    }
    else if(str_id.length() == 2){
        str_id.insert(0, "00");
    }
    else if(str_id.length() == 1){
        str_id.insert(0, "000");
    }

    return str_id;
}