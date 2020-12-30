#include <stdio.h>

int main()
{
    int result;

    __asm
    {
        mov ecx, 1

        loop_start:

        ; x²
        mov eax, ecx
        mul eax

        ; 10 * x²
        mov edx, 10
        mul edx
        mov ebx, eax

        ; 8 * x
        mov eax, ecx
        mov edx, 8
        mul edx

        ; 10 * x² - 8 * x
        sub ebx, eax

        ; 10 * x² - 8 * x + 15
        add ebx, 15

        cmp ebx, 900
        jg end

        inc ecx
        jmp loop_start

        end:
        mov [result], ecx
    }

    printf("%d\n", result);
}
