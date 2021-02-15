#include<list>
#include<iostream>
#include<unordered_map>

using namespace std;

/**
 *hashmap用来做O(1)的删除，list用来保存之前键值对的顺序
 *  所以hashmap为<key,pair<key,value>>的hash
 * list为list<pair<key,value>>ls的双向链表
 **/

class LRUCache {
private:
    unordered_map<int, list<pair<int,int>>::iterator> mps;
    list<pair<int,int>> ls;
    int cp;
    int curNum;
public:
    LRUCache(int capacity) {
        cp = capacity;
        curNum = 0;
    }
    
    int get(int key) {
        if(mps.find(key) == mps.end()){
            return -1;
        }
        auto iterator = mps[key];
        int val = iterator->second;
        ls.erase(iterator);
        ls.push_front({key,val});
        mps[key] = ls.begin();
        return val;
    }
    
    void put(int key, int value) {
        if(mps.find(key) == mps.end() && curNum == cp){
            int beginKey = ls.back().first;
            mps.erase(mps.find(beginKey));
            ls.pop_back();
        }else if(mps.find(key) != mps.end()){
            ls.erase(mps[key]);
            mps.erase(mps.find(key));
        } else{
            curNum++;
        }
        ls.push_front({key,value});
        mps[key] = ls.begin();
        return;
    }
};

int main()
{

}