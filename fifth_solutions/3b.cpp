#include <stdio.h>

int main()
{
    int result;
    const float a = 13.f;
    const float zero = 0;
    const float margin = 11500.f;

    __asm
    {
        fld1
        fld zero

        loop_start:

        ; 13 * n
        fld ST(1)
        fld a
        fmul

        ; sum += 13 * n
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
