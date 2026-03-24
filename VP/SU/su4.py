# # #part 1
# # #zad 1
# # nums = list(map(int, input("Задача 1 - Въведете числа: ").split()))

# # if nums:
# #     max_num = nums[0]
# #     for x in nums:
# #         if x > max_num:
# #             max_num = x
# #     print(f"Най-голямото число е: {max_num}")
# # else:
# #     print("Списъкът е празен.")
    
# # #zad 2   
# # words = input("Задача 2 - Въведете думи: ").split()

# # long_words = []
# # for word in words:
# #     if len(word) > 5:
# #         long_words.append(word)

# # print(f"Думи по-дълги от 5 букви: {long_words}")
    
# #zad 3
# # list1 = input("Задача 3 - Въведете първия списък: ").split()
# # list2 = input("Задача 3 - Въведете втория списък: ").split()

# # common_elements = []
# # for item in list1:
# #     if item in list2 and item not in common_elements:
# #         common_elements.append(item)

# # print(f"Общи елементи: {common_elements}")

# # #zad 4
# # nums = list(map(int, input("Задача 4 - Въведете числа: ").split()))

# # evens = []
# # odds = []  

# # for x in nums:
# #     if x % 2 == 0:
# #         evens.append(x)
# #     else:
# #         odds.append(x)

# # print(f"Четни: {evens}")
# # print(f"Нечетни: {odds}")

# # # zad 5
# # nums = list(map(int, input("Задача 5 - Въведете числа: ").split()))

# # if nums:
# #     average = sum(nums) / len(nums)
# #     print(f"Средна стойност: {average}")

# #     result = [x for x in nums if x > average]
# #     print(f"Числа по-големи от средното: {result}")

# # # zad 6
# # nums = list(map(int, input("Задача 6 - Въведете числа: ").split()))
# # limit = int(input("Въведете минималната граница (дадена стойност): "))

# # if nums:
# #     average = sum(nums) / len(nums)
# #     result = [x for x in nums if x < average and x > limit]
    
# #     print(f"Средна стойност: {average}")
# #     print(f"Елементи (по-големи от {limit} и по-малки от {average}): {result}")

# # # zad 7
# # def find_max_number(numbers_list):
# #     if not numbers_list:
# #         return None
# #     return max(numbers_list)

# # user_input = list(map(int, input("Задача 7 - Въведете числа: ").split()))
# # print(f"Максимумът е: {find_max_number(user_input)}")

# # # zad 8
# # def sum_greater_than_ten(numbers_list):
# #     total = 0
# #     for x in numbers_list:
# #         if x > 10:
# #             total += x
# #     return total

# # user_input = list(map(int, input("Задача 8 - Въведете числа: ").split()))
# # print(f"Сумата на числата > 10 е: {sum_greater_than_ten(user_input)}")

# # # zad9 
# # def count_evens(numbers_list):
# #     count = 0
# #     for x in numbers_list:
# #         if x % 2 == 0:
# #             count += 1
# #     return count

# # user_input = list(map(int, input("Задача 9 - Въведете числа: ").split()))
# # print(f"Брой на четните числа: {count_evens(user_input)}")

# # # zad 10
# # word1 = input("Задача 10 - Първа дума: ").strip().lower()
# # word2 = input("Задача 10 - Втора дума: ").strip().lower()

# # if sorted(word1) == sorted(word2):
# #     print("Думите СА анаграми.")
# # else:
# #     print("Думите НЕ са анаграми.")

# # # zad 11
# data = input("Задача 11 - Въведете елементи: ").split()
# n = len(data)
# sublists = []

# for i in range(n):
#     for j in range(i + 1, n + 1):
#         sublist = data[i:j]
#         sublists.append(sublist)

# print("Всички подсписъци са:")
# for s in sublists:
#     print(s)

# # # part 2

