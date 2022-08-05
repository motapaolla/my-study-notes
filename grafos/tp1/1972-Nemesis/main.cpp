#include <iostream>
#include <vector>
using namespace std;
 


void printG(vector<vector<int>> x, int m, int n){
    for (int i=0; i<n; i++){  // printando o array
        for (int j=0; j<m; j++){  // printando o array
            cout << x[i][j]; 
        }
        std::cout << '\n'; 
    }  
}


int main() {
 
    int v, e, n, m, c, final[3], s[3];
    cin >> n >> m;

    // n = linhas
    // m = colunas
    vector<vector<int>> dists; 
    vector<vector<int>> colors; 
    vector<vector<int>> g; 


    int line = 0;
    int col = 0; 
    while(line != n && col != m){
        cin >> c;
        col = 0;
        if (c == '.') {
            g[line][col] = 0;
            col = col + 1;
        }
        else if (c == 'H') {
            s[0] = line;
            s[1] = col;
            g[line][col] = 0;
            col = col + 1;
        }
        else if (c == 'E') {
            final[0] = line;
            final[1] = col;
            g[line][col] = 0;
            col = col + 1;
        }
            
        else if (c == '#') {
            g[line][col] = '|';
            colors[line][col] = 'b';
            dists[line][col] = '|';
            col = col + 1;
        }
            
        else {
            g[line][col] = int(c);
            col = col + 1;
        }

        line = line + 1;
    }

    printG(g, m, n);

    
    return 0;
}
