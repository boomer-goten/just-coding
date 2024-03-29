/* Дан массив целых чисел. Упорядочить элементы массива, расположив сначала
 * все четные числа в порядке возрастания, а затем - нечетные в порядке убывания.
 */
/* Задание делается исходя из того что массив одномерный и в программе задано число его элементов(10) */

#include <stdio.h>
#include <limits.h>

int main() {
    // Инициализируем и задаем массив
    int mass[10] = {7, 5, 9, 1, 3, 8, 10, 2, 6, 4};
    // Позиция четного числа
    int position_chet;
    // Промежуточная переменная для сортировки в цикле для четных числе
    int tmp_chet;
    // Первый цикл создается для того чтобы заменить элемент на позиции
    for (int i = 0; i < 10; i++) {
        int min_chet = INT_MAX;
        // Переменная ввелась для определения есть ли еще положительные числа
        int kolvo_chet = 0;
        // Второй цикл чтобы найти позицию минимального четного числа
        for (int j = i; j < 10; j++) {
            if (mass[j] % 2 == 0) {
                if (mass[j] < min_chet) {
                    min_chet = mass[j];
                    position_chet = j;
                    kolvo_chet = 1;
                }
            } 
        }
        // Cортируем масси по найденным позициям минимальное четного ставим в начало
        if (kolvo_chet == 1) {
            tmp_chet = mass[i];
            mass[i] = mass[position_chet];
            mass[position_chet] = tmp_chet;
        }
    }
    // Промежуточная переменная для сортировки в цикле для нечетных числе
    int tmp_nechet;
    // Позиция нечетного числа
    int position_nechet;
    // Первый цикл создается для того чтобы заменить элемент на позиции, при этом идем с конца
    for (int i = 9; i >= 0; i--) {
        int min_nechet = INT_MAX;
        // Второй цикл чтобы найти позицию минимального нечетного числа
        for (int j = i; j >= 0; j--) {
            if (mass[j] % 2 == 1) {
                if (mass[j] < min_nechet) {
                    min_nechet = mass[j];
                    position_nechet = j;
                }
            } 
        }
        // Если нашли четное число значит нечетных чисел больше нет и можно выйти из первого цикла
        if (mass[i] % 2 == 0) {
            break;
        }
        // Cортируем масси по найденным позициям минимальное нечетное ставим в конец
        tmp_nechet = mass[i];
        mass[i] = mass[position_nechet];
        mass[position_nechet] = tmp_nechet;
    }
    // Выводим массив и смотрим результат
    for (int k = 0; k < 10; k++) {
        printf("mass[%d] = %d\n", k, mass[k]);
    }
    return 0;
}