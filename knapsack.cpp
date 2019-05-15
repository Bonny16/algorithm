//using greedy method
#include<bits/stdc++.h>
using namespace std;
int n ;
struct objects{
    int weight;
    int profit;
};
bool compare(objects l, objects r){
    return l.profit > r.profit;
}
int main(){
    clock_t s = clock();
    srand(time(0));
    cout << "Total objects : ";
    cin >> n;
    int check[8];
    objects ob[n];
    int totalWeight = 0;
    int totalProfit = 0;
    for(int i=0; i<n; i++){
        cin>>ob[i].weight;
         cin>>ob[i].profit ;
        totalWeight+=ob[i].weight;
    }
    cout << "-------input objects-------" << endl << "weight \t profit" << endl;
    for(int i=0; i<n; i++)
        cout << ob[i].weight << " \t " << ob[i].profit << endl;
 totalWeight = totalWeight * 0.7;
    sort(ob, ob+n, compare);
   cout <<"-------Sorted according to profits---------" << endl;
    for(int i=0; i<n; i++)
         cout << ob[i].weight << " \t " << ob[i].profit << endl;
   cout << endl << "Weight of knapsack = " << totalWeight << endl << endl;
    cout <<"-------Taken objects ---------" << endl << endl;
    for(int i=0; i<n; i++){
        if(ob[i].weight <= totalWeight){
            check[i] = 1;
            totalWeight -= ob[i].weight;
            totalProfit += ob[i].profit;
            cout << i+1 <<" ( " << ob[i].weight << " ) "<< endl;
        }
    }
    cout << endl << "Profit = " << totalProfit << endl;
     clock_t e = clock();
    double diff = (double) (e-s)/2500000000;
    cout << "Execution time : " << diff << endl;
    return 0;
}

