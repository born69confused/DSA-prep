#include <bits/stdc++.h>
using namespace std;
/*
Question Link - https://practice.geeksforgeeks.org/problems/majority-element-1587115620/1

Given an array A of N elements. Find the majority element in the array.
A majority element in an array A of size N is an element that appears more than N/2 times in the array. If no majority exists, return -1.
Input:
N = 5
A[] = {3,1,3,3,2}
Output:
3

Method 1:
TC-O(N*N) SC-O(1)
*/
class Solution
{
public:
    int majorityElement(int arr[], int n)
    {
        for (int i = 0; i < n; i++)
        {
            int count = 1;
            for (int j = i + 1; j < n; j++)
                if (arr[i] == arr[j])
                    count++;

            if (count > n / 2)
                return arr[i];
        }
        return -1;
    }
};
/*
Method 2:
TC-O(N)+O(N) ~ O(N) SC-O(1)
*/
class Solution
{
public:
    int majorityElement(int arr[], int n)
    {
        if (n == 1)
            return arr[0];

        int res = arr[0], count = 1;
        for (int i = 1; i < n; i++)
        {
            if (res == arr[i])
                count++;
            else
                count--;
            if (count == 0)
            {
                res = arr[i];
                count = 1;
            }
        }

        count = 0;
        for (int i = 0; i < n; i++)
            if (res == arr[i])
                count++;

        return (count <= n / 2) ? -1 : res;
    }
};
