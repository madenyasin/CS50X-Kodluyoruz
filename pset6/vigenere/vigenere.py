from sys import argv
from cs50 import get_string


def main():
    if not len(argv) == 2 or not argv[1].isalpha():
        print("Usage: python caesar.py keyword")
        exit(1)
    keyword = argv[1].upper()
    plain_text = get_string("plaintext: ")
    cipher_text = convert_vigenere_text(plain_text, keyword)
    print("ciphertext:", cipher_text)
    exit(0)


def convert_vigenere_text(str, keyword):
    new_str = ""
    i = 0
    for c in str:
        if c.isalpha():
            if i % len(keyword) == 0:
                i = 0
            shift_ascii = 65 if c.isupper() else 97
            shift_value = ord(keyword[i]) - ord('A')
            new_str += chr(((ord(c) - shift_ascii + shift_value) % 26) + shift_ascii)
            i += 1
        else:
            new_str += c
    return new_str


if __name__ == "__main__":
    main()