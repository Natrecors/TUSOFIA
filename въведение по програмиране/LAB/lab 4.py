
# функция която приема като слисик ot 5 аргумрнта и 1 число, тази функция трябда да промени стойностите >=2рия аргумент да са =1, а вс <1 да са равни на 0 . след това да върне новия списък
# def modify_values(a, b, c, d, e, num):
#     values = [a, b, c, d, e]
#     new_list = []

#     for i in values:
#         if i >= num:
#             new_list.append(1)
#         elif i < 1:
#             new_list.append(0)
#         else:
#             new_list.append(i)

#     return new_list
# print(modify_values(1, 2, 3, 4, 5, 2))  

# функоя приемащ цяло число >2 въдеене от потредитлея, на база това трябда да се създае списък от 1 до това число каато  на база този списък  да се създане речник където ключовете са числата от списъка а стойностите . функцията да върне речника 1:n i n:1
# def create_mirror_dict():
#     n = int(input("Въведете цяло число >2: "))
#     if n <= 2:
#         print("Числото трябва да е по-голямо от 2.")
#         return {}
    
#     numbers = list(range(1, n+1))
#     print("Списъкът от 1 до n е:", numbers)
    
#     mirror_dict = {num: numbers[-(i+1)] for i, num in enumerate(numbers)}
    
#     print("Огледален речник:", mirror_dict)
#     return mirror_dict

# create_mirror_dict()


# def my_function(name, /):
#   print("Hello", name)

# my_function("Emil")



# for i in range(5):
#     num = input()
#     l1.append(num)
# print(l1)


# празен скисък и поебиеля въвежда 5 числа и ги добавя в списъка и да се премахват нечятните числа
l1 = []
for i in range(5):
    num = int(input("Въведете число: "))
    l1.append(num)
print("Първоначален списък:", l1)
l1 = [x for x in l1 if x % 2 == 0]

print("Списък след премахване на нечетните числа:", l1)