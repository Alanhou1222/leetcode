class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int front = 0;
        int back = arr.size()-1;
        int middle = front + (back-front)/2;
        int closest = 0;
        bool find = false;
        while(front <= back){
            if(arr[middle] == x){
                find = true;
                break;
            }
            else if(arr[middle] < x){
                front = middle + 1;
            }
            else{
                back = middle - 1;
            }
            if(abs(x-arr[middle]) < abs(x-arr[closest])||(abs(x-arr[middle]) == abs(x-arr[closest]) && arr[middle] < arr[closest])){
                closest = middle;
            }
            middle = front + (back-front)/2;
        }
        if(!find){
            middle = closest;
        }
        int count = 0;
        int n = arr.size();
        front = middle;
        back = middle + 1;
        while(count < k){
            if(back == n || (front >= 0 && x - arr[front] <= arr[back] - x)){
                front--;
            }
            else{
                back ++;
            }
            count ++;
        }
        front++;
        back--;
        vector<int> ans;
        for(int i = front; i <= back; i++){
            ans.push_back(arr[i]);
        }
        return ans;
    }
};