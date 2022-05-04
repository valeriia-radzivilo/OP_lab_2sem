#include "header.h"

Birthday::Birthday() {
    cout << "Who has a birthday? ";
    getline(cin, name);
    cout <<"What time does it start? ";
    getline(cin, time);
    cout << "How old is he/she? ";
    cin >> age;

}
void Meeting::SetMeeting() {
    cout << "Name: ";
    getline(cin, name);
    cout << "Place: ";
    getline(cin, place);
    cout << "Time: ";
    getline(cin, time);
}


void Meeting::printMeeting() {
    cout << "Name: "<< name<< endl;
    cout << "Place: "<< place <<endl;
    cout << "Time: "<< time << endl;
}

void Birthday::printBirthday() {
    cout << "Name: "<< name<< endl;
    cout << "Place: "<< place <<endl;
    cout << "Time: "<< time << endl;
}

int find_time(string* all_meets, Meeting meet, int total)
{
    for(int i=0;i<total;i++)
    {
        if(all_meets[i]==meet.time)
        {
            return 1;
        }
    }
}

void Meeting::MakeMeeting(string name_meet, string place_meet, string time_meet) {
    this->name = name_meet;
    this->place = place_meet;
    this->time = time_meet;
}

void Event::time_till(string time_start, string time_till) {
    int hours = string_to_hours(time_start) - string_to_hours(time_till);
    int minutes = string_to_minutes(time_start) - string_to_minutes(time_till);
    if(hours > 0 && minutes<0)
    {
        hours --;
        minutes += 60;
    }
    if (hours >=0 && minutes>=0){
        cout << "There are "<< hours <<" hours  "<< minutes<< " minutes left"<< endl;
    }
    if(hours<0 && minutes < 0)
    {
        cout << "The event has passed "<< endl;
    }

}

int string_to_hours(string time)
{
    int result;
    if (stoi(time.substr(0,1)) == 0)
    {
        result = stoi(time.substr(1,2));
    }
    else {
        result = stoi(time.substr(0, 2));
    }
    return result;
}
int string_to_minutes(string time)
{
    int result;
    if (stoi(time.substr(3,1)) == 0)
    {
        result = stoi(time.substr(3,1));
    }
    else {
        result = stoi(time.substr(3, 2));
    }
    return result;
}
void sort_schedule(Meeting *schedule, int amount)
{
    Meeting tmp;
    for(int j =0; j < amount;j++) {
        for (int i = 0; i < amount-1; i++) {
            if (string_to_hours(schedule[i].time) > string_to_hours(schedule[i + 1].time)) {
                tmp = schedule[i];
                schedule[i] = schedule[i + 1];
                schedule[i + 1] = tmp;
            }
            if (string_to_hours(schedule[i].time) == string_to_hours(schedule[i + 1].time)) {
                if (string_to_minutes(schedule[i].time) > string_to_minutes(schedule[i + 1].time)) {
                    tmp = schedule[i];
                    schedule[i] = schedule[i + 1];
                    schedule[i + 1] = tmp;
                }
            }
        }
    }
}

void schedule_output(Meeting * all_meets, int iterator)
{
    cout << endl << "Your schedule "<< endl;
    for (int i = 0; i < iterator; i++) {
        all_meets[i].printMeeting();
    }
}

void make_schedule(int start_point, int iterator, string *all_time_meets, Meeting *all_meets, int total){
    for (int i = 0; i < iterator; i++) {
        cout << "Enter meeting info " << endl;
        Meeting meet;
        meet.SetMeeting();
        if (find_time(all_time_meets, meet, total) != 1) {
            all_meets[start_point] = meet;
            all_time_meets[start_point] = meet.time;
            start_point++;
        } else {
            cout << "The time is already taken! Try again" << endl;
            i--;

        }
    }
}

void last_meet(Meeting * all_meets, int total_amount, Birthday birth) {
    if (string_to_hours(birth.time) != string_to_hours(all_meets[total_amount - 1].time) &&
        string_to_minutes(birth.time) !=
        string_to_minutes(all_meets[total_amount - 1].time)) {
        all_meets[total_amount - 1].printMeeting();
        cout << "Time till b-day: " << endl;
        all_meets[total_amount - 1].time_till(birth.time, all_meets[total_amount - 1].time);

    }
    else{
            all_meets[total_amount - 2].printMeeting();
            cout << "Time till b-day: " << endl;
            all_meets[total_amount - 2].time_till(birth.time, all_meets[total_amount - 2].time);
    }

}