while True:
    try:
        card = input("Number: ")
        if len(card) not in [13, 15, 16]:
            print("INVALID")
            exit()
    except ValueError:
        pass

suma = 0

for i in range(len(card) - 1, -1, -1):
    num = int(card[i])

    if (len(card) - i) % 2 == 0:
        num *= 2
        if num > 9:
            num -= 9
    suma += num

if suma % 10 != 0:
    print("INVALID")
