#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ret;

        unordered_map<int, int> hashMap;
        for(unsigned int i = 0; i < nums.size(); i++)
        {
            int complement = target - nums[i];
            auto it = hashMap.find(complement);
            if (it != hashMap.end())
            {
                ret.push_back(it->second);
                ret.push_back(i);
            }
            else
            {
                hashMap.insert(pair<int, int>(nums[i], i));
            }            
        }

        return ret;
    }
};

int main()
{
	return 0;
}