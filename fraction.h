#pragma once
typedef struct Fraction *PFraction;

PFraction Fraction_create(int num, int denom);
void Fraction_set(PFraction _this, int num, int denom);
int Fraction_getNumerator(PFraction _this);
int Fraction_getDenominator(PFraction _this);
void Fraction_show(PFraction _this);
PFraction Fraction_multiply(PFraction a, PFraction b);
PFraction Fraction_divide(PFraction a, PFraction b);
PFraction Fraction_add(PFraction a, PFraction b);
PFraction Fraction_subtract(PFraction a, PFraction b);
void Fraction_delete(PFraction _this);
void Fraction_massDelete(int count, ...);
int Fraction_equal(PFraction _this, PFraction f);
int Fraction_unequal(PFraction _this, PFraction f);
int Fraction_greater(PFraction _this, PFraction f);
int Fraction_smaller(PFraction _this, PFraction f);
int Fraction_smallerOrEqual(PFraction _this, PFraction f);
int Fraction_greaterOrEqual(PFraction _this, PFraction f);
