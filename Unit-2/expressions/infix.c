#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX 20


int prcd(char stk, char cur)    //1 to pop, 0 to push
{
    switch (cur)
    {
    case '(':
        return 0;
        break;
    case ')':
        if(stk=='(')
            return 0;
        return 1;
        break;
    case '+':
    case '-':
        if(stk == '(')
            return 0;
        return 1;
        break;
    case '*':
    case '/':
        if(stk == '(' || stk == '+' || stk == '-')
            return 0;
        return 1;
    }
}


char* inf_to_post(char* infix)
{

    char stack[MAX];
    int top = -1;

    int p = 0;
    char* postfix = (char*)calloc(sizeof(char),MAX);

    for(int i=0; infix[i]!='\0';i++)
    {
        if(infix[i]>='0' && infix[i]<='9')
            postfix[p++] = infix[i];
        else
        {
            while(top!=-1 && prcd(stack[top],infix[i]))
                postfix[p++] = stack[top--];
            if(infix[i]==')')
                stack[top--];
            else
                stack[++top] = infix[i];
        }
    }

    while(top!=-1)
        postfix[p++] = stack[top--];
    postfix[p] = '\0';
    return postfix;
}

int main()
{
    printf("hello %s",inf_to_post("2+3/(5*6)"));
}
