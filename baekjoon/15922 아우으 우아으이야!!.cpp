#include <iostream>
#include <queue>
#include <vector>

using namespace std;

priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;

int main(){
    int n, ans = 0;
    cin >> n;
    for(int i=0; i<n; i++){
        int s,e;
        cin >> s >> e;
        pq.push({s,e});
    }

    while(!pq.empty()){
        int ts = pq.top().first;
        int te = pq.top().second;
        pq.pop();
        while(!pq.empty() && te >= pq.top().first){
            if(pq.top().second > te){
                te = pq.top().second;
            }
            pq.pop();
        }
        ans += te - ts;
    }
    cout << ans;
}