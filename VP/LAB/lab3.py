#потредител въвежда цяло число >1 положитлено , трябва да се форматират 2  кортежа  : първият изжеда от първото число до това което сме въвели, втори съшите числа на обратно

# n = int(input("Въведете цяло положително число > 1: "))
# while n <= 1:
#     n = int(input("Моля, въведете число по-голямо от 1: ")) 
# first_tuple = tuple(range(1, n + 1))
# second_tuple = tuple(range(n, 0, -1))
# print("Първи кортеж:", first_tuple)
# print("Втори кортеж:", second_tuple)


#числoв списък се въвежда от поптребителя да положителни числа 5 на брой , след това да се прави нов списък който да  добава между всяка двока техният сбора.

# numbers = []
# for i in range(5):
#     num = float(input(f"Въведете положително число {i + 1}: "))
#     while num <= 0:
#         num = float(input("Моля, въведете положително число: "))
#     numbers.append(num)

# new_list = []
# for i in range(len(numbers) - 1):
#     new_list.append(numbers[i])
#     new_list.append(numbers[i] + numbers[i + 1])
# new_list.append(numbers[-1])

# formatted_list = [int(x) if x.is_integer() else x for x in new_list]

# print("Новият списък е:", formatted_list)

