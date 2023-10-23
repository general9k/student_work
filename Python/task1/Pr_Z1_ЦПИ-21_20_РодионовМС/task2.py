from module1 import *

while True:
    try:
        print("Введите 2 числа через Enter: ")
        x = float(input())
        y = float(input())
        M = x, y
    except ValueError:
        print("Некорректный ввод данных. Попробуйте снова")
        continue
    print(fp(M), '\n')

    print("Желаете выйти? Если да - введите цифру 0")
    if input() == '0':
        break

    print("Продолжаем \n")

