#include<stdio.h>
#define _CRT_SECURE_NO_WARNINGS

void tower(int n, int* x, int* st, int* y, int* dt, int* z, int* tt);
int POP(int* s, int* t);
void PUSH(int* s, int* t, int d);

void main()
{
	int n, i, j, w;

	printf("PLease Enter the no of disks you want \n");
	scanf_s("%d", &n);

	w = n - 1;
	int stop = -1, ttop = -1, dtop = -1;
	int source[3], temp[3], dest[3];

	for (i = w, j = 1; i >= 0; i--, j++)
	{
		source[i] = j;
		stop++;
	}

	tower(n, source, &stop, dest, &dtop, temp, &ttop);
	for (i = 0; i < n - 1; i++)
		printf("%d", dest[i]);
}


void tower(int n, int* x, int* st, int* y, int* dt, int* z, int* tt)
{
	int q;
	if (n > 0)
	{
		tower(n - 1, x, st, z, tt, y, dt);
		q = POP(x, st);
		PUSH(y, dt, q);
		//x to z using y i.e source to temp using dest
		printf("DISK%d:%d-->%d\n", n, *x, *y);//largest to destination
		tower(n - 1, z, tt, y, dt, x, st);//temp to dest using source
	}
}
int POP(int* s, int* t)
{
	if (*t == -1)
		printf("Stack si empty\n");
	else
	{//printf("%dTHIS the top and %dthis the base stack\n",*t,*s);
		int d = s[*t];
		printf("%dthe no popped ", s[*t]);
		(*t)--;

		return d;

	}
}
void PUSH(int* s, int* t, int d)
//{//if(*t==n-1)
//printf("Stack is full\n");
//else
{
	(*t)++;
	s[*t] = d;
}

//}
//void DISPLAY(int *s,int *t
