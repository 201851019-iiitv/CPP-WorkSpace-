
#include<bits/stdc++.h>
using namespace std;
#define  ll  long long  //define a macro variable of long long type
# define  loop(x,n)  for(int x = 0; x < n; ++x)  // define a for loop
#define   constloop(x,a,n) for(int x = a; x < n; ++x)  //define a for loop with start a const
#define  revloop(x,a,n)  for(int x = a; x > n; x--) // rev for loop
//#define   vect vector<ll>  // define a vector of longlong type;





int  main() {

ios_base::sync_with_stdio(false);
   cin.tie(NULL);
int t;
cin>>t;
while(t--)
{
  int n;
  cin>>n;
  int arr[n];
  set<int>s;
  loop(i,n)
  {
      cin>>arr[i];
      s.insert(arr[i]);
  }

 int max1=INT_MIN,index=-1;

    for(int l:s)
    {

       set<int>p;
       int start=0;
       for(int i=0;i<n;i++)
       {
           if(arr[i]==l)
           {
               start=i;
               break;
           }

       }


       for(int j=start;j<n-1;j+=2)
       {
            if(arr[j]==arr[j+1] || p.find(arr[j])!=p.end())
            {
                j--;
            }
             p.insert(arr[j]);


        }

        for(int g:p)
        {

            cout<<g<<" " ;
        }

        cout<<endl;1

cout<<p.size()<<"psize"<<endl;

          if(p.size()>max1)
          {

              max1=p.size();
              index=l;
          }



       }








  cout<<index<<" \n";
}


   return 0;

}
