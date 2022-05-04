#include "header.cpp"

int main()
{
    int a = 10;
    cout << "On which day do you want to make a schedule? ";
    string date;
    getline(cin, date);
    Birthday birth;
    // for code to be reusable
    int total_amount= 0;
    // all times that we have meetings on
    string all_time_meets[100];
    // list of all meetings
    Meeting all_meets[100];
    int zap = 0;
    int start = 0;

    do {
        zap++;
        cin.ignore();
        cout << "How much meetings do you have? ";
        int iterator;
        cin >> iterator;
        start+=total_amount-1;
        if(zap == 1)
        {
            // add birthday to both meets and times
            all_meets[0].MakeMeeting(birth.name, birth.place,birth.time);
            all_time_meets[0] = birth.time;
            start = 1;
        }
        cin.ignore();

        total_amount+=iterator;
        //create schedule
        make_schedule(start, iterator,all_time_meets,all_meets, total_amount);
        if(zap==1)
        {
            iterator++;
            total_amount++;
        }

        // sort schedule by time
        sort_schedule(all_meets, total_amount);
        // schedule output
        schedule_output(all_meets, total_amount);
        // last meet
        cout << endl << "The last meeting:" << endl;
        last_meet(all_meets, total_amount, birth);
        cout << "Do you want to extend your schedule? (print '0' if no)"<< endl;
        cin >> a;
    } while (a!=0);



}
