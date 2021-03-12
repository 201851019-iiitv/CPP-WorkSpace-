#include<bits/stdc++.h>

using namespace std;

bool allCharactersSame(string s) 
{ 
    return (s.find_first_not_of(s[0]) == string::npos); 
} 
bool allcharcterlexo(string s)
{
	for(int i=1;i<s.length();i++)
	{
		if(s[i-1]>s[i])
		return false;
	}
	
	return true;
	
}

int main()
{
int t;
cin>>t;
while(t--)
{
	
int n;
cin>>n;
string s;
cin>>s;
if(n==1)
{
		
cout<<"0"<<endl;
	


}
else if(allCharactersSame(s))
{
	cout<<"0"<<endl;
	
}
else if(allcharcterlexo(s))
{
	cout<<"0"<<endl;
	}	
	
	else
	{
		int ca=0,cb=0,ca1=0,cb1=0;
		for(int i=0;i<n/2;i++)
		{
			if(s[i]=='A')
			ca++;
			else
			cb++;
		}
		for(int j=n/2;j<n;j++)
		{
			if(s[j]=='A')
			ca1++;
			else
			if(s[j]=='A')
			cb1++;
		}
	int ans1=0,ans2=0;		
		if(ca>=cb && ca1>=cb1)
		{
			for(int i=0;i<n;i++)
			{
				if(s[i]=='B')
				ans1++;
			}
		}
		else if(cb>=ca && cb1>=ca1)
		{
				for(int i=0;i<n;i++)
			{
				if(s[i]=='A')
				ans1++;
			}
			
		}
		else
		{
			ans1=cb;
			int i=floor(n/2);
			while(i<n && s[i]=='A')
			{
				i++;
			}
			
			for(int j=i;j<n;j++)
			{
					if(s[i]=='A')
				   ans1++;
			}
			
			ans2=ca1;
			int p=n/2;
			while(p>=0 && s[p]=='B')
			{
				p--;
			}
			
			for(int i=0;i<=p;i++)
			{
				if(s[i]=='B')
				ans2++;
			}
			
		ans1=min(ans1,ans2);	
			
		}
		
		
		
		//ans--;
		cout<<ans1<<endl;
		
		
}
		
	}
	

	
	
	
	
	
	
	return 0;
}
