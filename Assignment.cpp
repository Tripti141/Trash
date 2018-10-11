#include <bits/stdc++.h>

using namespace std;

#define mx 500
map<string,int>mm;
map<int,string>mm2;
bool visited[mx];

vector<pair<int,int> >adj[mx];
int parent[mx];
int cost[mx];

bool bfs(int x,int y)
{
    memset(visited,0,sizeof(visited));
    memset(parent,-1,sizeof(parent));
    for(int i=0;i<mx;i++)
        cost[i]=9999999;
    priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > >q;
    q.push({0,x});
    visited[x]=true;
    cost[x]=0;
    bool ss=false;
    while(!q.empty())
    {
        int u=q.top().second;//only for accessing the node
        q.pop();//we are deleting both
        for(int i=0;i<adj[u].size();i++)
        {
            int v=adj[u][i].first;
            int c=adj[u][i].second;
            if(v==y)
                ss=true;
           // cout<<u<<" "<<v<<" "<<mm2[u]<<" "<<mm2[v]<<" "<<c<<endl;
            if(cost[v]>cost[u]+c)
            {

                cost[v]=cost[u]+c;
                parent[v]=u;
                q.push({cost[v],v});
                visited[v]=true;
            }
        }
        visited[u]=true;
    }
    if(ss)
        return true;
    return false;
}

int main(int argc, char **argv)
{

    //cmd

        if(argc < 4)
    {
        cout << "Not enough argument given" << endl;
        return -1;
    }
  // 4 ta arguments arg[0] = exe file ta
    string filepath = argv[1];
    string sourceCity = argv[2];
    string destinationCity = argv[3];
    freopen(filepath.c_str(),"r",stdin); //c_str = convert korlam string theke constnt




    map<string,int>mm;
    map<int,string>mm2;
    int j=1;
    for(int i=0;;i++)
    {
        string a,b;
        int c,u,v;
        cin>>a;
        if(a=="END")
            break;
        cin>>b>>c;
        if(mm[a]>0)
        {
            u=mm[a];
        }
        else
        {
            mm[a]=j;
            mm2[j]=a;
            u=j;
            j++;
        }
        if(mm[b]>0)
        {
            v=mm[b];
        }
        else
        {
            mm[b]=j;
            mm2[j]=b;
            v=j;
            j++;
        }


        adj[u].push_back(make_pair(v,c));
        adj[v].push_back(make_pair(u,c));
    }
    string tmp;
    cin>>tmp>>tmp;
    string a,b;
    int u,v;
    a=sourceCity;
    b=destinationCity;
    u=mm[a];
    v=mm[b];
    if(bfs(u,v)){
        cout<<"distance: "<<cost[v]<<" km"<<endl<<"route:"<<endl;
        stack<int> st;
        st.push(v);
        while(parent[v]!=u)
        {
            if(v==u)
                break;

            v=parent[v];
            st.push(v);
            //stack e shob parent gula thakbe
        }
        st.push(u);
        int p=st.top();
        st.pop();
        while(!st.empty())
        {
            cout<<mm2[p]<<" to "<<mm2[st.top()]<<", "<<cost[st.top()]-cost[p]<<" km"<<endl;
            p=st.top();
            st.pop();
        }


    }
    else{
        cout<<"distance: infinity"<<endl<<"route:"<<endl<<"none"<<endl;

    }



    return 0;
}
