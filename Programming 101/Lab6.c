#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>


struct students
{
	int persnum;
	char name[100];
	char wholeLine[100];
	char gender[100];
	char program[100];
	int age;
	char email[100];
	
	struct students* next;
};

struct students* head = NULL;
struct students* current = NULL;

struct program
{
	char program[100];
	int men, female, totalAge;
	struct program* next;
};
struct program* goNext = NULL;
struct program* first = NULL;



void add() //Always adds to the first location
{
	char tempChar[100];
	struct students* link = (struct students*) malloc(sizeof(struct students));
	printf("Enter personal number, name, gender, study program, age, email\n");
	scanf("%[^\n]", tempChar);
	strcpy(link->wholeLine, tempChar);
	sscanf(tempChar,"%d,%[^','],%[^','],%[^','],%d,%s", &link->persnum, &link->name, &link->gender, &link->program, &link->age, &link->email);
	
	
	link->next = head;
	head = link;
	
	
}
void print()
{
	struct students* ptr = head;
	
	while (!(ptr == NULL))
	{
		printf("%d %s %s %s %d %s are in the current session\n", ptr->persnum, ptr->name, ptr->gender, ptr->program, ptr->age, ptr->email);
		ptr = ptr->next;
	}
	
	
}
struct students* hittaPersnum(int personnummer)
{
	struct students* current = head;

	if (head == NULL) //If there are no current entries in students
	{
		return NULL;
	}
	while (current->persnum != personnummer)
	{
		if (current->next == NULL)
		{
			return NULL;
		}
		else
		{
			current = current->next;
		}
	}
	
	return current; //IFF the correct personal number is found
	
}
struct students* hittaNamn(char namnet[100])
{
	struct students* current = head;
	
	while ((current->name)!=NULL)
	{
		if (strcmp(current->name, namnet)==0)
		{
			printf("%d %s %s %s %d %s\n", current->persnum, current->name, current->gender, current->program, current->age, current->email);
		}
		if (current->next != NULL)
		{
			current = current->next;
		}
		else
		{
			break;
		}
			
	}
	
}
struct students* hittaProgram(char programmet[100])
{
	struct students* current = head;

