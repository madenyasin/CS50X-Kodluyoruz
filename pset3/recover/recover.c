#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        fprintf(stderr, "Usage: ./recover image\n");
        return 1;
    }
    char *rawFile = argv[1];
    unsigned char buffer[4];
    unsigned char temp[512 - 4];

    FILE *rawPtr = fopen(rawFile, "rb");
    if (rawPtr == NULL)
    {
        fprintf(stderr, "Could not open %s.\n", rawFile);
        return 2;
    }

    int GroupNo = 0, imgNo = 0, imgGroupNo = 0, counter = 0;
    int size = 0;

    // dosyadaki JPG sayısı bulunur
    while (1)
    {
        fread(buffer, 1, 4, rawPtr); // 512 lik byte kumesinin ilk 4 baytı okundu
        // okunan byte'lar bir jpg dosyasına mı ait?
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0))
        {
            imgNo++;
        }
        if (fread(temp, (512 - 4), 1, rawPtr) == 0)
        {
            break;
        }
    }

    int sizeArray[imgNo]; // gorsellerin boyutunu barındıracak bir dizi oluşturuyoruz

    fseek(rawPtr, 0, SEEK_SET); //imlec dosya başlangıcına

    while (1)
    {
        fread(buffer, 1, 4, rawPtr); // 512 lik byte kumesinin ilk 4 baytı okundu
        // okunan byte'lar bir jpg dosyasına mı ait?
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0))
        {
            // jpg bulundu
            GroupNo++;
            counter++;
            if (counter != 1)
            {
                // son jpg hariç diğer jpg'lerin boyutu hesaplanıp diziye atılıyor.
                // dizideki değerler 1 sağa kaymış vaziyette. 80. satırda elemanlar sola kaydırılıp sorun çözülüyor.
                // son elemanın boyutu 85. satırda hesaplanıp dizinin sonuna ekleniyor
                size = GroupNo - imgGroupNo;
                sizeArray[counter - 1] = size;
            }
            imgGroupNo = GroupNo;
            imgNo++;
            // printf("%d.\t512'lik byte kumesinde jpg başlangıcı bulundu | %d. jpg | jpg kume: %d | size: %d\n", GroupNo, imgNo, imgGroupNo, size);
        }
        else // jpg değil
        {
            GroupNo++;
            //printf("%d.\t512'lik byte kumesinde bir jpg görüntüsü bulunamadı!\n", GroupNo);
        }
        if (fread(temp, (512 - 4), 1, rawPtr) == 0)
        {
            // printf("%d.\t512'lik byte kümesi son kümedir\n", GroupNo); // son küme değeri
            //dosyanın sonuna gelindi
            break;
        }
    }

    int len = sizeof(sizeArray) / sizeof(int);
    // her eleman sola kayar || son elemanın boyutu belirsiz
    for (int i = 0, j = 1; i < len; i++, j++)
    {
        sizeArray[i] = sizeArray[j];
    }

    //son jpg dosyasının boyutu hesaplanıyor
    sizeArray[len - 1] = GroupNo - imgGroupNo; // son küme değeri - son jpg küme değeri = size

    // görselin tam boyutu hesaplanıyor
    for (int i = 0; i < len; i++)
    {
        sizeArray[i] = sizeArray[i] * 512;
    }

    // for (int i = 0, j = 0; i < len; i++, j++)
    // {
    //     printf("%d.\tJPG size: %d\n", j + 1, sizeArray[i]);
    // }

    fseek(rawPtr, 0, SEEK_SET);
    int n = 0;
    while (1)
    {
        fread(buffer, 1, 4, rawPtr); // 512 lik byte kumesinin ilk 4 baytı okundu
        // okunan byte'lar bir jpg dosyasına mı ait?
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0))
        {
            fseek(rawPtr, -4, SEEK_CUR);

            //dosya adlandırma işlemleri
            char file_name[15];
            sprintf(file_name, "%03d.jpg", n);

            FILE *img = fopen(file_name, "w");
            if (img == NULL)
            {
                fclose(rawPtr);
                fclose(img);
                fprintf(stderr, "Could not open %s.\n", rawFile);
                return 3;
            }


            // okuma - yazma - imleç işlemleri
            fseek(img, 0, SEEK_SET);

            unsigned char temp_img[sizeArray[n]];

            fread(temp_img, sizeArray[n], 1, rawPtr);

            fseek(rawPtr, -1 * sizeArray[n], SEEK_CUR);

            fwrite(temp_img, sizeArray[n], 1, img);

            fseek(rawPtr, 4, SEEK_CUR);
            n++;
        }
        if (fread(temp, (512 - 4), 1, rawPtr) == 0)
        {
            break;
        }
    }
    fclose(rawPtr);
    return 0;
}