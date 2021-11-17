#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define N_SIZE 32

void strcat_at_begin(char *src, char *dest)
{
    printf("strcat_at_begin(%s, %s)\n", src, dest);
    size_t buffer_len = (strlen(src) + strlen(dest));
    char *buffer = malloc(buffer_len * sizeof(char));
    snprintf(buffer, buffer_len + 1, "%s%s", src, dest);
    strcpy(dest, buffer);
    free(buffer);
}

// the following  function  is copied from the Nicholas Joseph from develeppez.com
/*/https://nicolasj.developpez.com/articles/libc/string*/

char *str_sub(const char *s, unsigned int start, unsigned int end)
{
    printf("> str_sub(s: %s, start: %u; end: %u)\n", s, start, end);
    char *new_s = NULL;
    
    if (s != NULL && start <= end)
    {
        new_s = malloc(sizeof(char) * (end - start + 2));
        memset(new_s, 0, sizeof(char) * (end - start + 2));
        if (new_s != NULL)
        {
            int i;

            for (i = start; i < end; i++)
            {
                new_s[i - start] = s[i];
            }
            new_s[i - start] = '\0';
        }
        else
        {
            fprintf(stderr, "Memoire insuffisante\n");
            exit(EXIT_FAILURE);
        }
    }
    return new_s;
}

int makeEqualLength(char *str1, char *str2)
{
    int len1 = strlen(str1);
    printf("len1 = %d\n", len1);
    int len2 = strlen(str2);
    printf("len2 = %d\n", len2);
    char *str_ptr = len1 < len2 ? str1 : str2;

    for (int i = 0; i < (len2 > len1 ? len2 - len1 : len1 - len2); i++)
    {
        //printf("ici str_ptr=%s\n", str_ptr);
        strcat_at_begin("0", str_ptr);
        //printf("str_ptr= %s \n", str_ptr);
    }
    return strlen(str_ptr); // for both the cases where len1 = len2 | len1 > len2
}

// the main function adds two bit sequences and returns the addition
char *addBitstrings(char *first, char *second)
{

    // make the lenghths same before adding
    int n = makeEqualLength(first, second);
    char *result = malloc(n * sizeof(char));
    int carry = 0; // Initialize carry
    // Add all bits one by one
    printf("n=%d; strlen(first)= %ld; strlen(second)=%ld\n", n, strlen(first), strlen(second));
    for (int i = n - 1; i >= 0; i--)
    {
        int firstBit = first[i] - '0'; // precedence lexicographiques
        int secondBit = second[i] - '0';
        // boolean expression for sum of 3 bits

        char sum = (firstBit ^ secondBit ^ carry) + '0';

        //result = (char)sum + result;
        strcat_at_begin(&sum, result);
        printf("i:%d, result=%s\n", i, result);
        // boolean expression for 3-bit addition
        carry = (firstBit & secondBit) | (secondBit & carry) | (firstBit & carry);
    }

    if (carry)
        result = '1' + result;

    return result;
}

// A utility function that multiply single bits of strings a and b
int multiplyiSIngleBit(const char *a, const char *b)
{
    return (a[0] - '0') * (b[0] - '0');
}

//the main function that multiplies two bit strings X and Y and returns
// results as long integer
long int multiply(char *X, char *Y)
{
    // Find the maximum of lenghts of x and y and make length
    // of smaller string same as that of larger string
    int n = makeEqualLength(X, Y);
    // Base cases
    if (n == 0)
        return 0;
    if (n == 1)
        return multiplyiSIngleBit(X, Y);

    int fh = n / 2;    // First half of string, floor(n/2)
    int sh = (n - fh); // Second half of string, ceil (n/2)

    // Find the first half and second half of string X

    char *Xl = str_sub(X, 0, fh - 1);
    char *Xr = str_sub(X, fh, n + 1);

    // Find the first half and second half of string X

    char *Yl = str_sub(Y, 0, fh - 1);
    char *Yr = str_sub(Y, fh, n + 1);

    // Recursively calcul the three products of inputs of size n/2
    printf("Xl= %s; Xr= %s; Yl= %s; Yr=%s\n", Xl, Xr, Yl, Yr);
    long int P1 = multiply(Xl, Yl);
    long int P2 = multiply(Xr, Yr);
    long int P3 = multiply(addBitstrings(Xl, Xr), addBitstrings(Yl, Yr));
    printf("P2 = %ld; P3 = %ld\n", P2, P3);
    //printf("P1 = %ld; P2 = %ld; P3 = %ld\n", P1, P2, P3);

    // combine the three products to get the final result.
    return (1 << (2 * sh)) + (P3 - P2) * (1 << sh) + P2;
}

int main()
{
    char a[N_SIZE];
    char b[N_SIZE];

    strcpy(a, "1000");
    strcpy(b, "10");
    char *c = str_sub(a, 0, 3);
    printf("%s\n", c);

    printf("before makeEqualLength:\na[%ld]=%s;\nb[%ld]=%s\n", strlen(a), a, strlen(b), b);
    int n = makeEqualLength(a, b);
    printf("after makeEqualLength:\na[%ld]=%s;\nb[%ld]=%s\n", strlen(a), a, strlen(b), b);
    //printf ("%s\n",strcat(a,b));

    printf("%s\n", addBitstrings(a, b));
    int fh = n / 2;    // First half of string, floor(n/2)
    int sh = (n - fh); // Second half of string, ceil (n/2)
    char *Xl = str_sub(b, 0, fh - 1);
    char *Xr = str_sub(b, fh, n + 1);
    printf("first_half = %s  &  second_half = %s", Xl, Xr);
    printf("%ld\n", multiply(a, b));
}
