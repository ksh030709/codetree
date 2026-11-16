#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

int main() {
    unordered_map<int,int> ma;
    vector<int> v;
    int n,m,b;
    int arr[100001];
    int f[100001];

    int cnt = 0;
    cin >> m >> n;
    for(int i=0; i<m; i++)
    {
        cin >> arr[i];
        ma[arr[i]] ++;
    }
    for(int i=0; i<n; i++)
    {
        cin >> b;
        cout << ma[b] << " ";
    }
    
    return 0;
}