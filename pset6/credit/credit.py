from cs50 import get_int


def main():
    n = 0
    while True:
        n = get_int("Number: ")
        if n > 0:
            break
    print(get_card_type(n))


def get_card_type(n):
    if not is_real_credit(str(n)):
        return "INVALID"
    n = str(n)
    n = int(n[:2])  # ilk iki haneyi al
    if n == 34 or n == 37:
        return "AMEX"
    elif n >= 51 and n <= 55:
        return "MASTERCARD"
    elif n // 10 == 4:
        return "VISA"
    else:
        return "INVALID"


def sum_of_digits(n):
    sum = 0
    for digit in str(n):
        sum += int(digit)
    return sum


def is_real_credit(str):
    r_str = str[::-1]  # sayıyı ters çevir
    i = 0
    sum = 0
    for c in r_str:
        if i % 2 == 1:
            sum += sum_of_digits(int(c) * 2)
        i += 1
    i = 0
    for c in r_str:
        if i % 2 == 0:
            sum += int(c)
        i += 1
    if sum % 10 == 0 and len(str) >= 13:
        return True
    else:
        return False


if __name__ == "__main__":
    main()