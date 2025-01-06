#include <iostream>
using namespace std;

int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};
bool grid[9][9];
int p[48];

int paths(int depth, int curX, int curY) {
    if(!grid[curX][curY+1] && !grid[curX][curY-1] && grid[curX+1][curY] && grid[curX-1][curY]) return 0;
    if(grid[curX][curY+1] && grid[curX][curY-1] && !grid[curX+1][curY] && !grid[curX-1][curY]) return 0;
        
	if (curY == 7 && curX == 1) { 
		if (depth == 48) return 1;
		return 0;
	}
	if (depth == 48) return 0;

	int ret = 0;
	grid[curX][curY] = true;

    if (p[depth] < 4){
        int nextX = curX + dx[p[depth]];
        int nextY = curY + dy[p[depth]];
        if (!grid[nextX][nextY]){ ret += paths(depth + 1, nextX, nextY); }
    }
    else {
        for (int i = 0; i < 4; i++){
            int nextX = curX + dx[i];
            int nextY = curY + dy[i];
            if (!grid[nextX][nextY]) ret += paths(depth + 1, nextX, nextY);
        }
    }

	grid[curX][curY] = false;
	return ret;
}

int main() {
    string strang;
    cin >> strang;


    for (int i = 0; i < strang.size(); i++){
        char cur = strang[i];
		if (cur == 'U') p[i] = 0;
		else if (cur == 'R') p[i] = 1;
		else if (cur == 'D') p[i] = 2;
		else if (cur == 'L') p[i] = 3;
		else p[i] = 4;
    }

    for (int i = 0; i < 9; i++){
        grid[i][0] = true;
        grid[0][i] = true;
        grid[8][i] = true;
        grid[i][8] = true;
    }
    
	for (int i = 1; i <= 7; i++) {
		for (int j = 1; j <= 7; j++) { grid[i][j] = false; }
	}

    int sol = paths(0, 1, 1);
    cout << sol << endl;
    return 0;
}