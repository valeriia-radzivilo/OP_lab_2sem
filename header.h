
#ifndef CPP_HEADER_H
#define CPP_HEADER_H
#include <iostream>
using namespace std;
class Event
{
public:
    string time;
    string date;
public:
    void time_till(string time_start, string time_till);
};

class Birthday: public Event{
public:
    string name;
    int age;
    string place = "Birthday party";
public:
    Birthday();
    void printBirthday();
};

class Meeting: public Event{
private:
    string name;
    string place;
public:
    void MakeMeeting(string name, string place, string time);
    void SetMeeting();
    void printMeeting();

};
int find_time(string* all_meets, Meeting meet, int iterator);
int string_to_hours(string time);
int string_to_minutes(string time);
void sort_schedule(Meeting *schedule, int amount);
void schedule_output(Meeting * all_meets, int iterator);
void make_schedule(int start_point, int iterator, string *all_time_meets, Meeting *all_meets, int total);










#endif //CPP_HEADER_H