	while ((current->program) != NULL)
	{
		if (strcmp(current->program, programmet) == 0)
		{
			printf("%d %s %s %s %d %s\n", current->persnum, current->name, current->gender, current->program, current->age, current->email);
		}
		if (current->next != NULL)
		{
			current = current->next;
		}
		else
		{
			break;
		}

	}
	
}
struct students* delete(int personnummer)
{
	struct students* current = head;
	struct students* previous = NULL;
	if (head == NULL) 
	{
		return NULL;
		
	}
	while (current->persnum != personnummer)
	{
		if (current->next == NULL)
		{
			return NULL;
			
		}
		else
		{
			previous = current;
			current = current->next;
		}
	}
	if (current == head)
	{
		
		head = head->next; //move one step for all list
	}
	else 
	{
		previous->next = current->next; //change other iterating current pointer
	}
	
	
	return current;
	
}
void statistics()
{
	int i;
	int j;
	double numFemale = 0;
	double numMale = 0;
	char currProg[100];
	int currPlaceNew=-1;
	int currPlaceOld;
	int maxSize = 0;
	bool isInList = false;
	double numAge=0;
	double avgAge=0;
	struct students* statlink = head;
	struct students* tmp;
	//general statistics for current database
	while (statlink->program != NULL)
	{
		if (strcmp(statlink->gender,"female") == 0)
		{
			numFemale++;
		}
		if (strcmp(statlink->gender,"male") == 0)
		{
			numMale++;
		}
		numAge = numAge+statlink->age;
			
		if (statlink->next != NULL)
		{
			statlink = statlink->next;
		}
		else
		{
			break;
		}
		
	}
	avgAge = (numAge/(numFemale + numMale));

	printf("Total number of students: %.f\n", (numFemale + numMale));
	printf("Number of female students: %.f\n", numFemale);
	printf("Number of male students: %.f\n", numMale);
	printf("Average age: %.f/%.f=%.1f\n",numAge,(numFemale+numMale), avgAge);
	//Next part: for each program
	statlink = head;
	while (statlink != NULL)
	{
		maxSize++;
		
		if (statlink->next != NULL) 
		{
			statlink = statlink->next;
		}
		else
		{
			break;
		}
	}
	//char *maxAmountOfPrograms[100] = malloc(maxSize * sizeof(char)); //We now have a sufficiently large array that can fit as many programs as there are students
	statlink = head;										 //We now want to find out how many programs there are and allocate the struct with the information
	struct program* progptr = (struct program*) malloc(maxSize * sizeof(struct program));
	for (i = 0; i < maxSize; i++) 
	{
		progptr[i].female = 0;
		progptr[i].men = 0;
		progptr[i].totalAge = 0;
	}
	i = 0;
	while (statlink != NULL)
	{
		
		for (i = 0; i < maxSize; i++)
		{
			if (strcmp(statlink->program, progptr[i].program) == 0)
			{
				isInList = true; //is in progptr[i].program at place i

				currPlaceOld = i;
				break; //Break for-loop, goes to allocation
			}
			if (i == maxSize-1)
			{
				isInList = false; //is not in progptr[i].program at place i
				currPlaceNew= currPlaceNew+1; //Starts at -1 so first program will be at progptr[0]
			}
		}
		
		if (isInList==true)
		{
			progptr[currPlaceOld].totalAge = progptr[currPlaceOld].totalAge + statlink->age;
			if (strcmp(statlink->gender, "female") == 0)
			{
				progptr[currPlaceOld].female++;
			}
			if (strcmp(statlink->gender, "male") == 0)
			{
				progptr[currPlaceOld].men++;
			}
		}
		if (isInList==false)
		{
			strcpy(progptr[currPlaceNew].program,statlink->program);
			progptr[currPlaceNew].totalAge = progptr[currPlaceNew].totalAge + statlink->age;
			if (strcmp(statlink->gender,"female")==0)
			{
				progptr[currPlaceNew].female++;
			}
			if (strcmp(statlink->gender, "male") == 0)
			{
				progptr[currPlaceNew].men++;
			}
		}

		if (statlink->next != NULL)
		{
			statlink = statlink->next;
		}
		else
		{
			break;
		}
	}
	for (i = 0; i < maxSize; i++) 
	{
		if (progptr[i].totalAge != 0&&(progptr[i].female!=0||progptr[i].men!=0))
		{
			avgAge = (double) (progptr[i].totalAge) / (progptr[i].female + progptr[i].men);
			printf("For program: %s male: %d female: %d Average age %.1f\n", (progptr[i].program), progptr[i].men, progptr[i].female, avgAge);

		}
	}
	
	
	
	
}
void save()
{
	FILE* fileptr;
	struct students* saveptr = head;
	
	char fileName[100];
	printf("Enter name of file\n");
	scanf("%s", &fileName); getchar();
	fileptr = fopen(fileName,"w");
	if (fileptr != NULL)
	{
		while (saveptr->program != NULL)
		{
			fprintf(fileptr, "%d,%s,%s,%s,%d,%s,\n", saveptr->persnum, saveptr->name, saveptr->gender, saveptr->program, saveptr->age, saveptr->email);

			if (saveptr->next != NULL)
			{
				saveptr = saveptr->next;
			}
			else
			{
			break;
			}

		}
	}
	fclose(fileptr);
	
}
void load()
{
	FILE* fileptr;
	struct students* loadptr = (struct students*) malloc(sizeof(struct students));
	struct students* tmp;
	char fileName[100];
	char savePrompt[2];
	int i;
	
	
	printf("Enter name of file\n");
	scanf("%s", &fileName); getchar();
	fileptr = fopen(fileName, "r");
	if (fileptr == NULL)
	{
		printf("No file named %s was found\n", fileName);

	}
	else if (fileptr != NULL)
	{
		printf("File named %s was found. Do you want to load it? [y/n]\n", fileName);
		scanf("%s", &savePrompt); getchar();
		if (strcmp(savePrompt, "y") == 0)
		{
			struct students* ptr = head;
			while (!(ptr == NULL))
			{
				delete(ptr->persnum); //Clear current DB from head to NULL
				ptr = ptr->next;
			}
			while (ptr != NULL)
			{
				if (ptr->next != NULL)
				{
					tmp = ptr;
					ptr = ptr->next;
					free(tmp);
				}
				else
				{
					break;
				}
			}
			while (fscanf(fileptr, "%d,%[^','],%[^','],%[^','],%d,%s", &loadptr->persnum, &loadptr->name, &loadptr->gender, &loadptr->program, &loadptr->age, &loadptr->email) != EOF)
			{
				loadptr->next = head;
				head = loadptr;
				loadptr = (struct students*) malloc(sizeof(struct students));

			}
			fclose(fileptr);
			printf("Done\n");
		}
		else
		{
			printf("File NOT loaded\n");
			fclose(fileptr);
		}
	}
	
}
void main()
{
	int choice = 0;
	int entries = 0;
	int searchEntries = 0;
	int i;
	char nameSearch[100];
	char programSearch[100];
	char tempChar[100];
	struct students* studentExists;
	choice = options(choice);
	while (choice != 7)
	{
		if (choice == 0)
		{
			print();
			choice = options(choice);
		}
		if (choice == 1)
		{
			printf("How many students do you want to add?\n");
			scanf("%d", &entries); getchar();
			for (i = 0; i < entries; i++)
			{
				add();
			}

			choice = options(choice);
		}
		if (choice == 2)
		{
			printf("Enter the personal number of the student that you want to modify\n");
			scanf("%d", &entries); getchar();
			studentExists = hittaPersnum(entries);
			if (studentExists != NULL)
			{
				
				printf("Student found!\n");
				printf("%d %s %s %s %d %s\n", studentExists->persnum, studentExists->name, studentExists->gender, studentExists->program, studentExists->age, studentExists->email);
				printf("Please enter the new information of student %d\n", studentExists->persnum);
				printf("In the format name, gender, study program, age, email\n");
				scanf("%[^\n]", tempChar);
				
				printf("%s",tempChar);
				sscanf(tempChar, "%[^','],%[^','],%[^','],%d,%s",&studentExists->name, &studentExists->gender, &studentExists->program, &studentExists->age, &studentExists->email);
				
			}
			else
			{
				printf("No student with that personal number was found\n");
			}
			choice = options(choice);
		}
		if (choice == 3)
		{
			printf("Enter the personal number of the student that you want to delete\n");
			scanf("%d", &entries); getchar();
			if (delete(entries)==NULL)
			{
				printf("No student with the personal number %d was found\n",entries);
			}
			else
			{
				printf("Student with personal number %d was deleted\n",entries);
			}
			choice = options(choice);
		}
		if (choice == 4)
		{
			printf("1. Personal number\n2. Name\n3. Study Program\n4. Statistics\n");
			scanf("%d", &searchEntries); getchar();
			if (searchEntries == 1) 
			{
				printf("Enter the personal number of the student that you want to search for\n");
				scanf("%d", &entries); getchar();
				studentExists = hittaPersnum(entries);
				if (studentExists != NULL)
				{
					printf("Student found!\n");
					printf("%d %s %s %s %d %s\n", studentExists->persnum, studentExists->name, studentExists->gender, studentExists->program, studentExists->age, studentExists->email);
				}
				else
				{
					printf("No student with that personal number was found\n");
				}
			}
			if (searchEntries == 2)
			{
				printf("Enter the student name that you want to search for\n");
				scanf("%[^\n]s", &nameSearch); getchar();
				hittaNamn(nameSearch);
			}
			if (searchEntries == 3)
			{
				printf("Enter the studying program of the student that you want to search for\n");
				scanf("%[^\n]s", &programSearch); getchar();
				hittaProgram(programSearch);
			}
			
			if (searchEntries == 4)
			{
				
				statistics();
				
			}
			choice = options(choice);

		}
		if (choice == 5)
		{
			save();
			choice = options(choice);
		}
		if (choice == 6) 
		{
			load();
			choice = options(choice);
		}
	}
	
	studentExists = head;
	struct students* tmp;
	while (studentExists != NULL)
	{
		if (studentExists->next != NULL)
		{
			tmp = studentExists;
			studentExists = studentExists->next;
			free(tmp);
		}
		else
		{
			break;
		}
	}


}
int options(int input)
{
	printf("1. Add\n");
	printf("2. Modify\n");
	printf("3. Delete\n");
	printf("4. Search\n");
	printf("5. Save\n");
	printf("6. Load\n");
	printf("7. Exit\n");
	scanf("%d", &input);
	return input;
}
