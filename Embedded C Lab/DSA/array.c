#include <stdio.h>
#include <stdlib.h>





typedef struct array
{
    int size;
    int capacity;
    int* ptr; 
}array;


void display(array *arr){

    for (int i = 0; i < arr->size; i++)
    {
        printf("%d",arr->ptr[i]);
    }

}


void append(array *arr,int val){

    if (arr->size < arr->capacity)
    {
        arr->ptr[arr->size] = val;
        arr->size++;
    }
    
}
void insert(array *arr,int index,int val){

    if (arr->size < arr->capacity)
    {        
        for (int i = arr->size; i >index; i--)
        {
            arr->ptr[i] = arr->ptr[i-1];
        }
        
        arr->ptr[index] = val;
        arr->size++;
    }
}

void delete(array *arr,int index){
    for (int i = index; i < arr->size; i++)
    {
        arr->ptr[i] = arr->ptr[i + 1];
    }
    arr->size--;
}

int search(array *arr,int val,int found){
    for (int i = 0; i < arr->size; i++)
    {
        if (arr->ptr[i] == val)
        {
            found = i;
            return found;
        }
    }
    return -1;
    
}

int max(array *arr){
    int max = arr->ptr[0];
    for (int i = 1; i < arr->size; i++)
    {
        if (arr->ptr[i] > max)
        {
            max = arr->ptr[i];
        }
        
    }
    return max;
}

int min(array *arr){
    int min = arr->ptr[0];
    for (int i = 1; i < arr->size; i++)
    {
        if (arr->ptr[i] < min)
        {
            min = arr->ptr[i];
        }
        
    }
    return min;
}






int main(){
    array newArr = {0, 10};
    newArr.ptr = (int*)malloc(newArr.capacity * sizeof(int));
    append(&newArr, 5);
    append(&newArr, 5);
    append(&newArr, 5);
    append(&newArr, 5);
    insert(&newArr, 3, 3);
    display(&newArr);
}
