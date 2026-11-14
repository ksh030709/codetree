#include <iostream>
using namespace std;
int arr[105][105];
int dr[4] = {0,1,0,-1};
int dc[4] = {1,0,-1,0};
int visited[105][105];
int n;
int cnt = 0;
int pcnt = 0;
int maxcnt = 0;

void dfs(int a, int b)
{
    for(int k=0; k<4; k++)
    {
        int row = a + dr[k];
        int col = b + dc[k];
        if(row>=0 && col>=0 && row<n && col<n && !visited[row][col] && arr[row][col]==arr[a][b])
        {
            cnt++;
            visited[row][col] = 1;
            dfs(row,col);
        }
    }
}

int main() 
{
    cin >> n;
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            cin >> arr[i][j];
        }
    }
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            if(!visited[i][j])
            {
                cnt++;
                visited[i][j] = 1;
                dfs(i,j);
                if(cnt>=4)
                {
                    pcnt++;
                }
                if(cnt > maxcnt)
                {
                    maxcnt = cnt;
                }
                cnt = 0;
            }
        }
    }
    cout << pcnt << " " << maxcnt;

    return 0;
}