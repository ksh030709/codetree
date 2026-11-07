#include <iostream>
#include <utility>
#include <queue>

using namespace std;

int n,k;
int a,b;
int arr[100][100];
int visited[100][100];
int dr[4] = {0,1,0,-1};
int dc[4] = {1,0,-1,0};
int max_r = 101;
int max_c = 101;
int max_v = 0;

void bfs(int row,int col)
{
    queue<pair<int,int>> q;
    q.push({row,col});
    visited[row][col] = 1;
    while(!q.empty())
    {
        pair<int,int> now = q.front();
        q.pop();
        int r = now.first;
        int c = now.second;
        for(int i=0; i<4; i++)
        {
            int nr = r+dr[i];
            int nc = c+dc[i];
            if(nr>=0 && nr<n && nc>=0 && nc<n && !visited[nr][nc] && arr[nr][nc]<arr[row][col])
            {
                visited[nr][nc] = 1;
                q.push({nr,nc});
                if(arr[nr][nc]>max_v)
                {
                    max_v = arr[nr][nc];
                    max_r = nr;
                    max_c = nc;
                }
                else if(arr[nr][nc]==max_v)
                {
                    if(nr<max_r)
                    {   
                        max_v = arr[nr][nc];
                        max_r = nr;
                        max_c = nc;
                    }
                    else if(nr==max_r && nc<max_c)
                    {
                        max_v = arr[nr][nc];
                        max_r = nr;
                        max_c = nc;
                    }
                }
            }
        }

    }
    if(max_r == 101 && max_c == 101)
    {
        return;
    }

    a = max_r+1;
    b = max_c+1;
    return;
}

int main() {
    cin >> n >> k;
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            cin >> arr[i][j];
        }
    }
    cin >> a >> b;
    for(int i=0; i<k; i++)
    {
        for(int q=0; q<100; q++)
        {
            for(int p=0; p<100; p++)
            {
                visited[q][p] = 0;
            }
        }
        max_r = 101;
        max_c = 101;
        max_v = 0;
        bfs(a-1,b-1);
    }
    cout << a << " "<<b << "\n";
    return 0;
}