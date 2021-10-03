class Solution {
public:
    int fact[11];
    vector<int> nums;
    void solve(int n, int k, string &ans){
        if(n==1){
            ans+=to_string(nums.back());
            return;
        }
        int dig = k/fact[n-1];
        if(k%fact[n-1]==0){
            dig--;
        }
        ans += to_string(nums[dig]);
        nums.erase(nums.begin()+dig);
        k -= fact[n-1]*dig;
        solve(n-1,k,ans);
    }
    string getPermutation(int n, int k) {
        if(n==1){
            return "1";
        }
        string ans = "";
        fact[0]=1;
        fact[1]=1;
        for(int i=2;i<=10;i++){
            fact[i]=i*fact[i-1];
        }
        for(int i=1;i<=n;i++){
            nums.push_back(i);
        }
        solve(n,k,ans);
        return ans;
    }
};