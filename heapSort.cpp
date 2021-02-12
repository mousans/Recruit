#include<iostream>
#include<vector>

using namespace std;

void swap(vector<int>&nums,int i,int j){
    int tp = nums[i];
    nums[i]=nums[j];
    nums[j]=tp;
    return ;
}

void heapChange(vector<int>&nums,int i,int n){
    int l=2*i+1;
    int r=2*i+2;
    int maxIndex=i;
    if(l<n&&nums[l]>nums[maxIndex]){
        maxIndex=l;
    }
    if(r<n&&nums[r]>nums[maxIndex]){
        maxIndex=r;
    }
    if(maxIndex!=i){
        swap(nums,i,maxIndex);
        heapChange(nums,maxIndex,n);
    }
    return ;
}


void heapBuild(vector<int>&nums,int n){
    for(int i=n/2+1;i>-1;i--){
        heapChange(nums,i,n);
    }
    return ;
}

void heapSort(vector<int>&nums){
    int n=nums.size();
    heapBuild(nums,n);
    for(int i=n-1;i>-1;i--){
        swap(nums,0,i);
        heapChange(nums,0,i);
    }
    for(int i=0;i<n;i++){
        cout<<nums[i]<<" "<<endl;
    }
    return ;
}


int main()
{
    vector<int>nums{10,234,56,32423,76,8,-12,123,11,-324,1,3,-2314};
    heapSort(nums);
    getchar();
    return 0;
}