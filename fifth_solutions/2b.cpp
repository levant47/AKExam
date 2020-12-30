#include <stdio.h>

int main()
{
    const int result_size = 7;
    int source[result_size] = { 1, 2, 3, 4, 5, 6, 7 };

    __asm
    {
        mov ecx, 0
        mov edx, 0

        loop_start:
        mov eax, [source + edx * 4]
        and eax, 1
        cmp eax, 1
        jne skip
        inc ecx
        skip:

        inc edx
        cmp edx, [result_size]
        jne loop_start
    }
}

