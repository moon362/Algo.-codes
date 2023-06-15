#include<bits/stdc++.h>
using namespace std;
int knapsack(int capacity,int weights[],int val[],int n)
{
    if(n==0||capacity==0)
    {
        return 0;
    }
    if (weights[n - 1] > capacity)
        return knapsack(capacity, weights, val, n - 1);
    else
    {
        return  max(val[n - 1]+ knapsack((capacity - weights[n - 1]),weights, val, n - 1),knapsack(capacity, weights, val, n - 1));
    }
}
int main()
{
    int weights[]= {2,3,4,5};
    int values[]= {3,4,5,6};
    int n=4, capacity=5;
    cout<<"Maximum value: "<<knapsack(capacity,weights,values,n);
}


