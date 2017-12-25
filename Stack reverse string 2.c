
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
	char c[50];
	printf("ENTER STRING ");
	gets(c);
	int length=strlen(c);
	int i=0;
	int j=length-1;
	int y;
	while(i<j)
	{
		y=c[i];
		c[i]=c[j];
		c[j]=y;
		i++;
		j--;
	}
	printf("REVERSE : %s",c);

	return 0;
}
