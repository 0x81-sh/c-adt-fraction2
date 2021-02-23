#include <stdio.h>
#include "fraction.h"

int testFn (char * name, PFraction have, PFraction got);
int lineTests ();
int pointTest ();
void alert (int count);

int main() {
    int values = 0;
    values += lineTests();
    values += pointTest();
    if (values != 0) alert(values);

    printf("All tests complete.");
}

int testFn (char * name, PFraction have, PFraction got) {
    printf("Test: %s\n", name);

    printf("\tExpected: ");
    Fraction_show(have);

    printf("\n\tGot: ");
    Fraction_show(got);

    int passed = Fraction_getNumerator(have) == Fraction_getNumerator(got) &&
              Fraction_getDenominator(have) == Fraction_getDenominator(got);
    printf("\n\tTest %s\n\n", passed ? "PASSED" : "FAILED");
    return !passed;
}

int lineTests () {
    PFraction f1, f2, res, exp;
    int testSum = 0;

    f1 = Fraction_create(1, 5);
    f2 = Fraction_create(9, 1);

    res = Fraction_add(f1, f2);
    exp = Fraction_create(46, 5);
    testSum += testFn("Fraction_Add (1/5 + 9/1)", exp, res);
    Fraction_massDelete(2, res, exp);

    res = Fraction_subtract(f2, f1);
    exp = Fraction_create(44, 5);
    testSum += testFn("Fraction_Subtract (9/1 - 1/5", exp, res);
    Fraction_massDelete(4, res, exp, f1, f2);

    return testSum;
}

int pointTest () {
    PFraction f1, f2, res, exp;
    int testSum = 0;

    f1 = Fraction_create(3, 2);
    f2 = Fraction_create(5, 18);

    res = Fraction_multiply(f1, f2);
    exp = Fraction_create(5, 12);
    testSum += testFn("Fraction_Multiply (1/2 * 5/18)", exp, res);
    Fraction_massDelete(2, res, exp);

    res = Fraction_divide(f2, f1);
    exp = Fraction_create(5, 27);
    testSum += testFn("Fraction_Divide (5/18 / 3/2)", exp, res);
    Fraction_massDelete(4, res, exp, f1, f2);

    return testSum;
}

void alert (int count) {
    printf("|-------------------------|\n");
    printf("|         WARNING         |\n");
    printf("|  SOME TESTS FAILED (%d)  |\n", count);
    printf("|-------------------------|\n\n");
}