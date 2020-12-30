#include <iostream>

void main() {
    float A = 2.3, B = 3.2, C = 1.0, S = 900.0, an = 0;
    long n = 0;

    _asm {
        m1:
        inc n        // N = N + 1
        finit        // очищаем стек

        fld A;   // Загрузка аргументов в стек
        fimul n;  // Умножение ST(0) на Х (результат в  ST(0))
        fimul n;  // Умножение ST(0) на Х (результат в  ST(0))
        fadd B;   // Добавить к ST(0) число c (результат в ST(0))

        fadd an        // добавляем к общей сумме

        fld S        // st = 900
        fcomi ST, ST(1)    // сравнение st(1) с 900
        fxch        // обмен регистров ST(0) и ST(1)
        fstp an        // выгружаем вершину в an
        ja m1        // прижок при an < 900

    }

    std::cout << "an = " << an << " n = " << n;
}
