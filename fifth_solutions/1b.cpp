#include <stdio.h>

int main()
{
    const int result_size = 5;
    float result[result_size];
    const float initial_x = 1.5f;
    const float step = 4.f;
    const float a = 33.f;
    const float b = 4.f;
    const float c = -8.5f;

    __asm
    {
        finit
        mov ecx, 0
        fld initial_x

        loop_start:

        ; 33 * x
        fld ST(0)
        fld a
        fmul

        ; x²
        fld ST(1)
        fld ST(0)
        fmul

        ; 4 * x²
        fld b
        fmul

        ; 4 * x² - 8.5
        fld c
        fadd

        ; 33 * x / (4 * x² - 8.5)
        fdiv

        ; result[i] = 33 * x / (4 * x² - 8.5)
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

