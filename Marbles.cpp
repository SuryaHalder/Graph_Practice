
/*
	Author : SURYA HALDER

    
    "I'm so lost in this problem, I might need a GPS to find my way out."
	"My love I know you are reading my code to get a path out of your errors, just like your presence in my life is a path out my errors,
	so please talk instead of ignoring me"
	"I may die today but for sure will be reborn tommorow like the phoenix"...
*/

#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> pbds;
//<data_type,mapping,order of ele,rb_tree,..>
//functions-> *A.find_by_order(X) [Xth index what?], A.order_of_key(X) [#ele<X]
//declaration-> pbds A;

#define ll long long
//#define int long long int
#define ff first
#define ss second
#define inf INT_MAX
#define sz size()
#define rtn return
#define rnt return
#define vi vector<int>
#define vvi vector<vector<int>>
#define vll vector<long long>
#define vvll vector<vector<long long>>
#define pb push_back
#define endl '\n'
#define maxheap priority_queue<int> //max heap
#define minheap priority_queue <int, vector<int>, greater<int>> //min heap
#define loop(i,a,b) for(int i=a;i<b;i++)     //for loop from a(included)->b(excluded)
#define roop(i,b,a) for(int i=b;i>=a;i--)    //rev. for loop from b(included)->a(inluded)
#define yes cout<<"YES"<<endl
#define no cout<<"NO"<<endl
#define pii pair<int,int>
#define pll pair<ll,ll>

//==============Modular arithematic==============//
const int mod=1000000000+7; 
ll mod_pow(ll a,ll b){
    if(b==0) return 1;
    if(b%2){
        return a* mod_pow(a,b-1) %mod;
    }
    ll temp= mod_pow(a,b/2);
    return temp*temp %mod;
}
ll mod_mul(ll a,ll b){
    return ((a%mod) * (b%mod))%mod;
}
ll mod_add(ll a,ll b){
    return ((a%mod) + (b%mod))%mod;
}
ll mod_sub(ll a,ll b){
    return ((a-b)%mod+mod)%mod;
}
ll mod_inv(ll a,ll b=mod-2){
    return mod_pow(a,b);
}
ll mod_div(ll a,ll b){
    int invb=mod_inv(b);
    return mod_mul(a,invb);
}
//==============End of Modular Arithematic==============//

//==============i/p and o/p==============//
template<typename T>
void inp(vector<T>& v) {
    for (auto& x : v) {
        cin >> x;
    }
}
template<typename T>
void out(const vector<T>& v) {
    for (const auto& x : v) {
        cout << x << " ";
    }
    cout << '\n';
}
//==============end of i/p and o/p==============//

//==============sorting==============//
template<typename T>
void sortA(vector<T>& v) {
    sort(v.begin(), v.end());
}

template<typename T>
void sortD(vector<T>& v) {
    sort(v.begin(), v.end(), greater<T>());
}
//==============End of sorting==============//


//==============Counting Inversions==============//

//inversion for a[i]>a[i+1]

int cnt_merge(vector<int>&a,int l,int m,int r){
    int n1=m-l+1, n2=r-m;
    vector<int>left(n1), right(n2);
    for(int i=0;i<n1;i++){
        left[i]=a[l+i];
    }
    for(int j=0;j<n2;j++){
        right[j]=a[m+1+j];
    }
    int ans=0;
    int i=0,j=0,k=l;
    while(i<n1 && j<n2){
        if(left[i]<=right[j]) a[k++]=left[i++];
        else{
            a[k++]=right[j++];
            ans+=(n1-i);
        }
    }
    while(i<n1){
        a[k++]=left[i++];
    }
    while(j<n2){
        a[k++]=right[j++];
    }
    rtn ans;
}
int cnt_inv(vector<int>&a,int l,int r){
    int ans=0;
    if(l<r){
        int m=l+(r-l)/2;
        ans+=cnt_inv(a,l,m);
        ans+=cnt_inv(a,m+1,r);
        ans+=cnt_merge(a,l,m,r);
    }
    rtn ans;
}
//==============End of Counting Inversions==============//

int dr[]={-1,0,1,0}; //up,left,down,right
int dc[]={0,-1,0,1};
bool in(int i,int j,int n,int m){
    rtn (i>=0 && i<n && j>=0 && j<m);
}

ll ncr(ll n,ll r){
    if(r<0 || r>n) rtn 0;
    if(r==0 || r==n) rtn 1;
    if(r>(n-r)) r=n-r;
    ll ans=1;
    for(int i=1;i<=r;i++) ans=ans*(n-i+1ll)/i;
    return ans;
}

void solve() {
    /*Your code here */
    ll n,k;
    cin>>n>>k;
    cout<<ncr((n-k)+k-1,k-1)<<endl;
    
}

int32_t main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    //==============Multi testcase==============//
    int t=1;
    cin >> t;
    while (t--){
        solve();
    }
    //==============comment till here==============//
    
    //==============ATCODER ALERT..don't forget to uncomment below==============//
    
    //solve();
    return 0;
}
