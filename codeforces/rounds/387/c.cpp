#include <bits/stdc++.h>
#define MAX_S 1e6

using namespace std;
using ii = pair<int, int>;
using iii = pair<int, ii>;

int main(){
    int n, q;
    scanf("%d %d", &n, &q);

    priority_queue<int, vector<int>, greater<int> > pq;
    priority_queue<ii, vector<ii>, greater<ii> > out;
    vector<iii> tasks;
    
    for(int i=1;i<=n;i++) pq.push(i);

    for(int i=0;i<q;i++){
        int t, k, d;
        scanf("%d %d %d", &t, &k, &d);
        tasks.push_back(iii(t, ii(k,d)));
    }

    for(auto task : tasks){
      int tm = task.first;
      int k = task.second.first;
      int d = task.second.second;

      while(!out.empty() and out.top().first < tm){
        int cur = out.top().second; out.pop();
        pq.push(cur);
      }

      if(pq.size() < k){
        printf("-1\n");
        continue;
      }

      int counter = 0;
      for(int i=0;i<k;i++){
        int cur = pq.top(); pq.pop();
        out.push(ii(tm + d - 1, cur));
        counter += cur;
      }

      printf("%d\n", counter);
    }

    return 0;
}
