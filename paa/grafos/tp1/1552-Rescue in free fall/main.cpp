#include <iostream>
 
using namespace std;
 
int main() {
 
    // for (std::string line; std::getline(std::cin, line);) {
    //     cin >> a >> b;
    //     inpt.push_back(a);
    //     inpt.push_back(b);
    // }
    
    int arr[] = {1,2,3,4,5};
    int arrSize = sizeof(arr)/sizeof(arr[0]);

    cout << "oi" << endl;
    cout << arrSize << endl;
    for (int i = 0; i < arrSize; i++){
        cout << arr[i] << endl;
    }

    return 0;
}