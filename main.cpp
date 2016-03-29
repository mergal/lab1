#include <stdio.h>
#include <stdlib.h>
#include <time.h>


char **charSquare(int n);
void drawCharSquare(char **square, int n);



int main(int argc, char **argv)
{
	srand(atoi(*(argv+2)));
	int n=atoi(*(argv+1));
	drawCharSquare(charSquare(n), n);	
	
}



char **charSquare(int n)
{
	char **square=new char* [n];
	for(int i=0;i<n;i++)
		*(square+i)=new char [n];
	
	for(int i=0;i<n*n;i++)
		*(*(square+i%n)+i/n)=rand()%26+97;
	return square;
}



void drawCharSquare(char **square, int n)
{
	for(int i=0;i<n*n;i++)
	(i+1)%n==0?printf("%c\n", *(*(square+i%n)+i/n))
			:printf("%c ",*(*(square+i%n)+i/n));

	for(int i=0;i<n;i++)
		delete [] *(square+i);
	delete [] square;
}