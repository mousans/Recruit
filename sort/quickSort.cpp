#include<iostream>
#include<vector>
#include<stdlib.h>
#include<time.h>

using namespace std;

void swap(vector<int>&nums,int i,int j){
    int tp=nums[i];
    nums[i]=nums[j];
    nums[j]=tp;
}

void quickSort(vector<int>&nums,int l,int r){
    if(l>=r){
        return ;
    }
    int base=nums[l];
    int i=l;
    int j=r;
    while(i<j){
        while(i<j&&nums[j]>=base){
            j--;
        }
        while(i<j&&nums[i]<=base){
            i++;
        }
        if(i<j){
            swap(nums,i,j);
        }
    }
    nums[l]=nums[i];
    nums[i]=base;
    quickSort(nums,l,i-1);
    quickSort(nums,i+1,r);
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
    quickSort(nums,0,num-1);
    for(int i=0;i<num;i++){
        cout<<nums[i]<<" "<<endl;
    }
    getchar();
    return 0;
}