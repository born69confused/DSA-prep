#include <bits/stdc++.h>
using namespace std;
/*
Question Link - https://practice.geeksforgeeks.org/problems/find-second-largest-element2406/1/

Given an array of elements. Your task is to find the second maximum element in the array otherwise return -1.
Input:
N=5
arr[] = { 2, 4, 5, 6, 7 }
Output:  6

Method 1:
TC - O(N), SC - O(1)
*/
class Solution
{
public:
    int print2largest(int arr[], int n)
    {
        int first = arr[0];
        int second = -1;
        for (int i = 1; i < n; i++)
        {
            if (arr[i] > first)
            {
                second = first;
                first = arr[i];
            }
            if (first > arr[i] && arr[i] > second)
            {
                second = arr[i];
            }
        }
        return second == -1 ? -1 : second;
    }
};
