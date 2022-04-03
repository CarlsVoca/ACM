tot[i]表示有多少个队的能力值<=val[i]

cnt[i]表示有多少个队的能力值==val[i]


$ans[i]=\frac{\frac{C(tot[i]-1,2^{n-1}-1)}{C(2^n-1,2^{n-1}-1)}}{cnt[i]}$