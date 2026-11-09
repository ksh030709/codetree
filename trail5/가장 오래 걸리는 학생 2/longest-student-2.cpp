#include <iostream>
#include <vector>
#include<queue>
#include<utility>

using namespace std;
int n,m,a,b,d;
vector<pair<int,int>> arr[100001];
const int inf = 1e9;

int dist[100001];

void dijkstra(int start)
{
    priority_queue<pair<int,int>,vector<pair<int,int>>, greater<pair<int,int>>> pq;
    dist[start] = 0;
    pq.push({0,start});
    while(!pq.empty())
    {
        int nowdist = pq.top().first;
        int now = pq.top().second;
        pq.pop();
        if(dist[now] < nowdist) continue;
        for(auto edge : arr[now])
        {
            int nextnode = edge.second;
            int nextdist = edge.first;
            if(dist[nextnode] > dist[now]+nextdist)
            {
                dist[nextnode] = dist[now]+nextdist;
                pq.push({dist[nextnode], nextnode});
            }
        }
    }

}

int main() {
    cin >> n >> m;
    for(int i=0; i<m; i++)
    {
        cin >> a >> b >> d;
        arr[b].push_back({d,a});
    }
    for(int i=1; i<=n; i++)
    {
        dist[i] = inf;
    }
    dijkstra(n);
    int max = -1;
    for(int i=1; i<n; i++)
    {
        if(dist[i]>max) max = dist[i];
    }
    cout << max << "\n";
    return 0;
}

// 문제1 dist를 벡터로 구현해서 inf를 못넣었다
// 문제2 pop을 안넣었다
// 문제3 arr을 받을때 역방향으로 했는데, edge에서는 생각을못했다