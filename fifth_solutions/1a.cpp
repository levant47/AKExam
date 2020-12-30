#include <stdio.h>

int main()
{
    const int result_size = 5;
    float result[result_size];
    const float initial_x = 6.0f;
    const float step = 3.0f;
    const float a = 13;
    const float b = 6;

    __asm
    {
        finit
        mov ecx, 0
        fld initial_x

        loop_start:

        ; x²
        fld ST(0)
        fld ST(0)
        fmul

        ; 13 * x²
        fld a
        fmul

        ; 6 + x
        fld ST(1)
        fld b
        fadd

        ; 13 * x² / (6 + x)
        fdiv

        ; √(13 * x² / (6 + x))
        fsqrt

        ; result[i] = √(13 * x² / (6 + x))
        fstp [result + ecx * 4]

        ; x += step
        fld [step]
        fadd

        inc ecx
        cmp ecx, [result_size]
        jne loop_start
    }

    for (int i = 0; i < result_size; i++)
    {
        printf("%f\n", result[i]);
    }
}

