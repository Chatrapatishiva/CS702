#include<stdio.h>
#include<time.h>
#include"gcd.h"

#define N 10000
unsigned int a[N],b[N];
void createSetA();
void createSetB();
int main()
{
	int count;
	int ch,c;
	long int i,j;
	clock_t start,end;
	createSetA();
	createSetB();
	printf("Count the number of relatively coprime:");
	printf("Approach to GCD\n(1) Recursive Algorithm \n(2) Euclidean Algorithm \n3) Brute-force Algorithm\n");
	printf("Enter your choice=");
	scanf("%d", &ch);
	count=0;
	switch(ch){
		case 1: 
			printf("Recursive Approach\n");
			start=clock();
			for(i=0;i<N;i++)
			{
				if(a[i]!=0)
				{
					for(j=0;j<N;j++)
					{
						if(b[j]!=0)
						   c = gcd_recursive(a[i], b[j]);
						if(c==1)
						  count++;			
					}
				}
			}
			end=clock();
		      break;
		case 2:
			printf("Euclidean Approach using Iteration\n");
			start=clock(); 
			for(i=0;i<N;i++)
			{
				for(j=0;j<N;j++)
				{
					c = gcd_euclidean(a[i], b[j]);
					{
						if(c==1)
						  count++;			
					}
				}
			}
			end=clock();
			break;
		case 3:
			printf("Euclidean Approach using Recursion\n");
			start=clock();
			for(i=0;i<N;i++)
			{
				for(j=0;j<N;j++)
				{
					c = gcd_bruteforce(a[i], b[j]);
					{
						if(c==1)
						  count++;			
					}
				}
			}
			end=clock();
			break;
		default: 
			printf("Invalid input! Using brute force algorithm!\n");
	}
	printf("count coprime in A & B=%d\n",count);
	printf("CPU Time:%lf\n",((double) (end - start)) / CLOCKS_PER_SEC);
	return 0;
}
void createSetA()
{
	unsigned long int i;
	int range=100000;
	for( i=0;i<N;i++)
	{
		a[i]=rand()%range;
	}
}
void createSetB()
{
	unsigned long int i;
	int range=100000;
	for( i=0;i<N;i++)
	{
		b[i]=(rand()%range)/2;
	}
}
