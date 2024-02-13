#include <iostream>
#include "Utility Functions .h"
using namespace std;


void parcelLoader(int *parcel, int *parcelSum, int truckWeight, int originalSize);

int main() {
    int parcels[10]={10,15,7,32,13,45,11,50,27,23};
    int parcelSum[10]={0};
    int originalSize=sizeof(parcels)/sizeof(parcels[0]);
    int truckWeight=50;

    mergeSortDecending(parcels,originalSize);

    printf("%d\n",originalSize);
    for (int i=0;i<originalSize;i++){
        printf("%d  ",parcels[i]);
    }
    parcelLoader(parcels,parcelSum,truckWeight,originalSize);
    printf("\n");
    int x=0;
    for (int i=0;i<originalSize;i++){
        printf("%d  ",parcelSum[i]);
        if(parcelSum[i]!=0){
            x++;
        }
    }
    printf("\n");
    printf("So %d trucks will be required \n",x);

    return 0;
}



void parcelLoader(int *parcel, int *parcelSum, int truckWeight, int originalSize) {
    int sum = 0; // Current sum of parcel weights for the current truck
    int k = 0; // Index for parcelSum array

    for (int i = 0; i < originalSize; i++) {
        // Check if adding the current parcel exceeds the truck weight
        if (sum + parcel[i] <= truckWeight) {
            sum += parcel[i]; // Add current parcel to the current truck load
        } else {
            // Current parcel cannot be added to the current truck load
            parcelSum[k++] = sum; // Save the current truck load and move to the next truck
            sum = parcel[i]; // Start a new truck load with the current parcel
        }
    }

    // Don't forget to save the last truck load if not empty
    if (sum > 0) {
        parcelSum[k] = sum;
    }
}












