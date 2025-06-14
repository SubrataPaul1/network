#include <stdio.h>
#include <string.h>
#include <math.h>

int main()
{
    char code[64];
    int m, r = 0, i, j, error_pos = 0;

    printf("Enter received codeword: ");
    scanf("%s", code);
    m = strlen(code);

    // Find number of parity bits
    while (pow(2, r) < m + r + 1)
        r++;

    // Calculate error position
    for (i = 0; i < r; i++)
    {
        int parity = 0;
        int pos = 1 << i;
        for (j = 1; j <= n; j++)
        {
            if (j & pos)
                parity ^= (code[n - j] - '0'); // n-j: MSB is position 1
        }
        if (parity)
            error_pos += pos;
    }

    if (error_pos == 0)
    {
        printf("No error detected.\n");
    }
    else
    {
        printf("Error at bit position: %d\n", error_pos);
        // Correct the error
        int idx = n - error_pos;
        code[idx] = (code[idx] == '0') ? '1' : '0';
        printf("Corrected codeword: %s\n", code);
    }

    return 0;
}