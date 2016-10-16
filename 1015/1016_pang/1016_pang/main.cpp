//
//  main.cpp
//  1016_pang
//
//  Created by pang on 16/10/16.
//  Copyright © 2016年 庞浩斌. All rights reserved.
//

#include <vector>
using namespace std;
using std::vector;
class Solution {
    public:

    void swap(int &m, int &n) {
        int x = m;
        m = n;
        n = x;
    }
    
    int compare6(int& a,int& b,int& c,int& d,int& e){
        if(a<b)swap(a,b);
        if(c<d)swap(c,d);
        if(a<c) {
            swap(a,c);
            swap(b,d);
        }
        if(b<e)swap(b,e);
        if(b<c) {
            swap(b,c);
            swap(d,e);
        }
        if(e<c) return c;
        else return e;  
    }
    
    void compare7(int& a,int& b,int& c,int& d,int& e){
        if(a<b)swap(a,b);
        if(c<d)swap(c,d);
        if(a<c){swap(a,c);swap(b,d);}
        if(c<e){
            if(a<e){
                if(b<c){
                    if(b<d)swap(b,d);
                    swap(a,d);
                    return;
                }
                else{
                    swap(a,d);
                    swap(b,c);
                    return;
                }
            }
            else{
                swap(c,e);
                swap(d,e);
            }
        }
        else{
            if(d<e)swap(d,e);
        }
        if(b<d){
            if(b<e)swap(b,e);
            swap(a,e);
            swap(c,d);
        }  
        else{  
            if(b<c)swap(b,c);
            swap(a,e);  
            swap(b,d);  
        }  
    }
};
int main(int argc, const char * argv[]) {

    Solution *solution = new Solution;
    vector<int> arr = {2,4,7,3,8};
    solution->compare7(arr[0], arr[1], arr[2], arr[3], arr[4]);
    for (int i=0; i<arr.size(); i++) {
        printf("arr排序 = %d",arr[i]);
    }
    printf("中位数 = %d ",solution->compare6(arr[0], arr[1], arr[2], arr[3], arr[4]));
    return 0;
}
