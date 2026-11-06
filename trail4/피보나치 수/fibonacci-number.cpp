#include <iostream>
using namespace std;

int main() {
    int fibo[45] = {1,1,};
    int a;
    cin >> a;
    for(int i=2; i<a; i++)
    {
        fibo[i] = fibo[i-1] + fibo[i-2];
    }
    cout << fibo[a-1];
    return 0;
}