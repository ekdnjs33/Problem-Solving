#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>
using namespace std;

int n, m, space, result = 0;
int map[8][8];
int cmap[8][8];
bool flag[64];
bool visited[8][8];
vector<pair<int, int>> virus, zero;

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

//바이러스 퍼트린 것을 맵에 반영
void bfs(int x, int y){
    queue<pair<int, int>> q;
    q.push(make_pair(x, y));
    
    visited[x][y] = true;
    
    while(!q.empty()){
        x = q.front().first;
        y = q.front().second;
        q.pop();
        
        for(int i=0; i<4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            
            if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            
            if(!visited[nx][ny] && cmap[nx][ny] == 0){ //퍼트린 바이러스 cmap에 반영
                cmap[nx][ny] = 2;
                visited[nx][ny] = true;
                q.push(make_pair(nx, ny));
            }
        }
    }
}
//벽을 세우고 바이러스를 퍼트린 후, 안전한 공간 세는 함수
void spread_virus(){
    int cnt = 0;
    
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cmap[i][j] = map[i][j];
        }
    }
    //visit을 전부 초기화
    memset(visited, false, sizeof(visited));
    
    for(int i=0; i<space; i++){ //세운 벽을 cmap에 반영
        if(cnt == 3) break;
        if(flag[i] == true){
            int x = zero[i].first;
            int y = zero[i].second;
            cmap[x][y] = 1;
            cnt++;
        }
    }
    
    for(int i=0; i<virus.size(); i++){ //바이러스 퍼트려
        bfs(virus[i].first, virus[i].second);
    }
    
    //바이러스를 다 퍼트리고 나서 안전한 공간 개수 세기
    int safe = 0;
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            if(cmap[i][j] == 0)
                safe++;
        }
    }
    
    result = max(result, safe);
}
//벽을 세울 공간 정하기
void make_wall(int index, int cnt){
    if(cnt == 3){
        spread_virus();
        return;
    }
    for(int i=index; i<space; i++){
        if(flag[i] == true) continue;
        flag[i] = true;
        make_wall(i, cnt + 1);
        flag[i] = false;
    }
}

int main(){
    cin >> n >> m;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >> map[i][j];
            if(map[i][j] == 0)
                zero.push_back(make_pair(i, j));
            if(map[i][j] == 2)
                virus.push_back(make_pair(i, j));
        }
    }
    space = zero.size();
    
    make_wall(0, 0);
    cout << result << endl;

    return 0;
}
