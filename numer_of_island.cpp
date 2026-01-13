//Leetcode Link: https://leetcode.com/problems/number-of-islands/description/

class Solution {
private:
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
    bool in(int r,int c,int m,int n){
        return (r>=0 && r<m && c>=0 && c<n);
    }
public:
    int numIslands(vector<vector<char>>& grid) {

        int m=grid.size();
        int n=grid[0].size();

        parent.resize(m*n);
        iota(parent.begin(),parent.end(),0);
        rank.assign(m*n,1);

        int dr[4]={0,0,-1,1};
        int dc[4]={1,-1,0,0};
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]=='0') continue;
                int u=i*n+j;
                for(int k=0;k<4;k++){
                    int ni=i+dr[k];
                    int nj=j+dc[k];
                    if(!in(ni,nj,m,n) || grid[ni][nj]=='0') continue;
                    int v=ni*n+nj;
                    merge(u,v);
                }
            }
        }

        int c=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]=='1' && find(i*n+j)==(i*n+j)) c++;
            }
        }

        return c;
    }
};
