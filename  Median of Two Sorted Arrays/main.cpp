#include<vector>
#include<iostream>
using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int pos11=0;
        int pos12=nums1.size();
        int pos21=0;
        int pos22=nums2.size();
        while(pos12+pos22-pos11-pos21>2){
          if(pos21==pos22||(pos11<pos12&&nums1[pos11]<nums2[pos21]))
            pos11++;
          else
            pos21++;
          if(pos21==pos22||(pos11<pos12&&nums1[pos12-1]>nums2[pos22-1]))
            pos12--;
          else
            pos22--;
        }
        if(pos12+pos22-pos11-pos21==1){
          if(pos11<pos12){
            return nums1[pos11];
          }
          else
            return nums2[pos21];
        }
        else{
          if(pos11==pos12-1){
            return (double)(nums1[pos11]+nums2[pos21])/2;
          }
          else if(pos11==pos12-2){
            return (double)(nums1[pos11]+nums1[pos11+1])/2;
          }
          else{
            return (double)(nums2[pos21]+nums2[pos21+1])/2;
          }
        }
    }
};

int main(){
    auto s=new Solution();
    vector<int> nums1,nums2;
    nums1.push_back(2);
    nums1.push_back(3);
    nums1.push_back(4);
    nums1.push_back(5);
    auto ans=s->findMedianSortedArrays(nums1,nums2);
    cout<<ans;
}
