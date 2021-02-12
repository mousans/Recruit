#include<iostream>
#include<vector>

using namespace std;

void swap(string& a,int i,int j){
    char tp = a[i];
    a[i] = a[j];
    a[j] = tp;
    return;
}

void reverse(string&a,int i,int j){
    if(i>=j){
        return;
    }
    while(i<j){
        swap(a, i, j);
        i++;
        j--;
    }
    return;
}
string nextOrder(string word){
    int n = word.length();
    int i;
    for (i = n - 2; i > -1;i--){
        if(word[i]-word[i+1]<0){
            break;
        }
    }
    if(i == -1){
        return "";
    }
    int targetIndex = -1;
    for (int j = n - 1; j > i;j--){
        if(word[j]-word[i]>0){
            if(targetIndex == -1 || word[targetIndex]-word[j]>0){
                targetIndex = j;
            }
        }
    }
    swap(word, i, targetIndex);
    reverse(word, i + 1, n - 1);
    return word;
}

int main()
{
    string word = "123";
    while(word.length()!=0){
        cout << word << endl;
        word = nextOrder(word);
    }
    getchar();
    return 0;
}