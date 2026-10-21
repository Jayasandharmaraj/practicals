import pipeline;
#include <iostream>
#include <vector>
using namespace std;
int main(){
    vector<int> data={-5,10,20,-3,15,30};
    vector<int> result=processData(data);
    cout<<"Original Data: ";for(int value:data) cout<<value<<" ";
    cout<<"\nProcessed Data: ";for(int value:result) cout<<value<<" ";
    cout<<endl;return 0;
}
