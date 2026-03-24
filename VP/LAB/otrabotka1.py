#1 ZAD
def area_square(a):
    return a * a

def area_rectangle(a, b):
    return a * b

def area_triangle(a, h):
    return (a * h) / 2

figure = int(input("Изберете фигура (1-квадрат, 2-правоъгълник, 3-прав. триъгълник): "))

if figure == 1:
    a = float(input("Въведете страна a: "))
    print("Лице на квадрата:", area_square(a))

elif figure == 2:
    a = float(input("Въведете страна a: "))
    b = float(input("Въведете страна b: "))
    print("Лице на правоъгълника:", area_rectangle(a, b))

elif figure == 3:
    a = float(input("Въведете страна a: "))
    h = float(input("Въведете височина h: "))
    print("Лице на триъгълника:", area_triangle(a, h))

else:
    print("Невалиден избор!")
#2 ZAD
def is_palindrome(n):
    n = str(n)
    if n == n[::-1]:
        return 1
    else:
        return 0


num = int(input("Въведете число: "))
print("Палиндром ли е?: ", is_palindrome(num))

#3 ZAD
def add(a, b):
    return a + b

def subtract(a, b):
    return a - b

def multiply(a, b):
    return a * b

def divide(a, b):
    if b == 0:
        return "Грешка: деление на нула!"
    return a / b

op = input("Въведете операция (+, -, *, /): ")

a = int(input("Първо число: "))
b = int(input("Второ число: "))

if op == "+":
    print("Резултат:", add(a, b))
elif op == "-":
    print("Резултат:", subtract(a, b))
elif op == "*":
    print("Резултат:", multiply(a, b))
elif op == "/":
    print("Резултат:", divide(a, b))
else:
    print("Невалидна операция!")

#4zad
def greater_than(lst, num):
    for i in range(len(lst)):
        if lst[i] > num:
            lst[i] = 0
    return lst


numbers = [1, 5, 8, 3, 10, 2]
limit = 4
print(greater_than(numbers, limit))
