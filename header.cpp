#include "header.h"


void get_info(int &goods_amount, string *prod_names,string *prod_date_mades,string *prod_use_till_dates, int *prices)
{
    string to_end;

    int i = 0;
    do {
        string prod_name;
        cout << "Enter product name: ";
        getline(cin, prod_name);
        prod_names[i] = prod_name;
        string prod_date_made;
        do {
            cout << "Enter product release date: ";
            getline(cin, prod_date_made);
        } while (prod_date_made.length() != 10);
        prod_date_mades[i] = prod_date_made;
        string prod_use_till_date;
        do {
            cout << "Enter product expiration date: ";
            getline(cin, prod_use_till_date);
        } while (prod_use_till_date.length() != 10);
        prod_use_till_dates[i] = prod_use_till_date;
        int prod_price;
        cout << "Enter product price: ";
        cin >> prod_price;
        prices[i] = prod_price;
        cout <<"Press Ctrl +P to end"<< endl;
        cin.ignore();
        getline(cin, to_end);
        i++;
    }while(to_end.find(16)==string::npos);
    goods_amount = i;
}
int make_first_file(struct Goods, int goods_amount, string *prod_names,string *prod_date_mades,string *prod_use_till_dates, int *prices, string first_file)
{
    ofstream wf(first_file, ios::out | ios::binary | ios::app);
    if(!wf) {
        cout << "Cannot open file!" << endl;
        return 1;
    }
    Goods prod[goods_amount];
    for(int i =0; i < goods_amount; i++)
    {
        prod[i].name = prod_names[i];
        prod[i].date_made = prod_date_mades[i];
        prod[i].use_till_date = prod_use_till_dates[i];
        prod[i].price = prices[i];

    }

    for(int i = 0; i < goods_amount; i++)
        wf.write((char *) &prod[i], sizeof(Goods));
    wf.close();
    if(!wf.good()) {
        cout << "Error occurred at writing time!" << endl;
        return 1;
    }

}

int read_file(string filename, int goods_amount)
{
    ifstream rf(filename, ios::in | ios::binary);
    if(!rf) {
        cout << "Cannot open file!" << endl;
        return 1;
    }
    Goods rprod[goods_amount];
    for(int i = 0; i < goods_amount; i++)
        rf.read((char *) &rprod[i], sizeof(rprod[i]));
    rf.close();
    if(!rf.good()) {
        cout << "Error occurred at reading time!" << endl;
        return 1;
    }
    cout<<"Good's Details:"<<endl;
    for(int i=0; i < goods_amount; i++) {
        cout << "Name: " << rprod[i].name << endl;
        cout << "Release date: " <<rprod[i].date_made << endl;
        cout << "Expiration date: " << rprod[i].use_till_date << endl;
        cout << "Price: " << rprod[i].price << endl;
        cout << endl;
    }
}

void find_data(int goods_amount,string second_file, string *prod_names,string *prod_date_mades,string *prod_use_till_dates, int *prices, string today)
{
    Goods prod[goods_amount];
    ofstream file_b2(second_file, ios::binary);
    int j =0;
    for(int i =0; i< goods_amount; i++)
    {
        string release = prod_date_mades[i];
        string expir = prod_use_till_dates[i];
        int can_use = date_difference(release,expir) / 10;
        int till_today = abs(date_difference(expir, today));
        if (can_use > till_today) {
            prod[j].name = prod_names[i];
            prod[j].date_made = prod_date_mades[i];
            prod[j].use_till_date = prod_use_till_dates[i];
            prod[j].price = prices[i];
            j++;
        }
    }
    for(int i = 0; i < j; i++)
        file_b2.write((char *) &prod[i], sizeof(Goods));
    file_b2.close();
    Goods pr;
    ifstream file_b(second_file, ios::binary);
    cout << "NEW FILE:"<< endl;
    while(file_b.read((char*)&pr, sizeof (Goods)))
    {
        cout << pr.name << " - " << pr.date_made << " - "<<pr.use_till_date << " - "<<pr.price << endl;
    }
}


int date_difference(string date_one, string date_two)
{
    int day_one = stoi(date_one.substr(0,2));
    int month_one = stoi(date_one.substr(3,2));
    int year_one = stoi(date_one.substr(6,4));
    int day_two = stoi(date_two.substr(0,2));
    int month_two = stoi(date_two.substr(3,2));
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

void in_the_last_ten(int goods_amount, string *prod_names,string *prod_date_mades,string *prod_use_till_dates, int *prices, string today) {
    Goods prod;
    cout <<"LIST OF PRODUCTS MADE IN THE LAST 10 DAYS:" << endl;
    for (int i = 0; i < goods_amount; i++) {
        string release = prod_date_mades[i];
        int made = date_difference(release, today);
        if (made <= 10) {
            cout << prod_names[i] << endl;
            cout << prod_date_mades[i] << endl;
            cout << prod_use_till_dates[i] <<endl;
            cout << prices[i] << endl;
        }
    }
}

