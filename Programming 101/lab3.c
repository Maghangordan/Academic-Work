#include <stdio.h>
#include <math.h>

int main()
{
	int optChosen = 0, firNum, secNum;
	double answer, decNum1, decNum2;
	//Vi kör ALLT i while-loopen och använder states
	while (!(optChosen == 8))
	{
		if (optChosen == 0) {
			printf("1. Sum \n2. Sub\n3. Mul\n4. Div\n5. Sqr\n6. Pow\n7. Avg\n8. Exit\nEnter an Option: ");
			scanf("%d", &optChosen);
		}
		if (optChosen == 1)
		{
			printf("Enter first number ");
			scanf("%d", &firNum);
			printf("Enter second number ");
			scanf("%d", &secNum);
			answer = firNum + secNum;
			printf("Summation of %d+%d=%.0f\n", firNum, secNum, answer);
			optChosen = 0;
		}
		if (optChosen == 2)
		{
			printf("Enter first number ");
			scanf("%d", &firNum);
			printf("Enter second number ");
			scanf("%d", &secNum);
			answer = firNum - secNum;
			printf("Summation of %d-%d=%.0f\n", firNum, secNum, answer);
			optChosen = 0;
		}
		if (optChosen == 3)
		{
			printf("Enter first number ");
			scanf("%d", &firNum);
			printf("Enter second number ");
			scanf("%d", &secNum);
			answer = firNum * secNum;
			printf("Summation of %d*%d=%.0f\n", firNum, secNum, answer);
			optChosen = 0;
		}
		if (optChosen == 4)
		{

			printf("Enter first number ");
			scanf("%lf", &decNum1);
			printf("Enter second number ");
			scanf("%lf", &decNum2);
			if (decNum2 == 0) {
				printf("Cannot divide by zero\n");
			}
			else {
				answer = decNum1 / decNum2;
				printf("Summation of %.0f/%.0f=%.2f\n", decNum1, decNum2, answer);
			}
			optChosen = 0;
		}
		if (optChosen == 5)
		{
			printf("Enter the number ");
			scanf("%lf", &decNum1);
			answer = sqrt(decNum1);
			printf("Square root of %.0f is %.2f\n", decNum1, answer);
			optChosen = 0;
		}
		if (optChosen == 6)
		{
			printf("Enter first number ");
			scanf("%lf", &decNum1);
			printf("Enter second number ");
			scanf("%lf", &decNum2);
			answer = pow(decNum1, decNum2);
			printf("%.0f to the power %.0f is %.2f\n", decNum1, decNum2, answer);
			optChosen = 0;
		}
		if (optChosen == 7)
		{
			answer = 0;
			printf("Enter amount of numbers ");
			scanf("%d", &firNum);
			for (int i = 0; i < firNum; i++)
			{
				printf("enter number %d ", (i + 1));
				scanf("%lf", &decNum1);
				answer = answer + decNum1;
			}
			if (firNum == 0) {
				printf("Cannot calculate average of 0 numbers\n");
			}
			else {

				answer = answer / firNum;
				printf("Average of numbers entered is %.2f\n", answer);
			}
			optChosen = 0;
		}
	}
}

