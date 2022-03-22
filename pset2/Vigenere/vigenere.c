#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

string convertToVigenereText(string, string);
bool isalphaString(string);
int shift(char);

int main(int argc, string argv[])
{
    // komut satiri arguman sayisi ve alfabetik karakter kontrolu
    if (argc != 2 || !isalphaString(argv[1]))
    {
        printf("Usage: ./vigenere keyword\n");
        return 1;
    }
    string plaintext = get_string("plaintext: ");
    printf("ciphertext: %s\n", convertToVigenereText(plaintext, argv[1]));
    return 0;

}

// parametre ile gonderilen stringin alfabetik karakterlerden mi olustugunu bildirir.
bool isalphaString(string s)
{
    for (int i = 0; i < strlen(s); i++)
    {
        if (!isalpha(s[i]))
        {
            return false;
        }
    }
    return true;
}

// Vigenere sifrelemesi icin karakterin kaydirma degerini hesaplar.
int shift(char c)
{
    if (c >= 'A' && c <= 'Z')
    {
        c -= 'A';
    }
    else if (c >= 'a' && c <= 'z')
    {
        c -= 'a';
    }
    return c;
}

// Vigenere sifresini olusturur.
string convertToVigenereText(string s, string keyword)
{
    int key;
    for (int i = 0, j = 0; i < strlen(s); i++, j++)
    {
        
        if (isspace(s[i]))
        {
            j--;
            continue;
        }
        key = shift(keyword[j % strlen(keyword)]);
        if (s[i] >= 'A' && s[i] <= 'Z')
        {
            s[i] -= 'A';
            s[i] = (s[i] + key) % 26;
            s[i] += 'A';
        }
        else if (s[i] >= 'a' && s[i] <= 'z')
        {
            s[i] -= 'a';
            s[i] = (s[i] + key) % 26;
            s[i] += 'a';
        }
    }
    return s;
}
