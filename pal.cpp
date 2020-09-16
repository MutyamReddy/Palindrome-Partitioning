bool pal(string s){ //to check palindrome
    int n=s.length();bool cond=true;
    for(int i=0;i<n/2;i++){
        if(s[i]!=s[n-1-i]){
            cond=false;
        }
    }
    if(n==0){
        return false;
    }
    return cond;
}
vector<vector<string>>ans; 
void backtrack(string s,int l,int n,vector<string>v){ 
    if(l>=n){ //base case
        ans.push_back(v);
        return ;
    }
    for(int i=l;i<=n;i++){
        string temp=s.substr(l,i-l); //partitioning palindrome from left side
        if(pal(temp)){
            v.push_back(temp);
            backtrack(s,i,n,v); // recursive call 
            v.pop_back();       // 
        }
    }
}
class Solution {
public:
    vector<vector<string>> partition(string s) {
        ans.clear();vector<string>v;
        backtrack(s,0,s.length(),v); 
        return ans;
    }
};
