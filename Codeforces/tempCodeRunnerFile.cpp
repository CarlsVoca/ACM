
                    dp[i]=min(dp[i],dp[i-(1<<j-1)-(1<<k-1)]+dis(p[0],p[j])+dis(p[j],p[k])+dis(p[k],p[0]));