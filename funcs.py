from datetime import datetime


class Event:
    def __init__(self, start_date='None', user_date='None'):
        self.date_ev = start_date
        self.us_date = user_date

    # to count how much time left till the event
    def count_time_left(self, us_date, date_ev):
        dt_user_date = datetime.strptime(us_date, '%H:%M')
        dt_event = datetime.strptime(date_ev, '%H:%M')
        day_left = dt_event - dt_user_date
        if day_left.days < 0:
            return 0
        else:
            return day_left


class Birthday(Event):
    def __init__(self):
        super().__init__()
        self.name = input("Who has a birthday? ")
        self.start_date = input("When is the birthday(e.g 15:40) ")
        self.pers_age = int(input("how old is he/she?"))
        self.meet_place = "Birthday party"

    def print_meet(self):
        print("Name: ", self.name)
        print("Place: ", self.meet_place)
        print("Time: ", self.start_date)


class Meeting(Event):
    def __init__(self):
        super().__init__()
        self.name = input("Name: ")
        self.meet_place = input("Place: ")
        self.start_date = input("Time(e.g 10:00): ")

    def print_meet(self):
        print("Name: ", self.name)
        print("Place: ", self.meet_place)
        print("Time: ", self.start_date)


def get_schedule(numb_meets, taken_times, schedule, bday):
    i = 0
    while i < numb_meets:
        print("Input the meeting info")
        meeting = Meeting()
        if meeting.start_date not in taken_times:
            meeting.us_date = bday
            taken_times.append(meeting.start_date)
            schedule.append(meeting)
            i += 1
        else:
            print("The time is already taken! Try again")


def output_schedule(numb_meets, schedule):
    print("\n Your schedule is:\n")
    for i in range(numb_meets + 1):
        schedule[i].print_meet()
        print('\n')


def last_meet_app(schedule, b_time):
    numb_meets = len(schedule)
    last_meet = schedule[numb_meets - 1]
    time_till_b = last_meet.count_time_left(last_meet.start_date, b_time)
    if time_till_b == 0:
        print("\n Last meet is \n")
        last_meet.print_meet()
        print("The event is after")
    else:
        last_meet = schedule[numb_meets - 2]
        print("\n Last meet is \n")
        last_meet.print_meet()
        time_till_b = last_meet.count_time_left(last_meet.start_date, b_time)
        if time_till_b.total_seconds != 0:
            print("Time till birthday is ", time_till_b)
