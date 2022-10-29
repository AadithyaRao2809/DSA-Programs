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
        return 1;
        break;
    case '+':
    case '-':
        if(stk == '(')
            return 0;
        return 1;
    case '*':
    case '/':
        if(stk == '*' || stk == '/')
            return 1;
        return 0;
    }
}


char* inf_to_post(char* inf)
{
    int iI = 0;

    char stack[MAX];
    int top = 0;

    int pI = 0;
    char* post = (char*)calloc(sizeof(char),MAX);

    while(inf[iI] != '\0')
    {
        if(inf[iI]>='0' && inf[iI]<='9')
            post[pI] = inf[iI];
        else if(top == -1)
            stack[++top] = inf[iI];
        else
        {
            if(prcd(stack[top],inf[iI]))
            {
                if(inf[iI]!=')')
                    post[pI++] = stack[top--]; 
                else
                {
                    while(stack[top]!='(')
                        post[pI++] = stack[top--];
                    top--;
                }
            }
            else
            {
                stack[++top] = inf[iI];
            }
        }
        iI++;
    }

    while(top!=-1)
        post[pI++] = stack[top--];
    post[pI] = '\0';
    return post;
}

int main()
{
    printf("hello %s",inf_to_post("2+3"));
}
