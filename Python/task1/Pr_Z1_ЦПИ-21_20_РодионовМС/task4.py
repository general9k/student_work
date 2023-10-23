from module1 import *
import random
import numpy as np
import pandas as pd

# Task 1-4: Write data
while True:
    try:
        n = int(input("Введите количество тестов "))
        print("Введите границы переборной области")
        print("Введите через пробел область по X ")
        start_x, end_x = map(float, input().split())
        print("Введите через пробел область по Y ")
        start_y, end_y = map(float, input().split())
        break
    except ValueError:
        print("Неверный ввод данных. Попробуйте снова \n")

# Task 5: Create dict from dataFrame
arr_test = {'Координата X': [], 'Координата Y': [], "Сообщение о попадании": []}
key = list(arr_test.keys())
for i in range(n):
    x = float("{:.2f}".format(random.uniform(start_x, end_x)))
    y = float("{:.2f}".format(random.uniform(start_y, end_y)))
    arr_test[key[0]].append(x)
    arr_test[key[1]].append(y)
    arr_test[key[2]].append(fp((x, y)))

# Task 6: Create dataFrame
arr_dataFrame = pd.DataFrame(arr_test, index=np.arange(1, n + 1))
arr_dataFrame = arr_dataFrame.rename_axis('Номер выстрела')

# Task 7: Write to csv and xlsx
arr_dataFrame.to_csv('output.csv')
arr_dataFrame.to_excel('output.xlsx')

# Task 8: Opening and Unpacking csv, xlsx
arr_csv = pd.read_csv('output.csv')
arr_xlsx = pd.read_excel('output.xlsx')
print(arr_csv)
print(arr_xlsx)

# Task 9: Probability calculation
arr_data = np.array(arr_xlsx)
counter = 0
for i in range(len(arr_data)):
    counter += arr_data[i][-1]
print(f"Статистическая вероятность для {n} выстрелов равна: ", "{:.6f}".format(counter / n))
print(f"Теоретическая вероятность для прямоугольника из длин l1 = {end_y - start_y}, l2 = {end_x - start_x} равна: ",
      "{:.6f}".format(10.78 / ((end_y - start_y) * (end_x - start_x))))


