#include <stdio.h>
#include <stdlib.h>

typedef int Item;

#define Key(A) (A)
#define less(A,B) (Key(A) < Key(B))
#define exch(A,B) {Item t = A; A=B; B=t;}
#define cmpexch(A,B) if(less(A,B)) exch(A,B)

void insertionsort(int v[], int l, int r)
{
    for (int i = r; i > l; i--)
        cmpexch(v[i-1], v[i]);

    for (int i = l+2; i <= r; i++)
    {
        int j = i;
        Item tmp = v[j];
        while (less(tmp, v[j-1]))
        {
            v[j] = v[j-1];
            j--;
        }
        v[j] = tmp;
    }
}

int main()
{
    int array[50000];
    int n = 0; // Initialize n to 0

    // Correct the while loop condition
    while (scanf("%d", &array[n]) != EOF)
    {
        n++;
    }

    insertionsort(array, 0, n-1); // Correct function name to insertionsort
    for (int i = 0; i < n; i++)
    {
        printf("%d ", array[i]);
    }

    printf("\n");
    return 0;
}
