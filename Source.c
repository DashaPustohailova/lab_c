
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

#include <stdlib.h>

#include <windows.h>

#define LETTER 1
#define NOT_THE_LETTER 0
#define NO 0
#define YES 1
#define MAXLEN 1000

void main(void)

{

	HANDLE hStdout; 

	FILE *fp;

	char line[MAXLEN]; 

	char word[MAXLEN]; 

	int i;

	int flag,komm=NO, s_komm = NO;

	int prev_flag;

	char *ptr; 

	WORD foregroundColor0; 

	WORD textAttribute; 


	hStdout = GetStdHandle(STD_OUTPUT_HANDLE);

	foregroundColor0 = FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN;//цвет букв

	fp = fopen("test.txt", "rt");

	if (fp == NULL)

		return; 

	while (!feof(fp))
	{
		
		ptr = fgets(line, MAXLEN, fp);
		komm = NO;
		//s_komm = NO;
		if (ptr == NULL)

			break;

		i = 0;

		prev_flag = flag = LETTER;

		word[0] = '\0';
		//komm = NO;
		while (*ptr!=0)

		{

			prev_flag = flag; 

			if (*ptr == ' ' || *ptr == ',' || *ptr == '.' || *ptr == '\n' || *ptr == '/' )

				flag = NOT_THE_LETTER;

			else

				flag = LETTER;

			if (flag != prev_flag)

			{

				word[i] = '\0';

				if (*ptr == '/')
				{
					if (*(ptr + 1) == '/')
						komm = YES;
					if (*(ptr + 1) == '*')
						s_komm = YES;
					else if (*(ptr - 1) == '*')
						s_komm = NO;
					
				}
				else
				{
					if ((komm == YES)|| (s_komm == YES))
					{
						textAttribute = foregroundColor0;
						SetConsoleTextAttribute(hStdout, textAttribute);
					}
					
					else
					  SetConsoleTextAttribute(hStdout, 7);

				}

				printf("%s", word); 
				i = 0; 

			}

			word[i++] = *ptr++;

		}

		if (i != 0)

		{

			word[i] = '\0';

			printf("%s", word);

		}
	}

	printf("\n");

	system("pause");

}