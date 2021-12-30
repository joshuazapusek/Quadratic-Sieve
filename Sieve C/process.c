////////////////////////////////////////////////////////////////////////
// Title: Quadratic Sieve Implementation in C: Data Processing
// File: Process.c
// Authur: Joshua Zapusek
// Date Modified: 12/30/2021

#include <stdio.h>
#include <stdlib.h>

///////////////////////////////////////////////////////////////////////
// Function: Fast Modular Exponentiation
// Description: Take exponent quickly
// Inputs: base, t, n
// Outpus: e (exponent) on success, -1 otherwise

int fast_exp(int base, int t, int n) {
    int e = 1;
    while (t > 0) {
        if (t % 2) {
            e = (e * base) % n;
        }
        t /= 2;
        base = (base * base) % n;
    }
    return (e);
}

///////////////////////////////////////////////////////////////////////
// Function: Strong Pseudoprime Test
// Description: Determine probable primality of an input integer
// Inputs: n (number to be factored)
// Outpus: 0 on non-prime, -1 otherwise

int strong_pseudo(int n, int *bases[], int blen) {
    int t = n - 1;
    int res = 0;
    for (int i = 0; i < blen; i++) {
        while(!(t % 2)) {
            res = fast_exp(*bases[i], t, n);
            if (res == 1) {
                t /= 2;
                continue;
            }
            else {
                //logfile
                return (-1);
            }
        }
    }
    return (0);
}

///////////////////////////////////////////////////////////////////////
// Function: Trial Division
// Description: Determine prime factors up to given prime index
// Inputs: n (number to be factored), parr (the prime array), plen (length of prime array)
// Outpus: prime count array of factors on success, -1 otherwise

int trial_div(int n, int *parr[], int plen) {
    for (int i = 0; i < plen; i++) {
        parr[i] = 0;
        while (1) {
            if ((n % *parr[i])) {
                parr[i] += 1;
                n /= *parr[i];
            }
            else {
                break;
            }
        }
    }
    return (&parr);
}

int gcd(int a, int b) {
    if (!b) {
        return a;
    }
    return (gcd(b, (a % b)));
}



///////////////////////////////////////////////////////////////////////
// Function: Extended Euclidean
// Description: Determine Inverse Modulo
// Inputs: a, b
// Outpus: Inverse on success, -1 otherwise
 
int ext_euclid(int a, int b) {

}
