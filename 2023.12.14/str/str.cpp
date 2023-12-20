#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstdlib>

int Strstr(char* str1, char* str2)
{
    int a = 0;
    int b = 0;

    while (str1[a] != '\0')
    {
        if (str1[a] == str2[b])
        {
            if (str2[b + 1] == '\0')
            {
                return a - b;
            }
            b++;
        }
        else
        {
            b = 0;
        }
        a++;
    }

    return -1;
}

int main(int argc, char** argv)
{
    FILE* f = fopen("in.txt", "r");

    char str1[256] = { 0 };
    char str2[256] = { 0 };
    fgets(str1, sizeof(str1), f);
    fgets(str2, sizeof(str2), f);

    fclose(f);

    int ans = Strstr(str1, str2);

    f = fopen("out.txt", "w");

    fprintf(f, "%d", ans);
    fclose(f);

    return 0;
}