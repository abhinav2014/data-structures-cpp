//
//  array.cpp
//  DSA
//
//  Created by BA-000277306 on 27/08/22.
//

#include <stdio.h>
#include <iostream>
#include "array.hpp"

using namespace::std;

void mergeTwoArrays() {
    int arr1[5] = {1,3,5,8,10};
    int arr2[5] = {2,4,6,7,9};
    int merged[10] = {};
    int arr1Index=0, arr2Index=0;
    for(int i=0;i<10;i++) {
        if (arr1Index == 5) { // overflow cnditions
            merged[i] = arr2[arr2Index];
            arr2Index+=1;
        } else if (arr2Index == 5) {
            merged[i] = arr1[arr1Index];
            arr1Index+=1;
        } else if (arr1[arr1Index] > arr2[arr2Index]) {  // Comparison
            merged[i] = arr2[arr2Index];
            arr2Index+=1;
        } else if (arr1[arr1Index] < arr2[arr2Index]) {
            merged[i] = arr1[arr1Index];
            arr1Index+=1;
        }
    }
    cout<<"\n";
    cout<<arr1Index;
    cout<<arr2Index;
    cout<<"Merged Array:\n";
    for(int i=0;i<10;i++) {
        cout<<merged[i];
    }
}
