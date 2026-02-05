#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define Max 100

int main()
{
    char P[Max];
    int STACK[Max];
    int TOP = -1;

    printf("Enter Postfix Expression: ");
    scanf("%s", P);

    strcat(P, ")");

    for(int i = 0; P[i] != ')'; i++)
    {
        char ch = P[i];

        if(isdigit(ch))
        {
            STACK[++TOP] = ch - '0';
        }
        else
        {
            int A = STACK[TOP--];
            int B = STACK[TOP--];
            int result;

            switch(ch)
            {
                case '+':
                    result = B + A;
                    break;
                case '-':
                    result = B - A;
                    break;
                case '*':
                    result = B * A;
                    break;
                case '/':
                    result = B / A;
                    break;
                
                default:
                    printf("Unknown Operator: %c\n", ch);
                    return 0;
            }
            STACK[++TOP] = result;

        }
    }

    printf("Result: %d\n", STACK[TOP]);
    
    return 0;
}