#include<stdio.h>
#include"arith.h"

int main()
{
	int t,u,v,x;

	t=add(20,10);
	printf("The sum is: %d\n",t);
	
	u=sub(40,10);
	printf("The substracted value is: %d\n",u);

	v=mul(4,5);
	printf("The product is: %d\n",v);

	x=div(100,10);
	printf("The quotient is: %d",x);

	return 0;
}
