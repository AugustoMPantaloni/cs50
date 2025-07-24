while True:
    card = input("Number: ")
    if not card.isdigit() or len(card) not in [13, 15, 16]:
        print("INVALID")
        exit()
    break

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
    exit()

if card.startswith("4") and len(card) in [13, 16]:
    print("VISA")
elif card[:2] in ["34", "37"] and len(card) == 15:
    print("AMEX")
elif card[:2] in ["51", "52", "53", "54", "55"] and len(card) == 16:
    print("MASTERCARD")
else:
    print("INVALID")
    exit()

print("VALID")
