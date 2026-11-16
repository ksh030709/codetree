#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;


int main() {
    unordered_map<int,int> m;
    int n;
    string s;
    int k,v;
    cin >> n;
    for(int i=0; i<n; i++)
    {
        cin >> s;
        if(s == "add")
        {
            cin >> k >> v;
            m[k] = v;
        }
        else if(s == "remove")
        {
            cin >> k ;
            m.erase(k);
        }
        else if(s == "find")
        {
            cin >> k ;
            if(m.find(k) != m.end())
            {
                cout << m[k]<<"\n";
            }
            else
            cout << "None" << "\n";
        }

    }
    return 0;
}