#include <stdio.h>

int main()
{
    const int result_size = 5;
    float result[result_size];
    const float initial_x = 1.f;
    const float step = 2.1f;
    const float a = 317.f;
    const float b = 3.6f;
    const float c = -7.5f;

    __asm
    {
        finit
        mov ecx, 0
        fld initial_x

        loop_start:

        ; 317
        fld a

        ; x²
        fld ST(1)
        fld ST(0)
        fmul

        ; 3.6 * x
        fld ST(2)
        fld b
        fmul

        ; x² + 3.6 * x
        fadd

        ; x² + 3.6 * x - 7.5
        fld c
        fadd

        ; 317 / (x² + 3.6 * x - 7.5)
        fdiv

        ; result[i] = 317 / (x² + 3.6 * x - 7.5)
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

