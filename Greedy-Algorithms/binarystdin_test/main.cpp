#include<iostream>
#include "../BinaryStdIn.h"
using namespace std;

int main()
{
    string filename = "data";

    BinaryStdIn binaryStdIn(filename);

    cout << binaryStdIn.readInt() << endl;

    binaryStdIn.close();

    return 0;
}
