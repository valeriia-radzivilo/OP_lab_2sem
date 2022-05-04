#include <iostream>
#include "header.cpp"

int main() {
    int a = 1;
    Line*lines[3];
    do {
        Line line_one(1,5, -2, -4);
        cout << "First line"<< endl;
        line_one.print();
        cout <<"Next line: "<< endl;
        Line line_two;
        cout <<"Next line: "<< endl;
        Line line_three;
        cout << endl << "RESULTS:" << endl;
        // check if 2 lines are parallel
        int check = line_one || line_two;
        if (check == 1)
            cout <<"The first line and second one are parallel!!!"<< endl;
        // add 1 to third line's length using ++
        cout<<"Length of third line before addding: " << line_three.getLineLength() << endl;
        cout<<"After adding 1: " << ++line_three << endl;
        // program can be re-used
        cout <<endl << "Do you want to re-run the program?(print '0' if yes): ";
        cin >> a;
    }while(a==0);
    return 0;

}