#include <iostream>
using namespace std;
int n;

void back2(int a)
{
    if(a==n)
    {
        cout << a << " ";
        return;
    }
    else
    {
        cout << a << " ";
        back2(a+1);
    }

}

void back1(int a)
{
    if(a==1)
    {
        cout << a << " ";
        back2(a);
    }
    else
    {cout << a << " ";
    back1(a-1);
    }
}


int main() {
    cin >> n;
    back1(n);
    return 0;
}