#include "header.h"

void get_amount(int &amount)
{
    cout <<"How much employees do you have?  ";
    cin >> amount;
}

void make_worker_list(string &PIB, string &date_employed)
{
    cin.ignore();
    cout << "Enter Name Surname Patronymic: "<< endl;
    getline(cin, PIB);
    cout << "Enter the date employed(example 10-25-2020(mm-dd-yyy)) "<< endl;
    getline(cin, date_employed);
}

string user_year() {
    cout << "Enter the date(mm-dd-yyyy): ";
    string date;
    cin.ignore();
    getline(cin, date);
    return date;
}

int Worker::worked_for(string date_employed, string user_date) {
    int worked = date_difference(user_date, date_employed);
    return abs(worked);
}


int date_difference(string date_one, string date_two)
{
    int month_one = stoi(date_one.substr(0,2));
    int day_one = stoi(date_one.substr(3,2));
    int year_one = stoi(date_one.substr(6,4));
    int month_two = stoi(date_two.substr(0,2));
    int day_two = stoi(date_two.substr(3,2));
    int year_two = stoi(date_two.substr(6,4));

    //calc
    int year_dif;
    int month_dif;
    int day_dif;
    year_dif=year_two-year_one;
    month_dif=month_two-month_one;
    day_dif=day_two-day_one;

    //case if dd is negative i.e. current dd is less than first date
    if(day_dif<0)
    {
        month_dif--;
        day_dif+=30;
    }

    //case if mm is negative i.e. current mm is less than first  date
    if (month_dif<0)
    {
        year_dif--;
        month_dif+=12;
    }
    int result;
    result = year_dif * 365 + month_dif * 30 + day_dif;
    return result;
}

void Worker::print() {
    cout << "Info: "<< endl;
    cout << "PIB: " << PIB << endl;
    cout << "Date employed: "<< date_employed << endl;
}