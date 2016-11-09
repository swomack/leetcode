#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map> // this is actually a hash_map with O(1) insert & find

using namespace std;

class Solution
{
public:
        vector<int> twoSum(vector<int>& nums, int target)
        {
			vector<int> ans;
			int index = 0;


			// concise but slow - 26ms
			// memory O(n)
			/*unordered_map<int, int> my_hash;
			for_each(nums.begin(), nums.end(), [&index, &target, &my_hash, &ans](int& n)
			{
				int complementary = target - n;

				if (my_hash.find(complementary) != my_hash.end())
				{
					ans.push_back(my_hash[complementary]);
					ans.push_back(index);
				}

				my_hash[n] = index;

				index++;
			}
			);*/



			// fast - 6ms
			// so vector access is faster than unorderd_map access
			// memory O(max_value - min_value)
			std::vector<int>::iterator result;
			result = min_element(nums.begin(), nums.end());
			int min_value = *result;

			result = max_element(nums.begin(), nums.end());
			int max_value = *result;

			int offset = -1 * min_value;
			int total_elem = max_value - min_value + 1;


			vector<int> hash_vec(total_elem);
			fill(hash_vec.begin(), hash_vec.end(), -1);

			for_each(nums.begin(), nums.end(), [&offset, &total_elem, &index, &target, &hash_vec, &ans](int& n)
			{
				int j = target - n;

				int hash_index = j + offset;

				if (hash_index >= 0 && hash_index < total_elem  &&  hash_vec[j + offset] != -1)
				{
					ans.push_back(hash_vec[j + offset]);
					ans.push_back(index);
				}

				hash_vec[n + offset] = index;

				index++;
			});



			// using find_if so that we can break the loop when we got the answer (surprisingly slower)
			/*find_if(nums.begin(), nums.end(), [&offset, &total_elem, &index, &target, &hash_vec, &ans](int& n)
			{
				int j = target - n;

				int hash_index = j + offset;

				if (hash_index >= 0 && hash_index < total_elem  &&  hash_vec[j + offset] != -1)
				{
					ans.push_back(hash_vec[j + offset]);
					ans.push_back(index);
					return true;
				}

				hash_vec[n + offset] = index;

				index++;
				return false;
			});*/

		
			return ans;

        }
};


int main()
{
        Solution s;
        vector<int> a;
        a.push_back(5);
        a.push_back(75);
        a.push_back(25);
       // a.push_back(15);

        vector<int> result = s.twoSum(a, 100);

		for_each(result.begin(), result.end(), [](int& n)
		{
			cout << n << endl;
		});

		return 0;
}
