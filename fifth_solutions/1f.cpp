#include <stdio.h>

int main()
{
    const int result_size = 5;
    int result[result_size];
    const float initial_n = 4.f;
    const float step = 1.f;
    const float a = 1.75f;
    const float b = 6.3f;
    const float zero = 0.f;

    __asm
    {
        finit
        mov ecx, 0
        fld initial_n
        fld zero

        loop_start:

        ; n²
        fld ST(1)
        fld ST(0)
        fmul

        ; 1.75 * n²
        fld a
        fmul

        ; 1.75 * n² + 6.3
        fld b
        fadd

        ; sum += 1.75 * n² + 6.3
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

