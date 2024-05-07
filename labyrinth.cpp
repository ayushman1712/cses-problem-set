#include <bits/stdc++.h>
using namespace std;

#define rep(i, k, n) for(int i = k; i <= n; i++)

void bfs (vector<vector<char>> &arr, int i, int j, vector<vector<bool>> &visited, int count) {
    visited[i][j] = 1;
    if (i-1 >= 0 && visited[i-1][j] == 0 && arr[i-1][j] == '.') {bfs(arr,i-1,j,visited,count);}
    if (j-1 >= 0 && visited[i][j-1] == 0 && arr[i][j-1] == '.') {bfs(arr,i,j-1,visited,count);}
    if (i+1 < arr.size() && visited[i+1][j] == 0 && arr[i+1][j] == '.') {bfs(arr,i+1,j,visited,count);}
    if (j+1 < arr[0].size() && visited[i][j+1] == 0 && arr[i][j+1] == '.') {bfs(arr,i,j+1,visited,count);}
}

int countingRooms(vector<vector<char>> &arr) {
    int n = arr.size(), m = arr[0].size(), count = 0;
    vector<vector<bool>> visited(n, vector<bool> (m));
    rep (i, 0, n-1) {
        rep (j, 0, m-1) {
            if (visited[i][j] == 0 && arr[i][j] == '.') {
                count++;
                bfs(arr,i,j, visited, count);}
        }
    }
    return count;
}

int main () {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n, m; char temp;
    cin >> n >> m;
    vector<vector<char>> building(n,vector<char>(m));
    rep (i, 0, n-1) {
        rep(j, 0, m-1) {
            cin >> temp;
            building[i][j] = temp;
        }
    }
    cout << countingRooms(building);
    return 0;
}
