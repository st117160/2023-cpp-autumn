#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstdlib>
#include <cstring>

void Substr(char* str1, const char* str2)
{
    int a = 0;
    int b = 0;
    int len1 = strlen(str1);
    int len2 = strlen(str2);

    while (a < len1)
    {
        if (str1[a] == str2[b])
        {
            while (b < len2 && str1[a] == str2[b])
            {
                a++;
                b++;
            }

            if (b == len2)
            {
                memmove(&str1[a - b], &str1[a], len1 - a + 1);
                return;
            }
        }
        else
        {
            a++;
        }
    }
}

int main(int argc, char** argv)
{
    FILE* f = fopen("in.txt", "r");

    char str1[256] = { 0 };
    char str2[256] = { 0 };

    fclose(f);

    Substr(str1, str2);

    f = fopen("out.txt", "w");


    fprintf(f, "%s", str1);
    fclose(f);

    return 0;
}