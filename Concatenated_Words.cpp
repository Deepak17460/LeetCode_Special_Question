 // Using Unordered_set
        unordered_set<string>s(words.begin(), words.end());
        vector<string>res;
        for (auto w : words) {
            int n = w.size();
            vector<int> dp(n+1,0);
            dp[0] = 1;
            for (int i = 0; i < n; i++) {
                if (dp[i] == 0)
                   continue;
                for (int j = i+1; j <= n; j++) {
                    if (j - i < n && s.count(w.substr(i, j-i))){
                        dp[j]=1;
                    }
                }
                // cout<<"Yes";
                // for(int &i:dp){
                //     cout<<i<<" ";
                // }
                // cout<<"No";
                if (dp[n]!=0){ 
                    res.push_back(w); 
                    break; 
                    }
            }
        }
        return res;
