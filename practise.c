#include <stdio.h>
#include <math.h>
#include <string.h>

int main()
{
    char data[128];

    // taking input data
    printf("enter the data:");
    scanf("%s", data);
    int m = strlen(data);
    int r = 0;

    // setting the array size
    while (pow(2, r) > m + r + 1)
        r++;
    int n = m + r;
    // initilize the code array with 0
    int code[128];
    for (int i; i <= n; i++)
        code[i] = 0;

    // placing the data bits skip the parity bit positions
    for (int i = 0, j = 1; j <= n; j++)
    {
        if ((j & (j - 1)) != 0)
        {
            code[j] = data[i++] - '0';
        }
    }

    // calculate the pariry bits
    for (int i = 0; i < r; i++)
    {
        int pos = 1 << i, parity = 0;
        for (int j = 1; j <= n; j++)
        {
            if (pos & j)
            {
                parity = parity ^ code[j];
            }
        }
        code[pos] = parity;
    }
    printf("Hamming code: ");
    for (int i = n; i >= 1; i--)
    {
        printf("%d", code[i]);
    }
    return 0;
}