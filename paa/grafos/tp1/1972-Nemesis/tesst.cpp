#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int c=1;
    // vector<vector<int>> dists(2, vector<int>(2)); 
    
    vector<vector<int> > matrix(2);
    for ( int i = 0 ; i < 2 ; i++ )
       matrix[i].resize(2);
    
    cin >> c;
    matrix[0][0] = c;
    
    int numElements = 2;
    for (int i = numElements - 1; i >= 0; i--) 
        cout << matrix[0][i];
    // cout << dists[0][1];

    return 0;
}