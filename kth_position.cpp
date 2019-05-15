#include<bits/stdc++.h>
using namespace std;
int arr[100000];

int position(int left, int right){
    int number = arr[left];
    int i = right+1;
    int j;
    int temp;
    for(j=right; j>left; j--)
    {
        if(arr[j]>=number)
        {
            i--;
            temp = arr[j];
            arr[j] = arr[i];
            arr[i] = temp;
        }
    }
    temp = arr[j];
    arr[j] = arr[i-1];
    arr[i-1] = temp;
    return i-1;
}

int Partition(int arr[], int left, int right, int pivotIndex){
    int pivotValue = arr[pivotIndex];
    swap(arr[pivotIndex], arr[right]);
    int storeIndex = left;
    for(int i = left; i<=right-1; i++) {
        if(arr[i]<=pivotValue)
        {
            swap(arr[i], arr[storeIndex]);
            storeIndex+=1;
        }
    }
    swap(arr[storeIndex], arr[right]);
    return storeIndex;
}

void Sort(int arr[], int left, int right){
    int q, i;
    if(right>left)
    {
        i =  (rand() % (right+1-left)) + left;
        swap(arr[right], arr[i]);
        int pivotIndex = i;
        int pivotNewIndex = Partition(arr, left, right, pivotIndex);
        Sort(arr, left, pivotNewIndex - 1);
        Sort(arr, pivotNewIndex + 1, right);
    }
}

int main(){
    int number_of_element;
    int actual_position;
     cout << "Enter the number of elements: ";
    cin >> number_of_element;
    srand(time(NULL));
    for(int i=0; i<number_of_element; i++)
        arr[i] = rand()%100+1;
    for(int i=0; i<number_of_element; i++)
        cout << arr[i] << "  ";
    cout << endl;
    actual_position = position(0,number_of_element-1);
    cout << "Actual position of first element: " << actual_position << endl;
    cout<<"After placing the first element in kth smallest position"<<endl;
    for(int i=0; i<number_of_element; i++)
        cout << arr[i] << "  ";
    cout<<endl;
    Sort(arr, 0, number_of_element-1);
     cout<<"Finally After sorting:"<<endl;
     for(int i=0; i<number_of_element; i++)
        cout << arr[i] << "  ";
    cout << endl;
    return 0;
}


