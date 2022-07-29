#include <bits/stdc++.h>
using namespace std;

void find_max_min(int arr[], int l, int r, int &mx,int &mn){
    if(l==r){
        mn = min(mn, arr[l]);
        mx = max(mx, arr[l]);
    }else if(r-l==1){
        if(arr[l]<arr[r]){
            mn = min(mn, arr[l]);
            mx = max(mx,arr[r]);
        }else{
            mn = min(mn,arr[r]);
            mx = max(mx,arr[l]);
        }
    }
    else{
        int mid = (l+r)/2;
        find_max_min(arr,l,mid,mx,mn);
        find_max_min(arr,mid+1,r,mx,mn);
    }
}

int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
      cin>>arr[i];

    int mx = INT_MIN;
    int mn = INT_MAX;

    find_max_min(arr,0,n-1,mx,mn);

    cout<<"max is "<<mx<<" min is "<<mn<<endl;

    return 0;
}
