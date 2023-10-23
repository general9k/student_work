import numpy as np


# Функция для генерации случайного пола
def generate_gender(prob_male, size):
    genders = np.random.choice(['м', 'ж'], size=size, p=[prob_male, 1 - prob_male])
    return genders
