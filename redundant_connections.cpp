//Leetcode link: https://leetcode.com/problems/redundant-connection/description/

class Solution {
public:
    vector<int> parent;
    vector<int> rank;
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
            rank[a]+=rank[b];
            parent[b]=a;
        }
        else{
            //b parent
            rank[b]+=rank[a];
            parent[a]=b;
        }
    }

    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n=edges.size();
        parent.resize(n+1);
        iota(parent.begin(),parent.end(),0);
        rank.assign(n+1,1);

        int ind=-1;
        for(int i=0;i<n;i++){
            int u=edges[i][0];
            int v=edges[i][1];
            int x=find(u);
            int y=find(v);
            if(x==y){
                ind=i;
                continue;
            }
            merge(u,v);
        }
        return edges[ind];
    }
};
