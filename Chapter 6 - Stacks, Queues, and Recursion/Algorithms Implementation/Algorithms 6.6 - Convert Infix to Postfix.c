#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX 100

char STACK[MAX];
int TOP = -1;

int precedence(char ch)
{
    if (ch == '^') 
    {
      return 3;
    }
    if (ch == '*' || ch == '/') 
    {
      return 2;
    }
    if (ch == '+' || ch == '-') 
    {
      return 1;
    }
    return 0;
}

int main()
{
    char Q[MAX] = "A+(B*C-(D/E^F)*G)*H";
    char P[MAX];
    int j = 0;

    STACK[++TOP] = '(';
    strcat(Q, ")");

    printf("Infix Expression: A+(B*C-(D/E^F)*G)*H\n");

    for (int i = 0; Q[i] != '\0'; i++)
    {
        char ch = Q[i];

        if (isalpha(ch))
        {
            P[j++] = ch;
        }
        else if (ch == '(')
        {
            STACK[++TOP] = ch;
        }
        else if (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^')
        {
            while (TOP >= 0 && precedence(STACK[TOP]) >= precedence(ch))
                P[j++] = STACK[TOP--];
            STACK[++TOP] = ch;
        }
        else if (ch == ')')
        {
            while (STACK[TOP] != '(')
                P[j++] = STACK[TOP--];
            TOP--;
        }
    }

    P[j] = '\0';
    printf("Postfix Expression: %s\n", P);

    return 0;
}
