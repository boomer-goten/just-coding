// Программа на языке C для преобразования реального значения
// к представлению с плавающей запятой IEEE 754

#include <stdio.h>

void printBinary(int n, int i) {
  // Печатает двоичное представление
  // числа n до i бит.
  for (int k = i - 1; k >= 0; k--) {
    if ((n >> k) & 1)
      printf("1");
    else
      printf("0");
  }
}

typedef union {
  float f;
  struct {
    // Порядок важен.
    // Здесь члены структуры данных union
    // используем ту же память (32 бита).
    // Заказ принят
    // от LSB к MSB.
    unsigned int mantissa : 23;
    unsigned int exponent : 8;
    unsigned int sign : 1;

  } raw;
} myfloat;

// Функция для преобразования реального значения
// в представление с плавающей запятой IEEE
void printIEEE(myfloat var) {
  // Печатает представление IEEE 754
  // значения с плавающей запятой (32 бита)
  printf("%d | ", var.raw.sign);
  printBinary(var.raw.exponent, 8);
  printf(" | ");
  printBinary(var.raw.mantissa, 23);
  printf("\n");
}

// Код драйвера
int main() {
  // Создаем объединение
  myfloat var;
  // Получить реальное значение
  var.f = -2.25;
  // Получить представление IEEE с плавающей запятой
  printf("IEEE 754 representation of %f is : \n", var.f);
  printIEEE(var);

  return 0;
}