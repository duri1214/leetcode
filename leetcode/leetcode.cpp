﻿// leetcode.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include<string>
#include <algorithm>
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

////leetcode 5. 最长回文子串 暴力法 On3 leetcode超时
//class Solution {
//public:
//    string longestPalindrome(string s) {
//        string ret, temp;
//        for (int i = 0; i < s.size(); ++i)
//        {
//            for (int j = i; j < s.size(); ++j)  //j=i 注意
//            {
//                temp += s[j];
//                string rev_temp(temp);
//                reverse(rev_temp.begin(), rev_temp.end());
//                if (temp == rev_temp)
//                {
//                    ret = (rev_temp.size() > ret.size()) ? temp : ret;
//                }
//            }
//            temp = "";
//        }
//        return ret;
//    }
//};

////leetcode 5. 最长回文子串 动态规划 时间On2 空间On2
//class Solution {
//public:
//    string longestPalindrome(string s) {
//        vector<vector<int>> dp(s.size(),vector<int>(s.size(),0));
//        int left = 0;
//        int right = 0;
//        int max_len = 0;
//        for (int i = s.size() -1; i >= 0; --i)
//        {
//            for (int j = i; j < s.size(); ++j)//注意遍历顺序
//            {
//                if (s[i] == s[j])
//                {
//                    if (j - i <= 1)
//                    {
//                        dp[i][j] = 1;
//                    }
//                    else if(dp[i+1][j-1])
//                    {
//                        dp[i][j] = 1;
//                    }
//                }
//                if (dp[i][j] && (j - i + 1) > max_len)
//                {
//                    max_len = (j - i + 1);
//                    left = i;
//                    right = j;
//                }
//            }
//        }
//        return s.substr(left, right - left + 1);
//    }
//};

////leetcode 5. 最长回文子串 双指针 时间On2 空间O1
//class Solution {
//public:
//    int left = 0;
//    int right = 0;
//    int max_len = 0;
//
//    void extend(const string& s, int i, int j, int n)
//    {
//        while (i >= 0 && i < n && s[i] == s[j])//从中间，向两边判断
//        {
//            if ((j - i + 1) > max_len)
//            {
//                max_len = j - i + 1;
//                left = i;
//                right = j;
//            }
//            --i;
//            ++j;
//        }
//    }
//
//    string longestPalindrome(string s) {
//        for (int i = 0; i < s.size(); ++i)
//        {
//            extend(s, i, i, s.size());      //一个元素做为中心点
//            extend(s, i, i+1, s.size());    //两个元素做为中心点
//        }
//
//        return s.substr(left, right - left + 1);
//    }
//};
//
//
//int main()
//{
//    std::cout << "Hello World!\n";
//    string s = "cbbd";
//    Solution test;
//    test.longestPalindrome(s);
//    std::cout << "Hello World!\n";
//    std::cout << "Hello World!\n";
//}

class Solution { //15. 三数之和 暴力法 时间复杂度：On3 超出时间限制 空间复杂度：On
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ret;
        unordered_map<string, vector<int>> map_;
        for (int i = 0; i < nums.size(); ++i)
        {
            for (int j = i + 1; j < nums.size(); ++j)
            {
                for (int k = j + 1; k < nums.size(); ++k)
                {
                    if (nums[i] + nums[j] + nums[k] == 0)
                    {
                        ret.push_back({ nums[i],nums[j],nums[k] });
                    }
                }
            }
        }
        for (auto& its : ret)
        {
           std::sort(its.begin(), its.end());
           map_[to_string(its[0]) + "" + to_string(its[1]) + "" + to_string(its[2])] = its;
       
        }
        ret.clear();
        for (auto &it: map_)
        {
            ret.push_back(it.second);
        }
        return ret;
    }
};


int main()
{
    std::cout << "Hello World!\n";
    vector<int> s = { -1,0,1,2,-1,-4 };
    Solution test;
    test.threeSum(s);
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
