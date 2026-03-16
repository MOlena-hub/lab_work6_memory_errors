#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main() {
    printf("Запуск тесту переповнення купи (heap)...\n");

    // Виділяємо 16 байт
    char *dynamic_array = (char *)malloc(16 * sizeof(char));
    
    if (dynamic_array == NULL) {
        return 1;
    }

    // Спроба записати 64 байти в 16-байтний буфер
    printf("Запис за межі виділеної пам'яті...\n");
    memset(dynamic_array, 'A', 64); 

    // Виводимо для перевірки (хоча ASan зупинить програму раніше)
    printf("Дані записано. Очищення пам'яті...\n");
    
    free(dynamic_array);
    return 0;
}
