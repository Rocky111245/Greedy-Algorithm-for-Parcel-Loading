# Greedy-Algorithm-for-Parcel-Loading
This code addresses the problem of optimally loading parcels into trucks for a transportation company that ships between Kuala Lumpur and Singapore. The algorithm is based on a simple greedy approach. 

## Problem Statement:
A transportation company that ships parcels between Kuala Lumpur and Singapore has approached 
you for consultation. The volume of parcels that needs to be shipped is high resulting in a number 
of trucks required each day to transport the parcels from Kuala Lumpur to Singapore. Each truck 
has a maximum amount of weight, WT, that it is allowed to carry. Parcels arrive at the Kuala 
Lumpur station and are processed for shipment one by one (in sequence). Each parcel Pi has a 
weight Wi. The parcel loading station is quite small. At most one truck can be at the loading station 
at any one time. Company policy requires that parcels are shipped in the order they arrive as the 
item(s) in the parcels are easily perishable. In addition, all parcels must be shipped within the same 
day it is received. You may assume that there are only 5 trucks (with the same maximum amount 
of weight) available each day to ship the parcels from Kuala Lumpur to Singapore. At present, the 
company is using a simple greedy algorithm for shipping parcels. They load the parcels into the 
truck in the order that it arrives at the Kuala Lumpur station. When the next parcel does not fit into 
the truck due to the maximum weight the truck is allowed to carry, the truck drives off to Singapore.

-A transportation company ships parcels between Kuala Lumpur and Singapore.
-Each truck has a maximum weight capacity, WT.
-Parcels arrive sequentially and each parcel Pi has a weight Wi
-Company policy requires parcels to be shipped in the order they arrive, as the items in the parcels are perishable.
-All parcels must be shipped within the same day they are received.
-There are only 5 trucks available each day, and each has the same maximum weight.
-The current loading strategy is to load parcels into the truck in the order they arrive. If the next parcel does not fit, the truck departs.

## Code:
```
#include <iostream>
using namespace std;

void displayArray(int pweight[], int no_of_parcels);
void parcelLoad(int numberofTrucks, int truckWeight, int pWeight[],int size, int truckLoadCapacity[5]);

int main() {
    int truckWeight;
    int numberofTrucks=5;
    int size;
    cout << "Greedy algorithm" << endl;
    cout<<"Enter truck weight: ";
    cin >> truckWeight;
    int truckLoadCapacity[5]={truckWeight, truckWeight, truckWeight, truckWeight, truckWeight};
    cout << "Enter total number of parcels: ";
    cin >> size;
    int pweight[size];
    int temp[size];

    // Initialize the elements of the pweight array
    for (int i = 0; i < size; i++) {
        cout << "Enter weight of parcel " << (i + 1) << ": ";
        cin >> temp[i];
        if(temp[i] >truckWeight) {
            cout << "Invalid weight" << endl;
            i=i-1;//This is to go back to the previous element.Gives user a chance to correct their mistake.
        }
        else{
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
void displayTruckLoad(int truckLoadCapacity[], int numberofTrucks){
    for (int i = 0; i < numberofTrucks; i++) {
        cout << "Truck " << (i + 1) << " has a remaining capacity of " << truckLoadCapacity[i] << endl;
    }
}
//suppose truckweight is 50
//20 20 30 40 20 10
void parcelLoad(int numberofTrucks, int truckWeight, int pWeight[],int size, int truckLoadCapacity[5]){
    int i=1;
    int parcelNumber=0;
    int truckNumber=0;
    while (i<=numberofTrucks && parcelNumber+1<=size){
        if(truckLoadCapacity[truckNumber] - pWeight[parcelNumber]>=0){
            truckLoadCapacity[truckNumber]= truckLoadCapacity[truckNumber] - pWeight[parcelNumber];
            parcelNumber++;
        if(truckLoadCapacity[truckNumber] == 0){
            cout << "Truck number " << (truckNumber + 1)  << " and has left the parcel station" << endl;
            truckNumber++;
            i++;
        }
        }

        else if(truckLoadCapacity[truckNumber] - pWeight[parcelNumber]<0){
            cout<<"Truck number "<<truckNumber+1<<" does not have enough space for next parcel and has left the parcel station"<<endl;
            truckNumber++;
            i++;

        }

    }
    displayTruckLoad(truckLoadCapacity,numberofTrucks);



}
```
## Code Structure:

