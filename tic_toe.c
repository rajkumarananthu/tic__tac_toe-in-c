#include<stdio.h>
#include<string.h>
void display();
void init();
int check();
int hor_check();
int ver_check();
int diag_check();


char mat[3][3];
char A;

int main()
{
	int m=0,n=0,c=0,d=0,p=0,q=0,cnt=0;
	init();	
	while(c!=1||d!=1)
	{
		printf("\nthe possition for player 0\n");
		scanf("%d %d",&m,&n);
		cnt++;
		mat[m][n]='0';
		c=check(m,n);
		display();
		if(c==1)
		{
			printf("\n----------------------player 0 wins\n");
			break;
		}
		if(cnt!=9)	
		{	
			printf("\nposition for player 1\n");
			scanf("%d %d",&p,&q);
			cnt++;
			mat[p][q]='1';
			d=check(p,q);
			display();
			if(d==1)
			{
				printf("\n----------------------player 1 wins\n");
				break;
			}		
		}
		else
		{
			printf("\n\n---------------------------------\n\n");
			printf("TIE BETWEEN THE PLAYERS\n");
			break;
		}
	}
	scanf("%c",&A);
}



void init()
{
	int i,j;
	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
		{
			mat[i][j]=' ';
		}
	}
	printf("\nnWELCOME TO TIC_TAC_TOE GAME\n\n");
	printf("\n=-------------------=====\n=========================\n");
}


void display()
{
	int i,j;
	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
			printf("%c\t",mat[i][j]);
		printf("\n");
	}
}


int check(int u,int v)
{
	return (hor_check(u,v)||ver_check(u,v)||diag_check(u,v));
}


int ver_check(int u,int v)
{
	switch(u)
	{
		case 0:if(mat[u][v]==mat[u+1][v]&&mat[u+1][v]==mat[u+2][v]) 
				return 1;
			else
				return 0;
			break;
		case 1:if(mat[u-1][v]==mat[u][v]&&mat[u][v]==mat[u+1][v]) 
				return 1;
			else
				return 0;
			break;
		case 2:if(mat[u-2][v]==mat[u-1][v]&&mat[u-1][v]==mat[u][v]) 
				return 1;
			else
				return 0;
			break;
	}
}

int hor_check(int u,int v)
{
	switch(v)
	{
		case 0:if(mat[u][v]==mat[u][v+1]&&mat[u][v+1]==mat[u][v+2]) 
				return 1;
			else
				return 0;
			break;
		case 1:if(mat[u][v-1]==mat[u][v]&&mat[u][v]==mat[u][v+1]) 
				return 1;
			else
				return 0;
			break;
		case 2:if(mat[u][v-2]==mat[u][v-1]&&mat[u][v-1]==mat[u][v]) 
				return 1;
			else
				return 0;
			break;
	}
}

int diag_check(int u,int v)
{
	if(u!=v||!(u==0&&v==2||v==0&&u==2))
		return 0;
	else
	{
		if(u==v&&v!=1)
		{
			if(mat[1][1]==mat[2][2]&&mat[2][2]==mat[0][0])
				return 1;
			else
				return 0;
		}
		else
		{
			if(mat[2][0]==mat[1][1]&&mat[1][1]==mat[0][2])
				return 1;
			else
				return 0;
		}
	}
}





















