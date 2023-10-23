import numpy as np


# Функция для генерации случайных признаков
def generate_categorical_feature(categories, probabilities, size):
    return np.random.choice(categories, size=size, p=probabilities)
