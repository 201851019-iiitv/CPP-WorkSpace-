
#include<bits/stdc++.h>

using namespace std;

int main()
{
  int t;
  cin>>t;
  while(t--)
  {


      string s;
      cin>>s;
      int count0=0,count1=0;


      for(int i=0;i<s.length();i++)
      {
          if(s[i]==0)
            count0++;
          else
            count1++;
      }

      cout<<count0<<" "<<count1;
if(count0==0 ||count1==0)
{
    cout<<s<<endl;


}
else if(count0==count1)
{
    bool a=true;
    for(int i=0;i<n;i++)
    {
        if(a)
        {

         cout<<"0"<<endl;

        }
        else
        {

         cout<<"1"<<endl;

        }

    }
}
else{
         bool a=true;

       int n=s.length();
       for(int i=0;i<2*n;i++)
       {
          if(a)
        {

         cout<<"0"<<endl;

        }
        else
        {

         cout<<"1"<<endl;

        }
       }




}



  }





    return 0;
}
