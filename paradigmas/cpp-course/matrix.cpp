#include <iostream>
#include <vector>
using namespace std;


void printMat(vector<vector<int>> x, int lines, int columns){
    cout << "Printing: " << endl;
    for (int l=0; l!=lines; l++){
        for (int c=0; c!=columns; c++){
            cout << x[l][c]; 
        }  
        cout << '\n';
    }  
}

int main() {
 
    // vector<vector<int>> x; 
    int inpt, size, l, c, lines, columns;
    
    cin >> lines >> columns;

    vector<vector<int>> x(lines, vector<int>(columns));

    for(int l = 0; l != lines ; l++){
        for(int c = 0; c != columns ; c++){
            cin >> inpt;
            x[l][c] = inpt;
        }
    }

    printMat(x, lines, columns);

    return 0;
}
