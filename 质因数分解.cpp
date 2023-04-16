#include<stdio.h>
int Isprime(int n)
{
	for (int i = 2; i < n / 2; i++)
		if (n % i == 0) return 1;
	return 0;
}
void fun(int n)
{
	int i = 0, j;
	int m = n;
	for (j = 2;j < m/2; j++)
			while(n % j == 0)
			{
				printf("%d", j);
				if (n / j > 2) printf("*");
				n /= j;
			}
}
int main()
{
	int n;
	int c;
	scanf("%d", &n);
	c = Isprime(n);
	if (c)  fun(n);
	else printf("it is a prime\n");
}

