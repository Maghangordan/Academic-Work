#include <stdio.h>
#include <string.h>
#include <ctype.h>


int main()
{
	int optChosen = 0;
	char input[100];
	char removed[100];
	char added[100];
	char cleanInput[100];
	int somevar;
		
	//Vi kör ALLT i while-loopen och använder states
	while (!(optChosen == 8))
	{
		if (optChosen == 0) {

			printf("1. Split text \n2. Upper case to lower case\n3. Lower case to upper case\n4. Remove a character\n5. Add a character\n6. Replace a character\n7. Statistics\n8. Exit\nEnter an Option: \n");
			scanf("%d",&optChosen);
			getchar();
		}
		if (optChosen == 1)
		{
			printf("Enter text to be split unto seperate lines\n");
			fgets(input, 100, stdin);
			for (int i = 0; i < sizeof(input); i++)
			{
				somevar = (int)input[i];
				if (!(somevar == 0) && !(somevar == 10) && !(somevar == -52)) 
				{
					printf("%c",input[i]);
				}
				if (somevar == 32) {
					printf("\n");
				}
			}
			printf("\n");
			
			optChosen = 0;
			
		}
		if (optChosen == 2)
		{
			
			printf("Enter text to be converted lower case\n");
			fgets(input, 100, stdin);
			for (int i = 0; i<100; i++)
			{
				if (input[i] >= 65 && input[i] <= 90)
				{
					input[i] = input[i] + 32;
					printf("");
				}
			}
			printf("%s", input);
			optChosen = 0;
		}
		if (optChosen == 3)
		{
			printf("Enter text to be converted to upper case\n");
			fgets(input, 100, stdin);
			for (int i = 0; i < 100; i++)
			{
				if (input[i] >=97 && input[i] <= 122)
				{
					input[i] = input[i] - 32;
					printf("");
				}
			}
			printf("%s", input);
			optChosen = 0;
		}
		if (optChosen == 4)
		{
			printf("Enter text for character removal\n");
			fgets(input, 100, stdin);
			printf("Enter character to be removed\n");
			fgets(removed, 100, stdin);
			
			int j; j = 0;
			for (int i=0;i<sizeof(input);i++)
			{
				if (!(input[i]==removed[0]))
				{
					cleanInput[j] = input[i]; j++;	
				}
			}
			printf("%s",cleanInput);
			optChosen = 0;
		}
		if (optChosen == 5)
		{
			printf("Enter text to add a character at the end of each word to\n");
			fgets(input,100,stdin);
			printf("Enter character to add to the end of each word\n");
			fgets(added, 100, stdin);
			int j; j = 0;
			int position; position = 0;
			int spaces; spaces = 0;
			for (int i = 0; i < sizeof(input); i++) 
			{
				somevar = (int)input[i];
				
				if (!(somevar == 0) && !(somevar == 10) && !(somevar == -52)&&!(somevar==32)) 
				{
					printf("%c", input[i]);
				}
				if (input[i]==' '&&input[i-1]!=' ')
				{
					printf("%c ", added[0]);	
				}
				if (input[i] == ' ' && input[i - 1] == ' ')
				{
					printf(" ");
				}
				if (somevar == 0)
				{
					printf("%c ", added[0]);
				}
			}
			printf("\n");
			optChosen = 0;
		}	
		if (optChosen == 6)
		{
			printf("Enter text which may or may not include a character which should be replaced\n");
			fgets(input,100,stdin);
			printf("Which character should be replaced?\n");
			fgets(removed, 100, stdin);
			printf("Enter new character\n");
			fgets(added,100,stdin);
	
			for (int i = 0; i < sizeof(input); i++)
			{
				if (input[i] == removed[0])
				{
					input[i] = added[0]; 
				}
			}
			printf("%s\n",input);
			optChosen = 0;
		}
		if (optChosen == 7)
		{
			fflush(stdin);
			printf("Enter a text\n");
			fgets(input, 100, stdin);
			int words = 0;
			int charNum = 0;
			int tempvar;
			int j; j = 0;
			int charay[100];
			int charayClean[100];
			int charayCleanCount[100];
			int found;
			int tempAscii = 0;
			int stat[128] = { 0 };
			char tempchar = ' ';
			
			for (int i=0;i<sizeof(input);i++) //checking amount of words and characters
			{
				if (input[i] == ' '&&input[i+1]!=' ')
				{
					words++; 
				}
				if (input[i] == '\0')
				{
					words++;
				}
				tempvar = (int)input[i];

				if (!(tempvar == -52) && !(tempvar == 10) && !(tempvar == 0))
				{
					charNum++;
				}
			}
			printf("Words: %d\n", words);
			printf("Characters including spaces: %d\n", charNum);
			
			for (int i = 0; i < sizeof(input); i++)
			{
					
				tempvar = input[i];
				if (tempvar != -52 && tempvar != 0 && tempvar != 10)
				{

					stat[(int)input[i]]++;
					
				}
				
			}
			for (int i = 0; i < 128; i++)
			{
				
				if (stat[i] != 0) {
					tempchar = i;
					printf("' %c ' found %d times\n",tempchar,stat[i]);
				}
			}

			optChosen = 0;
		}
	}
}


