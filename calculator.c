#include <stdio.h>
int main() {
double num1, num2;
char op;
printf("Enter first number: ");
scanf("%lf", &num1);
printf("Enter second number: ");
scanf("%lf", &num2);
printf("Enter operation (+, -, *, /): ");
scanf(" %c", &op);
switch(op) {
case '+':
printf("Result = %.2lf", num1 + num2);
break;
case '-':
printf("Result = %.2lf", num1 - num2);
break;
case '*':
printf("Result = %.2lf", num1 * num2);
break;
case '/':
if(num2 != 0)
printf("Result = %.2lf", num1 / num2);
else
printf("Error: Division by zero is not valided");
break;
default:
printf("Invalid operator");
}
return 0;
}
