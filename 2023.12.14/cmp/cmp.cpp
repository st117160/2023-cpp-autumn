#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>
#include<cstdlib>

int Strcmp(char* str1, char* str2)
{
	int a = 0;
	int b = 0;
	while (str1[a] != '\0')
	{
		if (str1[a] != str2[b])
		{
			break;
		}
		str1++;
		str2++;
	}
	return str1[a] - str2[b];
}

int main(int argc, char** argv)
{
	FILE* f = fopen("in.txt", "r");

	char str1[256] = { 0 };
	char str2[256] = { 0 };
	fgets(str1, sizeof(str1), f);
	fgets(str2, sizeof(str2), f);

	fclose(f);

	int n = Strcmp(str1, str2);
	f = fopen("out.txt", "w");

	if (n > 0)
	{
		fprintf(f, "%s", "1 > 2");
	}
	else if (n < 0)
	{
		fprintf(f, "%s", "1 < 2");
	}
	else
	{
		fprintf(f, "%s", "1 = 2");
	}

	fclose(f);

	return 0;
}
