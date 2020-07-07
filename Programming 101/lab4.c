#include <stdio.h>
#include <math.h>

int throw_at_rectangle(double x, double y, double x1, double y1, double x2, double y2)
{
	double xTemp, yTemp;
	if (x1 > x2) //x2,y2 should always be to the right of our arbitrary origin (don't know why)
	{
		xTemp = x1;
		x1 = x2;
		x2 = xTemp;
	}
	if (y1>y2) { //--||--
		yTemp = y1;
		y1 = y2;
		y2 = yTemp;
	}
	if (x1 == x2 || y1 == y2) //If (x1,y1) and (x2,y2) share either coordinate they span a line, not a rectangle
	{
		return -1;
	}
	else if (x > x1&& x<x2 && y>y1&& y < y2) // x is in [x1,x2] and y is in [y1,y2]
	{
		return 5;
	}
	else if (x < x1 || x > x2 || y < y1 || y > y2) //(x,y) utanför
	{
		return 0;
	}
	else if(x==x1||x==x2||y==y1||y==y2)
	{
		return 3;
	}
}

int outside_throw()
{
	if (throw_at_rectangle(0, 0, 1, 1, 2, 2) == 0)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
int on_right_edge()
{
	if (throw_at_rectangle(2, 2, 0, 0, 2, 2) == 3)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
int bullseye()
{
	if (throw_at_rectangle(1, 1, 0, 0, 2, 2) == 5)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
int backwards_throw()
{
	if (throw_at_rectangle(-10, -10, 0, 0, 2, 2)==0)
	{
		return 1;
	}
	else 
	{
		return 0;
	}
}
int broken_rectangle()
{
	if (throw_at_rectangle(0, 0, 1, 1, 1, 2) == -1)
	{
		return 1;
	}
	else 
	{
		return 0;
	}
}
int precision_throw_inside()
{
	if (throw_at_rectangle(1.111111111111, 1.111111111111, 0, 0, 2, 2) == 5)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

int main()
{
	int result;
	int antalFel = 0;
	result = outside_throw();			if (result == 0) { antalFel++; }
	printf("%d\n", result);
	result = on_right_edge();			if (result == 0) { antalFel++; }
	printf("%d\n", result);
	result = bullseye();				if (result == 0) { antalFel++; }
	printf("%d\n", result);
	result = backwards_throw();			if (result == 0) { antalFel++; }
	printf("%d\n", result);
	result = broken_rectangle();		if (result == 0) { antalFel++; }
	printf("%d\n", result);
	result = precision_throw_inside();  if (result == 0) { antalFel++; }
	printf("%d\n", result);
	if (antalFel >= 1)
	{
		printf("Number of errors: %d\n", antalFel);
	}
	else
	{
		printf("All tests passed successfully\n");
	}
	//3:(x,y) on either (x1,y1),(x2,y2)
	//0:(x,y) ej innanför (x1,y1),(x2,y2)
	//5:(x,y) innanför (x1,y1),(x2,y2)
	//2:samma kant (fel)

}
