#include<stdio.h>
int main() {
  double a,b, prod;
  printf("enter two numbers: ");
  scanf("%lf %lf",&a, &b);
  prod= a*b;
  printf("prod=%.3lf",prod);
  return 0;
}
