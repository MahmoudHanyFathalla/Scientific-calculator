#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <ctype.h>
#include <string.h>
#include <math.h>
// I Assiste
int counter = 0;
struct Stack
{
    float* arr;
    int sp;
    int size;
    Stack()
    {
        arr = NULL;
        sp = -1;
        size = 0;
    }
};

bool initializeStack(Stack* s, int sz)
{
    if (s->arr != NULL)
        free(s->arr);
    s->arr = (float*)malloc(sizeof(float) * sz);
    if (s->arr == NULL)
        return false;
    s->size = sz;
    s->sp = -1;
    return true;
}

int push(Stack* s, char item)
{
    if (s->arr == NULL)
        return -1;
    if (s->sp + 1 == s->size)
        return -2;

    s->sp = s->sp + 1;
    s->arr[s->sp] = item;
    counter++;
    return 0;
}

int pop(Stack* s, char* item)
{
    if (s->arr == NULL)
        return -1;
    if (s->sp == -1)
        return -2;

    *item = s->arr[s->sp];
    s->sp = s->sp - 1;
    counter--;
    return 0;
}

int top(Stack* s, char* item)
{
    if (s->arr == NULL)
        return -1;
    if (s->sp == -1)
        return -2;

    *item = s->arr[s->sp];
    return 0;
}

int pushfloat(Stack* s, float item)
{
    if (s->arr == NULL)
        return -1;
    if (s->sp + 1 == s->size)
        return -2;

    s->sp = s->sp + 1;
    s->arr[s->sp] = item;
    return 0;
}

int popfloat(Stack* s, float* item)
{
    if (s->arr == NULL)
        return -1;
    if (s->sp == -1)
        return -2;

    *item = s->arr[s->sp];
    s->sp = s->sp - 1;
    return 0;
}

int topfloat(Stack* s, float* item)
{
    if (s->arr == NULL)
        return -1;
    if (s->sp == -1)
        return -2;

    *item = s->arr[s->sp];
    return 0;
}
int isempty()
{
    // I Assisted Ahmed Osama in this part with his code
    if (counter == 0) {
        return 0;
    }
    else {
        return 1;
    }
}

int brackets(Stack s, char array[], int size)
{

    // I Assiste
    for (int i = 0; i <= size; i++)
    {
        char it = array[i];
        if (it == '(')
        {
            push(&s, array[i]);
        }
        if (array[i] == ')')
        {
            int popcheck = pop(&s, &it);
            if (popcheck == -2)
            {

                return -7;


            }
        }
    }
    int che = isempty();
    if (che == 0) {

        return 0;
    }
    else if (che == 1) {

        return -8;
    }
}
int check(char array[], int size)
{
    int count = 0;

    if (array[0] == '+' || array[0] == '*' || array[0] == '/' || array[0] == '^')
    {
        return -1;
    }
    for (int i = 0; i < size; i++)
    {
        if (array[i] == '/')
        {
            if (array[i + 1] == '0')
            {
                return -12;
            }
        }
        if (array[i] >= 'a' && array[i] <= 'z')
        {
            return -11;
        }
        if (array[i] >= 'A' && array[i] <= 'Z')
        {
            return -11;
        }

        if (array[i] == '+' || array[i] == '-' || array[i] == '*' || array[i] == '/' || array[i] == '^')
        {
            if (array[i + 1] == '*' || array[i + 1] == '/' || array[i + 1] == '^' || array[i + 1] == '+' || array[i + 1] == '-')
            {
                return -1;
            }

            else if (array[i] == array[i + 1])
            {
                return -1;
            }

            else if (array[i + 1] == ')')
            {
                return -1;
            }
            else if (i + 1 == size)
            {
                return -1;
            }
            else if (array[i] != '-')
            {
                if (array[i - 1] == '(')
                {
                    return -1;
                }
            }


        }
        if (array[i] == '(')
        {
            if (array[i + 1] == ')')
            {
                return -6;
            }
        }
        if (array[i] == '+' || array[i] == '-' || array[i] == '*' || array[i] == '/' || array[i] == '^')
        {

            count = count + 1;
        }
    }
    if (count == 0)
    {
        return  -9;
    }
    return 0;
}
void chek_name(int x, int x_brac)
{
    // I Assiste
    if (x == -1)
    {
        printf("Error : Operator is in the wrong position. \n");
    }
    else if (x == -6)
    {
        printf("Error : Empty Brackets. \n");
    }
    else if (x == -9)
    {
        printf("Error : There is no Operator. \n");
    }
    else if (x == -11)
    {
        printf("Error : Wrong icon. \n");
    }
    else if (x == -12)
    {
        printf("Error : Can't divide on 0. \n");
    }
    if (x_brac == -7 || x_brac == -8)
    {
        printf("Error : Brackets Error. \n");
    }

}
int priority(char infix)
{
    // I Assisted Ahmed Osama in this part with his code
    // I Assiste
    if (infix == '^')
        return 5;
    else if (infix == '*' || infix == '/')
        return 4;
    else if (infix == '+' || infix == '-')
        return 3;
    else
        return 0;

}
void rev(char* str)
{

    int i, size, temp;
    size = strlen(str);
    for (i = 0; i < size / 2; i++)
    {
        temp = str[i];
        str[i] = str[size - i - 1];
        str[size - i - 1] = temp;
    }
}

