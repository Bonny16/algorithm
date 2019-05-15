#include<bits/stdc++.h>
using namespace std;
void load_array(int arr[],int n){
    int tem;
    for(int i=0;i<n;i++){
        cin>>tem;
        arr[i]=tem;
    }
}
int Max, Min;
int count1=0;
int arr[1000];
void maxmin(int Start, int End)
{
 int max1, min1, mid;
 if(Start==End)
 {
  Max= Min = arr[Start];
 }
  else
  {
   mid = (Start+End)/2;
   maxmin(Start, mid);
   max1 = Max;
    min1 = Min;
   maxmin(mid+1, End);
   if(Max<max1)
    Max = max1;
   if(Min > min1)
    Min = min1;
    count1=count1+2;
  }
 }
int main ()
{
   int n;
    cout<<"enter how many elements in array :";
    cin>>n;
    freopen("input.txt","r",stdin);
    load_array(arr,n);
   for(int i=0;i<n;i++)
  cout<<arr[i]<<" ";
 cout<<endl;
 Max = arr[0];
 Min= arr[0];
 maxmin(1, n);
 printf ("Minimum element in an array : %d\n", Min);
 printf ("Maximum element in an array : %d\n", Max);
 cout<<"Number of comparison: "<<count1<<endl;
 return 0;
}



