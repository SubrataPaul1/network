#include <stdio.h>
#include <string.h>

// Function to compute one's complement of a binary string
void ones_complement(char *bin, int len)
{
    for (int i = 0; i < len; i++)
    {
        bin[i] = (bin[i] == '0') ? '1' : '0';
    }
}

int main()
{
    char data[128] = "11001100101010101111000011000011";
    int segment_len;

    // Input data
    printf("Enter binary data: ");
    // scanf("%s", data);
    int data_len = strlen(data);

    // Input segment length (must be a power of 2)
    do
    {
        printf("Enter segment length (power of 2): ");
        scanf("%d", &segment_len);
    } while (segment_len != 1 && segment_len != 2 && segment_len != 4 && segment_len != 8 && segment_len != 16 && segment_len != 32 && segment_len != 64);

    // Pad data with leading zeros if needed
    int pad = data_len % segment_len ? segment_len - (data_len % segment_len) : 0;
    char padded[128] = {0};
    for (int i = 0; i < pad; i++)
        padded[i] = '0';
    strcpy(padded + pad, data);
    int total_len = data_len + pad;

    // Initialize sum
    char sum[65] = {0};
    for (int i = 0; i < segment_len; i++)
        sum[i] = '0';

    // Add segments
    for (int i = 0; i < total_len; i += segment_len)
    {
        int carry = 0;
        for (int j = segment_len - 1; j >= 0; j--)
        {
            int a = sum[j] - '0';
            int b = padded[i + j] - '0';
            int s = a + b + carry;
            sum[j] = (s % 2) + '0';
            carry = s / 2;
        }
        // End-around carry
        int idx = segment_len - 1;
        while (carry)
        {
            int s = (sum[idx] - '0') + carry;
            sum[idx] = (s % 2) + '0';
            carry = s / 2;
            idx--;
            if (idx < 0)
                idx = segment_len - 1;
        }
    }

    // Compute checksum (one's complement)
    char checksum[65];
    strcpy(checksum, sum);
    ones_complement(checksum, segment_len);

    // Output
    printf("Checksum: %s\n", checksum);
    printf("Codeword (data + checksum): %s%s\n", padded, checksum);

    return 0;
}