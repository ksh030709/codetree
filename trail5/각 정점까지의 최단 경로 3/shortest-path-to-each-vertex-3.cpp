#include <iostream>
#include <queue>
#include <vector>
#include <utility>

using namespace std;

const int inf = 1e9;
int n,m;
int a,b,c; // 시작, 끝, 가중치
vector<pair<int, int>> graph[20005];
vector<int> dist;

void dik(int start)
{
    priority_queue<pair<int,int>,vector<pair<int,int>>, greater<pair<int,int>>> pq;
    dist[start] = 0;
    pq.push({0,start}); // 가중치,노드값
    while(!pq.empty())
    {
        int curdist = pq.top().first;
        int curnode = pq.top().second;
        pq.pop();
        if (dist[curnode] < curdist) continue;
        for(auto edge : graph[curnode])
        {
            int nxtdist = edge.first;
            int nxtnode = edge.second;
            if(dist[curnode]+nxtdist < dist[nxtnode])
            {
                dist[nxtnode] = dist[curnode]+nxtdist;
                pq.push({dist[nxtnode], nxtnode}); // 여기를 pq.push({nxtdist, nxtnode}); 라고함
            }
        }
    }
}

int main() {
    cin >>n>>m;
    for(int i=0; i<m; i++)
    {
        cin >> a >> b >> c;
        graph[a].push_back({c,b});
    }
    dist.assign(n + 1, inf);
    dik(1);
    for(int i=2; i<=n; i++)
    {
        if (dist[i] == inf) cout << "-1" << "\n";
        else cout << dist[i] << "\n";
    }
    return 0;
}