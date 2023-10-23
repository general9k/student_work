from module1 import fp
import random


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

for i in range(n):
    x = float("{:.2f}".format(random.uniform(start_x, end_x)))
    y = float("{:.2f}".format(random.uniform(start_y, end_y)))
    M = x, y
    print(f"x = {x}, y = {y}, fp(x,y) = {fp(M)} \n")
