#include <iostream>

void swap(int *xp, int *yp)  
{  
    int temp = *xp;  
    *xp = *yp;  
    *yp = temp;  
}  

int main(){

    int array[3] = {7, 9, 4};
    swap(&array[0], &array[1]);
    for (int i = 0; i < 3; i++){
        std::cout << array[i];
    }
}