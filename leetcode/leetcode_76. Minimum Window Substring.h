//
// Created by Li,Yang(Duer04) on 2018/7/16.
//

#ifndef INC_1STPROGRAM_76_MINIMUM_WINDOW_SUBSTRING_H
#define INC_1STPROGRAM_76_MINIMUM_WINDOW_SUBSTRING_H

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution{
public:
    string minWindow(string s, string t) {
        vector<int> map(128,0);
        for(auto c: t)
            map[c]++;
        int counter= static_cast<int>(t.size()), begin=0, end=0, d=INT_MAX, head=0;
        while(end<s.size()){
            if(map[s[end++]]-->0)
                counter--; //in t
            while(counter==0){ //valid
                if(end-begin<d)
                    d=end-(head=begin);
                if(map[s[begin++]]++==0)
                    counter++;  //make it invalid
            }
        }
        return d==INT_MAX? "":s.substr(head, d);
    }
};
#endif //INC_1STPROGRAM_76_MINIMUM_WINDOW_SUBSTRING_H
