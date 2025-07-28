import datetime
import threading
import time

date = datetime.date(2025, 1, 2)
today = datetime.date.today()
random_time = datetime.time(hour=23, minute=59, second=59)
now = datetime.datetime.now()

now = now.strftime("%H:%M:%S %d-%m-%y")

target_datetime = datetime.datetime(2026, 1, 2, 12, 30, 1)
current_datetime = datetime.datetime.now()

if current_datetime < target_datetime:
    print("Target date is in the future")
else:
    print("Target date is in the past")

def add_sprinkles(func):
    def wrapper():
        func()
        print("And sprinkles!")
    return wrapper

@add_sprinkles
def get_ice_crem():
    print("Here is your ice crem")

get_ice_crem()


def walk_dog(first, last):
    time.sleep(8)
    print(f"Walking the dog {first} {last}")

def take_out_trash():
    time.sleep(2)
    print("Take out trash")

def get_mail():
    time.sleep(4)
    print("Here is your mail")

# threads
chore1 = threading.Thread(target=walk_dog, args=("Scooby", "Doo"))
chore2 = threading.Thread(target=take_out_trash)
chore3 = threading.Thread(target=get_mail)

chore1.start()
chore2.start()
chore3.start()

chore1.join()
chore2.join()
chore3.join()

print("All done")