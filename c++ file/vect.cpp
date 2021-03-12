// working of erase() function 
#include <iostream> 
#include <vector> 
using namespace std; 
  
int main() 
{ 
    vector<int> myvector; 
    for(int i=1;i<=4;i++)
    myvector.push_back(i);
  cout<<myvector.size()<<endl; 
  
   for (int a:myvector) 
        cout << ' ' << a; 
    myvector.erase(myvector.begin()+2); 
  cout<<myvector.size()<<endl;
   for (int a:myvector) 
        cout << ' ' << a; 
  
   
    return 0; 
} 
