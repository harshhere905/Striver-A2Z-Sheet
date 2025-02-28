class Solution {
public:
   vector<int>next_smaller(vector<int>nums,int n){
        stack<int>s;
        s.push(-1);
        vector<int>ans(n);
        for(int i=n-1;i>=0;i--){
            int curr=nums[i];
            while(s.top()!=-1&&nums[s.top()]>=curr){
                s.pop();
            }
        ans[i]=s.top();
        s.push(i);
        }
        return ans;
    }
    vector<int>prev_smaller(vector<int>nums,int n){
        stack<int>s;
        s.push(-1);
        vector<int>ans(n);
        for(int i=0;i<n;i++){
            int curr=nums[i];
            while(s.top()!=-1&&nums[s.top()]>=curr){
                s.pop();
            }
        ans[i]=s.top();
        s.push(i);
        }
        return ans;
    }
    int largestRectangleArea(vector<int>& heights) {
        int n=heights.size();
        vector<int>next(n);
        next=next_smaller(heights,n);
        vector<int>prev(n);
        prev=prev_smaller(heights,n);
        int area=INT_MIN;
        for(int i=0;i<n;i++){
            int l=heights[i];
            if(next[i]==-1){
                next[i]=n;
            }
            int b=next[i]-prev[i]-1;
            int new_area=l*b;
            area=max(area,new_area);
        }
         return area;
    }
};