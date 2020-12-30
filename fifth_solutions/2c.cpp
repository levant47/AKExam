#include <stdio.h>

int main()
{
    const int result_size = 7;
    int source[result_size] = { 0x00010002, 0x00030004, 0x00050006, 0x00070008, 0x0009000A, 0x000B000C, 0x000D000E };

    __asm
    {
        mov ecx, 0

        loop_start:
        mov eax, [source + ecx * 4]
        mov ebx, eax
        shr eax, 16
        and ebx, 0x0000FFFF
        mul ebx
        mov [source + ecx * 4], eax

        inc ecx
        cmp ecx, [result_size]
        jne loop_start
    }

    for (int i = 0; i < result_size; i++)
    {
        printf("%d\n", source[i]);
    }
}

