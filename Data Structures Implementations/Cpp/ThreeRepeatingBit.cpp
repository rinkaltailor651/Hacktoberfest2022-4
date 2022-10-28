#include<bits/stdc++.h>
using namespace std;


int solution(vector<int>& arr){
    int one=0,two=0,three=INT_MAX;
    for(int i=0;i<arr.size();i++){
        int mask1=(one & arr[i]);
        int mask2=(two & arr[i]);
        int mask3=(three & arr[i]);

        int none= (one & (~mask1));
        none=(none|mask3);
        
        int ntwo= (two & (~mask2));
        ntwo=(ntwo|mask1);

        int nthree= (three & (~mask3));
        nthree=(nthree|mask2);

        one=none;
        two=ntwo;
        three=nthree;

    }
    return one;
}


int main(){
    int n;
    cin>>n;
    
    vector<int>arr(n);
    
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    
    cout<<solution(arr);
}
