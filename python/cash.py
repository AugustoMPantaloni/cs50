while True:
    try:
        change = float(input("change: "))
        if change > 0:
            break
    except ValueError:
        pass

change = round(change * 100)

coins = [25, 10, 5, 1]

totalCoins = 0

while change != 0:
    for coin in coins:
        if coin <= change:
            change -= coin
            totalCoins += 1
            break

print(totalCoins)