char* inf_to_pst(Stack s, char infix[], int sizee, char arrn[])
{
   
    char item;
    int z = 0;
    for (int i = 0; i < sizee; i++)
    {
        if (infix[i] == '+' || infix[i] == '-' || infix[i] == '*' || infix[i] == '/' || infix[i] == '^')
        {
            if (top(&s, &item) == -2)
            {
                push(&s, infix[i]);
            }

            else if (priority(item) < priority(infix[i]))
            {
                push(&s, infix[i]);
            }
            else if (priority(item) >= priority(infix[i]))
            {
                top(&s, &item);
                while (priority(item) >= priority(infix[i]) && top(&s, &item) != -2)
                {
                    pop(&s, &item);
                    arrn[z] = item;
                    z++;
                    top(&s, &item);

                }
                push(&s, infix[i]);

            }
        }
        else if (infix[i] >= '0' && infix[i] <= '9')
        {
            arrn[z] = infix[i];
            z++;

        }
        else if (infix[i] == '(')
        {
            push(&s, infix[i]);

        }
        else if (infix[i] == ')')
        {
            top(&s, &item);
            while (item != '(')
            {
                pop(&s, &item);
                arrn[z] = item;
                z++;
                top(&s, &item);
            }
            pop(&s, &item);
        }



    }

    while (top(&s, &item) != -2)
    {
        pop(&s, &item);

        arrn[z] = item;
        z++;
    }
    arrn[z] = '\0';
    return &arrn[0];


}

char* inf_to_pree(Stack s, char infix[], int sizee, char arrn[])
{

    char item;
    int z = 0;
    rev(infix);
    for (int i = 0; i < sizee; i++)
    {
        if (infix[i] == '+' || infix[i] == '-' || infix[i] == '*' || infix[i] == '/' || infix[i] == '^')
        {
            if (top(&s, &item) == -2)
            {
                push(&s, infix[i]);
            }

            else if (priority(item) < priority(infix[i]))
            {
                push(&s, infix[i]);
            }
            else if (priority(item) >= priority(infix[i]))
            {
                top(&s, &item);
                while (priority(item) >= priority(infix[i]) && top(&s, &item) != -2)
                {
                    pop(&s, &item);
                    arrn[z] = item;
                    z++;
                    top(&s, &item);

                }
                push(&s, infix[i]);

            }
        }
        else if (infix[i] >= '0' && infix[i] <= '9')
        {
            arrn[z] = infix[i];
            z++;

        }
        else if (infix[i] == ')')
        {
            push(&s, infix[i]);

        }
        else if (infix[i] == '(')
        {
            top(&s, &item);
            while (item != ')')
            {
                pop(&s, &item);
                arrn[z] = item;
                z++;
                top(&s, &item);
            }
            pop(&s, &item);
        }



    }

    while (top(&s, &item) != -2)
    {
        pop(&s, &item);

        arrn[z] = item;
        z++;
    }
    arrn[z] = '\0';
    return &arrn[0];


}
float preefeval(Stack s, int sizee, char* st) {
    int i = 0;
    float result;

    char postfix[256];
    while (*st != '\0') {
        postfix[i] = *st;
        st++;
        i++;
    }
    postfix[i] = '\0';
    printf("The Prefix is: \n");
    rev(postfix);
    puts(postfix);
    rev(postfix);
    i = 0;
    while (postfix[i] != '\0') {
        float num1, num2;
        if (isdigit(postfix[i])) {
            push(&s, postfix[i] - '0');
        }
        else if (postfix[i] == '-') {
            popfloat(&s, &num1);
            popfloat(&s, &num2);
            pushfloat(&s, ((float)num1 - (float)num2));
        }
        else if (postfix[i] == '+') {
            popfloat(&s, &num1);
            popfloat(&s, &num2);
            pushfloat(&s, ((float)num1 + (float)num2));
        }
        else if (postfix[i] == '/') {
            popfloat(&s, &num1);
            popfloat(&s, &num2);
            pushfloat(&s, ((float)num1 / (float)num2));
        }
        else if (postfix[i] == '*') {
            popfloat(&s, &num1);
            popfloat(&s, &num2);
            pushfloat(&s, ((float)num1 * (float)num2));
        }
        else if (postfix[i] == '^') {
            popfloat(&s, &num1);
            popfloat(&s, &num2);
            pushfloat(&s, (float)pow((float)num1, (float)num2));
        }
        i++;
    }
    topfloat(&s, &result);
    return result;
}


