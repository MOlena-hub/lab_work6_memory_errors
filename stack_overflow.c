#include <stdio.h>

void recursive_function(int counter) {
    int large_array[256]; 
    large_array[0] = counter;
    
    if (counter % 1000 == 0) {
        printf("Поточна глибина стеку: %d (значення: %d)\n", counter, large_array[0]);
    }
    recursive_function(counter + 1);
}

int main() {
    printf("Запуск тесту переповнення стеку...\n");
    recursive_function(1);
    return 0;
}
