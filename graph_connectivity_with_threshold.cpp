//Leetcode link: https://leetcode.com/problems/graph-connectivity-with-threshold/description/

class Solution {
public:
    vector<int> parent;
    vector<int>rank;
    int find(int node){
        if(parent[node]==node) return node;
        return parent[node]=find(parent[node]);
    }
    void merge(int a,int b){
        a=find(a);
        b=find(b);
        if(a==b) return;
        if(rank[a]>rank[b]){
            //a parent
            parent[b]=a;
            rank[a]+=rank[b];
        }
        else{
            //b parent
            parent[a]=b;
            rank[b]+=rank[a];
        }
    }
    vector<bool> areConnected(int n, int threshold, vector<vector<int>>& queries) {
        parent.resize(n+1);
        iota(parent.begin(),parent.end(),0);
        rank.assign(n+1,1);

        for(int i=threshold+1;i<=n;i++){
            if((i<<1)>n) break;
            int j=2;
            while((i*j)<=n){
                merge(i,i*j);
                j++;
            }
        }

        vector<bool> ans;
        for(auto &it:queries){
            int u=it[0];
            int v=it[1];
            ans.push_back(find(u)==find(v));
        }
        return ans;
    }
};
