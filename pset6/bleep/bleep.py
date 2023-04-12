from cs50 import get_string
from sys import argv


def main():
    # TODO

    if not len(argv) == 2:
        print("Usage: python bleep.py dictionary")
        exit(1)
    dictionary_path = argv[1]

    message = get_string("What message would you like to censor?\n")
    words_in_message = message.split()  # kelimeleri ayır

    banned_word_set = set()
    dictionary_file = open(dictionary_path, "r")
    lines = dictionary_file.readlines()

    for line in lines:
        banned_word_set.add(line.lower().rstrip('\n'))  # yasaklı kelime set oluştur
    censor_str = ""
    # her kelimeyi tüm yasaklı kelimler ile karşılaştır ve sansürlü cümleyi oluştur
    for word in words_in_message:
        if word.lower() in banned_word_set:
            censor_str += len(word) * '*'
        else:
            censor_str += word
        censor_str += ' '

    print(censor_str)
    exit(0)


if __name__ == "__main__":
    main()
