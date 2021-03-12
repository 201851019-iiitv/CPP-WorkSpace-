#include <bits/stdc++.h>
using namespace std;

#define MAX_N 150005
#define MAX_M 100005
#define LG_MAX_N 20

int N, M, time_counter, block_size, distinct;
int wt[MAX_N], entry_time[MAX_N], exit_time[MAX_N], depth[MAX_N], freq[MAX_N];
bool inrange[MAX_N];
int time_log[MAX_N<<1];
int anc[MAX_N][LG_MAX_N];  // ancestor table; anc[u][i] is the 2^i th ancestor of u
vector<int> g[MAX_N];

struct query{
    int id, l, r, lca;
}q[MAX_M];
int ans[MAX_M];

void dfs(int u, int par){
    time_counter++;
    entry_time[u] = time_counter;
    time_log[time_counter] = u;

    for(int i=1; i<LG_MAX_N; i++)
        anc[u][i] = anc[anc[u][i-1]][i-1];

    for(int i=0; i<g[u].size(); i++){
        int v = g[u][i];
        if(v==par) continue;
        depth[v] = depth[u] + 1;
        anc[v][0] = u;
        dfs(v, u);
    }

    time_counter++;
    exit_time[u] = time_counter;
    time_log[time_counter] = u;
}

int lca(int u, int v){
    if(depth[u]>depth[v])
        swap(u, v);

    for(int i=LG_MAX_N-1; i>=0; i--)
        if(depth[v]-depth[u]>=(1<<i))
            v = anc[v][i];
    if(u==v) return u;

    for(int i=LG_MAX_N-1; i>=0; i--){
        if(anc[u][i]!=anc[v][i]){
            u = anc[u][i];
            v = anc[v][i];
        }
    }
    return anc[u][0];
}

bool qcomp(query &q1, query &q2){
    int b1 = q1.l/block_size;
    int b2 = q2.l/block_size;
    return b1==b2 ? q1.r<q2.r : b1<b2;
}

void add_rem(int i){
    int u = time_log[i];
    if(inrange[u]){
        freq[wt[u]]--;
        if(freq[wt[u]]==0)
            distinct--;
    }
    else{
        if(freq[wt[u]]==0)
            distinct++;
        freq[wt[u]]++;
    }
    inrange[u] ^= 1;
}

void mo(){

    block_size = (int)(sqrt(N<<1)+0.5);
    sort(q, q+M, qcomp);

    int curr_l = 0, curr_r = -1;
    distinct = 0;
    for(int i=0; i<M; i++){

        while(curr_l<q[i].l){
            add_rem(curr_l);
            curr_l++;
        }
        while(curr_l>q[i].l){
            curr_l--;
            add_rem(curr_l);
        }

        while(curr_r<q[i].r){
            curr_r++;
            add_rem(curr_r);
        }
        while(curr_r>q[i].r){
            add_rem(curr_r);
            curr_r--;
        }

        if(time_log[q[i].l]!=q[i].lca)
            add_rem(entry_time[q[i].lca]);
        ans[q[i].id] = distinct;
        if(time_log[q[i].l]!=q[i].lca)
            add_rem(entry_time[q[i].lca]);
    }
}


int main(){

    scanf("%d%d", &N, &M);
    for(int i=1; i<=N; i++)
        scanf("%d", &wt[i]);
    
    map<int, int> cc;
    int ccval = 1;
    for(int i=1; i<=N; i++){
        if(cc.count(wt[i])==0)
            cc[wt[i]] = ccval++;
        wt[i] = cc[wt[i]];
    }

    for(int i=1; i<=N-1; i++){
        int u, v;
        scanf("%d%d", &u, &v);
        g[u].push_back(v);
        g[v].push_back(u);
    }

    anc[1][0] = 1;
    time_counter = 0;
    dfs(1, -1);

    for(int i=0; i<M; i++){
        int l, r;
        scanf("%d%d", &l, &r);
        if(entry_time[l]>entry_time[r])
            swap(l, r);
        q[i].id = i;
        q[i].lca = lca(l, r);
        if(q[i].lca==l){
            q[i].l = entry_time[l];
            q[i].r = entry_time[r];
        }
        else{
            q[i].l = exit_time[l];
            q[i].r = entry_time[r];
        }
    }

    mo();

    for(int i=0; i<M; i++)
        printf("%d\n", ans[i]);

    return 0;
}
