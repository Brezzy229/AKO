#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Myobject
{
    char* s1 = NULL; // one of the two bit string
    char* s2 = NULL; // the second one
    int  n = 0;
};

// the following  function  is copied from the Nicholas Joseph from develeppez.com
/*/https://nicolasj.developpez.com/articles/libc/string*/

char *str_sub (const char *s, unsigned int start, unsigned int end)
{
    char *new_s = NULL;

    if (s != NULL && start < end )
    {
        new_s = malloc(sizeof (char) * (end - start + 2));
        memset(new_s,0,sizeof (char) * (end - start + 2));
        if(new_s != NULL)
        {
            int i;

            for(i = start; i <= end; i++)
            {
                new_s[i-start] = s[i];
            }
            new_s[i-start]='\0';
        }
        else
        {
            fprintf (stderr, "Memoire insuffisante\n");
            exit (EXIT_FAILURE);
        }
    }
    return new_s;
}

// New structure bitString
struct Myobject *S = (struct Myobject *) malloc(sizeof(struct Myobject));
/*
bitString makeEqualLength(char* str1,char* str2 )
{
    
    if (S != NULL)
    {
        S.s1  = (char *) malloc((strlen(str1) + 1)* sizeof(char));
        S.s2  = (char *) malloc((strlen(str2) + 1)* sizeof(char));
        if (S ->s1 != NULL && S -> s2 != NULL)
        {
            strcpy(S ->s1,str1);
            strcpy(S ->s2,str2);
            size_t len1 =  strlen(S ->s1);
            size_t len2 =  strlen(S ->s2);
            if (len1 < len2)
            {
                for(size_t i = 0; i < len2 - len1 ; i++)
                {
                    S ->s1 = '0' + S ->s1;
                }
                S ->n = len2;
            }

            else if (len2 < len1)
            {
                for(size_t i = 0; i < len1 - len2; i++)
                {
                    S ->s2 = '0' + S ->s2;
                }
            }
            S ->n = len1; // for both the cases where len1 = len2 | len1 > len2
        }

    }
    else
    {
        free(S);
        S = NULL;
    }
    return *S;
}


// the main function that adds two bit sequences and returns the addition

char* addBitStrings( char* first,  char* second)
{
    char* result; // To store the sum bits

    // make the lenghths same before adding 

    bitString S = makeEqualLength(first,second);

    int length = S.n;
    int carry = 0; // Initialize carry

    // Add all bits one by one
    for(int i = length-1; i >=0 ; i--)
    {
        int firstBit  = *(S.s1 + i)  - '0'; // precedence lexicographique
        int secondBit = *(S.s2 + i) - '0'; 

        // boolean expression for sum of 3 bits

        int sum  = (firstBit ^ secondBit ^ carry) + '0';
    
        result = (char)sum + result;

        // boolean expression for 3-bit addition
        carry = (firstBit & secondBit) | (secondBit & carry) | (firstBit & carry);
    }

    // if overflow, then add a leading 1
    if (carry) result = '1' + result;

    return result;
}


// A utility function that multiply single bits of strings a and b
int multiplyiSIngleBit(const char* a, const char* b)
{
    return(a[0] - '0')*(b[0] - '0');
}

//the main function that multiplies two bit strings X and Y and returns
// results as long integer
long int multiply(char* X, char* Y)
{
    // Find the maximum of lenghts of x and y and make length
    // of smaller string same as that of larger string
    bitString S = makeEqualLength(X,Y);
    int n = S.n;

    // Base cases
    if (n == 0) return 0;
    if (n == 1) return multiplyiSIngleBit(X,Y);



   
    int fh = n/2; // First half of string, floor(n/2)
    int sh = (n-fh); // Second half of string, ceil (n/2)

    // Find the first half and second half of string X

    char* Xl = str_sub(S.s1,0,fh);
    char* Xr = str_sub(S.s1,fh,n);

    // Find the first half and second half of string X

    char* Yl = str_sub(S.s2,0,fh);
    char* Yr = str_sub(S.s2,fh,n);

    // Recursively calcul the three products of inputs of size n/2
    printf("Xl= %s; Xr= %s; Yl= %s; Yr=%s\n",Xl,Xr,Yl,Yr);
    long int P1 = multiply(Xl,Yl);
    long int P2 = multiply(Xr,Yr);
    long int P3 = multiply (addBitStrings(Xl,Xr),addBitStrings(Yl,Yr));
    printf("P1 = %ld; P2 = %ld; P3 = %ld\n",P1,P2,P3);

    // combine the three products to get the final result.
    return P1*(1<<(2*sh)) + (P3 - P1 - P2)*(1<<sh) + P2;   
}

int main()
{

    char* a = "12577200";
    char* b = "1082528";
    char* c = str_sub(a,2,7);
    printf("%s\n", c);

    printf("%s\n",a);
    printf("%d\n",makeEqualLength(a,b).n);
    printf("%s\n",b);

   //printf("%ld\n",multiply("110", "1010"));
   //printf("%ld\n", multiply("1100", "1010"));
   
*/
    return 0;
}