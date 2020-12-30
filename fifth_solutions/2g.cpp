#include <stdio.h>

int main()
{
    const int result_size = 7;
    int source[result_size] = { 1, -2, 3, -4, 5, -6, 7 };

    __asm
    {
        mov edi, 0
        mov edx, 0

        loop_start:
        mov eax, [source + edx * 4]
        cmp eax, 0
        jge skip
        inc edi
        skip:

        inc edx
        cmp edx, [result_size]
        jne loop_start
    }
}

