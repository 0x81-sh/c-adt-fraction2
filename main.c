#include <stdio.h>
#include "fraction.h"
#define fc Fraction_create

void dotTests ();
void lineTests ();
void boolTests ();

void testPFraction (PFraction expected, PFraction paramA, PFraction paramB, PFraction (*fn)(PFraction, PFraction), char *);
void testBool (int expected, PFraction paramA, PFraction paramB, int (*fn)(PFraction, PFraction), char *);

int globalHasFailed = 0;

int main () {
    lineTests();
    dotTests();
    boolTests();

    if (globalHasFailed) {
        printf("\nNOTICE: SOME TESTS HAVE FAILED.\n");
        return 1;
    } else {
        printf("\nAll tests passed.\n");
        return 0;
    }
}

void dotTests () {
    testPFraction(fc(5, 12), fc(3, 2), fc(5, 18), Fraction_multiply, "Fraction_multiply");
    testPFraction(fc(27, 5), fc(3, 2), fc(5, 18), Fraction_divide, "Fraction_divide");
}

void lineTests () {
    testPFraction(fc(46, 5), fc(1, 5), fc(9, 1), Fraction_add, "Fraction_add");
    testPFraction(fc(-44, 5), fc(1, 5), fc(9, 1), Fraction_subtract, "Fraction_subtract");
}

void boolTests () {
    testBool(1, fc(1,2), fc(16, 32), Fraction_equal, "Fraction_equal");
    testBool(0, fc(1, 2), fc(16, 32), Fraction_unequal, "Fraction_unequal");

    testBool(1, fc(13, 27), fc(15, 31), Fraction_greater, "Fraction_greater");
    testBool(0, fc(13, 27), fc(15, 31), Fraction_smaller, "Fraction_smaller");

    testBool(1, fc(300, 150), fc(30, 15), Fraction_greaterOrEqual, "Fraction_greaterOrEqual");
    testBool(1, fc(600, 300), fc(60, 30), Fraction_smallerOrEqual, "Fraction_smallerOrEqual");
}

//------ print methods

void testPFraction (PFraction expected, PFraction paramA, PFraction paramB, PFraction (*fn)(PFraction, PFraction), char * name) {
    PFraction returnValue = fn(paramA, paramB);

    printf("Test %s with ", name);
    Fraction_show(paramA);
    printf(" and ");
    Fraction_show(paramB);

    printf("\n\tExpected: ");
    Fraction_show(expected);
    printf("\n\tGot: ");
    Fraction_show(returnValue);

    printf("\n\tTest %s\n\n", Fraction_equal(expected, returnValue) ? "PASSED" : "FAILED");

    if (!Fraction_equal(expected, returnValue)) globalHasFailed = 1;
    Fraction_massDelete(4, returnValue, paramA, paramB, expected);
}

void testBool (int expected, PFraction paramA, PFraction paramB, int (*fn)(PFraction, PFraction), char * name) {
    int returnValue = fn(paramA, paramB);

    printf("Test %s with ", name);
    Fraction_show(paramA);
    printf(" and ");
    Fraction_show(paramB);

    printf("\n\tExpected: %s\n", expected ? "TRUE" : "FALSE");
    printf("\tGot: %s\n", returnValue ? "TRUE" : "FALSE");
    printf("\tTest %s\n\n", expected == returnValue ? "PASSED" : "FAILED");

    if (expected != returnValue) globalHasFailed = 1;
    Fraction_massDelete(2, paramA, paramB);
}