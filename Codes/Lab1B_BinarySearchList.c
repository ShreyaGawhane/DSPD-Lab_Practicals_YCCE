//ShreyaGawhane-IT-B-120
/*Write a program to implement a Binary Search algorithm. Write a search function which takes a SearchList as its first parameter and a Comparable as its second. If either parameter is null, or if the SearchList is empty, you should return NULL.
 implement the following algorithm: 
• Examine the value in the middle of the current array and print it. 
• If the midpoint value is the value that we are looking for, return true 
• If the value that we are looking for is greater than the midpoint value, adjust the current array to start at the midpoint and print the index.
• if the value that we are looking for is less than the midpoint value, adjust the current array to end at the midpoint  and print the index.
• Continue until you find the value, or until the start reaches the end.*/
#include <stdio.h>
int main() {
    int n, i, key, low, high, mid, found=0;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    int arr[100];
    
    printf("Enter %d elements of sorted array: ", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    printf("Enter the element to search: ");
    scanf("%d", &key);
    low = 0;
    high = n-1;
    while (low <= high) {
        mid = (low + high) / 2;
        printf("\nRemaining array:\n");
        for (i = low; i <= high; i++) {
            printf("%d ", arr[i]);
        }
        printf("\n Start = %d, End = %d, Mid = %d\n", low, high, mid);
        printf("Element at mid = %d \n", arr[mid]);
        printf("\n");
        
        if (arr[mid] == key) 
        {
            printf("The element %d is located at position %d\n", key, mid + 1);
            found = 1;
            break;
        } else if (key < arr[mid]) 
        {
            high = mid - 1;
        } else 
        {
            low = mid + 1;
        }
    }
    
    if (!found) {
        printf("The element %d is not present in the array\n", key);
    }
    
    return 0;
}
