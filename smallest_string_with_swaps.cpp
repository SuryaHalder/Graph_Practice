//Leetcode link: https://leetcode.com/problems/smallest-string-with-swaps/description/

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


    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        int n=s.size();
        parent.resize(n);
        iota(parent.begin(),parent.end(),0);
        rank.assign(n,1);
        
        for(auto &it:pairs){
            int u=it[0];
            int v=it[1];
            if(find(u)!=find(v)) merge(u,v);
        }
        unordered_map<int,vector<char>> mp;
        for(int i=0;i<n;i++){
            int x=find(i);
            mp[x].push_back(s[i]);
        }
        for(auto &it:mp) sort(it.second.rbegin(),it.second.rend());
        string ans;
        for(int i=0;i<n;i++){
            int x=find(i);
            ans.push_back(mp[x].back());
            mp[x].pop_back();
        }
        return ans;
    }
};
