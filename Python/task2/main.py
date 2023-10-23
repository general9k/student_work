import pandas as pd
from functions import generate_2type
from functions import print_2type

# Загрузка данных из файла
df = pd.read_excel('data.xlsx')

# Вывод исходных данных
print("Исходный DataFrame:")
print(df)

# Сортировка данных по возрастанию и убыванию
sorted_df_ascending = df.sort_values(by='Год рождения')
sorted_df_descending = df.sort_values(by='Год рождения', ascending=False)
sorted_df_ascending.to_csv('age1_output.csv')  # По дате рождения по возрастанию
sorted_df_descending.to_csv('age2_output.csv')  # По дате рождения по убыванию

# Сортировка по 'Душевой доход семьи'
sorted_df_credit = df.sort_values(by='Душевой доход семьи')
sorted_df_credit.to_csv('income.csv')  # По душевому по возрастанию

# Сортировка по 'Работающие'
sorted_df_sellers_first = df[df['Уровень'] == 'Работающие']
sorted_df_sellers_first.to_csv('worker.csv')  # По работающим

# Фильтрация данных по критериям
filtered_df_gender = df[df['Пол'] == 'м']
filtered_df_gender.to_csv('gender.csv')  # По мужскому полу
filtered_df_age = df[(df['Год рождения'] >= 1980) & (df['Год рождения'] <= 2000)]
filtered_df_age.to_csv('age_1980_2000.csv')  # По году от 80 до 2000 года
filtered_df_weight = df[(df['Вес (кг)'] >= 60) & (df['Вес (кг)'] <= 80)]
filtered_df_weight.to_csv('weight.csv')  # По весу 60-80
filtered_df_height = df[(df['Рост (см)'] >= 160) & (df['Рост (см)'] <= 180)]
filtered_df_height.to_csv('height.csv')  # По росту 160-180

# Перебор всех качественных признаков
profile_name = ['Терапия', 'Хирургия', 'Стоматология', 'Эндокринология', 'Офтальмология']
level_name = ['Работающие', 'Учащиеся', 'Пенсионеры']
data_2type = generate_2type.generate(df, 'Профиль', 'Уровень', profile_name, level_name)
print_2type.print_2type(data_2type)

# Проверка наличия столбца 'Хирургия'
if 'Профиль' in df.columns:
    filtered_df_profile = df[df['Профиль'] == 'Хирургия']
    filtered_df_profile.to_csv('surgery.csv')
else:
    print("\nСтолбец 'Профиль' отсутствует в DataFrame.")
