// leetcode.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//
#include<vector>
#include<map>
#include<unordered_map>
#include <iostream>

using namespace std;
//leetcode题目代码，均提交测试通过，同一题目，方法，从上往下，逐步优化

////leetcode 1. 两数之和 暴力法，时间复杂度On2,空间复杂度O1
//class Solution {
//public:
//    vector<int> twoSum(vector<int>& nums, int target) {
//        int i = 0;
//        int j = 0;
//        for (i = 0; i < nums.size(); ++i)
//        {
//            for (j = i + 1; j < nums.size(); ++j)
//            {
//                if (nums[i] + nums[j] == target)
//                {
//                    return { i,j };
//                }
//            }
//        }
//        return { i,j };
//    }
//};

////leetcode 1. 两数之和 哈希表 时间On(2n)空间On
//class Solution {
//public:
//    vector<int> twoSum(vector<int>& nums, int target) {
//        map<int, int> map_;
//        for (int i = 0; i < nums.size(); ++i)
//        {
//            map_[nums[i]] = i; //key存放值，value存数组下标
//        }
//        for (int i = 0; i < nums.size(); ++i)
//        {
//            auto it = map_.find(target - nums[i]);
//            if ((it != map_.end()) && (it->second != i))//注意这里，避免同一个下标相加
//            {
//                return { it->second, i };
//            }
//        }
//        return {};//无用，leetcode提交需要
//    }
//};

////leetcode 1. 两数之和 哈希表 时间On空间On,一个循环(如果数据量非常大，O2n和On还是有差异的)
//class Solution {
//public:
//    vector<int> twoSum(vector<int>& nums, int target) {
//        map<int, int> map_;
//        for (int i = 0; i < nums.size(); ++i)
//        {
//            //map_[nums[i]] = i; //key存放值，value存数组下标
//            map_.insert({ nums[i],i }); //key存放值，value存数组下标，这里不能用覆盖的写法，因为一个循环
//
//            auto it = map_.find(target - nums[i]);
//            if ((it != map_.end()) && (it->second != i))//注意这里，避免同一个下标相加
//            {
//                return { it->second, i };
//            }
//        }
//        return {};//无用，leetcode提交需要
//    }
//};
//
//int main()
//{
//    std::cout << "Hello World!\n";
//    vector<int> nums{ 3,2,4 };
//    Solution test;
//    test.twoSum(nums, 6);
//    std::cout << "Hello World!\n";
//}


int main()
{
    std::cout << "Hello World!\n";
    vector<int> nums{ 3,2,4 };
    //Solution test;
    //test.twoSum(nums, 6);
    std::cout << "Hello World!\n";
    std::cout << "Hello World!\n";
}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
