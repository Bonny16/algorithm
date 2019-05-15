#include<bits/stdc++.h>
using namespace std;
void load_array(int arr[],int n){
    int tem;
    for(int i=0;i<n;i++){
        cin>>tem;
        arr[i]=tem;
    }
}
void merging(int arr[],int start,int mid,int eend){
    int p=start;
    int left_ele_no=mid-start+1;
    int right_ele_no=eend-mid;
    int left[left_ele_no],right[right_ele_no];
    for(int i=0;i<left_ele_no;i++)
        left[i]=arr[start+i];
    for(int i=0;i<right_ele_no;i++)
        right[i]=arr[mid+1+i];
    int i=0,j=0;
    while(i<left_ele_no && j <right_ele_no){
        if(left[i]<=right[j]){
            arr[p++]=left[i];
            i++;
        }else{
            arr[p++]=right[j];
            j++;
        }
    }
    while(i<left_ele_no){
        arr[p++]=left[i];
            i++;
    }
    while(j<right_ele_no){
        arr[p++]=right[j];
            j++;
    }
}
void merge_sort(int arr[],int start,int eend){
    int mid;
    if(start<eend){
        mid=(start+eend)/2;
        merge_sort(arr,start,mid);
        merge_sort(arr,mid+1,eend);
        merging(arr,start,mid,eend);
    }
}
int main(){
    int n,m;
    int arr[200005];
    cout<<"                     merge sort : "<<endl;
    cout<<"enter how many elements in array :";
     cin>>n;
      freopen("input.txt","r",stdin);
    load_array(arr,n);
    time_t S=clock();
    merge_sort(arr,0,n-1);
   time_t E=clock();
    cout<<" required time : "<<double(E-S)/ 2500000000<<endl;
    cout<<"\n\nSORTED ARAY IN ASSENDING ORDER :"<<endl;
  for(int i=0;i<n;i++)
     cout<<arr[i]<<" ";
    return 0;
}
