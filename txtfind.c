#include <stdio.h>
#define LINE 256
#define WORD 30

int getLine(char s[])
{
    char ch;
    int count = 0;
    while (scanf("%c", &ch) == 1)
    {
        if (count == LINE)
            break;
        s[count] = ch;
        if (ch == '\n')
            break;
        count++;
    }
    return count;
}

int getWord(char w[])
{
    char ch;
    int count = 0;
    while (scanf("%c", &ch) > 0)
    {
        if (count == WORD)
            break;


        w[count] = ch;
        if ((ch == '\n') || (ch == '\t') || (ch == ' ') || (ch == 0))
            break;

        count++;
    }
    return count;
}

int substring(char *str1, char *str2)
{

    int j = 0;
    for (int i = 0; i < LINE; i++)
    {
        if (*(str1 + i) == *(str2 + j))
        {
            j++;
            if ((*(str2 + j) == 0) || (*(str2 + j) == ' ') || (*(str2 + j) == '\n'))
                return 1;
        }
        else
        {
            j = 0;
        }
        if (*(str1 + i) == '\n')
            break;
        if (*(str1 + i) == '\0')
            break;
    }

    return 0;
}

int similiar(char *s, char *t, int n)
{
    int helper = n;
    int i, j = 0;
    for (i = 0; i < LINE; i++)
    {
        if (s[i] == '\n' || (s[i] == '\t') || (s[i] == ' ') || (s[i] == 0))
        {
            break;
        }
        if (s[i] == t[j])
        {
            j++;
        }
        else
        {
            helper--;
        }
    }
    if (s[i] == '\n' || s[i] == 0 || s[i] == ' ' || s[i] == '\t')
    {
        if (t[j] == ' ' || t[j] == '\t' || t[j] == '\n' || t[j] == 0)
        {
            if (helper >= 0)
            {
                return 1;
            }
        }
    }

    return 0;
}

void print_lines(char *str)
{
    int n;
    char current[LINE];
    getLine(current);
    while ((n = getLine(current)) > 0)
    {
        if (substring(current, str) == 1)
        {
            for (int i = 0; i < n; i++)
            {
                printf("%c", current[i]);
            }
            printf("\n");
        }
    }
}

void print_similar_words(char *str)
{
    int n;
    char current[WORD];
    getWord(current);
    while ((n = getWord(current)) > 0)
    {
        if (similiar(current, str, 1) == 1)
        {
            for (int i = 0; i < n; i++)
            {
                printf("%c", current[i]);
            }
            printf("\n");
        }
    }
}

int main() 
{
    char word[WORD];
    char option[WORD];
    getWord(word);
    getWord(option);

    if(option[0] == 'a')
    {
        print_lines(word);
    } else if(option[0] == 'b') {
        print_similar_words(word);
    }
    return 0;
}