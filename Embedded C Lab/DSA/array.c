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
        printf("%d,",arr->ptr[i]);
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





void reverse(array *arr){
    int temp;
    int j = 0;
    for (int i = arr->size-1; i > arr->size /2; i--)
    {
        temp = arr->ptr[j];
        arr->ptr[j] = arr->ptr[i];
        arr->ptr[i] = temp;
        j++; 
    }

}


void shiftLift(array* arr, int k){
    
    for (int i = k; i < arr->size; i++)
    {
        arr->ptr[i-k] = arr->ptr[i];
        

    }
    for (int i = arr->size-k; i < arr->size; i++)
    {
        arr->ptr[i] = 0;
    }
    
}

void rotateLeft(array *arr, int k){
    int temp;
    
    for (int i = 0; i < k; i++)
    {
        temp = arr->ptr[0];
        arr->ptr++;
        arr->ptr[arr->size-1] = temp;

    }
    
}
void rotateRight(array *arr, int k){
    int temp;
    
    for (int i = 0; i < k; i++)
    {
        temp = arr->ptr[arr->size-1];
        arr->ptr--;
        arr->ptr[0] = temp;

    }
    
}

void arrayRealloc(array* arr){
    arr->capacity *= 2;
    arr->ptr = (int*)realloc(arr->ptr, arr->capacity * sizeof(int));
    
}

void merge(array *arr, array *arr1){
    while(arr->size + arr1->size > arr->capacity)
    {
        arrayRealloc(arr);
    }
    for (int i = 0; i < arr1->size; i++)
        {
            arr->ptr[arr->size] = arr1->ptr[i];
            arr->size++;

        }
    
}


void sum(array* arr){
    int sum = 0;
    for (int i = 0; i < arr->size; i++)
    {
        sum += arr->ptr[i];
    }
    printf("sum is %d ", sum);
    
}
void average(array* arr){
    float avg = 0;
    for (int i = 0; i < arr->size; i++)
    {
        avg += arr->ptr[i];
    }
    avg /= arr->size;
    printf("sum is %.2f ", avg);
    
}



void replace(array *arr, int i, int j){
    int temp = arr->ptr[i];
    arr->ptr[i] = arr->ptr[j];
    arr->ptr[j] = temp;
}













int main(){
    array newArr = {0, 10};
    newArr.ptr = (int*)malloc(newArr.capacity * sizeof(int));
    array newArr1 = {0, 10};
    newArr1.ptr = (int*)malloc(newArr1.capacity * sizeof(int));
    append(&newArr, 5);
    append(&newArr, 5);
    append(&newArr, 5);
    append(&newArr, 5);
    insert(&newArr, 3, 3);
    append(&newArr1, 1);
    append(&newArr1, 1);
    append(&newArr1, 8);
    append(&newArr1, 6);
    insert(&newArr1, 2, 2);
    display(&newArr);
    reverse(&newArr);
    printf("\n");
    display(&newArr);
    printf("\n");
    shiftLift(&newArr, 2);
    display(&newArr);
    printf("\n");
    rotateLeft(&newArr,2);
    display(&newArr);
    printf("\n");
    rotateRight(&newArr,2);
    display(&newArr);
    printf("\n");
    merge(&newArr, &newArr1);
    display(&newArr);
}

