#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include "multiStack.h"

void evaluate_postfix(char*);
char* infix_to_postfix(char*);

int prcd(digit, digit);   // precidence of ops

int main()
{
    char infix[1000];
    char* post;

    printf("Enter infix Exp.: ");
    scanf("%s",infix);

    post = infix_to_postfix(infix);

    printf("%s\n",post);
     

    evaluate_postfix(post);
}


void evaluate_postfix(char* postFix)
{
    STACK operands;
    init(&operands);

    int i=0;
    digit res;
    while(postFix[i] != '\0')
    {
        if(postFix[i]>='0' && postFix[i]<='9')
        {
            push(&operands, (digit)(postFix[i]-'0'));
        } 
        else
        {
            digit op1;
            digit op2;
            pop(&operands,&op2);
            pop(&operands,&op1);
            switch (postFix[i])
            {
            case '+':
                res.i = op1.i+op2.i;
                break;
            case '-':
                res.i = op1.i-op2.i;
                break;
            case '*':
                res.i = (op1.i)*(op2.i);
                break;
            case '/':
                res.i = op1.i/op2.i;
                res.i = op1.i/op2.i;
                break;
            
            default:
                break;
            }
            push(&operands,(digit)res);
        }
        
        i++;
    }
        pop(&operands,&res);
        if(!isEmpty(&operands))
            printf("INVALID EXPRESSION\n");
        else
            printf("Result of Expression is %d\n", res.i);
}

char* infix_to_postfix(char* infix)
    {
        STACK ops;
        init(&ops);
        
        char* postfix = (char*)malloc(50*sizeof(char));

        int infInd = 0;
        int pstInd = 0;

        while(infix[infInd] != '\0')
        {
            if(isalnum(infix[infInd]))
                postfix[pstInd++] = infix[infInd];
            else
            {
                digit stackTop;
                peep(&ops,&stackTop);
                while(!(isEmpty(&ops)) && prcd(stackTop,(digit)infix[infInd]))
                {
                    digit popped;
                    pop(&ops,&popped);
                    printf("%c popped\n",popped.c);
                    postfix[pstInd++] = popped.c;
                }
                if(infix[infInd] == '(')
                {
                    push(&ops,(digit)(infix[infInd]));
                    printf("%c pushed\n",infix[infInd]);
                }
                else
                {
                    do
                    {
                        digit popped;
                        pop(&ops,&popped);
                        postfix[pstInd++] = popped.c;

                        peep(&ops,&stackTop);
                    }while(stackTop.c != '(');
                    digit _;
                    pop(&ops,&_);
                }
                


            }

            infInd++;
        }
        
        while(!isEmpty(&ops))
        {
            digit popped;
            pop(&ops, &popped);
            postfix[pstInd++] = popped.c;
        }

        postfix[pstInd++] = '\0';
        return postfix;
    }




int prcd(digit stackTop, digit op)    // precidence of ops
{                                   //1 => stackTop.c is to be popped
    switch (op.c)
    {
    case '(':
        return 0;
    case ')':
        if(stackTop.c == '(')
            return 0;
        return 1;

    case '+':
    case '-':
        if(stackTop.c != '(')
            return 1;
        return 0;
    case '*':
    case '/':
    
        if(stackTop.c == '*' || stackTop.c == '/')
            return 1;
        return 0;
    default:
        break;
    }
}
