#include<iostream>
using namespace std;
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int precedence(char c) {
    if (c == '^')
        return 3;
    else if (c == '/' || c == '*')
        return 2;
    else if (c == '+' || c == '-')
        return 1;
    else
        return -1;
}


char associativity(char c) {
    if (c == '^')
        return 'R';
    return 'L'; 
}


void infixToPostfix(char s[]) {
    char result[100];
    int rindex = 0;
    int len = strlen(s);
    char stack[100];
    int sindex = -1;

    for (int i = 0; i < len; i++) {
        char c = s[i];

        
        if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9')) {
            result[rindex++] = c;
        }
       
        else if (c == '(') {
            stack[++sindex] = c;
        }
        
        else if (c == ')') {
            while (sindex >= 0 && stack[sindex] != '(') {
                result[rindex++] = stack[sindex--];
            }
            sindex--; 
        }
       
        else {
            while (sindex >= 0 && (precedence(s[i]) < precedence(stack[sindex]) || precedence(s[i]) == precedence(stack[sindex]) && associativity(s[i]) == 'L')) {
                result[rindex++] = stack[sindex--];
            }
            stack[++sindex] = c;
        }
    }


    while (sindex >= 0) {
        result[rindex++] = stack[sindex--];
    }

    result[rindex] = '\0';
    printf("%s\n", result);
}


int main() {
    char exp[] = "(a+b)+(c+d)";

  
    infixToPostfix(exp);

    return 0;
}






