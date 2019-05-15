#include<bits/stdc++.h>
using namespace std;
void load_array(int arr[],int n){
    int tem;
     for(int i=0;i<n;i++){
        cin>>tem;
        arr[i]=tem;
    }
}
void bubble_sort(int arr[],int n)
{
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(arr[i]>arr[j])
                swap(arr[i],arr[j]);
           }
      }
}
int main()
{
    int n,m;
    int arr[200005];
    cout<<"                     Bubble sort : "<<endl;
    cout<<"enter how many elements in array :";cin>>n;
    freopen("input.txt","r",stdin);
     load_array(arr,n);
     time_t S=clock();
    bubble_sort(arr,n-1);
    time_t E=clock();
   cout<<" required time for bubble sorting : "<<double(E-S)/2500000000<<endl;
   cout<<"\n\nSORTED ARAY IN ASSENDING ORDER :"<<endl;
   for(int i=0;i<n;i++)
      cout<<arr[i]<<" ";
    return 0;
}
