#include <iostream>
#include "header.h"
#include <cmath>
#include <cstring>
#include <fstream>

using namespace std;

int amount_of_spaces (string input)
{
    int len = input.length();
    char s[len];
    strcpy(s,input.c_str());
    int count=0;
    for(int i =0; i<len;i++)
    {
        if(s[i] ==' ') count ++;
    }
    return count;
}
void delete_doubles(string &input)
{
    int n = input.find("  ");
    while(n>=0)
    {
        n = input.find("  ");
        if(n>=0)
            input.erase(n,1);
    }
}

void change_line(string &input, int len)
{
    string text = input;


    int text_len = text.length();
    text+=" ";
    if(len>text_len)
    {
        float needToAdd = (float)(len - text_len);
        float spaces = (float)(amount_of_spaces(text) - 1);
        float add =needToAdd / spaces;
        input.erase();
        int n = text.find(" ");
        for(int l =0; l <spaces;l++)
        {
            n = text.find(" ");
            if(n>=0)
            {
                input.append(text,0,n+1);
                for(int i =0;i < (int)add; i++)
                    input +=" ";
                //if(l==0 && floor(add) != add )
                //    input+=' ';
            }
            text.erase(0,n+1);
        }
        input+=text;
    }
}

void get_inp(string *input, int &i)
{
    string enter;
    do{

        getline(cin, enter);
        if(!enter.empty())
        {
            input[i] = enter;
            i++;
        }
    }while(!enter.empty());
}

int text_op(string *input, int i)
{
    fstream usText;
    usText.open("Text.txt");
    if(!usText)
    {
        cout <<"Cannot open the file" << endl;
        return 1;
    }


    int len;
    cout <<"Enter length: ";
    cin >> len;
    cout <<"After: "<< endl;
    for(int j = 0;j<i; j++)
    {
        string changed = input[j];
        delete_doubles(changed);
        change_line(changed, len);
        usText << changed << endl;
        cout << changed << endl;
    }


    usText.close();
    //cout <<"Done"<< endl;
}
