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

        ; 3 * x²
        mov edx, 3
        mul edx
        push eax

        ; 6 * x
        mov eax, ecx
        mov edx, 6
        mul edx

        ; 6 * x / (3 * x²)
        pop edi
        mov edx, 0
        div edi

        cmp eax, 170
        jg end

        inc ecx
        jmp loop_start

        end:
        mov [result], ecx
    }

    printf("%d\n", result);
}
