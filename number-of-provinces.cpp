//Leetcode link: https://leetcode.com/problems/number-of-provinces/description/

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
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size();
        parent.resize(n);
        iota(parent.begin(),parent.end(),0);
        rank.assign(n,1);

        int seg=n;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(isConnected[i][j]){
                    if(find(i)!=find(j)){
                        seg--;
                        merge(i,j);
                    }
                }
            }
        }
        return seg;
    }
};
