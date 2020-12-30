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

        ; 5 * x²
        mov edx, 5
        mul edx
        push eax

        ; 7 * x
        mov eax, ecx
        mov edx, 7
        mul edx

        ; 7 * x / (5 * x²)
        pop edi
        mov edx, 0
        div edi

        cmp eax, 250
        jg end

        inc ecx
        jmp loop_start

        end:
        mov [result], ecx
    }

    printf("%d\n", result);
}
