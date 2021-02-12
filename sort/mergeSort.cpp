#include<iostream>
#include<vector>
#include<time.h>
#include<stdlib.h>

using namespace std;

void mergeSort(vector<int>&nums,int l,int r){
    if(l>=r){
        return ;
    }
    int mid = (l+r)/2;
    mergeSort(nums,l,mid);
    mergeSort(nums,mid+1,r);
    int i=l;
    int j=mid+1;
    int index=0;
    vector<int>tp(r-l+1);
    while(i<mid+1&&j<r+1){
        if(nums[i]<nums[j]){
            tp[index++]=nums[i++];
        }else{
            tp[index++]=nums[j++];
        }
    }
    while(i<mid+1){
         tp[index++]=nums[i++];
    }
    while(j<r+1){
        tp[index++]=nums[j++];
    }
    for(int i=l;i<r+1;i++){
        nums[i]=tp[i-l];
    }
    return ;
}

int main()
{
    srand((unsigned)time(NULL));
    int num = rand()%20+10;
    vector<int>nums(num);
    for(int i=0;i<num;i++){
        nums[i]=rand();
    }
    mergeSort(nums,0,num-1);
    for(int i=0;i<num;i++){
        cout<<nums[i]<<" "<<endl;
    }
    getchar();
    return 0;
}