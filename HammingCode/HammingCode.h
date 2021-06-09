#ifndef HAMMINGCODE_HAMMINGCODE_H
#define HAMMINGCODE_HAMMINGCODE_H
#include <vector>
#include <iostream>

using namespace std;

class HammingCode {
private:
    bool isPowerOf2(int num);
    int XorOperand(int num1, int num2);
public:
    HammingCode();
    vector<int> getHammingCode(vector<int> bitVector);
    bool detectError(vector<int> bitVector);
};


#endif //HAMMINGCODE_HAMMINGCODE_H
