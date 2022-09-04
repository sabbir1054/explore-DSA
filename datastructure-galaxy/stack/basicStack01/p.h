#include <stdio.h>
#include <string.h>
int top = -1;
char Stack[4] = {'\0'};
void Push(char x)
{
    Stack[++top] = x;
    return;
}
char Pop(void)
{
    return Stack[top--];
}