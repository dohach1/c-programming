#include<stdio.h>
int main() {
  double first ,second,third;
  printf("enter the first number:");
  scanf("%lf",&first);
  printf("enter the second number:");
  scanf("%lf",&second);
  printf("\nbefore swapping,first number%.2lf\n",first);
  printf("\nbefore swapping,second number%.2lf\n",second);
  
  third=first;
  first=second;
  second=third;
  printf("\nresult, first number = %.2lf\n", first);
  printf("result, second number = %.2lf\n", second);
  return 0;
    
}

