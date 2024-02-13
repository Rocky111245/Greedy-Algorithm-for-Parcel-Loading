#include <iostream>

using namespace std;

void displayArray(int pweight[], int no_of_parcels);

void parcelLoad(int numberofTrucks, int truckWeight, int pWeight[], int size, int truckLoadCapacity[5]);

int main() {
    int truckWeight;
    int numberofTrucks = 10;
    int size;
    cout << "Greedy algorithm" << endl;
    cout << "Enter truck weight: ";
    cin >> truckWeight;
    int truckLoadCapacity[5] = {truckWeight, truckWeight, truckWeight, truckWeight, truckWeight};
    cout << "Enter total number of parcels: ";
    cin >> size;
    int pweight[size];
    int temp[size];

    // Initialize the elements of the pweight array
    for (int i = 0; i < size; i++) {
        cout << "Enter weight of parcel " << (i + 1) << ": ";
        cin >> temp[i];
        if (temp[i] > truckWeight) {
            cout << "Invalid weight" << endl;
            i = i - 1;//This is to go back to the previous element.Gives user a chance to correct their mistake.
        } else {
            pweight[i] = temp[i];
        }

    }

    displayArray(pweight, size);
    parcelLoad(numberofTrucks, truckWeight, pweight, size, truckLoadCapacity);

    return 0;
}

//A function to display the array
void displayArray(int pweight[], int no_of_parcels) {
    for (int i = 0; i < no_of_parcels; i++) {
        cout << "Weight of parcel " << (i + 1) << ": " << pweight[i] << endl;
    }
}

void displayTruckLoad(int truckLoadCapacity[], int numberofTrucks) {
    for (int i = 0; i < numberofTrucks; i++) {
        cout << "Truck " << (i + 1) << " has a remaining capacity of " << truckLoadCapacity[i] << endl;
    }
}

//suppose truckweight is 50
//20 20 30 40 20 10
void parcelLoad(int numberofTrucks, int truckWeight, int pWeight[], int size, int truckLoadCapacity[5]) {
    int i = 1;
    int parcelNumber = 0;
    int truckNumber = 0;
    while (i <= numberofTrucks && parcelNumber + 1 <= size) {
        if (truckLoadCapacity[truckNumber] - pWeight[parcelNumber] >= 0) {
            truckLoadCapacity[truckNumber] = truckLoadCapacity[truckNumber] - pWeight[parcelNumber];
            parcelNumber++;
            if (truckLoadCapacity[truckNumber] == 0) {
                cout << "Truck number " << (truckNumber + 1) << " and has left the parcel station" << endl;
                truckNumber++;
                i++;
            }
        } else if (truckLoadCapacity[truckNumber] - pWeight[parcelNumber] < 0) {
            cout << "Truck number " << truckNumber + 1 << " does not have enough space for next parcel and has left the parcel station" << endl;
            truckNumber++;
            i++;

        }

    }
    displayTruckLoad(truckLoadCapacity, numberofTrucks);


}