float postfixeval(Stack s, int sizee, char* st) {
    int i = 0;
    float result;

    char postfix[256];
    while (*st != '\0') {
        postfix[i] = *st;
        st++;
        i++;
    }
    postfix[i] = '\0';
    printf("The Postfix is: \n");
    puts(postfix);

    i = 0;
    while (postfix[i] != '\0') {
        float num1, num2;
        if (isdigit(postfix[i])) {
            push(&s, postfix[i] - '0');
        }
        else if (postfix[i] == '+') {
            popfloat(&s, &num1);
            popfloat(&s, &num2);
            pushfloat(&s, ((float)num2 + (float)num1));
        }
        else if (postfix[i] == '-') {
            popfloat(&s, &num1);
            popfloat(&s, &num2);
            pushfloat(&s, ((float)num2 - (float)num1));
        }
        else if (postfix[i] == '*') {
            popfloat(&s, &num1);
            popfloat(&s, &num2);
            pushfloat(&s, ((float)num2 * (float)num1));
        }
        else if (postfix[i] == '/') {
            popfloat(&s, &num1);
            popfloat(&s, &num2);
            pushfloat(&s, ((float)num2 / (float)num1));
        }
        else if (postfix[i] == '^') {
            popfloat(&s, &num1);
            popfloat(&s, &num2);
            pushfloat(&s, (float)pow((float)num2, (float)num1));
        }
        i++;
    }
    topfloat(&s, &result);
    return result;
}


int main()
{
    char flag[] = "0";

    while (flag[0] == '0')
    {
        Stack s,res;


        int z = 0;
        char infix[256], arrn[256], * st;

        float y;
        int size, x = 0;



        while (x == 0)
        {
            int value;
            int ch_check;
            printf("Please Enter The Infix: \n");
            gets(infix);
            size = strlen(infix);
            initializeStack(&s, size);
            initializeStack(&res, size);
            value = brackets(s, infix, size);
            ch_check = check(infix, size);
            counter = 0;
            if (value == 0 && ch_check == 0)
            {

                x = 1;
            }
            else
            {
                chek_name(ch_check, value);
            }
            value = 0;
            ch_check = 0;
            counter = 0;

        }
        int fg = 0;
        while (fg == 0)
        {
            char m[100];
            printf("For Postfix enter 1: \n");
            printf("For Prefix enter 2: \n");
            gets(m);
            if (m[0] == '1')
            {
                st = inf_to_pst(s, infix, size, arrn);
                y = postfixeval(res, size, st);

                printf("The Final Result is: \n");
                printf("%.2f\n", y);
                counter = 0;
                fg = 1;
            }
            else if (m[0] == '2')
            {
                st = inf_to_pree(s, infix, size, arrn);
                y = preefeval(res, size, st);

                printf("The Final Result is: \n");
                printf("%.2f\n", y);
                counter = 0;
                fg = 1;
            }
            else
            {
                printf("Error : Enter '1' or '2: \n");
                fg = 0;
            }
            counter = 0;
        }
        printf("Enter 0 to Continue or Enter 1 to Exit: \n");
        gets(flag);


    }
}
