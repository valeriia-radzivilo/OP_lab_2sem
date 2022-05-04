from datetime import datetime

import funcs

a = 'y'
schedule = []
taken_times = []
user_date_inp = input("What date do you want? (e.g 10.05.2022) ")
birthday = funcs.Birthday()
b_time = birthday.start_date
numb_meets = 0
taken_times.append(b_time)
# add birthday event to the schedule
schedule.append(birthday)
while a != 'n':
    # the amount of times program has to ask info about Meetings
    iterations = 0
    iterations += int(input("How much meetings do you want? "))
    # amount of all Meetings
    numb_meets += iterations
    # create schedule
    funcs.get_schedule(iterations, taken_times, schedule, birthday.us_date)
    # sort the schedule to be more user-friendly
    schedule.sort(key=lambda x: x.start_date)
    # output user's schedule sorted by time
    funcs.output_schedule(numb_meets, schedule)
    # last meeting
    funcs.last_meet_app(schedule, b_time)
    if numb_meets == 0:
        numb_meets += 1
    # the schedule can be extended
    a = input("Do you want to append your schedule? (print 'n' if no)  ")
