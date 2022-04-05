import pickle as pk
from datetime import date, datetime, timedelta


def make_product_list(filename):
    goods_amount = int(input("How much products do you want to add?"))
    product = []
    product_info = []
    for i in range(goods_amount):
        name = input("Name: ")
        release_date = input("Release date: ")
        expirat_date = input("Expiration date: ")
        price = input("Price: ")
        product = [name, release_date, expirat_date, price]
        product_info.append(product)
    file = open(filename, 'wb')
    pk.dump(product_info, file)
    file.close()


def read_file(filename):
    print("The file " + filename)
    f = open(filename, 'rb')
    products_data = pk.load(f)
    f.close
    for product in products_data:
        print("Name: " + str(product[0]))
        print("Release date: " + str(product[1]))
        print("Expiration date: " + str(product[2]))
        print("Price: " + str(product[3]))


def transfer_data_expiration(from_file, to_file):
    d1 = datetime.today()
    print("Today is :" + str(d1))
    f = open(from_file, 'rb')
    products_data = pk.load(f)
    f.close
    suitable_prod = []
    suitable_prod_info = []
    for product in products_data:
        release = product[1]
        expire = product[2]
        dt_start = datetime.strptime(release, '%d.%m.%Y')
        dt_end = datetime.strptime(expire, '%d.%m.%Y')
        allowed_time = dt_end - dt_start
        if d1 > dt_end:
            substr = d1 - dt_end
        else:
            substr = dt_end - d1
        if allowed_time / 10 > substr:
            print(product[0] + " fits " + str(allowed_time / 10) + " - " + str(substr))
            suitable_prod = [product[0], product[1], product[2], product[3]]
            suitable_prod_info.append(suitable_prod)
    file = open(to_file, 'wb')
    pk.dump(suitable_prod_info, file)
    file.close()


def info_ten_days(filename):
    print("Products made in the last 10 days: ")
    f = open(filename, 'rb')
    products_data = pk.load(f)
    f.close
    d1 = datetime.today()
    for product in products_data:
        release = product[1]
        dt_start = datetime.strptime(release, '%d.%m.%Y')
        days_made = d1 - dt_start
        if days_made <= timedelta(days=10):
            print("Name: " + str(product[0]))
            print("Release date: " + str(product[1]))
            print("Expiration date: " + str(product[2]))
            print("Price: " + str(product[3]))

def dopys(): #to re-run the program
    while True:
        answ = input("Press yes if you want to add and no if you don`t:  ")
        if answ == "yes":
            make_product_list("product_list_py.dat")
            read_file("product_list_py.dat")
            print("Finding products")
            transfer_data_expiration("product_list_py.dat", "almost_expired_py.dat")
            print("NEW FILE:")
            read_file("almost_expired_py.dat")
            info_ten_days("product_list_py.dat")
        if answ != "yes":
            break
