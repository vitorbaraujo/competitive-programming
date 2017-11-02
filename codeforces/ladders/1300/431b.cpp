#include <bits/stdc++.h>

using namespace std;

int main(){
    vector<int> v { 1,2,3,4,5 };
    int max_sum = -1;

    int grid[7][7];

    for(int i=1;i<=5;i++)
        for(int j=1;j<=5;j++)
            scanf("%d", &grid[i][j]);

    int sum = 0;

    sum += grid[v[0]][v[1]];
    sum += grid[v[1]][v[0]];
    sum += grid[v[2]][v[3]];
    sum += grid[v[3]][v[2]];
    sum += grid[v[1]][v[2]];
    sum += grid[v[2]][v[1]];
    sum += grid[v[3]][v[4]];
    sum += grid[v[4]][v[3]];
    sum += grid[v[2]][v[3]];
    sum += grid[v[3]][v[2]];
    sum += grid[v[3]][v[4]];
    sum += grid[v[4]][v[3]];

    max_sum = max(max_sum, sum);

    while(next_permutation(v.begin(), v.end())){
        int sum = 0;

        sum += grid[v[0]][v[1]];
        sum += grid[v[1]][v[0]];
        sum += grid[v[2]][v[3]];
        sum += grid[v[3]][v[2]];
        sum += grid[v[1]][v[2]];
        sum += grid[v[2]][v[1]];
        sum += grid[v[3]][v[4]];
        sum += grid[v[4]][v[3]];
        sum += grid[v[2]][v[3]];
        sum += grid[v[3]][v[2]];
        sum += grid[v[3]][v[4]];
        sum += grid[v[4]][v[3]];

        max_sum = max(max_sum, sum);
    }

    cout << max_sum << endl;

    return 0;
}