### Main Function->

-Get the maximum weight a truck can carry.
-Initialize truck capacities.
-Get the total number of parcels and their respective weights. Ensure parcel weight doesn't exceed truck capacity.
-Display the entered parcel weights.
-Load parcels onto trucks using the greedy algorithm.

### displayArray Function:
A utility function to display the weights of the parcels.

### displayTruckLoad Function:
A utility function to display the remaining capacities of the trucks after loading parcels.

### parcelLoad Function:
-Implements the greedy loading strategy.
-Iterates through the trucks and parcels.
-If the current parcel fits into the current truck, it's loaded.
-If the truck gets filled, it departs.
-If a parcel can't fit into the current truck, the truck departs and the next truck is used.

## How the Algorithm Works:
1. Parcels are processed in the order they arrive.
1. If the current parcel fits in the current truck, it's added. The truck's capacity is reduced accordingly.
1. If the parcel doesn't fit, the current truck departs and the next truck is used.
1. If a truck gets filled up, it departs and the next truck is used.
1. This continues until all parcels are loaded or all trucks are used.


## Observations:
The current strategy is a straightforward greedy approach. While it ensures that parcels are shipped in the order they arrive, it might not always be the most optimal in terms of truck usage. Depending on the order and weights of the parcels, there might be cases where a more sophisticated algorithm could use fewer trucks. However, given the constraints, this greedy method is simple, easy to implement, and ensures timely shipment of parcels.

## Time Complexity of the Algorithm:
## Efficiency Analysis of the Greedy Parcel Loading Algorithm

### 1. Initialization

The initialization process involves:
- Setting up the truck capacities, which is \(O(1)\) since the number of trucks is constant (5 trucks).
- Inputting the total number of parcels and their respective weights, which is \(O(n)\) where \(n\) is the number of parcels.

**Time Complexity for Initialization**: \(O(n)\)

### 2. `displayArray` Function

This function iterates through all the parcels to display their weights.

**Time Complexity**: \(O(n)\)

### 3. `displayTruckLoad` Function

This function iterates through all the trucks to display their remaining capacities.

**Time Complexity**: \(O(1)\) since the number of trucks is constant (5 trucks).

### 4. `parcelLoad` Function

The primary logic of the algorithm resides in the `parcelLoad` function. Here's a breakdown of its operations:
- Iterating over all the parcels: \(O(n)\)
- For each parcel, in the worst-case scenario, it checks each truck to see if it fits (given that the number of trucks is constant): \(O(1)\)

Thus, the nested loop structure in the `parcelLoad` function doesn't result in quadratic behavior due to the fixed number of trucks. Instead, the time complexity is primarily influenced by the number of parcels.

**Time Complexity for `parcelLoad`**: \(O(n)\)

### Overall Time Complexity

Combining all the functions and their operations, the overall time complexity is:

\[O(n) + O(n) + O(1) + O(n) = O(n)\]

## Why is this Algorithm Efficient?

1. **Linear Complexity**: The algorithm operates with a linear time complexity of \(O(n)\). This means that the time taken by the algorithm grows linearly with the number of parcels. Thus, even if the number of parcels increases significantly, the algorithm remains scalable.

2. **Constant Factors**: The number of trucks is a constant factor (5 trucks). Hence, the algorithm doesn't experience a quadratic or polynomial increase in time complexity due to the nested loop in `parcelLoad`.

3. **Straightforward Operations**: The operations inside the loops are basic arithmetic and comparison operations, which are quick to execute.

4. **Greedy Nature**: The algorithm makes local optimal choices at each step by loading a parcel if it fits or moving to the next truck if it doesn't. This greedy approach avoids the need for backtracking or exploring multiple solutions, which would significantly increase the time complexity.

5. **No Sorting or Advanced Data Structures**: The algorithm doesn't rely on sorting operations or advanced data structures, both of which could add overhead in terms of time complexity.

In conclusion, the greedy parcel loading algorithm is efficient due to its linear time complexity and the simplicity of its operations. Given the constraints of the problem (such as shipping parcels in the order they arrive), this algorithm provides a time-efficient solution.


















