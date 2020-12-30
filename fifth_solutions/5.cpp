#include <stdio.h>
#include <stdint.h>

int main()
{
    const uint32_t result_size = 6;
    int32_t result[result_size];
    int32_t argument = 4;
    __asm
    {
        mov eax, 1
        mov ecx, 1
        loop_start:
        cmp ecx, 7
        je loop_end

        mul ecx
        mov DWORD PTR [result + ecx * 4 - 4], eax

        inc ecx
        jmp loop_start
        loop_end:
    } 
    for (uint32_t i = 0; i < result_size; i++)
    {
        printf("%u: %d\n", i+1, result[i]);
    }
}
