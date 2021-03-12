

    #include<bits/stdc++.h>
     
    using namespace std;
     
     
     
    long countLessThanOrEqual(const std::vector<int>& vec1,
                            const std::vector<int>& vec2) {
                            long count=0;
        std::map<int, unsigned int> countOfVec2;
        for (const auto& item : vec2) {
            ++countOfVec2[item];
        }
     
        unsigned int prev = 0;
        for (auto& pair : countOfVec2) {
            pair.second += prev;
            prev = pair.second;
        }
    	vector<int>res;
        // Traverse arr1[] and print result
        for (const auto& item : vec1) {
            unsigned int result = (--countOfVec2.upper_bound(item))->second;
                          res.push_back(result);
    				                                                             //        std::cout << result << " ";
        }
     
        sort(res.begin(),res.end());
        int index=0;
        while(res[index]==0)
        {
     
        	index++;
     
    	}
    	int l=0;
      while(l<vec1.size())
      {
    int k=1;
        for(int i=index;i<res.size();i++)
        {
          //cout<<res[i]<<" ";
         
     
    	res[i]=res[i]-k;
       l++;
       k++;
    	}
      count++;
    //  cout<<count<<endl;
     
    }
       return count;
     
    }
     
     
    int main()
    {
    	int n,m;
    	cin>>n>>m;
    	vector<int> arr;
    	for(int i=0;i<n;i++)
    	{
    	 int p;
    	 cin>>p;
    	 arr.push_back(p);
    	}
     
     
    	vector<int> b;
    	for(int i=0;i<m;i++)
    	{
    		int q;
    		cin>>q;
    		b.push_back(q);
    	}
     
    long count;
    sort(arr.begin(),arr.end());   //sort the passegeners
    sort(b.begin(),b.end());   //sort the flight  capacity
     
    	if(arr[n-1]>b[m-1])
      {
       // cout<<arr[n-1]<<" "<<b[m-1];
    	cout<<"-1"<<endl;
      }
    	else
    	{
     
    	count= countLessThanOrEqual(b,arr);
     
     
     
     
     
         long ans  =(2*count)-1;
     
    	cout<<ans<<endl;
     
    }
     
     
     
     
     
    	return 0;
    }

Language: C++14

