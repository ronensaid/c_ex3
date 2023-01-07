#include <stdio.h>

void print_array(int *data, int n) {
	int i;
	for(i = 0; i<n; i++) {
		printf("%d ", *data);
		data++;
	}
	printf("\n");
}

/* The method gets a pointer and moves the
following n characters to the right */
int shift_element(int* arr, int i) {
    int *dest = (int*)arr;
    for ( ;i>0; i--) {
        
        *(dest+i) = *(dest+i-1);
                  
    }

    return 0;
}

/* The method performs insertion sort by double-looping
and moving each number to the appropriate position */
int insertion_sort(int* arr , int len) {
    int temp = *(arr);
    int *pointer = (int*)arr;
    for (int i = 1; i<len; i++){
        temp = *(arr+i);
        for (int j = 0; j<i; j++){
            pointer = arr+j;
            if (temp<*pointer) {
                shift_element(pointer,i-j);
                *pointer = temp;
                break;
            }
        }
    }
    return 0;
}
int main() {
	
	int arr[] = {93,49,32,8,25,46,31,8,44,14,1,9,58,78,66,64,25,81,46,79,6,28,42,42,59,48
                  ,38,67,70,40,77,14,64,5,56,32,13,55,21,40,2,26,96,23,76,70,29,28,43,75};
	int n = sizeof(arr)/sizeof(int);
    printf("before: ");
	print_array(&arr[0], n);
	
	insertion_sort(&arr[0], n);
    //shift_element(&arr[2],4);
	printf("after; ");
	print_array(&arr[0], n);
    return 0;

}