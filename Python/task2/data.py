import pandas as pd
import numpy as np
from functions import age
from functions import gender
from functions import categorical
from functions import weight_height

# Генерация данных
N = np.random.randint(30, 46)  # Количество строк таблицы

# Добавление столбца 'Душевой доход семьи'
income_limit_mean = 25000
income_limit_std = 12000
income_limit = np.random.normal(loc=income_limit_mean, scale=income_limit_std, size=N)

# Списки с именами и фамилиями
names = ['Валя', 'Саша', 'Женя', 'Мирик', 'Никуша', 'Нико', 'Еник', 'Валера']
surnames = ['Скотт', 'Блэр', 'Рид', 'Рой', 'Трамп', 'Янг', 'Бувви', 'Купер']
profile_name = ['Терапия', 'Хирургия', 'Стоматология', 'Эндокринология', 'Офтальмология']
profile_chance = [0.5, 0.1, 0.2, 0.1, 0.1]
level_name = ['Работающие', 'Учащиеся', 'Пенсионеры']
level_chance = [0.5, 0.1, 0.4]

data = {'Номер': range(1, N + 1),
        'Фамилия Имя': ['{} {}'.format(np.random.choice(surnames), np.random.choice(names)) for _ in range(N)],
        'Год рождения': [0] * N,
        'Пол': gender.generate_gender(0.5, N),
        'Вес (кг)': [0] * N,
        'Рост (см)': [0] * N,
        'Профиль': categorical.generate_categorical_feature(profile_name, profile_chance, N),
        'Уровень': categorical.generate_categorical_feature(level_name, level_chance, N),
        'Душевой доход семьи': income_limit}

# Генерация возраста
age.generate_age(data, N, level_name)

# Разделение данных по полу и генерация веса и роста
male_indices = data['Пол'] == 'м'
female_indices = data['Пол'] == 'ж'

male_weight, male_height = weight_height.generate_weight_height('м', sum(male_indices))
female_weight, female_height = weight_height.generate_weight_height('ж', sum(female_indices))

# Создание DataFrame
df = pd.DataFrame(data)

# Добавление столбца 'Профиль'
df['Профиль'] = categorical.generate_categorical_feature(profile_name, profile_chance, N)

# Добавление столбца 'уровень'
df['Уровень'] = categorical.generate_categorical_feature(level_name, level_chance, N)

# Используем .loc для присвоения значений веса и роста
df.loc[male_indices, 'Вес (кг)'] = male_weight.astype(int)
df.loc[male_indices, 'Рост (см)'] = male_height.astype(int)
df.loc[female_indices, 'Вес (кг)'] = female_weight.astype(int)
df.loc[female_indices, 'Рост (см)'] = female_height.astype(int)

# Запись DataFrame в файл Excel
df.to_excel('data.xlsx', index=False)

# Запись DataFrame в файл CSV
df.to_csv('data.csv', index=False)

print("Данные успешно сгенерированы и записаны в файлы data.xlsx и data.csv.")
