class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<pair<int,int>> adj[n+1];
        for(auto edge : times){
            adj[edge[0]].push_back({edge[1],edge[2]});
        }
        multiset<pair<int,int>> s;
        vector<int> dist(n+1,1e7);
        dist[k]=0;
        s.insert({0,k});
        pair<int,int> ele;
        int i;
        while(!s.empty()){
            ele = *s.begin();
            s.erase(s.begin());
            i = ele.second;
            for(auto x : adj[i]){
                if(dist[x.first]>dist[i]+x.second){
                    dist[x.first]=dist[i]+x.second;
                    s.insert({dist[x.first],x.first});
                }
            }
        }
        int ans = -1;
        for(int i=1;i<=n;i++){
            ans = max(ans,dist[i]);
            
        }
        if(ans==1e7){
            return -1;
        }
        return ans;
        
    }
};