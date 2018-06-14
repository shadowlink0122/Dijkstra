class Dijkstra{
private:
  struct edge{int to,cost;};
  typedef pair<int,int> P;
  vector<edge> graph[100000];
  int ans[100000];

public:
  int vertces,edges;
  Dijkstra(){
    cin >> vertces >> edges;
    for(int i = 0;i < edges;i++){
      int a,b,c;
      cin >> a >> b >> c;
      a--;b--;
      graph[a].push_back(edge{b,c});
      graph[b].push_back(edge{a,c});
    }
  }

  void goal(int goal){
    printf("%d\n",ans[goal-1]);
  }

  void process(int s = 0){
    priority_queue<P,vector<P>,greater<P> > que;
    fill(ans,ans+vertces,1e+9+7);
    ans[s] = 0;
    que.push(P(0,s));

    while(!que.empty()){
      P p = que.top();que.pop();
      int v = p.second;
      if(ans[v] < p.first)continue;

      rep(i,0,graph[v].sz){
        edge e = graph[v][i];
        if(ans[e.to] > ans[v]+e.cost){
          ans[e.to] = ans[v] + e.cost;
          que.push(P(ans[e.to],e.to));
        }
      }
    }
  }
};

int main(){
  Dijkstra dij;
  dij.process();
  for(int i = 1;i <= dij.vertces;i++)dij.goal(i);
  return 0;
}