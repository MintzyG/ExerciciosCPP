#include <vector>
#include <iostream>
using namespace std;

int main(){
    vector<int> vect1{
        {1, 2, 3}
    };

    for (int x : vect1){
        cout<< x << " ";
    }

    vector<vector<int>> vect2{
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    cout<<endl<<endl;

    //for(tipo<contem> nome : De onde)
    for (vector<int> vect : vect2){
        for (int x : vect){
            cout<< x << " ";
        }
        cout<<endl;
    }
}