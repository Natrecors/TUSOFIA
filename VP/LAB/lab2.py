# потребитяля въвежда число ,  което е броят на елементите n koito iska da vavedete sled tovva vuvejda 5 chisla  da printira nai - golqmoto
# n = int(input("Въведете броя на елементите: "))
# b =0
# for i in range(n):
#     chislo = float(input("Въведете число: "))
#     if chislo > b:
#         b = chislo
# print(f"Най-голямото число е: {b}")




    # порграм която въвежда н числа и ги умножва н  е се въвежда от потедитяля и птин в козолата

# n = int(input("Въведете колко числа ще умножавате: "))

# proizvedenie = 1  

# for i in range(n):
#     chislo = float(input(f"Въведете число {i + 1}: "))
#     proizvedenie *= chislo

# # Извеждаме резултата
# print("Произведението на въведените числа е:", proizvedenie)

 

# potrebitqlq vujed cislo int  aako ne da dava gresha i da se vuvede novo i go prnit s zvezdi4ki  ot 1 do n. 
# while True:
#     try:
#         n = int(input("Въведи цяло число: "))
#         break
#     except ValueError:
#         print("Грешка! Моля, въведи цяло число.")
# for i in range(1, n + 1):
#     print('*' * i)

# # poteditel vuvveda 3 chisla i progtra proverq sa chetno ili ne chetno
for i in range(3):
    chislo = int(input("Въведете число: "))
    if chislo % 2 == 0:
        print(f"{chislo} е четно число.")
    else:
        print(f"{chislo} е нечетно число.")


