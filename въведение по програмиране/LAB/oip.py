import numpy as np
import matplotlib.pyplot as plt

# --- 1. ВХОДНИ ДАННИ ---
A = 5          # Амплитуда
f = 20         # Честота на сигнала
fs = 100       # Честота на дискретизация

# Изчисления от задачата
T = 1 / f      # Период: 0.05 s
t_max_plot = 2 * T 

# --- 2. ГЕНЕРИРАНЕ НА СИГНАЛИТЕ ---
# Аналогов сигнал
t_continuous = np.linspace(0, t_max_plot, 1000) 
x_continuous = A * np.sin(2 * np.pi * f * t_continuous)

# Дискретен сигнал
t_samples = np.arange(0, t_max_plot + 1/fs, 1/fs)
x_samples = A * np.sin(2 * np.pi * f * t_samples)

# --- 3. ВИЗУАЛИЗАЦИЯ ---
plt.figure(figsize=(12, 6))

# Чертане на аналоговия сигнал
plt.plot(t_continuous, x_continuous, 
         label='Аналогов сигнал', 
         color='blue', linewidth=2)

# Чертане на дискретните отчети (ПОПРАВЕНО: махнато е use_line_collection=True)
plt.stem(t_samples, x_samples, 
         linefmt='r--', markerfmt='ro', basefmt=' ', 
         label=f'Дискретизация ({fs} Hz)')

# Оформление
plt.title(f'Синусоидален сигнал: A={A}V, f={f}Hz, T={T}s')
plt.xlabel('Време (t) [секунди]')
plt.ylabel('Амплитуда (U) [Волтове]')
plt.axhline(0, color='black', linewidth=0.8)
plt.axvline(0, color='black', linewidth=0.8)
plt.grid(True, which='both', linestyle=':', alpha=0.7)

# Маркиране на Амплитудата (A)
plt.axhline(A, color='green', linestyle='--', alpha=0.6)
plt.text(t_max_plot * 1.01, A, f'A = {A}V', color='green', fontweight='bold')

# Маркиране на Периода (T)
plt.annotate('', xy=(T, -5.5), xytext=(0, -5.5), 
             arrowprops=dict(arrowstyle='<->', color='purple', lw=1.5))
plt.text(T/2, -6.5, f'Период T = {T} s', color='purple', ha='center', fontweight='bold')

plt.xlim(-0.005, t_max_plot + 0.005)
plt.ylim(-7, 7)
plt.legend(loc='upper right')

plt.show()