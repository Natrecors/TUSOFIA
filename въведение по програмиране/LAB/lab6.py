# l1 = []
# print("Моля, въведете 12 числа:")
# for i in range(12):
#     n = int(input("Vavedete chislo: "))
#     if n > 0:
#         l1.append(n)

# odd = 0
# for j in l1:
#     if j % 2 == 1:
#         odd += 1
# print(f"Брой на нечетните числа в списъка: {odd}")

# avarage = sum(l1) / len(l1)
# print(f"Средноаритметичната стойност: {avarage}")

# l2 = []
# for k in l1:
#     if k % 2 == 0:
#         l2.append(k)

# l2.sort(reverse=True)
# l2 = l2[:5]
# print(f"Петте най-големи числа, кратни на 2: {l2}")

# l2.sort(reverse=True)
# print(f"Сортиран втори списък в низходящ ред: {l2}")

# del l2[::2]
# print(f"Втори списък след изтриване на елементи с четен индекс: {l2}")

#zad 2 
class ClothesShop:
    def __init__(self, id_num, type_clothe, brand, price, quantity):
        self.id = id_num
        self.type = type_clothe
        self.brand = brand
        self.price = price
        self.quantity = quantity

    def clothe_info(self):
        print(f"ID: {self.id}")
        print(f"Type: {self.type}")
        print(f"Brand: {self.brand}")
        print(f"Price: {self.price}")
        print(f"Quantity: {self.quantity}")

    def change_price(self):
        new_price = float(input("Enter new price: "))
        self.price = new_price

    def change_qty(self):
        new_qty = int(input("Enter new quantity: "))
        self.quantity = new_qty

def search_by_id(clothes_list, id_num):
    for item in clothes_list:
        if item.id == id_num:
            item.clothe_info()
            return
    print("Не е открит такъв продукт")

def search_by_brand(clothes_list, brand):
    for item in clothes_list:
        if item.brand == brand:
            item.clothe_info()

def sell_clothe_by_id(clothes_list, id_num, num):
    for item in clothes_list:
        if item.id == id_num:
            if item.quantity >= num:
                item.quantity = item.quantity - num
                print("Успешна продажба")
            else:
                print("Недостатъчна наличност")
            return
    print("Не е открит такъв продукт")

item1 = ClothesShop(1, "T-shirt", "Nike", 50, 100)
item2 = ClothesShop(2, "Jeans", "Zara", 80, 50)
item3 = ClothesShop(3, "Jacket", "Adidas", 120, 20)

clothes_list = [item1, item2, item3]

search_by_id(clothes_list, 1)
search_by_brand(clothes_list, "Zara")
sell_clothe_by_id(clothes_list, 1, 5)

#zad 3
import random

l1 = []
for i in range(20):
    n = random.randint(-100, -1)
    l1.append(n)

print(f"Генериран списък: {l1}")

max_num = max(l1)
print(f"Най-голямото число е: {max_num}")

total_sum = sum(l1)
print(f"Сумата на числата е: {total_sum}")

l2 = []
for k in l1:
    if k % 3 == 0:
        l2.append(k)
print(f"Числата кратни на 3: {l2}")

l2.sort()
print(f"Сортиран втори списък във възходящ ред: {l2}")

del l2[1::2]
print(f"Втори списък след изтриване на елементи с нечетен индекс: {l2}")


#zad 4
class Market:
    def __init__(self, barcode, name, manufacturer, price, quantity):
        self.barcode = barcode
        self.name = name
        self.manufacturer = manufacturer
        self.price = price
        self.quantity = quantity

    def product_info(self):
        print(f"Баркод: {self.barcode}")
        print(f"Име: {self.name}")
        print(f"Производител: {self.manufacturer}")
        print(f"Цена: {self.price}")
        print(f"Количество: {self.quantity}")

    def change_barcode(self):
        new_barcode = input("Въведете нов баркод: ")
        self.barcode = new_barcode

    def change_quantity(self):
        new_quantity = int(input("Въведете ново количество: "))
        self.quantity = new_quantity

def search_by_barcode(product_list, barcode):
    found = False
    for item in product_list:
        if item.barcode == barcode:
            item.product_info()
            found = True
            break
    if not found:
        print("Не е открит такъв продукт")

def search_by_man(product_list, manufacturer):
    print(f"--- Продукти на {manufacturer} ---")
    for item in product_list:
        if item.manufacturer == manufacturer:
            print(f"{item.name} - Цена: {item.price}")

def sell_product_by_name(product_list, name, num):
    found = False
    for item in product_list:
        if item.name == name:
            found = True
            if item.quantity >= num:
                item.quantity = item.quantity - num
                print("Успешна продажба")
            else:
                print("Недостатъчна наличност")
            break
    
    if not found:
        print("Не е открит такъв продукт")

p1 = Market(111, "Mlyako", "Vereya", 2.50, 20)
p2 = Market(222, "Shokolad", "Milka", 3.00, 50)
p3 = Market(333, "Voda", "Bankya", 1.20, 100)

product_list = [p1, p2, p3]

print("\n--- Търсене по баркод ---")
search_by_barcode(product_list, 222)

print("\n--- Търсене по производител ---")
search_by_man(product_list, "Vereya")

print("\n--- Продажба на продукт ---")
sell_product_by_name(product_list, "Mlyako", 5)
sell_product_by_name(product_list, "Shokolad", 100)
sell_product_by_name(product_list, "Hlyab", 1)