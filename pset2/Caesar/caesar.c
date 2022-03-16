#include <stdio.h>
#include <cs50.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main(int argc, string argv[])
{
    if (argc == 2)
    {        
        int i = 0;
        // Bu döngü ile komut satırı argümanı rakamlardan mı oluşuyor onu kontrol ediyoruz.
        while (argv[1][i] != '\0')
        {
            if (!(isdigit(argv[1][i])))
            {
                printf("Usage: ./caesar key\n");
                return 1;
            }
            i++;
        }
        int shift = atoi(argv[1]);
        string plaintext = get_string("plaintext: ");
        // Bu döngü ile Caesar'ın şifrelemesini yapıyoruz.
        for (i = 0; i < strlen(plaintext); i++)
        {
            // Büyük - küçük harf kontrolü yaparak gerekli şifrelemeler koşulların içinde yapılıyor.
            if (plaintext[i] >= 'A' && plaintext[i] <= 'Z')
            {
                plaintext[i] -= 'A';
                plaintext[i] = ((plaintext[i] + shift) % 26) + 'A';
            }
            else if (plaintext[i] >= 'a' && plaintext[i] <= 'z')
            {
                plaintext[i] -= 'a';
                plaintext[i] = ((plaintext[i] + shift) % 26) + 'a';            
            }
        }
        printf("ciphertext: %s\n", plaintext);
        return 0;
    }
    else
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
}

