#include <iostream>
#include <vector>
using namespace std;


void printVec(vector<int> x, int size){
    for (int i=0; i!=size; i++){
        cout << x[i]; 
    }  
}

int main() {
 
    vector<int> x; 
    int c, size;
    
    cin >> size;

    for(int i = 0; i != size ; i++){
        cin >> c;
        x.push_back(c);
    }

    printVec(x, size);

    return 0;
}
