#include <iostream>
#include "header.cpp"
using namespace std;
int main() {
    int amount;
    get_amount(amount);
    Worker*pers[amount];//making array of Workers
    string worker_most;
    int worked[amount];
    int max_work;
    string user_date = user_year();
    do {
        for (int i = 0; i < amount; i++) {

            string PIB, date;
            make_worker_list(PIB, date);
            Worker worker_pers(PIB, date);
            pers[i] = &worker_pers; //write an object int array
            pers[i]->print();
            worked[i] = pers[i]->worked_for(date, user_date);
            cout << "Worked till the date for: " << worked[i] << endl;
            max_work = worked[0];
            if (worked[i] >= max_work) {
                max_work = worked[i];
                worker_most = PIB;
            }
        }
        cout << endl << "THE RESULT" << endl;
        cout << " Worked the most: " << worker_most << endl;
        cout << "He/she worked for: " << max_work << " days" << endl;
    } while (true);
    return 0;



}
