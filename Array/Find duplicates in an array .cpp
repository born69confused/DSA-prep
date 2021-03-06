#include <bits/stdc++.h>
using namespace std;
/*
Question Link - https://practice.geeksforgeeks.org/problems/find-duplicates-in-an-array/1

Given an array a[] of size N which contains elements from 0 to N-1, you need to find all the elements occurring more than once in the given array.

Input:
    N = 4
    a[] = {0,3,1,2}
Output: -1

Method 1:
TC - O(N) , SC - O(N)
*/
class Solution
{
public:
    vector<int> duplicates(int arr[], int n)
    {
        vector<int> res;
        int freq[n] = {0};
        for (int i = 0; i < n; i++)
        {
            freq[arr[i]]++;
        }
        for (int i = 0; i < n; i++)
        {
            if (freq[i] > 1)
                res.push_back(i);
        }
        if (res.size() == 0)
            return {-1};
        return res;
    }
};
/*
Method 2:
TC - O(N) , SC - O(1)
*/
class Solution
{
public:
    vector<int> duplicates(int arr[], int n)
    {
        vector<int> res;
        for (int i = 0; i < n; i++)
        {
            arr[arr[i] % n] += n;
        }
        for (int i = 0; i < n; i++)
        {
            if (arr[i] / n > 1)
                res.push_back(i);
        }
        if (res.size() == 0)
            res.push_back(-1);
        return res;
    }
};