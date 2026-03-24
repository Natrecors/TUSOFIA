import networkx as nx

# Опитайте да импортирате matplotlib; ако не е наличен, пропуснете чертането
try:
    import matplotlib.pyplot as plt
except ImportError:
    plt = None
    print("Warning: matplotlib is not installed; plotting is skipped. Install with: pip install matplotlib")

# Създаване на насочен граф
G = nx.DiGraph()

# Дефиниране на ръбовете (работите) според Таблица 1
# (Начален възел, Краен възел, Етикет на работата)
edges = [
    (1, 2, 'A'),
    (1, 3, 'B'),
    (2, 3, 'C'),
    (2, 4, 'D'),
    (3, 4, 'E'),
    (3, 5, 'F'),
    (4, 6, 'G'),
    (5, 6, 'H')
]

for u, v, label in edges:
    G.add_edge(u, v, label=label)

# Позициониране на възлите за прегледност (ръчно зададени координати)
pos = {
    1: (0, 1),   # Начало (ляво център)
    2: (1, 2),   # Горе (след A)
    3: (2, 1),   # Център (след B и C)
    4: (3, 2),   # Горе дясно (след D и E)
    5: (3, 0),   # Долу дясно (след F)
    6: (4, 1)    # Край (най-дясно)
}

if plt is None:
    # Ако matplotlib липсва, отпечатайте информация за графа вместо да се опитвате да чертаете
    print("Nodes:", list(G.nodes()))
    print("Edges with labels:", [(u, v, data.get('label')) for u, v, data in G.edges(data=True)])
    print("To enable plotting, install matplotlib: pip install matplotlib")
else:
    plt.figure(figsize=(10, 6))

    # Рисуване на възлите
    nx.draw_networkx_nodes(G, pos, node_size=2000, node_color='lightblue', edgecolors='black')
    nx.draw_networkx_labels(G, pos, font_size=12, font_weight='bold')

    # Рисуване на стрелките
    nx.draw_networkx_edges(G, pos, arrowstyle='-|>', arrowsize=20, edge_color='black')

    # Добавяне на етикетите на стрелките (буквите на задачите)
    edge_labels = {(u, v): label for u, v, label in edges}
    nx.draw_networkx_edge_labels(G, pos, edge_labels=edge_labels, font_size=14, font_color='red', label_pos=0.5)

    plt.title("Мрежов график по Таблица 1", fontsize=16)
    plt.axis('off') # Скриване на осите
    plt.show()