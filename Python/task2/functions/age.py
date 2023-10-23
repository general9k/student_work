import numpy as np

# Функция для генерации случайного возраста
def generate_age(data, N, level_name):
    for i in range(N):
        s = data['Уровень'][i]
        if s == level_name[0]:  # Работающие
            data['Год рождения'][i] = int(np.random.normal(loc=1985, scale=3))
        elif s == level_name[1]:  # Учащиеся
            data['Год рождения'][i] = int(np.random.normal(loc=1998, scale=2))
        else:  # Пенсионеры
            data['Год рождения'][i] = int(np.random.normal(loc=1968, scale=2.5))
