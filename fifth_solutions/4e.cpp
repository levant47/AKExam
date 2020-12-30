#include <iostream>

using namespace std;

int main() {
    #define V 15
    long X = 0;
    long RESULT;

    _asm
    {
        cycle : mov EAX, 8;  //EAX = 8
        mul X;     //EAX = 8 * x
        mul X;     //EAX = 8 * x ^ 2
        add EAX, 25;   //EAX = 8 * x ^ 2 + 25
        mov EDI, EAX;   //пересылка делителя в регистр EDI
        mov EAX, 17000;   //EAX = 17000
        div EDI;    //частное – EAX, остаток – EDX
        cmp EAX, V;  //сравнение EAX и 20
        mov EAX, X;    //переслыка в EAX значения текущего аргумента
        mov RESULT, EAX;  //пересылка аргумента в RESULT
        inc X;     //инкремент X
        ja cycle;    //переход если EAX > 20
    }

    cout << RESULT << endl;
}
