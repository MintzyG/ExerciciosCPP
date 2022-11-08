
// CPP Program to demonstrate passing
// an array to a function is always treated
// as a pointer
#include <iostream>
#include <vector>
using namespace std;
 

void modify(vector<vector<int>>& vec){

   for (int i = 0; i < vec.size(); i++) {
        for (int j = 0; j < vec[i].size(); j++)
            cout << vec[i][j] << "  ";
        cout << endl;
    } 

}





// Driver Code
int main()
{
    int L, C;
    cin>>L; cin>>C; 

    int linha = 0;

    cout<<endl;
    vector<vector<int>> vec;
    for (int i = 0; i < L; i++)
    {    
            vector<int> v1;

            for (int j = 0; j < C; j++)
            {
                v1.push_back(i + j);
            }
            vec.push_back(v1);
    }

    modify(vec);

}