class Solution {
public:
    string removeDuplicateLetters(string s) {
        int cnt[26]={0};
        int vis[26]={0};
        string ans="";
        for(int i=0;i<s.size();i++){
            cnt[s[i]-'a']++;
        }
        stack<char> stk;
        for(int i=0;i<s.size();i++){
            cnt[s[i]-'a']--;
            if(vis[s[i]-'a']){
                continue;
            }
            while(!stk.empty() && stk.top()>s[i] && cnt[stk.top()-'a']>0){
                vis[stk.top()-'a']=0;
                stk.pop();
            }
            stk.push(s[i]);
            vis[s[i]-'a']=1;
            
        }
        while(stk.size()){
            ans = stk.top() + ans;
            stk.pop();
        }
        return ans;
    }
};