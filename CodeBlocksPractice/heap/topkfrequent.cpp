#include <bits/stdc++.h>

#define psi pair<int, string>

using namespace std;
// word, freq
class Comp {
  public:
    bool operator() (const psi &p1, const psi &p2)
    {
        // freq equal then lexicographic
        if (p1.first == p2.first)
            return p1.second < p2.second;

        // for minheap we use greater function.
        return p1.first > p2.first;
    }
};

vector<string> getTopKMostFrequentElement(vector<string> &words, int k)
{
    int totalWorods= words.size();
    unordered_map <string, int> wordFrequency;

    for (string word: words)
    {
        wordFrequency[word]++;
    }

    priority_queue<psi, vector<psi>, Comp> minHeapFreqToWord;

    for (auto wordEntry : wordFrequency)
    {
        minHeapFreqToWord.push({wordEntry.second, wordEntry.first});
        if (minHeapFreqToWord.size() >k)
        {
            minHeapFreqToWord.pop();
        }
    }

    vector<string> ans(k);
    int m = k-1;
    while (minHeapFreqToWord.size() > 0){
        //cout << "m " << m ;
        auto topItem = minHeapFreqToWord.top();
        //cout << topItem.second << endl;
        ans[m--] = topItem.second;
        minHeapFreqToWord.pop();
    }
    return ans;
}

int main() {
  int n, k=3;
  //cin >> n >> k;

  vector<string> arr = {"hi", "this", "is" ,"something", "is" ,"this", "ok" ,"is" ,"ok"};
//  for(int i=0; i<n; i++) {
//    string s; cin >> s;
//    arr[i] = s;
//  }
   for(string s : arr) {
    cout << s << " ";
  }
  vector<string> topKFreq(getTopKMostFrequentElement(arr, k));

  cout << "Ans" << endl;
  for(string s : topKFreq) {
    cout << s << " ";
  }

  return 0;
}
