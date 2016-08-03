#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main(int argc, char const *argv[])
{
	char str1[50], str2[50];
	gets(str1);
	gets(str2);
	int len1 = strlen(str1);
	int len2 = strlen(str2);
	int len = len1 >= len2 ? len1: len2;
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
	int i, tmp;
	for (i = len-1, tmp = len1-1; i >= len-len1; i--)
	{
		p_str1[i] = str1[tmp--];
	}
	for (i = len-1, tmp = len2-1; i >= len-len2; i--)
	{
		p_str2[i] = str2[tmp--];
	}
	char* p_str = (char*) malloc ((len+1) * sizeof(char));
	while (p_str == NULL)
	{
		p_str = (char*) malloc ((len+1) *sizeof(char));
	}

	for (i = len-1; i >= 0; i--)
	{
		p_str[i+1] = (p_str1[i] == 0 ? 0 : (p_str1[i]-'0')) \
		+ (p_str2[i] == 0 ? 0 : (p_str2[i]-'0')) + '0';
	}

	p_str[0] = '0';
	for (i = len; i >= 1; i--)
	{
		if (p_str[i] > '9')
		{
			p_str[i-1] += (p_str[i] - '0') / 10;
			p_str[i] = (p_str[i] - '0') % 10 + '0';
			
		}
	}
	if (p_str[0] != '0')
	{
		printf("%c", p_str[0]);
	}
	for (i = 1; i <= len; i++)
	{
		printf("%c", p_str[i]);
	}

	free(p_str1);
	p_str1 = NULL;
	free(p_str2);
	p_str2 = NULL;
	free(p_str);
	p_str = NULL;
	return 0;
}
