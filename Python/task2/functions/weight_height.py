import numpy as np


# Функция для генерации случайного веса и роста в зависимости от пола
def generate_weight_height(gender, size):
    if gender == 'м':
        weight = np.random.normal(loc=75, scale=10, size=size)
        height = np.random.normal(loc=175, scale=7, size=size)
    else:
        weight = np.random.normal(loc=60, scale=7, size=size)
        height = np.random.normal(loc=162, scale=6, size=size)
    return weight, height
