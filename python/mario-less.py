height = 0

while height <= 0 or height > 8:
    try:
        height = int(input("Enter a number between 1 and 8: "))
    except ValueError:
        print("Enter a valid integer")

for i in range(1, height + 1):
    print(" " * (height - i) + "#" * i)
