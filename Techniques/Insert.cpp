#include <iostream>
int array[] = {3, 5, 7, 11, 13, 2, 9, 6};
int insert(int len, int rightIndex, int value) {
    int j;
    for(j = rightIndex;j >= 0 && array[j] > value;j--) 
    {array[j + 1] = array[j];}   
    array[j + 1] = value; 
};

int main(){
    

    insert(8, 4, 2);
    std::cout << "Array after inserting 2:  " << array;
    insert(8, 5, 9);
    std::cout << "Array after inserting 9:  " << array;
    insert(8, 6, 6);
    std::cout << "Array after inserting 6:  " << array;
}