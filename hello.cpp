#include <iostream>
using namespace std;

int main() {
    int** p, *q;
    q = new int(1);
    *p = q;
    cout << *p << " " << p << " " << q << endl;
    return 0;
}