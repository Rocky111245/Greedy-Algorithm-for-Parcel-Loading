//
// Created by rakib on 13/2/2024.
//
#include <iostream>
#include "Utility Functions .h"




int *arrayMergerAscending(int *firstArray, int *secondArray, int originalSize) {
    int half = originalSize / 2;
    int k = 0, l = 0, i = 0;
    // Allocate memory for the merged array
    int *mergedArray = (int *)malloc(originalSize * sizeof(int));
    if (!mergedArray) return nullptr; // Check for malloc failure

    // Merge arrays until one is fully merged
    while (k < half && l < originalSize - half) {
        if (firstArray[k] < secondArray[l]) {
            mergedArray[i++] = firstArray[k++];
        } else {
            mergedArray[i++] = secondArray[l++];
        }
    }

    // Append remaining elements from either array
    while (k < half) {
        mergedArray[i++] = firstArray[k++];
    }
    while (l < originalSize - half) {
        mergedArray[i++] = secondArray[l++];
    }

    return mergedArray;
}

int *arrayMergerDecending(int *firstArray, int *secondArray, int originalSize) {
    int half = originalSize / 2;
    int k = 0, l = 0, i = 0;
    // Allocate memory for the merged array
    int *mergedArray = (int *)malloc(originalSize * sizeof(int));
    if (!mergedArray) return nullptr; // Check for malloc failure

    // Merge arrays until one is fully merged
    while (k < half && l < originalSize - half) {
        // Modify the condition to sort in descending order
        if (firstArray[k] > secondArray[l]) {
            mergedArray[i++] = firstArray[k++];
        } else {
            mergedArray[i++] = secondArray[l++];
        }
    }

    // Append remaining elements from either array
    while (k < half) {
        mergedArray[i++] = firstArray[k++];
    }
    while (l < originalSize - half) {
        mergedArray[i++] = secondArray[l++];
    }

    return mergedArray;
}



void mergeSortAscending(int *array, int size) {
    if (size <= 1) {
        return; // Base case: Array with 1 or no elements is already sorted.
    }

    // Calculate sizes for left and right halves
    int leftSize = size / 2;
    int rightSize = size - leftSize; // This accounts for odd sizes correctly

    // Split the array into left and right halves
    int *leftArray = halfArrayLeft(array, size);
    int *rightArray = halfArrayRight(array, size);

    // Recursively sort each half
    mergeSortAscending(leftArray, leftSize);
    mergeSortAscending(rightArray, rightSize);

    // Merge the sorted halves back into the original array
    int *mergedArray = arrayMergerAscending(leftArray, rightArray, size);
    arrayCopier(array, mergedArray, size); // Copy the merged array back to the original array

    // Free the dynamically allocated memory to prevent memory leaks
    free(leftArray);
    free(rightArray);
    free(mergedArray);
}
void mergeSortDecending(int *array, int size) {
    if (size <= 1) {
        return; // Base case: Array with 1 or no elements is already sorted.
    }

    // Calculate sizes for left and right halves
    int leftSize = size / 2;
    int rightSize = size - leftSize; // This accounts for odd sizes correctly

    // Split the array into left and right halves
    int *leftArray = halfArrayLeft(array, size);
    int *rightArray = halfArrayRight(array, size);

    // Recursively sort each half
    mergeSortDecending(leftArray, leftSize);
    mergeSortDecending(rightArray, rightSize);

    // Merge the sorted halves back into the original array
    int *mergedArray = arrayMergerDecending(leftArray, rightArray, size);
    arrayCopier(array, mergedArray, size); // Copy the merged array back to the original array

    // Free the dynamically allocated memory to prevent memory leaks
    free(leftArray);
    free(rightArray);
    free(mergedArray);
}











int *halfArrayRight(int *originalArray, int size){
    int half = (size + 1) / 2; // Ensures the "right" half gets the extra element if size is odd
    int *rightArray = (int *) malloc(half * sizeof(int));
    if (rightArray == nullptr) return nullptr; // Check for malloc failure
    for (int i = 0; i < half; i++) {
        rightArray[i] = originalArray[size/2 + i]; // Start from the middle to the end
    }
    return rightArray;
}

int *halfArrayLeft(int *originalArray, int size){
    int half = size / 2; // "Left" half size
    int *leftArray = (int *) malloc(half * sizeof(int));
    if (leftArray == nullptr) return nullptr; // Check for malloc failure
    for (int i = 0; i < half; i++) {
        leftArray[i] = originalArray[i]; // Start from the beginning to the middle
    }
    return leftArray;
}


void arrayCopier(int *originalArray, int *returnedArray, int size){
    for (int i=0;i<size;i++){
        originalArray[i]= returnedArray[i];
    }
}