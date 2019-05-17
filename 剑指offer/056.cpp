/*
请实现一个函数用来找出字符流中第一个只出现一次的字符。例如，当从字符流中只读出前两个字符"go"时，
第一个只出现一次的字符是"g"。当从该字符流中读出前六个字符“google"时，第一个只出现一次的字符是"l"
*/

class Solution
{
public:
  //Insert one char from stringstream
    void Insert(char ch)
    {
        Q.push(ch);
        M[ch]++;
    }
  //return the first appearence once char in current stringstream
    char FirstAppearingOnce()
    {
        while(!Q.empty() && M[Q.front()]!=1)
            Q.pop();
        return Q.empty()?'#':Q.front();
    }
private:
    queue<char> Q;
    unordered_map<char,int> M;
};
