from nltk.tokenize import sent_tokenize

def lines(a, b):
    """Return lines in both a and b"""

    # TODO

    #  satırları ayırıp benzersiz satırları kümeledik
    lines_a = set(a.splitlines())
    lines_b = set(b.splitlines())


    #  aynı satırları diziye ekkliyoruz
    same_lines = []
    for line in lines_a:
        if line in lines_b:
            same_lines.append(line)

    return same_lines


def sentences(a, b):
    """Return sentences in both a and b"""

    # TODO

    #  stringlerdeki benzersiz cümleler kümelere ekleniyor
    sentences_a = set(sent_tokenize(a))
    sentences_b = set(sent_tokenize(b))

    #  aynı cümleler listeye ekleniyor
    same_sentences = []
    for sentence in sentences_a:
        if sentence in sentences_b:
            same_sentences.append(sentence)

    return same_sentences


def substrings(a, b, n):
    """Return substrings of length n in both a and b"""

    # TODO

    #  stringler metot yardımı ile benzersiz parçalara ayrılır
    substrings_a = slice(a, n)
    substrings_b = slice(b, n)

    #  aynı str'ler listeye eklenir
    same_substrings = []
    for string in substrings_a:
        if string in substrings_b:
            same_substrings.append(string)

    return same_substrings

def slice(string, n): #  (0, n) --> (len - n, len)

    #  set veri yapısı sayesinde benzersiz veriler depolanabilir
    substrings = set()
    i = 0

    #  belirlenen n'e göre tüm substringler oluşturulur
    while i <= len(string) - n:
        substrings.add(string[i : i + n])
        i += 1

    return substrings