class Account:
    def __init__(self, account_number, balance, pin):
        self.account_number = account_number
        self.balance = float(balance)
        self.pin = pin

    def deposit(self, amount):
        if amount > 0:
            self.balance += amount
            print(f"Успешно депозирахте {amount:.2f} лв.")
        else:
            print("Сумата трябва да е положителна.")

    def withdraw(self, amount, pin):
        if pin != self.pin:
            print("Грешен ПИН код!")
            return
        
        if amount <= 0:
            print("Сумата трябва да е положителна.")
            return

        if self.balance - amount < 0:
            print("Недостатъчна наличност!")
        else:
            self.balance -= amount
            print(f"Успешно изтеглихте {amount:.2f} лв.")

    def get_account_info(self):
        print(f"Номер на сметката: {self.account_number}")
        print(f"Баланс: {self.balance:.2f}")

acc_num = input("Номер на сметката: ")
start_bal = float(input("Начален баланс: "))
acc_pin = input("ПИН код: ")

my_account = Account(acc_num, start_bal, acc_pin)

while True:
    print("==================")
    print("МЕНЮ")
    print("==================")
    print("1. Депозит")
    print("2. Теглене")
    print("3. Инфо за сметката")
    print("4. Изход")
    print("==================")
    
    choice = input("Въведете номер на операция: ")

    if choice == '1':
        amount = float(input("Депозит: "))
        my_account.deposit(amount)
    
    elif choice == '2':
        amount = float(input("Сума за теглене: "))
        pin_attempt = input("ПИН код: ")
        my_account.withdraw(amount, pin_attempt)
    
    elif choice == '3':
        my_account.get_account_info()
    
    elif choice == '4':
        print("Довиждане!")
        break
    
    else:
        print("Невалидна операция. Опитайте отново.")

# # зад 2 
# class Restaurant:
#     def __init__(self, name, address):
#         self.name = name
#         self.address = address
#         self.menu = []  

#     def add_menu_item(self, dish_name, dish_price):
#         """Помощен метод за добавяне на ястие в менюто"""
#         self.menu.append({'name': dish_name, 'price': float(dish_price)})

#     def get_order_data(self):
#         number_of_table = input("Номер на маса: ")
#         ordered_dishes_str = input("Поръчани ястия (разделени със запетая): ")
        
#         ordered_dishes = [dish.strip() for dish in ordered_dishes_str.split(',')]
        
#         return (number_of_table, ordered_dishes)

#     def calculate_order_value(self, order):
#         ordered_dishes = order[1]
#         order_value = 0.0
        
 
#         for dish_name in ordered_dishes:
#             for menu_item in self.menu:
#                 if menu_item['name'] == dish_name:
#                     order_value += menu_item['price']
                    
#         return order_value

#     def generate_receipt(self, order):
#         number_of_table = order[0]
#         ordered_dishes = order[1]
#         total_value = self.calculate_order_value(order)

#         print("\n\t**Регистрация/Касов бон**")
#         print(f"Ресторант: {self.name}")
#         print(f"Адрес: {self.address}")
#         print(f"Поръчка № {number_of_table}")
        

#         for dish_name in ordered_dishes:
#             found = False
#             for menu_item in self.menu:
#                 if menu_item['name'] == dish_name:
#                     print(f"* {menu_item['name']} : {menu_item['price']:.2f} лв.")
#                     found = True
#             if not found:
#                  print(f"* {dish_name} : (Не е намерено в менюто)")

#         print(f"Общо: {total_value:.2f} лв.")


# rest_name = input("Име на ресторанта: ")
# rest_address = input("Адрес: ")
# restaurant = Restaurant(rest_name, rest_address)


# while True:
#     d_name = input("Име на ястие: ")
#     d_price = input("Цена на ястие: ")
#     restaurant.add_menu_item(d_name, d_price)
    
#     cont = input("Искате ли да въведете още ястия? (Y/N): ")
#     if cont.upper() != 'Y':
#         break
# current_order = restaurant.get_order_data()
# restaurant.generate_receipt(current_order)

