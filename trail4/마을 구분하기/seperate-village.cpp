#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int n;
int arr[25][25];
int visited[25][25];
int cnt = 0;
int ans[625];
int p=0;

void dfs(int a, int b)
{
    int dx[4] = {1,0,-1,0};
    int dy[4] = {0,1,0,-1};
    for(int k=0; k<4; k++)
    {
        int x = a + dx[k];
        int y = b + dy[k];
        if(x>=0 && x<n && y>=0 && y<n && arr[y][x]==1 && !visited[y][x])
        {
            visited[y][x] = 1;
            cnt++;
            dfs(x,y);
        }
    }
    return;
}

int main() {
    cin >> n;
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            cin >> arr[j][i];
        }
    }
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            if(arr[j][i]==1 && !visited[j][i])
            {
            cnt++;
            visited[j][i] = 1;
            dfs(i,j);
            ans[p] = cnt;
            p++;
            cnt = 0;
            }
        }
    }

    sort(ans, ans+p);
    cout << p << "\n";
    for(int i=0; i<p; i++)
    {
        cout << ans[i] << "\n";
    }
    return 0;
}