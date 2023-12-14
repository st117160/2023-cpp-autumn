#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>
#include<cstdlib>
#include<string>

void CountSize(char* filename, int& lines, int& maxLine)
{
	FILE* file = fopen(filename, "r");

	int currentLen = 0;
	while (!feof(file))
	{
		char c = 0;
		fscanf_s(file, "%c", &c);
		if (c == '\n')
		{
			lines++;
			maxLine = (maxLine > currentLen ? maxLine : currentLen);
			currentLen = 0;
		}
		else
		{
			currentLen++;
		}
	}
	lines++;
	fclose(file);
}

void ReadLines(char* filename, char** lines, int maxlen)
{
	FILE* file = fopen(filename, "r");

	int ind = 0;
	while (!feof(file))
	{
		fgets(lines[ind], maxlen, file);
	}

	fclose(file);
}

int StrLen(char* filename)
{
	int cnt = 0;
	while (filename[cnt] != '\0')
	{
		cnt++;
	}
	return cnt;
}

char* Strcat(char* a, char* b)
{
	int lena = StrLen(a);
	int lenb = StrLen(b);
	for (int i = 0; i < lenb + 1; i++)
	{
		a[lena] = b[i];
		lena++;
	}
	return a;
}


int Strstr(char* x, char* y)
{
	int ans = 0;
	int i = 0;
	int j = 0;
	while (x[i] != '\0')
	{
		if (x[i] == y[i + j])
		{
			ans = j;
			i++;
		}
		else 
		{
			i = 0;
			j++;
		}

	}

	return ans;
}

int Strcmp(char* a, char* b)
{
	while (*a)
	{
		if (*a != *b)
		{
			break;
		}

		a++;
		b++;
	}

	return *a - *b;
}

char* Substr(const char* str, int b, int a)
{
	int len = a - b;
	char* sub = (char*)malloc(sizeof(char) * (len + 1));

	for (int i = b; i < a && (*(str + i) != '\0'); i++)
	{
		*sub = *(str + i);
		sub++;
	}

	*sub = '\0';

	return (sub - len);
}


int main(int argc, char** argv)
{
	FILE* f = fopen("in1.txt", "r");

	char a[200] = { 0 };
	char b[200] = { 0 };
	fscanf(f, "%s", &a);
	fscanf(f, "%s", &b);

	fclose(f);

	char* n = Strcat(a, b);

	f = fopen("out.txt", "a");
	fprintf(f, "%s", n);
	fclose(f);

	FILE* file = fopen("in2.txt", "r");

	char x[200] = { 0 };
	char y[200] = { 0 };
	fscanf(f, "%s", &x);
	fscanf(f, "%s", &y);

	fclose(file);

	int k = Strstr(x, y);

	f = fopen("out.txt", "a");
	fprintf(file, "%d", k);

	fclose(f);

	FILE* f = fopen("in.txt", "r");

	char str1[256] = { 0 };
	char str2[256] = { 0 };
	fgets(str1, 100, f);
	fgets(str2, 100, f);

	fclose(f);

	int n = Strcmp(str1, str2);
	f = fopen("out.txt", "w");

	if (n > 0)
	{
		fprintf(f, "%s", "str1 is greater than str2");
	}
	else if (n < 0)
	{
		fprintf(f, "%s", "str1 is less than str2");
	}
	else
	{
		fprintf(f, "%s", "str1 is equal to str2");
	}

	fclose(f);

	FILE* f = fopen("in1.txt", "r");
	char word1[256] = { 0 };
	fscanf(f, "%s", &word1);
	char word2[256] = { 0 };
	fscanf(f, "%s", &word2);
	fclose(f);

	char* t = Strcat(word1, word2);

	f = fopen("out.txt", "w");
	fprintf(f, "%s", t);
	fclose(f);

	return 0;
}