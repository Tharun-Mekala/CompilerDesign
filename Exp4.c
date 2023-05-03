#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdbool.h> 
void ELF(char s[])
{
	int not=0,i,f=0,j;
	for(i=0;i<strlen(s);i++)
		if(s[i]=='|')
			not++;
	if(not==0)
	{
		printf("Given production %s is not in left factoring\n",s);
		return;
	}
	char s1[not+1][100];
	int idx1=0,idx2=0;
	int Strlen[not+1],flag[not+1],c=0,ci=0;
	bool index[not+1];
	for(i=3;i<strlen(s);i++)
	{
		if(s[i]=='|')
		{
			idx2=0;
			Strlen[idx1]=c;
			flag[idx1]=0;
			index[idx1]=true;
			c=0;
			idx1++;
		}
		else
		{
			s1[idx1][idx2]=s[i];
			c++;
			idx2=idx2+1;
		}
	}
	Strlen[idx1]=c;
	flag[idx1]=0;
	index[idx1]=true;
	int k=0;
	for(i=0;i<not;i++)
	{
		int j=i+1;
		while(j<=not)
		{
			if(s1[i][k]==s1[j][k]&&index[j]==true)
			{
				int len=(Strlen[i]>Strlen[j])?Strlen[j]:Strlen[i];
				for(k=1;k<=len;k++)
				{
					if(s1[i][k]!=s1[j][k])
					{
						break;
					}
				}
				if(i==0)
				flag[i]=k-1;
				else
				flag[i]=(flag[i]>k-1)?k-1:flag[i];
				flag[j]=i;
				index[j]=false;
			}
			j++;
			k=0;
		}
	}
	printf("%c->",s[0]);
	for(i=0;i<=not;i++)
	{
		if(index[i]==true)
		{
			if(f==1)
					printf("%c'|",s[0]);
			for(j=0;j<=flag[i];j++)
			{
				printf("%c",s1[i][j]);
				f=1;
			}
		}	
	}
	f=0;
	printf("\n%c'->",s[0]);
	for(i=0;i<=not;i++)
	{
		int si=flag[i];
			if(index[i]==false)
				si=flag[flag[i]];
		if(Strlen[i]!=si+1)
		{
			if(f==1)
			printf("|");
			for(j=si+1;j<Strlen[i];j++)
			{
				printf("%c",s1[i][j]);
			}
			f=1;
		}
	}
	printf("|#\n");	
}
void main()
{
	char s[100];
	int n;
	printf("Enter no of productions : ");
	scanf("%d",&n);
	while(n--!=0)
	{
		printf("Ener the Production in the form(A->A@|B) : ");
		scanf("%s",s);
		printf("The Production is : %s\n",s);
		ELF(s);
	}
}
