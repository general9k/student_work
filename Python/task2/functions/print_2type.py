import pandas as pd


def print_2type(data):
    colums_names = {0: 'Номер', 1: "Фамилия Имя", 2: "Год рождения", 3: "Пол", 4: "Вес (кг)", 5: "Рост (см)",
                    6: "Профиль", 7: "Уровень", 8: "Душевой доход семьи"}
    k = 0
    for key in data.keys():
        pd.DataFrame(data[key]).rename_axis('Индекс').rename(columns=colums_names).to_csv(
            str(key[0]) + ' и ' + str(key[1]) + ".csv")
        k += 1
