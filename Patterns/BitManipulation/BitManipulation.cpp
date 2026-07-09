#include<iostream>
using namespace std;

/*
Bit Manupulation:
Bit Operation are used to optimize speed efficiency as
these operate at Binary level which is extremely light
in the CPU and it can execute such operations with the
extreme speed. BitWise operators include:

1. &  (Performs AND logic on Bits)
2. |  (Performs OR logic on Bits)
3. ~  (Performs NOT logic on Bits)
4. ^  (Performs XOR logic on Bits)
5. << (Performs Left Shift on Bits)
6. >> (Performs Right Shift on Bits)

Common Uses:
BitWise & is often used with 1 to determine if a number
is odd or not. BitWise >> is used to discard the LSB bit
where as BitWise << is used to shift all bits left by 1
and make a Reset bit as LSB, then | with 1 can be used to
Set that LSB as well. All these operations allow various
uses such as mirroring/reversing bits. Even performing
multiplication and division by powers of 2 at CPU level.
*/

// Bit Functions
class BitManipulation {
public:
    bool isEven(int n)    { return !(n&1);    }
    int mulBy2(int n)     { return n<<=1;     }
    int divBy2(int n)     { return n>>=1;     }
    int bitReverse(int n) {
        int rev=0;
        for(int i=0;i<32;i++) {
            rev<<=1;
            rev|=(n&1);
            n>>=1;
        }
        return rev;
    }
};

// Main Function
int main()
{
    BitManipulation obj;
    int num=66;
    cout<<"Num is : "<<num<<'\n';
    cout<<"Is Even: "<<(obj.isEven(num)?"True":"False")<<'\n';
    cout<<"Mul by2: "<<obj.mulBy2(num)<<'\n';
    cout<<"Div by2: "<<obj.divBy2(num)<<'\n';
    cout<<"Bit Rev: "<<obj.bitReverse(num)<<'\n';
    return 0;
}