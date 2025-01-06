#include <iostream>
#include <vector>
#include <set>

using namespace std;

int main(){

	int t, m, n, inp;
	cin >> t;
	while(t--){
		cin >> n >> m;

		vector< vector<int> > matrix(m);		
		for(int i = 0; i < n; ++i){
			for(int j = 0; j < m; ++j){
				int inp;
				cin >> inp;
				if(inp)
					matrix[j].push_back(i);
			}
		}

		bool isgood = true;
		for(int j = 0; j < m; ++j){
			if(matrix[j].size() != 2){
				isgood = false;
				break;
			}
		}

		if(isgood){
			set< pair<int, int> > verticesPair;
			
			for(int j = 0; j < m; ++j)
				verticesPair.insert(make_pair(matrix[j][0], matrix[j][1]));
			
			if(verticesPair.size() == m){
				cout << "Yes" << endl;
                continue;
			}
		}

        cout << "No" << endl;
	}

	return 0;
}