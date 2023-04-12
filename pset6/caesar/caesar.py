from sys import argv
from cs50 import get_string


def main():
    if not len(argv) == 2:
        print("Usage: python caesar.py k")
        exit(1)
    k = int(argv[1])
    plain_text = get_string("plaintext: ")
    cipher_text = convert_caesar_text(plain_text, k)
    print("ciphertext:", cipher_text)
    exit(0)


def convert_caesar_text(str, k):
    new_str = ""
    for c in str:
        if c.isalpha():
            shift_ascii = 65 if c.isupper() else 97
            new_str += chr(((ord(c) - shift_ascii + k) % 26) + shift_ascii)
        else:
            new_str += c
    return new_str


if __name__ == "__main__":
    main()