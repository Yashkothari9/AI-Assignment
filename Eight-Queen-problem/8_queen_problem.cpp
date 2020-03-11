#include <iostream>
#include<stdlib.h>
#define N 8
using namespace std;

struct node{
int array_list[8];
struct node *link;
};
struct node *forward_node = NULL;
struct node *backward = NULL;
struct node* flag;

int *get_front() {
 flag = forward_node;
 if (flag->link != NULL) {
 forward_node=forward_node->link;
 return flag->array_list;
 } else {
 flag =forward_node;
 forward_node = NULL;
 backward = NULL;
 return flag->array_list;

 }

}
void insert_into(int value,int ar[N]) {
int check =0;
 if (backward == NULL) {
 backward = (struct node *)malloc(sizeof(struct node));
 backward->link = NULL;
 for(int i=0;i<N;i++)
 {
	if(ar[i]==0 && check==0)
	{
	backward->array_list[i]=value;
	check++;
	}
	else
	{
	backward->array_list[i]=ar[i];
	}
 }
 forward_node = backward;
 } else {
 flag=(struct node *)malloc(sizeof(struct node));
 backward->link = flag;
 for(int i=0;i<N;i++)
 {
 if(ar[i]==0 && check==0)
 {
 flag->array_list[i]=value;
 check++;
 }
else
{
flag->array_list[i]=ar[i];
}
 }
 flag->link = NULL;
 backward = flag;
 }
}

void matrix_print(int board[N][N],int ls[N])
{
	for(int i=0;i<N;i++)
	{
	board[i][ls[i]-1]=1;
	}
 for (int i = 0; i < N; i++)
 {
 for (int j = 0; j < N; j++)
 cout <<" | " << board[i][j];
 cout<<" |";

 cout << "\n";
 cout<<"----------------------------------" <<endl ;
 }
 exit(0);

}

bool clear(int board[N][N], int cols, int l[N])
{
int check = 0;

 int i, j,rows,b[8][8]={0};

 for(int i=0;i<N;i++)
 {
 if(l[i]==0 && check==0)
 {
 rows=i;
 break;
}
if(l[i]!=0)
{
b[i][l[i]-1]=1;
}
}
 for (i = 0; i < rows; i++)
 if (b[i][cols])
 return false;

 for (i = rows, j = cols; i >= 0 && j >= 0; i--, j--)
 if (b[i][j])
 return false;

 for (i = rows, j = cols; i >= 0 && j < N; i--, j++)
 if (b[i][j])
 return false;

 if(rows==7)
 {
 l[rows]=cols+1;
 matrix_print(board,l);
}

 return true;
}

void solve(int board[N][N],bool cond)
{
int array_list[N]= {0};
 if(!cond)
 {
	int *ptr;
	ptr = get_front();
	for(int i=0;i<N;i++)
	{
	array_list[i]=*ptr;
	ptr++;
	}

	for(int i=0;i<N;i++)
	{
	if(clear(board,i,array_list))
	{
	insert_into(i+1,array_list);
	}
	}
	}

	if(cond)
	{
	for (int i = 0; i < N; i++)
	{
	insert_into(i+1,array_list);
	}
	cond=false;
	}
	solve(board,cond);
}

int main()
{
 int i,j;
 int board[N][N] ;
 for(i=0;i<8;i++){
 for(j=0;j<8;j++){
 board[i][j]=0;
 }
 }
 solve(board, true);

 return 0;
}
