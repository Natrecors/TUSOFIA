import math
# Изчисляване на лицето на трапец: потребителят въвежда a, b (основи) и h (височина)
# Резултатът се извежда закръглен до 2 десетични знака

# try:
# 	a = float(input("Въведете а (първа основа): "))
# 	b = float(input("Въведете b (втора основа): "))
# 	h = float(input("Въведете h (височина): "))
# except ValueError:
# 	print("Моля, въведете валидно число.")
# 	raise

# resultat = ((a + b) * h) / 2

# print(f"Лицето на трапеца е: {resultat:.2f}")


# кръг r лице и периметър

# r = float(input("Въведете радиус r на кръга: "))
# area = math.pi * r**2
# perimeter = 2 * math.pi * r
# print(f"Лицето на кръга е: {area:.3f}")
# print(f"Периметърът на кръга е: {perimeter:.3f}")


# калкулатор за паркинг  колко часа  колко пари дължи час е кръгъл  ако е 1 час фрее 2-4 3 лв от 4 нагоре 2 лв на час
# try:
#     chasa = int(input("Въведете броя часове за паркиране: "))

#     if chasa <= 0:
#         print("Моля, въведете положителен брой часове.")
#     elif chasa <= 1:
#         cena = 0
#         print(f"Таксата за паркиране е: {cena} лв. (първият час е безплатен)")
#     elif 2 <= chasa <= 4:
#         cena = chasa * 3
#         print(f"Таксата за паркиране е: {cena} лв.")
#     else: 
#         cena = 4 * 3 + (chasa - 4) * 2
#         print(f"Таксата за паркиране е: {cena} лв.")

# except ValueError:
#     print("Моля, въведете валидно число за часовете.")


    #калуларот за операция  + - * /  и две числа и въвдеждаме резултатът
# try:

#     operaciq = input("Въведете операция (+, -, *, /): ")
#     chislo1 = float(input("Въведете първото число: "))
#     chislo2 = float(input("Въведете второто число: "))
#     if operaciq == '+':
#         resultat = chislo1 + chislo2
#     elif operaciq == '-':
#         resultat = chislo1 - chislo2
#     elif operaciq == '*':
#         resultat = chislo1 * chislo2
#     elif operaciq == '/':
#         if chislo2 != 0:
#             resultat = chislo1 / chislo2
#         else:
#             print("Грешка: Деление на нула не е позволено.")
#             exit()
#     else:
#         print("Невалидна операция.")
#         exit()
#     print(f"Резултатът е: {resultat:.0f}")
# except ValueError:
#     print("Моля, въведете валидни числа.")


import numpy as np
import matplotlib.pyplot as plt

# Входни данни
A = 3  # Амплитуда
f = 20 # Честота (Hz)
fs = 100 # Дискретизация (Hz)
duration = 90 # Продължителност (секунди)

# Генериране на сигнал
t = np.arange(0, duration, 1/fs)
signal = A * np.sin(2 * np.pi * f * t)

# Визуализация (частична)
plt.plot(t[:100], signal[:100])
plt.title("Синусоидален сигнал")
plt.xlabel("Време [s]")
plt.ylabel("Амплитуда [V]")
plt.grid(True)
plt.show()

print(f"Период: {1/f} s")
print(f"Брой отчети: {len(signal)}")