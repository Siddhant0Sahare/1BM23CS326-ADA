#include <stdio.h>


void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}


void heapify(int a[], int n, int i) {
    int largest = i;        
    int left = 2 * i + 1;    
    int right = 2 * i + 2;   

   
    if (left < n && a[left] > a[largest])
        largest = left;

  
    if (right < n && a[right] > a[largest])
        largest = right;

  
    if (largest != i) {
        swap(&a[i], &a[largest]);

      
        heapify(a, n, largest);
    }
}


void heapSort(int a[], int n) {
   
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(a, n, i);

   
    for (int i = n - 1; i >= 0; i--) {
       
        swap(&a[0], &a[i]);

        
        heapify(a, i, 0);
    }
}


void printArray(int a[], int n) {
    for (int i = 0; i < n; i++)
        printf("%d ", a[i]);
    printf("\n");
}

int main() {
    int a[100], n;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter the elements:\n");
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);

    heapSort(a, n);

    printf("Sorted array:\n");
    printArray(a, n);

    return 0;
}
