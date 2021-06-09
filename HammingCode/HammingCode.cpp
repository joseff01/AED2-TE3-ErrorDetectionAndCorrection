#include "HammingCode.h"

vector<int> HammingCode::getHammingCode(vector<int> bitVector) {
    vector<int> baseVector;
    int numParityBits = 0;
    for (int i = 1; bitVector.size()+i > pow(2,i-1); ++i) {
        //cout<<bitVector.size()+i<< endl;
        //cout<<pow(2,i-1)<< endl;
        numParityBits = i;
    }
    int totalBitNum = numParityBits + bitVector.size();
    //cout << "number of total bits: " << totalBitNum << endl;
    int bitCounter = 0;
    for (int i = 0; i < totalBitNum; ++i) {
        if(i == 0 || i == 1){
            //cout << i << endl;
            baseVector.push_back(0);
        } else if (isPowerOf2(i+1)) {
            //cout << i << endl;
            baseVector.push_back(0);
        }else{
            baseVector.push_back(bitVector[bitCounter]);
            bitCounter++;
        }
    }
    for (int i : baseVector) {
        //cout << i << " ";
    }
    int parityCounter = 0;
    for (int i = 0; i < totalBitNum; ++i) {
        //cout << "i: " << i << endl;
        if (i == 0 || i == 1){
            int skipValue = pow(2,parityCounter);
            //cout << "skipValue: " << skipValue << endl;
            for (int j = i; j < totalBitNum; j += (skipValue*2)) {
                //cout << "j: " << j << endl;
                for (int k = 0; k < skipValue; ++k) {
                    //cout << "k: " << k << endl;
                    baseVector[i] = XorOperand(baseVector[i],baseVector[j+k]);
                }
            }
            //cout << "Pos " << i << ": " << baseVector[i] << endl;
            parityCounter++;
        }else if (isPowerOf2(i+1)) {
            int skipValue = pow(2,parityCounter);
            //cout << "skipValue: " << skipValue << endl;
            for (int j = i; j < totalBitNum; j += (skipValue*2)) {
                //cout << "j: " << j << endl;
                for (int k = 0; k < skipValue; ++k) {
                    //cout << "k: " << k << endl;
                    baseVector[i] = XorOperand(baseVector[i],baseVector[j+k]);
                }
            }
            //cout << "Pos " << i << ": " << baseVector[i] << endl;
            parityCounter++;
        } else{
            //cout << "no" << endl;
            continue;
        }
    }
    return baseVector;
}

bool HammingCode::detectError(vector<int> bitVector) {
    int parityCounter = 0;
    for (int i = 0; i < bitVector.size(); ++i) {
        //cout << "i: " << i << endl;
        if (i == 0 || i == 1){
            int skipValue = pow(2,parityCounter);
            //cout << "skipValue: " << skipValue << endl;
            for (int j = i; j < bitVector.size(); j += (skipValue*2)) {
                //cout << "j: " << j << endl;
                for (int k = 1; k < skipValue; ++k) {
                    //cout << "k: " << k << endl;
                    bitVector[i] = XorOperand(bitVector[i],bitVector[j+k]);
                }
            }
            cout << "Pos " << i << ": " << bitVector[i] << endl;
            if (bitVector[i] == 1){
                return false;
            }
            parityCounter++;
        }else if (isPowerOf2(i+1)) {
            int skipValue = pow(2,parityCounter);
            //cout << "skipValue: " << skipValue << endl;
            for (int j = i; j < bitVector.size(); j += (skipValue*2)) {
                //cout << "j: " << j << endl;
                for (int k = 1; k < skipValue; ++k) {
                    //cout << "k: " << k << endl;
                    //cout << bitVector[i] << "xor" << bitVector[j+k] << endl;
                    bitVector[i] = XorOperand(bitVector[i],bitVector[j+k]);
                    //cout <<"=" << bitVector[i] << endl;
                }
            }
            cout << "Pos " << i << ": " << bitVector[i] << endl;
            if (bitVector[i] == 1){
                return false;
            }
            parityCounter++;
        } else{
            //cout << "no" << endl;
            continue;
        }
    }
    return true;
}

bool HammingCode::isPowerOf2(int num) {
    while(num % 2 == 0){
        num/=2;
    }
    if(num == 1){
        return true;
    } else{
        return false;
    }
}

int HammingCode::XorOperand(int num1, int num2) {
    if (num1 + num2 == 1){
        return 1;
    } else {
        return 0;
    }
}

HammingCode::HammingCode() = default;
