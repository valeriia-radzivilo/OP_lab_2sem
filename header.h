//
// Created by leraz on 26-03-22.
//

#ifndef INC_2LAB_HEADER_H
#define INC_2LAB_HEADER_H
#include <iostream>
#include <fstream>
#include <filesystem>
#include <cstring>

using namespace std;
typedef struct Goods {
    string name;
    string date_made;
    string use_till_date;
    int price;
}Pack;

void get_info(int &goods_amount, string *prod_names,string *prod_date_mades,string *prod_use_till_dates, int *prices);
int make_first_file(struct Goods, int goods_amount, string *prod_names,string *prod_date_mades,string *prod_use_till_dates, int *prices, string first_file);
int date_difference(string date_one, string date_two);
int read_file(string filename, int goods_amount);
void find_data(int goods_amount,string second_file, string *prod_names,string *prod_date_mades,string *prod_use_till_dates, int *prices, string today);
void in_the_last_ten(int goods_amount, string *prod_names,string *prod_date_mades,string *prod_use_till_dates, int *prices, string today);
#endif //INC_2LAB_HEADER_H


