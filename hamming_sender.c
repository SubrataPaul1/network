#include <stdio.h>
#include <string.h>
#include <math.h>

int main()
{
    char data[32];
    int m, r = 0, i, j, n;
    int code[64] = {0};

    printf("Enter dataword: ");
    scanf("%s", data);
    m = strlen(data);

    // Find number of parity bits needed
    while (pow(2, r) < m + r + 1)
        r++;
    n = m + r;

    // Place data bits (skip parity bit positions)
    int data_idx = 0;
    for (i = 1; i <= n; i++)
    {
        if ((i & (i - 1)) != 0)
        {
            code[i] = data[data_idx++] - '0';
        }
    }

    // Calculate parity bits
    for (i = 0; i < r; i++)
    {
        int pos = 1 << i;
        int parity = 0;
        for (j = 1; j <= n; j++)
        {
            if (j & pos)
                parity ^= code[j];
        }
        code[pos] = parity;
    }

    // Print Hamming code with position 1 as MSB (leftmost)
    printf("Hamming code: ");
    for (i = n; i >= 1; i--) // reversed
        printf("%d", code[i]);
    printf("\n");

    return 0;
}
