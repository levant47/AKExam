#include <iostream>
int main() {
      const int n = 7; // размер массива
      long  x[n] = { 7, 2, 3, 4, 5, 6, 7 }; // массив в памяти
      int result = 0;
      _asm
      {
                lea  EBX, x; // начальный адрес массива – в ЕВХ
                mov  ECX, n; // счетчик повторений
                mov  EAX, dword ptr[EBX]; //первый элемент – в ЕАХ
      m1:
                popcnt EDX, EAX; //popcnt подсчитывает количество установленных; битов в машинном слове
                add result, EDX; //суммируем к - во едениц в каждом элементе массива
                add EBX, 4; //увеличение адреса
                mov EAX, dword ptr[EBX]; //помещаем в EAX следующее занчение; массива х
                loop m1; //зацикливание по счетчику
                mov ESI, result; //esi = result
      }
      std::cout << result << "\n";
      system("pause");
}
