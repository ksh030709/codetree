#include <iostream>
#include <queue>
#include <utility>
#include <cstring> // gpt
#include <algorithm> // gpt


using namespace std;
int n,k,u,d;
int dr[4] = {0,1,0,-1};
int dc[4] = {1,0,-1,0};
int visited[10][10];
int arr[10][10];
int selected[10][10];
int cnt = 0;
int max_cnt=0;

void bfs(int a, int b)
{
    queue<pair<int,int>> q;
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            if(selected[i][j]==1 && !visited[i][j])
            {
                q.push({i,j});
                visited[i][j] = 1;
                cnt++;
            }
        }
    }
    while(!q.empty())
    {
        int row = q.front().first;
        int col = q.front().second;
        q.pop();
        for(int x=0; x<4; x++)
        {
            int nr = row + dr[x];
            int nc = col + dc[x];
            if(nr>=0 && nc>=0 && nr<n && nc<n &&!visited[nr][nc])
            {
                if(arr[row][col]-arr[nr][nc]>=0)
                {
                    if(arr[row][col]-arr[nr][nc]>=u && arr[row][col]-arr[nr][nc]<=d)
                    {
                        cnt++;
                        visited[nr][nc] = 1;
                        q.push({nr,nc});
                    }
                }
                else if(arr[row][col]-arr[nr][nc]<0)
                {
                    if(arr[row][col]-arr[nr][nc]<=-u && arr[row][col]-arr[nr][nc]>=-d)
                    {
                        cnt++;
                        visited[nr][nc] = 1;
                        q.push({nr,nc});
                    }
                }
            }
        }
    }
}
//gpt
void sel(int idx, int depth)
{
    // K개의 도시를 모두 선택한 경우
    if(depth == k)
    {
        memset(visited, 0, sizeof(visited));
        cnt = 0;

        // 선택된 도시들을 시작점으로 BFS 실행
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(selected[i][j] && !visited[i][j])
                {
                    bfs(i, j);
                }
            }
        }

        max_cnt = max(max_cnt, cnt);
        return;
    }

    // 도시 선택
    for(int i = idx; i < n * n; i++)
    {
        int row = i / n;
        int col = i % n;

        selected[row][col] = 1;

        sel(i + 1, depth + 1);

        // 선택 취소
        selected[row][col] = 0;
    }
}
//gpt
int main() 
{
    cin >> n >> k >> u >> d;
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            cin >> arr[i][j];
        }
    }
    //gpt
    sel(0, 0);
    cout << max_cnt;
    //gpt
    return 0;
}