#include <stdio.h>

int main()
{
    int result;
    const float a = 7.f;
    const float b = 68.f;
    const float zero = 0;
    const float margin = 640.f;

    __asm
    {
        fld1
        fld zero

        loop_start:

        ; n²
        fld ST(1)
        fld ST(0)
        fmul

        ; 7 * n
        fld ST(2)
        fld a
        fmul

        ; n² + 7 * n
        fadd

        ; n² + 7 * n + 68
        fld b
        fadd

        ; sum += n² + 7 * n + 68
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
