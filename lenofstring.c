#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
#define NO_OF_CHARS 256
int min(int a, int b);
int longestUniqueSubsttr(char *str)
{
    int n = strlen(str);
    int current_length = 1;
    int maximum_length = 1;  
    int previous_index; 
    int i;
    int *visited = (int *)malloc(sizeof(int)*NO_OF_CHARS);
    for (i = 0; i < NO_OF_CHARS;  i++)
    {
        visited[i] = -1;
    visited[str[0]] = 0;
    }
    for (i = 1; i < n; i++)
    {
        previous_index =  visited[str[i]];
        if (previous_index == -1 || i - current_length > previous_index)
            current_length++;
        else
        {
            if (current_length > maximum_length)
                maximum_length = current_length;
              current_length = i - previous_index;
        }
        visited[str[i]] = i;
    }
    if (current_length > maximum_length)
        maximum_length = current_length;
 
    free(visited); 
    return maximum_length;
}
int min(int a, int b)
{
    return (a>b)?b:a;
}
int main()
{
    char str[] = "ABCABCBB";
    printf("The input string is %s n", str);
    int length =  longestUniqueSubsttr(str);
    printf("The length of the longest non-repeating "
           "character substring is %d", length);
    return 0;
}
