#include <iostream>
#include "HammingCode.h"
#include <vector>
#include <iostream>

using namespace std;

int main() {
    HammingCode hammingCode = HammingCode();
    //Example: array of bits
    vector<int> vec = {1,0,0,1};
    for (int i : vec) {
        cout << i << " ";
    }
    cout << endl;
    //get it's HammingCode
    vector<int> hammingVec = hammingCode.getHammingCode(vec);
    for (int i : hammingVec) {
        cout << i << " ";
    }
    cout << endl;
    //check if it has any errors
    if (hammingCode.detectError(hammingVec)){
        cout << "No Error Found" << endl;
    } else {
        cout << "Error Found" << endl;
    }

    //create error
    hammingVec[0] = 1;
    //check if it detects the error
    if (hammingCode.detectError(hammingVec)){
        cout << "No Error Found" << endl;
    } else {
        cout << "Error Found" << endl;
    }

}
