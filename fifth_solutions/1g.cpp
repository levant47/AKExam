#include <stdio.h>

int main()
{
    const int result_size = 5;
    int result[result_size];
    const float initial_n = 1.f;
    const float step = 1.f;
    const float a = 4.75f;
    const float b = 5.f;
    const float zero = 0.f;

    __asm
    {
        finit
        mov ecx, 0
        fld initial_n
        fld zero

        loop_start:

        ; 4.75 * n
        fld ST(1)
        fld a
        fmul

        ; n + 5
        fld ST(2)
        fld b
        fadd

        ; 4.75 * n / (n + 5)
        fdiv

        ; sum += 4.75 * n / (n + 5)
        fadd

        ; result[i] = sum
        fist [result + ecx * 4]

        ; x += step
        fld [step]
        fadd ST(0), ST(2)
        fstp ST(2)

        inc ecx
        cmp ecx, [result_size]
        jne loop_start
    }

    for (int i = 0; i < result_size; i++)
    {
        printf("%d\n", result[i]);
    }
}

