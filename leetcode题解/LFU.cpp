#include<iostream>
#include<set>
#include<unordered_map>
using namespace std;



/**
 * 
 * LFU：当空间不够的时候,删除最少使用次数,最早出现时间的数据
 * */
struct Node{
    int cnt;
    int time;
    int key;
    int value;
    Node(int c, int t,int k,int v){
        cnt = c;
        time = t;
        key = k;
        value = v;
    }
    bool operator <(const Node& n) const{
        return cnt == n.cnt ? time < n.time : cnt < n.cnt;
    } 
};

class LFUCache {
private:
    int cap;
    unordered_map<int, Node> mps;
    set<Node> nodes;
    int time;
    int curCap;
public:
    LFUCache(int capacity) {
        cap = capacity;
        time = 0;
        curCap = 0;
    }

    int get(int key) {
        auto iterators = mps.find(key);
        if(iterators == mps.end()){
            return -1;
        }
        Node curNode = iterators->second;
        nodes.erase(curNode);
        curNode.cnt++;
        curNode.time = time;
        time++;
        nodes.insert(curNode);
        iterators->second = curNode;
        return curNode.value;
    }
    
    void put(int key, int value) {
        if( cap == 0){
            return ;
        }
        auto iterators = mps.find(key);
        if(iterators != mps.end()){
            Node curNode = iterators->second;
            nodes.erase(curNode);
            curNode.time = time;
            curNode.cnt++;
            curNode.value = value;
            nodes.insert(curNode);
            iterators->second = curNode;
        }else{
            if(curCap == cap){
                curCap--;
                auto iterators = nodes.begin();
                mps.erase(mps.find(iterators->key));
                nodes.erase(iterators);
            }
            Node curNode = Node(1, time, key, value);
            mps.insert(make_pair(key, curNode));
            nodes.insert(curNode);
            curCap++;
        }
        time++;
    }
};


int main()
{

}