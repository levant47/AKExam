#include <stdio.h>

int main()
{
    const int result_size = 5;
    float result[result_size];
    const float initial_x = 3.f;
    const float step = 2.5f;
    const float a = 15.f;
    const float b = 32.f;

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

        ; 15 * x²
        fld a
        fmul

        ; 32 / x
        fld b
        fld ST(2)
        fdiv

        ; 15 * x² + 32 / x
        fadd

        ; √(15 * x² + 32 / x)
        fsqrt

        ; result[i] = √(15 * x² + 32 / x)
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

