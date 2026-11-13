#include <iostream>
#include <vector>
using namespace std;
vector<int> arr;
int n;
int answer = 0;

void back(int cnt)
{
    if(cnt==n)
    {

        answer++;
        return;
    }
    for(int i=1; i<=4; i++)
    {
        if(cnt+i>n)
        continue;
        for(int j=1; j<=i; j++)
        {
            arr.push_back(i);
        }
        back(cnt+i);
        for(int j = 1; j <= i; j++)
        {
            arr.pop_back();
        }
    }
}

int main() {
    cin >> n;
    back(0);
    cout << answer;
    return 0;
}