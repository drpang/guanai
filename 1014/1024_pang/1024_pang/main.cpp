//
//  main.cpp
//  1024_pang
//
//  Created by pang on 16/10/16.
//  Copyright © 2016年 庞浩斌. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;
using std::vector;
class Solution {
public:
    void swap(vector<int>& arr, int m, int n) {
        int x = arr[m];
        arr[m] = arr[n];
        arr[n] = x;
    }
    
    int gcd(int x, int y) {
        while(x!=y) {
            if(x>y) x=x-y;
            else y=y-x;
        }
        return x;
    }
    
    int moveArray(vector<int>& arr, int k, int g) {
        if (arr.empty() || arr.size() == 0) {
            return -1;
        }
        for (int i=0; i<(arr.size()/g) - 1; i++) {
            for (int j=0; j<g; j++) {
                this->swap(arr, j, ((i + 1) * k + j) % arr.size());
            }
        }
        return  -1;
    }
};
int main(int argc, const char * argv[]) {
    Solution *solution = new Solution;
    vector<int> arr = {1,2,3,4,5,6,7,8,9,10};
    int k = 3;
    int g = solution->gcd((int)arr.size(), k);
    solution->moveArray(arr, k, g);
    for (int i=0; i<arr.size(); i++) {
        printf("arr = %d \r",arr[i]);
    }
    return 0;
}
