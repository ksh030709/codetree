#include <iostream>
#include <queue>
#include <utility>

using namespace std;
int n,k;
int arr[100][100];
int visited[100][100];
int cnt = 0;
int dr[4] = {0,1,0,-1};
int dc[4] = {1,0,-1,0};

void bfs(int a, int b)
{
    if(visited[a][b]==1) return;
    queue<pair<int,int>> q;
    q.push({a,b});
    visited[a][b] = 1;
    cnt++;
    while(!q.empty())
    {
        pair<int,int> now = q.front();
        int r = now.first;
        int c = now.second;
        q.pop();
        for(int i=0; i<4; i++)
        {
            int nr = r+dr[i];
            int nc = c+dc[i];
            if(nr>=0 && nr<n && nc>=0 && nc<n && arr[nr][nc]==0 && !visited[nr][nc])
            {
                q.push({nr,nc});
                visited[nr][nc] = 1;
                cnt++;
            }
        }
    }
}

int main() {
    cin >> n >> k;
    int col,row;
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            cin >> arr[i][j];
        }
    }
    for(int i=0; i<k; i++)
    {
        cin >> row >> col;
        bfs(row-1,col-1);
    }
    cout << cnt;
    return 0;
}