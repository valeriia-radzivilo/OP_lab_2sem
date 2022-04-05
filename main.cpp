#include<iostream>
#include<fstream>
#include <ctime>
#include "header.cpp"
using namespace std;


int main() {
    int work = 0;

    do {
        time_t ttime = time(0);
        tm *local_time = localtime(&ttime);
        string today = "0" + to_string(local_time->tm_mday) + ".0" + to_string(1 + local_time->tm_mon) + "." +
                       to_string(1900 + local_time->tm_year);// today's date as string
        Pack Goods;
        int goods_amount = 200;
        string names[goods_amount], date_mades[goods_amount], use_till_dates[goods_amount];
        int prices[goods_amount];
        //get input from user
        get_info(goods_amount, names, date_mades, use_till_dates, prices);
        //create and fill first file with product list
        make_first_file(Goods, goods_amount, names, date_mades, use_till_dates, prices, "product_list.dat");
        //read the file
        read_file("product_list.dat", goods_amount);
        //make new file according to the task
        find_data(goods_amount, "end_of_expiration.dat", names, date_mades, use_till_dates, prices, today);
        cout << endl;
        // print products that were made 10 days or less ago
        in_the_last_ten(goods_amount, names, date_mades, use_till_dates, prices, today);
        cout << "Do you want to do the program again?(print 0 if yes)"<< endl;
        //to re-run the program
        cin >> work;
        cin.ignore();
    }while(work == 0);


    return 0;
}