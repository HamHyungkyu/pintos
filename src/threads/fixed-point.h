#ifndef FIXED_POINT_H
#define FIXED_POINT_H

#define FIXED_POINT_FORMAT (1 << 14)

/* Convert integer N to fixed point number */
int convert_to_fp(int n) { return n * FIXED_POINT_FORMAT; }

/* Convert fixed point x to integer rounding towrad zero*/
int convert_to_int_rounding_toward_zero(int x) { return x / FIXED_POINT_FORMAT; }

/* Convert fixed point x to integer rounding towrad nearest*/
int convert_to_int_rounding_toward_nearest(int x)
{
    if (x >= 0)
    {
        return (x + FIXED_POINT_FORMAT / 2) / FIXED_POINT_FORMAT;
    }
    else
    {
        return (x - FIXED_POINT_FORMAT / 2) / FIXED_POINT_FORMAT;
    }
}

int add_fp_and_fp(int x, int y) { return x + y; }
int sub_fp_and_fp(int x, int y) { return x - y; }
int add_fp_and_int(int x, int n) { return x + n * FIXED_POINT_FORMAT; }
int sub_int_form_fp(int x, int n) { return x - n * FIXED_POINT_FORMAT; }
int mult_fp_and_fp(int x, int y) { return ((int64_t)x) * y / FIXED_POINT_FORMAT; }
int mult_fp_and_int(int x, int n) { return x * n; }
int div_fp_by_fp(int x, int y) { return ((int64_t)x) * FIXED_POINT_FORMAT / y; }
int div_fp_by_int(int x, int n) { return x / n; }

#endif /* threads/fixed_point.h */
