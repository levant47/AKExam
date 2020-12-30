#include <stdio.h>

int main()
{
    int result;
    const float a = 3.f;
    const float b = -5.f;
    const float c = 12.f;
    const float zero = 0;
    const float margin = 1250.f;

    __asm
    {
        fld1
        fld zero

        loop_start:

        ; n²
        fld ST(1)
        fld ST(0)
        fmul

        ; 3 * n²
        fld a
        fmul

        ; -5 * n
        fld ST(2)
        fld b
        fmul

        ; 3 * n² - 5 * n
        fadd

        ; 3 * n² - 5 * n + 12
        fld c
        fadd

        ; sum += 3 * n² - 5 * n + 12
        fadd

        fld margin
        fcomip ST(0), ST(1)
        jbe end

        fld1
        fadd ST(0), ST(2)
        fstp ST(2)
        jmp loop_start

        end:
        fstp ST(0)
        fist result
    }

    printf("%d\n", result);
}
