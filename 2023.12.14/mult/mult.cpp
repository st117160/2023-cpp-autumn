#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>
#include<cstdlib>

int Strlen(char* str)
{
    int ans = 0;
    while (str[ans++] != '\0');
    return ans;
}

char* Strmult(char* str, int n)
{
    int len = (Strlen(str)) * n;
    char* ans = (char*)calloc(len, sizeof(char*));
    int a = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < Strlen(str); j++)
        {
            ans[a] = str[j];
            a++;
        }
    }

    return ans;
}

int main(int argc, char** argv)
{
    FILE* f = fopen("in.txt", "r");

    int n;
    fscanf(f, "%d", &n);
    char str[256] = { 0 };
    fgets(str, sizeof(str), f);
    fclose(f);

    char* ans = Strmult(str, n);

    f = fopen("out.txt", "w");
    fprintf(f, "%s", ans);
    fclose(f);

    free(ans);

    return 0;
}