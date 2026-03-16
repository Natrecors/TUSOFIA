import random
import numpy as np
import matplotlib.pyplot as plt

classroom_width = 7
classroom_length = 5
population_size = 12
generations = 10
mutation_rate = 0.1

# 2. Функция за фитнес (сила на сигнала)
def calculate_signal_strength(ap_x, ap_y, point_x, point_y):
    distance = np.sqrt((ap_x - point_x)**2 + (ap_y - point_y)**2)
    return 1 / (distance + 1)

# 3. Инициализация
random.seed(42) 
initial_population = [(random.uniform(0, classroom_width), random.uniform(0, classroom_length)) for _ in range(population_size)]
population = [initial_population.copy()]


best_solution = None
best_fitness = float('-inf')
all_fitness_scores = []

# 4. Основен цикъл
for generation in range(generations):

    fitness_scores = []
    current_pop = population[generation]
    
    for ap_x, ap_y in current_pop:
        coverage = 0
        for point_x in range(int(classroom_width) + 1):
            for point_y in range(int(classroom_length) + 1):
                coverage += calculate_signal_strength(ap_x, ap_y, point_x, point_y)
        fitness_scores.append(coverage)

    current_max = max(fitness_scores)
    if current_max > best_fitness:
        best_fitness = current_max
        best_solution = current_pop[fitness_scores.index(current_max)]
    all_fitness_scores.append(current_max)

    selected_parents = random.choices(current_pop, weights=fitness_scores, k=population_size)

    offspring = []
    for _ in range(population_size):
        parent1, parent2 = random.sample(selected_parents, 2)
        
        cx = random.uniform(min(parent1[0], parent2[0]), max(parent1[0], parent2[0]))
        cy = random.uniform(min(parent1[1], parent2[1]), max(parent1[1], parent2[1]))
        
        if random.random() < mutation_rate:
            cx = random.uniform(0, classroom_width)
            cy = random.uniform(0, classroom_length)
            
        offspring.append((cx, cy))
    
    population.append(offspring)

print(f"Best Coordinates: {best_solution}")
print(f"Best Fitness: {best_fitness}")

# 5. Визуализации

# 2.3 Начално и крайно разпределение
plt.figure(figsize=(10, 6))
# Начална (червено)
ix, iy = zip(*initial_population)
plt.scatter(ix, iy, c='red', label='Начална позиция (Gen 0)')
for i, (x, y) in enumerate(initial_population):
    plt.text(x, y, str(i+1), fontsize=8)
# Крайна (синьо)
fx, fy = zip(*population[-1])
plt.scatter(fx, fy, c='blue', label=f'Крайна позиция (Gen {generations})')
for i, (x, y) in enumerate(population[-1]):
    plt.text(x, y, str(i+1), fontsize=8)
plt.title('2.3. Начално и крайно разпределение на точките за достъп')
plt.xlabel('Ширина (m)')
plt.ylabel('Дължина (m)')
plt.legend()
plt.grid(True)
plt.savefig('2_3_distribution.png')

# 2.4 Топлинна карта на най-доброто решение (последно поколение)
plt.figure(figsize=(10, 6))
X = np.linspace(0, classroom_width, 100)
Y = np.linspace(0, classroom_length, 100)
XX, YY = np.meshgrid(X, Y)
ZZ = np.zeros_like(XX)
bx, by = best_solution
ZZ = 1 / (np.sqrt((XX - bx)**2 + (YY - by)**2) + 1)
plt.pcolormesh(XX, YY, ZZ, shading='auto', cmap='viridis')
plt.colorbar(label='Сила на сигнала')
plt.scatter([bx], [by], c='red', marker='*', s=200, label='Най-добър AP')
plt.title('2.4. Сила на сигнала (Най-добро решение)')
plt.xlabel('Ширина (m)')
plt.ylabel('Дължина (m)')
plt.legend()
plt.savefig('2_4_heatmap.png')

# 2.5 Траектория
trajectory_scores = []
final_best_arr = np.array(best_solution)
for gen_pop in population:
    dists = [np.linalg.norm(np.array(p) - final_best_arr) for p in gen_pop]
    trajectory_scores.append(np.mean(dists))

plt.figure(figsize=(10, 6))
plt.plot(range(len(population)), trajectory_scores, marker='o')
plt.title('2.5. Траектория на популацията (Сходимост към оптимума)')
plt.xlabel('Поколение')
plt.ylabel('Средно разстояние до най-доброто решение')
plt.grid(True)
plt.savefig('2_5_trajectory.png')

# Добави това в секция 5. Визуализации

# Генериране на графика за ВСЯКО поколение (за да имаш 10 снимки за протокола)
for gen_idx in range(generations):
    plt.figure(figsize=(12, 5))
    
    # 1. Топлинна карта + точките от текущото поколение
    plt.subplot(1, 2, 1)
    
    # Взимаме популацията за текущото поколение
    current_pop_viz = population[gen_idx]
    
    # Създаваме мрежата за чертане
    X = np.linspace(0, classroom_width, 100)
    Y = np.linspace(0, classroom_length, 100)
    XX, YY = np.meshgrid(X, Y)
    ZZ = np.zeros_like(XX)
    
    # Изчисляваме силата на сигнала от ВСИЧКИ точки в това поколение (сумарно или най-доброто)
    # Забележка: Условието иска визуализация на разпределението. 
    # Ще покажем най-доброто от това поколение за фон или просто точките.
    # По-долу следвам логиката от PDF (source 146-147), където сумират сигнала от всички AP
    for ap_x, ap_y in current_pop_viz:
        ZZ += calculate_signal_strength(ap_x, ap_y, XX, YY)
        
    plt.pcolormesh(XX, YY, ZZ, shading='auto', cmap='viridis')
    plt.colorbar(label='Сила на сигнала')
    
    # Чертаем самите точки (индивиди)
    px, py = zip(*current_pop_viz)
    plt.scatter(px, py, color='red', marker='o', label='Индивиди')
    for i, (x, y) in enumerate(current_pop_viz):
        plt.text(x, y, str(i+1), color='white', fontsize=8)
        
    plt.title(f'Поколение {gen_idx + 1}: Разпределение')
    plt.xlabel('Ширина (m)')
    plt.ylabel('Дължина (m)')
    
    # 2. Графика на фитнеса до момента
    plt.subplot(1, 2, 2)
    # Взимаме фитнеса само до текущото поколение
    current_fitness_scores = all_fitness_scores[:gen_idx+1]
    plt.plot(range(1, gen_idx + 2), current_fitness_scores, marker='o', color='blue')
    plt.title(f'Фитнес резултат (Gen {gen_idx + 1})')
    plt.xlabel('Поколение')
    plt.ylabel('Max Fitness')
    plt.grid(True)
    
    plt.tight_layout()
    # Запазваме файл за всяко поколение
    plt.savefig(f'Gen_{gen_idx+1}_visualization.png')
    plt.close() # Затваряме, за да не трупа памет

# 2.6 Графика на сходство (Fitness curve)
plt.figure(figsize=(10, 6))
plt.plot(range(1, generations + 1), all_fitness_scores, marker='o', color='green')
plt.title('2.6. Графика на сходство (Максимален фитнес по поколения)')
plt.xlabel('Поколение')
plt.ylabel('Най-добър фитнес')
plt.grid(True)
plt.savefig('2_6_similarity.png')