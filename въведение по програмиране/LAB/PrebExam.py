import random

def main():
    # --- НАЧАЛО: Генериране на границите a и b ---
    # a е случайно цяло число в интервала [-2500, -1300]
    a = random.randint(-2500, -1300)
    # b е случайно цяло число в интервала [1111, 4444]
    b = random.randint(1111, 4444)

    print(f"Генериран интервал: ({a}; {b}]")
    print("-" * 50)

    # --- (7т.) Вход за n и създаване на mylst_1 ---
    n = 0
    while True:
        try:
            user_input = input("Въведете цяло число n (10 < n < 50): ")
            n = int(user_input)
            
            if 10 < n < 50:
                break
            else:
                print("Грешка: Числото трябва да е по-голямо от 10 и по-малко от 50.")
        except ValueError:
            print("Грешка: Невалиден формат. Моля въведете цяло число.")

    mylst_1 = []
    print(f"\nВъведете {n} на брой числа в интервала ({a}; {b}]:")

    while len(mylst_1) < n:
        try:
            val = int(input(f"Елемент {len(mylst_1) + 1}: "))
            # Интервалът е (a; b], тоест a < val <= b
            if a < val <= b:
                mylst_1.append(val)
            else:
                print(f"-> Числото трябва да е строго по-голямо от {a} и по-малко или равно на {b}.")
        except ValueError:
            print("-> Моля въведете валидно цяло число.")

    print(f"\nСписък mylst_1: {mylst_1}")

    # --- (5т.) Брой на отрицателните елементи, чиято цифра на десетиците е кратна на 4 или 5 ---
    # Цифра на десетиците се намира чрез (abs(num) // 10) % 10
    count_task_2 = 0
    for num in mylst_1:
        if num < 0:
            tens_digit = (abs(num) // 10) % 10
            if tens_digit % 4 == 0 or tens_digit % 5 == 0:
                count_task_2 += 1
    
    print(f"\nБрой отрицателни елементи с цифра на десетиците кратна на 4 или 5: {count_task_2}")

    # --- (5т.) Средно-аритметично на двуцифрените и четни елементи ---
    sum_digits = 0
    count_digits = 0
    
    for num in mylst_1:
        # Проверка дали е двуцифрено (положително или отрицателно) и четно
        if 10 <= abs(num) <= 99 and num % 2 == 0:
            sum_digits += num
            count_digits += 1

    if count_digits > 0:
        avg = sum_digits / count_digits
        print(f"Средно-аритметично на четните двуцифрени числа: {avg:.2f}")
    else:
        print("Няма намерени двуцифрени четни числа в списъка.")

    # --- (5т.) Създаване на mylst_2 (трицифрени и кратни на 3 от mylst_1) ---
    mylst_2 = []
    for num in mylst_1:
        if 100 <= abs(num) <= 999 and num % 3 == 0:
            mylst_2.append(num)
    
    print(f"\nСписък mylst_2 (трицифрени, кратни на 3): {mylst_2}")

    # --- (5т.) Брой на елементите с нечетна стойност на четен индекс в mylst_2 ---
    count_odd_val_even_idx = 0
    # Обхождаме индексите: 0, 2, 4...
    for i in range(0, len(mylst_2), 2):
        if mylst_2[i] % 2 != 0:
            count_odd_val_even_idx += 1
            
    print(f"Брой елементи с нечетна стойност на четен индекс в mylst_2: {count_odd_val_even_idx}")

    # --- (5т.) Замяна на елементите с нечетен индекс в mylst_2 с числото 13 ---
    # Обхождаме индексите: 1, 3, 5...
    for i in range(1, len(mylst_2), 2):
        mylst_2[i] = 13
        
    print(f"Списък mylst_2 след замяната на нечетните индекси с 13: {mylst_2}")

    # --- (5т.) Сравняване на дължините и изтриване на първи и последен елемент от по-дългия ---
    len1 = len(mylst_1)
    len2 = len(mylst_2)

    print("\n--- Сравняване на дължините ---")
    if len1 > len2:
        print("mylst_1 е по-дълъг. Изтриваме първия и последния му елемент.")
        if len(mylst_1) > 0:
            mylst_1.pop(0) # Изтрива първия
        if len(mylst_1) > 0:
            mylst_1.pop()  # Изтрива последния (който вече е нов последен)
    elif len2 > len1:
        print("mylst_2 е по-дълъг. Изтриваме първия и последния му елемент.")
        if len(mylst_2) > 0:
            mylst_2.pop(0)
        if len(mylst_2) > 0:
            mylst_2.pop()
    else:
        print("Двата списъка имат еднаква дължина. Не се изтрива нищо.")

    print(f"Окончателен вид на mylst_1: {mylst_1}")
    print(f"Окончателен вид на mylst_2: {mylst_2}")

if __name__ == "__main__":
    main()

#zad2
class Market:
    def __init__(self, barcod, name, manufacturer, price, quantity):
        self.barcod = barcod
        self.name = name
        self.manufacturer = manufacturer
        self.price = price
        self.quantity = quantity

    # Метод за продажба (4т.)
    def sale(self, qty_to_sell):
        if self.quantity >= qty_to_sell:
            self.quantity -= qty_to_sell
            print(f"Продадени {qty_to_sell} бр. от {self.name}. Остават: {self.quantity}")
        else:
            print(f"Недостатъчно количество! Налични: {self.quantity}")

    # Метод за отстъпка (5т.)
    def discount(self):
        # Ако цената е между 50 и 30 лв. (включително) -> 5% отстъпка
        if 30 <= self.price <= 50:
            self.price = self.price - (self.price * 0.05)
        # Ако цената е между 30 и 10 лв. -> 7% отстъпка
        # (използваме < 30, за да не се застъпва с горното условие при точно 30 лв)
        elif 10 <= self.price < 30:
            self.price = self.price - (self.price * 0.07)
        # В противен случай (под 10 или над 50) няма промяна
        elif self.price < 10 or self.price > 50:
            pass 

    # Метод за красиво принтиране на обекта (за удобство)
    def __str__(self):
        return f"Баркод: {self.barcod} | Продукт: {self.name} | Произв.: {self.manufacturer} | Цена: {self.price:.2f} | Кол.: {self.quantity}"

# --- Функции извън класа (според условието) ---

# Функция за търсене по баркод (5т.)
def search_by_barcod(product_list, search_code):
    found = False
    for product in product_list:
        if product.barcod == search_code:
            print("\n--- Намерен продукт ---")
            print(product)
            found = True
            break # Спираме търсенето, защото сме го намерили
            
    if not found:
        print("\n* Wrong barcode !!!")
        print("Налични баркодове в магазина:")
        # Събираме всички баркодове в списък и ги принтираме
        all_barcodes = [p.barcod for p in product_list]
        print(all_barcodes)

# Функция за търсене по производител и средна цена (5т.)
def search_by_manufacturer(product_list, search_manuf):
    # 1. Намираме всички продукти от този производител
    manuf_products = [p for p in product_list if p.manufacturer == search_manuf]
    
    if not manuf_products:
        return [] # Няма продукти от този производител
    
    # 2. Изчисляваме средната цена на продуктите на този производител
    total_price = sum(p.price for p in manuf_products)
    avg_price = total_price / len(manuf_products)
    
    # 3. Филтрираме тези, които са с цена <= средната
    result_list = [p for p in manuf_products if p.price <= avg_price]
    
    return result_list

# Функция за сортиране по количество (5т.)
def sort_by_quantity(product_list):
    # Сортираме списъка на място (key указва по какво да сравняваме)
    product_list.sort(key=lambda x: x.quantity)
    
    print("\n--- Списък сортиран по количество (възходящ ред) ---")
    for p in product_list:
        print(p)

# Функция за изтриване по име и малко количество (5т.)
def delete_by_name(product_list, product_name):
    # Трябва да обходим списъка отзад-напред, за да трием безопасно елементи
    initial_count = len(product_list)
    
    for i in range(len(product_list) - 1, -1, -1):
        product = product_list[i]
        if product.name == product_name and product.quantity <= 3:
            del product_list[i]
            
    # Проверка дали е изтрито нещо
    if len(product_list) < initial_count:
        print(f"\nИзтрити са продукти с име '{product_name}' и количество <= 3.")
    else:
        print(f"\nНяма намерени продукти за изтриване (или количеството им е > 3).")


# --- ОСНОВНА ПРОГРАМА (Main) ---

product_list = []

# Въвеждане на брой продукти (5т.)
try:
    n = int(input("Въведете брой продукти (n): "))
except ValueError:
    n = 0

for i in range(n):
    print(f"\nВъвеждане на продукт {i+1}:")
    b_code = input("Баркод: ") # Ако искате число, сложете int(), но за баркод string е по-добре
    p_name = input("Име: ")
    p_manuf = input("Производител: ")
    p_price = float(input("Цена: "))
    p_quant = int(input("Количество: "))
    
    obj = Market(b_code, p_name, p_manuf, p_price, p_quant)
    # Прилагаме отстъпката веднага при създаването (по желание) или по-късно
    obj.discount() 
    
    product_list.append(obj)

# --- ДЕМОНСТРАЦИЯ НА ФУНКЦИИТЕ ---

# 1. Търсене по баркод
t_code = input("\nВъведете баркод за търсене: ")
search_by_barcod(product_list, t_code)

# 2. Търсене по производител (цена <= средна)
t_manuf = input("\nВъведете производител за филтриране: ")
filtered_products = search_by_manufacturer(product_list, t_manuf)
print(f"Продукти на '{t_manuf}' с цена под средната:")
for p in filtered_products:
    print(p)

# 3. Изтриване на продукт
del_name = input("\nВъведете име на продукт за изтриване (ако кол. <= 3): ")
delete_by_name(product_list, del_name)

# 4. Сортиране по количество
sort_by_quantity(product_list)
