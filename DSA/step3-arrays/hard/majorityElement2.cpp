class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int count1 = 0;
        int ele1 = -1;
        int count2 = 0;
        int ele2 = -1;

        for (int i = 0; i < nums.size(); i++) {
            if (count1 == 0 && ele2 != nums[i]) {
                count1++;
                ele1 = nums[i];
            } else if (count2 == 0 && ele1 != nums[i]){
                count2++;
                ele2 = nums[i];
            } else if (ele1 == nums[i]) count1++;
            else if (ele2 == nums[i]) count2++;
            else {
                count1--;
                count2--;
            }
        }
        vector<int> ans;
        int lene = nums.size() / 3;
        int count11 = 0;
        int count22 = 0;
        for (int i : nums) {
            if (i == ele1) count11++;
            else if (i == ele2) count22++;
        }
        if (count11> lene) ans.push_back(ele1);
        if (count22> lene) ans.push_back(ele2);
        return ans;
    }
};
