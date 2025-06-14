#include <stdio.h>
#include <string.h>

int main()
{
    char data[100], sum[20];
    int seg, len, i, j, carry;

    printf("Enter received codeword: ");
    scanf("%s", data);
    printf("Enter segment length: ");
    scanf("%d", &seg);

    len = strlen(data);

    // Initialize sum to 0
    for (i = 0; i < seg; i++)
        sum[i] = '0';

    // Add segments
    for (i = 0; i < len; i += seg)
    {
        carry = 0;
        for (j = seg - 1; j >= 0; j--)
        {
            int s = (sum[j] - '0') + (data[i + j] - '0') + carry;
            sum[j] = (s % 2) + '0';
            carry = s / 2;
        }
        // End-around carry
        j = seg - 1;
        while (carry)
        {
            int s = (sum[j] - '0') + carry;
            sum[j] = (s % 2) + '0';
            carry = s / 2;
            j--;
            if (j < 0)
                j = seg - 1;
        }
    }

    // Check if all bits in sum are 1
    int error = 0;
    for (i = 0; i < seg; i++)
        if (sum[i] != '1')
            error = 1;

    if (error)
        printf("Data received wrong\n");
    else
    {
        printf("Data received OK\n");
        printf("Actual data: ");
        for (i = 0; i < len - seg; i++)
            printf("%c", data[i]);
        printf("\n");
    }
    return 0;
}