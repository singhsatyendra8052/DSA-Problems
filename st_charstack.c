#include<stdio.h>
#include<stdlib.h>
int top = -1;
int maxsize;
char *stack;
void initializeStack(int size) {
    maxsize = size;
    stack = (char *)malloc(maxsize * sizeof(char));
}
int isFull() {
    return (top == maxsize - 1);
}

void push()
{
    char d;
    getchar(); // Consume the newline character
    scanf("%c", &d);
    
    if (isFull())
    {
        printf("stack overflow");
    }
    else {
        top = top + 1;
        stack[top] = d;
    }
}

void display()
{
    for (int i = top; i >= 0; i--)
    {
        printf("%c", stack[i]);
    }
}

int main()
{
    int size;
    scanf("%d",&size);

    initializeStack(size);

    for (int i = 0; i < size; i++)
    {
        char data;
        scanf("%d",&data);
        push(data);
    }
    
    display();
    
    return 0;
}
