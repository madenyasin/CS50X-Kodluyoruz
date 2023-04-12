from cs50 import get_int


def main():
    n = 0
    while True:
        n = get_int("Height: ")
        if not n < 1 and not n > 8:
            break
    print_sharp(n)


def print_sharp(n):
    counter = 1
    while n > 0:
        for i in range(n - 1):
            print(' ', end="")
        for i in range(counter):
            print('#', end="")
        counter += 1
        n -= 1
        print()

if __name__ == "__main__":
    main()
