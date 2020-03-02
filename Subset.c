/*
 * Isabella Man
 * 1602153
 * CSE 15
 * 10/11/19
 * Prints all the k-element subsets of any n-element set, wherein 0 < k < n < 100
 */

//#define _GNU_SOURCE

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#include <string.h>


#define MAX_SIZE 100

bool isNumber(char s[]) {
	for  (int i = 0; i < strlen(s); i++) {
                if (isdigit(s[i]) == false) {
                        return false;
                }
	}
        return true;
}

/* Prints all subsets represented by integers */
void printSet(int B[], int n) {
	int C[n];
	int j = 0;
	int index;
        for (index = 1; index < n + 1;) {
                if (B[index] == 1) {
			C[j] = index;
			j++;
			index++;
		}
		else {
			index++;
		}
        }
	printf("{");
	for (int k = 0; k < j; k++) {
		printf("%d", C[k]);
		if (k != j - 1) {
			printf(", ");
		}
	}
	printf("}\n");
}

/* Implements recursive algorithm */
void printSubsets(int B[], int n, int k, int i) {
	//printf("k = %d\n", k);
	//printf("i = %d\n", i);

        if (k == 0) {
		/* Prints out all subsets in bit-array */
        	//for (int i = 1; i < n + 1; i++) {
                	//printf("%d",B[i]);
        	//}
       		//printf("\n"); 
		
		printSet(B, n);
		return;
	}

	/* Checks number of candidates remaining (n-i+1)
	 * If k, number of elements still needed, 
	 * is greater, return
	 */
	if (k > n - i + 1) {
                return;
        }

	B[i] = 1;
        if (k > 0 || k < n) {
                printSubsets(B, n, k-1, i+1);
		B[i] = 0;
		printSubsets(B, n, k, i+1);		
        }
}

int main(int argc, char *argv[]) {
	int n, k;

	/* Ensure only two arguments */
	if (argc == 3) {
		n = atoi(argv[1]);
		k = atoi(argv[2]);
	}
	else {
                printf("Usage: Subset n k (n and k are ints satisfying 0<=k<=n<=100)\n");
                return 1;
        }

	/* Check if arguments are integers */
	if (isNumber(argv[1]) == false || isNumber(argv[2]) == false) {
		printf("Usage: Subset n k (n and k are ints satisfying 0<=k<=n<=100)\n");
                return 1;
	}

        /* Check if inequality is false: k < n < 100 */
	if (n < k || n > MAX_SIZE) {
        	printf("Usage: Subset n k (n and k are ints satisfying 0<=k<=n<=100)\n");
                return 1;
        }

        int B[MAX_SIZE + 1];
        /* Initialize all elements to zero */
        for (int i = 1; i < n + 1; i++) {
                B[i] = 0;
        }

	if (argc > 2) {
		int i = 1;
		printSubsets(B, n, k, i);
	}

	return 0;
}
