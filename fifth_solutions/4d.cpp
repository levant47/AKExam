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

        ; 7 * x²
        mov edx, 7
        mul edx
        mov ebx, eax

        ; 25 * x
        mov eax, ecx
        mov edx, 25
        mul edx

        ; 7 * x² + 25 * x
        add ebx, eax

        ; 7 * x² + 25 * x - 27
        sub ebx, 27

        cmp ebx, 3000
        jg end

        inc ecx
        jmp loop_start

        end:
        mov [result], ecx
    }

    printf("%d\n", result);
}
