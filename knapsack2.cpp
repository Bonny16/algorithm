//using dynamic programming approach
#include<bits/stdc++.h>
using namespace std;
int max(int a, int b) {
      return (a > b)? a : b;
  }
int knapSack(int capacity, int weight[], int profit[], int object){
   int i, w;
   int K[object+1][capacity+1];
   for (i = 0; i <= object; i++)
   {
       for (w = 0; w <= capacity; w++)
       {
           if (i==0 || w==0)
               K[i][w] = 0;
           else if (weight[i-1] <= w)
                 K[i][w] = max(profit[i-1] + K[i-1][w-weight[i-1]],  K[i-1][w]);
           else
                 K[i][w] = K[i-1][w];
       }
   }
   return K[object][capacity];
}
int main(){
     cout << "Enter the number of items in a Knapsack:";
    int object, capacity;
    cin >> object;
    int profit[object], weight[object];
    for (int i = 0; i < object; i++)
    {
        cout << "Enter weight & profit for item " << i+1 << ":";
        cin >> weight[i];
        cin >> profit[i];
    }
    cout << "Enter the capacity of knapsack: ";
    cin >> capacity;
    cout<<"The maximum profit is:";
    printf("%d", knapSack(capacity, weight, profit, object));
    return 0;
} 

