#include<iostream>
#define SIZE_INT sizeof(int)
#define INT_BIT SIZE_INT*8-1
int main() {
    
    int b;
    scanf("%d",&b);
   while(b--)
   {unsigned int num,rot=2147483649,rot1,n1;
   
	scanf("%d",&num);
	 n1=num;
	 rot1=num;
	while(rot!=n1)
	{	
	   int rep=(num>>INT_BIT);
	   num=(num<<1)|rep;
       printf("%d\t",num);
	   if(rot1<num)
	   {
	       rot1=num;
	   }
	   rot=num;
	   
	}
	printf("%u \n",rot1);
   }
	return 0;
}