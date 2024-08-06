#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int mod = 1e9+7;
//vector<int> del = {-1,0,1,0,-1};

struct Trie{
    Trie * links[2];
    bool doesContain(int num)
    {
        return links[num]!=NULL;
    }
    int contribute=0;
};
Trie * root;

void insert(int num)
{
    Trie *node =root;
    for(int i=31;i>=0;i--)
    {
        int bit = (num>>i)&1;

        if(!node->doesContain(bit))
        {
            node->links[bit] = new Trie();
        }
        node = node->links[bit];
        node->contribute++;
    }
}

void remove(int num )
{
    Trie * node=root;
    for(int i=31;i>=0;i--)
    {
        int bit = (num>>i)&1;
        node = node->links[bit];
        node->contribute--;
    }
}
int getMini(int num )
{
    Trie * node = root;

    int mini =0;
    for(int i=31;i>=0;i--)
    {
        int bit = (num>>i)&1;
        if(node->doesContain(bit) && node->links[bit]->contribute>0 )
        {
            node = node->links[bit];
        }
        else
        {
            mini = mini | (1<<i);
            node = node->links[bit^1];
        }
    }
    return mini;
}

void code()
{
    int n;
    cin>>n;
    vector<int>a(n);
    vector<int>p(n);
    root =new Trie();
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    for(int i=0;i<n;i++)
    {
        cin>>p[i];
        insert(p[i]);
    }
    for(int i=0;i<n;i++)
    {
        int ans = getMini(a[i]);
        remove(ans^a[i]);
        cout<<ans<<" ";
    }
    cout<<"\n";
    return;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);
    // cout.tie(NULL);
    ll t=1;
    //cin>>t;
    while(t--){
        code();
    }
    return 0;
}