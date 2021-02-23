#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>
#include "fraction.h"

struct Fraction {
    int num;
    int denom;
};

void checkSign(PFraction _this);
void reduce(PFraction _this);
int gcd(int a, int b); //greatest common divisor
int lcm(int a, int b); //least common multiple

PFraction Fraction_create (int num, int denom) {
    PFraction allocated = (PFraction) malloc(sizeof(struct Fraction));
    if (allocated == NULL) {
        printf("\nCould not allocate Fraction, no memory available.\n");
        exit(1);
    }

    Fraction_set(allocated, num, denom);
    return allocated;
}

void Fraction_set (PFraction _this, int num, int denom) {
    _this->num = num;
    _this->denom = denom;

    if (denom == 0) {
        printf("\nWARN: Denominator is smaller than 0 (Cannot divide by zero).\n");
        _this->denom = 1;
    }

    checkSign(_this);
    reduce(_this);
}

int  Fraction_getNumerator (PFraction _this) {
    return _this->num;
}

int  Fraction_getDenominator (PFraction _this) {
    return _this->denom;
}

void Fraction_show (PFraction _this) {
    printf("(%d/%d)", _this->num, _this->denom);
}

PFraction Fraction_multiply (PFraction a, PFraction b) {
    return Fraction_create(a->num * b->num, a->denom * b->denom);
}

PFraction Fraction_divide(PFraction a, PFraction b) {
    return Fraction_create(a->num * b->denom, a->denom * b->num);
}

PFraction Fraction_add(PFraction a, PFraction b) {
    int lcmV = lcm(a->denom, b->denom);
    return Fraction_create((a->num * lcmV / a->denom) + (b->num * lcmV / b->denom), lcmV);
}

PFraction Fraction_subtract(PFraction a, PFraction b) {
    int lcmV = lcm(a->denom, b->denom);
    return Fraction_create((a->num * lcmV / a->denom) - (b->num * lcmV / b->denom), lcmV);
}

void Fraction_delete (PFraction _this) {
    free(_this);
}

void Fraction_massDelete(int count, ...) {
    va_list args;
    va_start(args, count);

    for (int i = 0; i < count; i++) {
        free(va_arg(args, PFraction));
    }

    va_end(args);
}

int Fraction_equal(PFraction _this, PFraction f) {

}

int Fraction_unequal(PFraction _this, PFraction f) {

}

int Fraction_greater(PFraction _this, PFraction f) {

}

int Fraction_smaller(PFraction _this, PFraction f) {

}

int Fraction_smallerOrEqual(PFraction _this, PFraction f) {

}

int Fraction_greaterOrEqual(PFraction _this, PFraction f) {
    
}

// --------- helper functions

void checkSign (PFraction _this) {
    if (_this->denom >= 0) return;

    _this->num *= -1;
    _this->denom *= -1;
}

void reduce (PFraction _this) {
    if (_this->num == 0) {
        _this->denom = 1;
        return;
    }

    int gcdV = gcd(abs(_this->num), _this->denom);

    if (gcdV != 1) {
        _this->num /= gcdV;
        _this->denom /= gcdV;
    }
}

int gcd (int a, int b) {
    if (a == b) return a;

    if (a > b) {
        return gcd(a - b, b);
    } else {
        return gcd(b - a, a);
    }
}


int lcm (int a, int b) {
    return abs(a / gcd(a, b) * b);
}