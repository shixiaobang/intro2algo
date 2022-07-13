#if !defined(HORNERS_RULE_H)
#define HORNERS_RULE_H

/**
 * Horner’s rule to evaluate the polynomial, given the coefficients in an array A[0 : n] and the value of x.
 * @param array pointer to array
 * @param n length of array
 * @param x value of x
 * @return the value of the polynomial
 */
int horner(int *array, int n, int x);

#endif // HORNERS_RULE_H
