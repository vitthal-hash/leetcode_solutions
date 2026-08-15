class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        int low = 0;
        int high = nums.size() - 1;
        mergeSort(nums, low, high);

        return nums;
    }

    void mergeSort(vector<int> &nums, int low, int high){
        if(low >= high)
            return;

        int mid = low + (high - low) / 2;

        mergeSort(nums, low, mid);
        mergeSort(nums, mid + 1, high);
        merge(nums, low, mid, high);
        
    }

    void merge(vector<int> &nums, int low,int mid, int high){
        vector <int> temp;
        int i = low;
        int j = mid + 1;

        while(i <= mid && j <= high){
            if(nums[i] <= nums[j]){
                temp.push_back(nums[i]);
                i++;
            }else{
                temp.push_back(nums[j]);
                j++;
            }
        }

        while(i <= mid){
            temp.push_back(nums[i]);
            i++;
        }

        while(j <= high){
            temp.push_back(nums[j]);
            j++;
        }

        for(int k = 0; k< temp.size(); k++){
            nums[low + k] = temp[k];
        }
        
    }
};