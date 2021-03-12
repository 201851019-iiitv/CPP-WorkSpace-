// Created by  Ambesh kumar
#include "bits/stdc++.h"

#define  ll  long long  
# define  loop(x,n)  for(int x = 0; x < n; ++x)  
#define   constloop(x,a,n) for(int x = a; x < n; ++x)  
#define  revloop(x,a,n)  for(int x = a; x > n; x--) 

using namespace std;

void merge(int arr[],int low,int mid,int high)
{

vector<int>left;
vector<int>right;

int n1=mid-low+1;
int n2=high-mid;
for(int i=low;i<n1;i++)
left.push_back(arr[i]);

for(int j=mid+1;j<n2;j++)
right.push_back(arr[j]); 

int k=low;
int j=0;
int s=0;
while(k<=high &&j<left.size() &&s<right.size())
{

if(left[j]<=right[s])
{

arr[k]=left[j];
k++;
j++;

}
else 
{

arr[k]=right[s];
k++;
s++;

}

}

while(j<left.size())
{

arr[k]=left[j];
k++;
j++;

} 

while(s<right.size())
{

arr[k]=right[s];
k++;
s++;

} 




}


void printArray(int A[], int size) 
{ 
    int i; 
    for (i=0; i < size; i++) 
        printf("%d ", A[i]); 
    printf("\n"); 
} 





void mergeSort(int arr[],int low,int high)
{

cout<<low<<" "<<high<<endl;
constloop(i,low,high+1)
cout<<arr[i]<<" ";
cout<<endl;


if(low>=high)
	return;

int mid=(low+high)/2;

mergeSort(arr,low,mid);
mergeSort(arr,mid+1,high);

merge(arr,low,mid,high);


}


int main()
{

#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif


    ios::sync_with_stdio(0);
    cin.tie(0);
        int n;
        cin>>n;
       int arr[n];
        loop(i,n)
        cin>>arr[i];

mergeSort(arr,0,n-1);

printf("\nSorted array is \n"); 
    printArray(arr,n); 
        
    return 0;
}