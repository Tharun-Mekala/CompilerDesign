#include<stdio.h>
#include<string.h>
void main()
{
	char s[100];
	printf("Enter the string : ");
	scanf("%s",s);
	printf("Given String : ");
	puts(s);
	int idx=0,i;
	printf("State\tcharacter\tNextState\n");
	for(i=0;i<strlen(s);i++)
	{
		printf("q%d\t%c\t\t",idx,s[i]);
		if(idx==0)
		{
			if(s[i]=='a')
				idx=1;
			else 
				idx=0;
		}
		else if(idx==1)
		{
			if(s[i]=='a')
				idx=1;
			else if(s[i]=='b')
				idx=2;
			else 
				idx=0;
		}
		else if(idx==2)
		{
			if(s[i]=='a')
				idx=1;
			else if(s[i]=='b')
				idx=0;
			else 
				idx=3;
		}
		else
		{
			if(s[i]=='a')
				idx=1;
			else 
				idx=0;
		}
		printf("q%d\n",idx);
	}
	if(idx==3)
	printf("Given String %s accepted\n",s);
	else
	printf("Given String %s not accepted\n",s);
}
