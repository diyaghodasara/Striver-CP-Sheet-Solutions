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
    int contribute =0;
};
Trie *root;
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

void del(int num)
{
    Trie *node=root;
    for(int i=31;i>=0;i--)
    {
        int bit = (num>>i)&1;
        node =node->links[bit];
        node->contribute--;
    }
}

int getMax(int num)
{
    Trie * node = root;

    int maxi =0;
    for(int i=31;i>=0;i--)
    {
        int bit = (num>>i)&1;
        if(node->doesContain(bit^1) && node->links[bit^1]->contribute>0)
        {
            maxi = maxi | (1<<i);
            node = node->links[bit^1];
        }
        else
        {
            node = node->links[bit];
        }
    }
    return maxi;
}

void code()
{
    int q ;
    cin>>q;
    vector<pair<char,int>>input;
    for(int i=0;i<q;i++)
    {
        char op;
        int num;
        cin>>op>>num;
        input.push_back({op,num});
    }

    root = new Trie();
    insert(0);

    for(int i=0;i<q;i++)
    {
        char op = input[i].first;
        int num = input[i].second;
        if(op=='+')
        {

            insert(num);


        }
        else if(op=='-')
        {

            del(num);
        }
        else if(op=='?')
        {
            int ans = getMax(num);
            cout<<ans<<"\n";
        }
    }
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