#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
	char str1[50], str2[50];
	int len1, len2, len;
	int i, j, tmp;
	gets(str1);
	gets(str2);

	len1 = strlen(str1);
	len2 = strlen(str2);
	len = len1 + len2;

	char* p_str1 = (char*) malloc (len * sizeof(char));
	while (p_str1 == NULL)
	{
		p_str1 = (char*) malloc (len * sizeof(char));
	}
	char* p_str2 = (char*) malloc (len * sizeof(char));
	while (p_str2 == NULL)
	{
		p_str2 = (char*) malloc (len * sizeof(char));
	}

	for (i = len-1, tmp = len1-1; i >= len-len1; i--)
	{
		p_str1[i] = str1[tmp--];
	}
	for (i = len-1, tmp = len2-1; i >= len-len2; i--)
	{
		p_str2[i] = str2[tmp--];
	}

	char* p_str[len];
	for (i = 0; i < len; i++)
	{
		p_str[i] = (char*) malloc (len * sizeof(char));
		while (p_str[i] == NULL)
		{
			p_str[i] = (char*) malloc (len * sizeof(char));
		}
		for (j = len-1; j >= 0; j--)
		{
			if (j >= i)					//?
			{
				p_str[i][j-i] = (p_str1[j] == 0 ? 0 : p_str1[j] - '0')\
				* (p_str2[len-1-i] == 0 ? 0: p_str2[len-1-i] - '0');	//特别注意
			}
		}
	}

	char* p_sum = (char*) malloc (len * sizeof(char));
	while (p_sum == NULL)
	{
		p_sum = (char*) malloc (len * sizeof(char));
	}

	for (i = len-1; i >= 0; i--)		//表示二维数组的列数，从右到左
	{
		for (j = 0; j < len; j++)
		{
			p_sum[i] += p_str[j][i];
		}
	}

	for (i = len-1; i > 0; i--)
	{
		if (p_sum[i] > 9)
		{
			p_sum[i-1] += p_sum[i] / 10;
		}
		p_sum[i] = p_sum[i] % 10 + '0';
	}
	p_sum[0] += '0';
	if (p_sum[0] != '0')
	{
		printf("%c", p_sum[0]);
	}
	for (i = 1; i < len; i++)
	{
			printf("%c", p_sum[i]);
	}
	printf("\n");

	free(p_str1);
	p_str1 = NULL;
	free(p_str2);
	p_str2 = NULL;
	free(p_sum);
	p_sum = NULL;
	for (i = 0; i < len; i++)
	{
		free(p_str[i]);
		p_str[i] = NULL;
	}
	return 0;
}
