//
// Created by leraz on 28-03-22.
//

#ifndef CPP_HEADER_H
#define CPP_HEADER_H
#include <iostream>
using namespace std;
class Worker{
    string PIB;
    string date_employed;
public:
    Worker(string x,string y)
    {
        PIB = x;
        date_employed = y;
    };
    void print();
    int worked_for(string date_employed, string user_date);

};
void find_worker(string user_date);

string user_year();
void make_worker_list(string &PIB, string &date_employed);
int date_difference(string date_one, string date_two);
#endif //CPP_HEADER_H
