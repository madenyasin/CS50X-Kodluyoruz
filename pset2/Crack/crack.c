#include <cs50.h>
#include <stdio.h>
#include <crypt.h>
#include <stdlib.h>
#include <string.h>

void bruteForce1();
void bruteForce2();
void bruteForce3();
void bruteForce4();
void bruteForce5();

char *alpha;
char *bruteHash;
string hash = NULL;
char *salt;

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./crack hash\n");
        return 1;
    }
    hash = argv[1];
    bruteHash = (char *) malloc(sizeof(hash));
    alpha = (char *) malloc(5);
    salt = (char *) malloc(2);
    for (int i = 0; i < 2; i++)
    {
        salt[i] = hash[i];
    }
    bruteForce1();
    if (strcmp(hash, bruteHash) == 0)
    {
        printf("Bingo! --> %s\n", alpha);
        return 0;
    }
    bruteForce2();
    if (strcmp(hash, bruteHash) == 0)
    {
        printf("Bingo! --> %s\n", alpha);
        return 0;
    }
    bruteForce3();
    if (strcmp(hash, bruteHash) == 0)
    {
        printf("Bingo! --> %s\n", alpha);
        return 0;
    }
    bruteForce5();
    if (strcmp(hash, bruteHash) == 0)
    {
        printf("Bingo! --> %s\n", alpha);
        return 0;
    }
    return 0;
}
// 1 karakterden oluşan sozcukleri tarar ve hash karsilastirmasi yapar.
void bruteForce1()
{
    int i = 65;
    while (true)
    {
        alpha[0] = i;
        bruteHash = crypt(alpha, salt);
        //printf("%s, hash: %s\n", alpha, bruteHash);
        if (strcmp(hash, bruteHash) == 0)
        {
            return;
        }
        if (i == 90)
        {
            i = 96;
        }
        if (i == 122)
        {
            break;
        }
        i++;
    }
}
// 2 karakterden oluşan sozcukleri tarar ve hash karsilastirmasi yapar.
void bruteForce2()
{
    int i = 65;
    while (true)
    {
        alpha[0] = i;
        int j = 65;
        while (true)
        {
            alpha[1] = j;
            bruteHash = crypt(alpha, salt);
            //printf("%s, hash: %s\n", alpha, bruteHash);
            if (strcmp(hash, bruteHash) == 0)
            {
                return;
            }
            if (j == 90)
            {
                j = 96;
            }
            if (j == 122)
            {
                break;
            }
            j++;
        }
        if (i == 90)
        {
            i = 96;
        }
        if (i == 122)
        {
            break;
        }
        i++;
    }
}
// 3 karakterden oluşan sozcukleri tarar ve hash karsilastirmasi yapar.
void bruteForce3()
{
    int i = 65;
    while (true)
    {
        alpha[0] = i;
        int j = 65;
        while (true)
        {
            alpha[1] = j;
            int k = 65;
            while (true)
            {
                alpha[2] = k;
                bruteHash = crypt(alpha, salt);
                //printf("%s, hash: %s\n", alpha, bruteHash);
                if (strcmp(hash, bruteHash) == 0)
                {
                    return;
                }
                if (k == 90)
                {
                    k = 96;
                }
                if (k == 122)
                {
                    break;
                }
                k++;
            }
            if (j == 90)
            {
                j = 96;
            }
            if (j == 122)
            {
                break;
            }
            j++;
        }
        if (i == 90)
        {
            i = 96;
        }
        if (i == 122)
        {
            break;
        }
        i++;
    }
}
// 4 karakterden oluşan sozcukleri tarar ve hash karsilastirmasi yapar.
void bruteForce4()
{
    int i = 65;
    while (true)
    {
        alpha[0] = i;
        int j = 65;
        while (true)
        {
            alpha[1] = j;
            int k = 65;
            while (true)
            {
                alpha[2] = k;
                int l = 65;
                while (true)
                {
                    alpha[3] = l;
                    bruteHash = crypt(alpha, salt);
                    //printf("%s, hash: %s\n", alpha, bruteHash);
                    if (strcmp(hash, bruteHash) == 0)
                    {
                        return;
                    }
                    if (l == 90)
                    {
                        l = 96;
                    }
                    if (l == 122)
                    {
                        break;
                    }
                    l++;
                }
                if (k == 90)
                {
                    k = 96;
                }
                if (k == 122)
                {
                    break;
                }
                k++;
            }
            if (j == 90)
            {
                j = 96;
            }
            if (j == 122)
            {
                break;
            }
            j++;
        }
        if (i == 90)
        {
            i = 96;
        }
        if (i == 122)
        {
            break;
        }
        i++;
    }
}
// 5 karakterden oluşan sozcukleri tarar ve hash karsilastirmasi yapar.
void bruteForce5()
{
    int i = 65;
    while (true)
    {
        alpha[0] = i;
        int j = 65;
        while (true)
        {
            alpha[1] = j;
            int k = 65;
            while (true)
            {
                alpha[2] = k;
                int l = 65;
                while (true)
                {
                    alpha[3] = l;
                    int m = 65;
                    while (true)
                    {
                        alpha[4] = m;
                        bruteHash = crypt(alpha, salt);
                        //printf("%s, hash: %s\n", alpha, bruteHash);
                        if (strcmp(hash, bruteHash) == 0)
                        {
                            return;
                        }
                        if (m == 90)
                        {
                            m = 96;
                        }
                        if (m == 122)
                        {
                            break;
                        }
                        m++;
                    }
                    if (l == 90)
                    {
                        l = 96;
                    }
                    if (l == 122)
                    {
                        break;
                    }
                    l++;
                }
                if (k == 90)
                {
                    k = 96;
                }
                if (k == 122)
                {
                    break;
                }
                k++;
            }
            if (j == 90)
            {
                j = 96;
            }
            if (j == 122)
            {
                break;
            }
            j++;
        }
        if (i == 90)
        {
            i = 96;
        }
        if (i == 122)
        {
            break;
        }
        i++;
    }
}
