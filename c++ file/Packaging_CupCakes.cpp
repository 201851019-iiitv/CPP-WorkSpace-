// Created by  Ambesh kumar
#include "bits/stdc++.h"

#define  ll  long long  
# define  loop(x,n)  for(int x = 0; x < n; ++x)  
#define   constloop(x,a,n) for(int x = a; x < n; ++x)  
#define  revloop(x,a,n)  for(int x = a; x > n; x--) 

using namespace std;

int main()
{

#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif


    ios::sync_with_stdio(0);
    cin.tie(0);

    
    int t;
    cin>>t;
    while(t--){
  
string s;

cin>>s;


int n=s.length();
    stack <char> op;
    stack<char>opend;
    stack<char>br;
    for(int i=0;i<n;i++)
    {
         
   if(s[i]=='+'||s[i]=='-'||s[i]=='*'||s[i]=='/'||s[i]=='^')
        op.push(s[i]);
    else if(s[i]=='(' ||s[i]==')')
    {
        br.push(s[i]);
    }
   else
    opend.push(s[i]);


    }

for(int i=0;i<n;i++)
{
   if(s[i]=='(')
   {
     cout<<opend.top();
     opend.pop();
   }





}





  

    }
    return 0;
}