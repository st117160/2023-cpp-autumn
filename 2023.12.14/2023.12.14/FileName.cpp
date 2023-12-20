#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>
#include<cstdlib>

int main(int argc, char** argv)
{
	int sentlen = 0;
	int cnt = 0;
	int max = 0;
	int start = 0;
	int maxbeg = 0;
	int maxend = 0;

	char ch = 0;
	int i = 0;

	FILE* f = fopen("in.txt", "r");

	while (!feof(f))
	{
		ch = fgetc(f);
		i++;
		if (ch == ' ')
		{
			cnt++;
			sentlen++;
		}
		else if (ch == '.')
		{
			if (sentlen > max)
			{
				maxbeg = start;
				max = sentlen;
				maxend = i;
			}
			sentlen = 0;
			start = i + 1;
		}
	}

	FILE* file = fopen("out.txt", "w");
	fprintf(file, "%d\n", cnt);

	fseek(f, maxbeg, SEEK_SET);

	for (int i = maxbeg; i < maxend + 1; i++)
	{
		fprintf(file, "%c", fgetc(f));
	}

	fclose(file);
	fclose(f);

	return 0;
}
