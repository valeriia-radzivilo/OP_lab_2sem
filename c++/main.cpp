#include <iostream>
#include <windows.h>
#include "header.cpp"
using namespace std;


int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    //setlocale(LC_CTYPE, "ukrainian");
    //setlocale(LC_ALL,"Russian_Russia.1251");
    string input[100];
    int i =0;
    while(true)
    {
    cout <<"Enter a text. Tap enter twice to stop input" << endl;
    get_inp(input,i);
    text_op(input,i);
    }
    


}

