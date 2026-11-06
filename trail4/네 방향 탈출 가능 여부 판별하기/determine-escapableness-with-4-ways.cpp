#include <iostream>
#include <utility>
#include <queue>
using namespace std;

int arr[101][101];
int visited[101][101];
int n,m;
int answer = 0;

void dfs(int a, int b)
{
    queue<pair<int,int>> q;
    q.push({a,b});
    visited[a][b] = 1;
    while(!q.empty())
    {
        pair<int,int> now = q.front();
        q.pop();
        int dr[4] = {0,1,0,-1};
        int dc[4] = {1,0,-1,0};
        int row = now.first;
        int col = now.second;
        for(int i=0; i<4; i++)
        {
            int new_row = row+dr[i];
            int new_col = col+dc[i];
            if(new_row>=0 && new_row<n && new_col>=0 && new_col<m && arr[new_row][new_col]==1 && !visited[new_row][new_col])
            {
                if(new_row==n-1 && new_col==m-1) answer = 1;
                visited[new_row][new_col] = 1;
                q.push({new_row,new_col});
            }
        }
    }
}

int main() {
    cin >> n >> m;
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            cin >> arr[i][j];
        }
    }
    dfs(0,0);
    cout << answer;
    return 0;
}