from cs50 import get_float


def main():
    n = 0
    while True:
        n = get_float("Change owed: ")
        if not n < 0:
            break
    n = int(round(n * 100))  # dollar to cent
    print(number_of_coins(n))


def number_of_coins(n):
    coins = 0
    while not n == 0:
        if n >= 25:
            n -= 25
            coins += 1
        elif n >= 10:
            n -= 10
            coins += 1
        elif n >= 5:
            n -= 5
            coins += 1
        elif n >= 1:
            n -= 1
            coins += 1

    return coins


if __name__ == "__main__":
    main()