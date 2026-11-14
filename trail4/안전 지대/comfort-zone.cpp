#include <iostream>
#include <utility>
using namespace std;
int k,n,m;
int cnt = 0;
int maxk = 0;
int ak = 1;
int arr[51][51];
int visited[51][51];
int dr[4] = {0,1,0,-1};
int dc[4] = {1,0,-1,0};


void bfs(int a, int b)
{
    for(int p=0; p<4; p++)
    {
        int row = a + dr[p];
        int col = b + dc[p];
        if(!visited[row][col]&& row>=1 && col>=1 && row<=n && col<=m && arr[row][col]>k)
        {
            visited[row][col] = 1;
            bfs(row, col);
        }
    }
}

int main() {
    cin >> n >> m;
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=m; j++)
        {
            cin >> arr[i][j];
        }
    }
    for(k=1; k<=100; k++)
    {
        for(int i=1; i<=n; i++)
        {
            for(int j=1; j<=m; j++)
            {
                if(!visited[i][j]&& arr[i][j]>k)
                {
                    cnt++;
                    bfs(i,j);
                }
            }
        }
        for(int i=1; i<=n; i++)
        {
            for(int j=1; j<=m; j++)
            {
                visited[i][j] = 0;
            }
        }
        if(cnt > maxk)
        {
            ak = k;
            maxk = cnt;
        }
        cnt = 0;
    }
    cout << ak << " " << maxk;
    return 0;
}