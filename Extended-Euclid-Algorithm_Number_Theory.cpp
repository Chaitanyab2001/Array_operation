// ax + by = gcd(a,b)
// gcd(a,b) = gcd(b,a%b)

#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e5+2,MOD = 1e9+7;

struct triplet{
    int x,y,gcd;
};

triplet extendedEuclid(int a,int b)
{
    if(b==0)
    {
        triplet ans;
        ans.x = 1;
        ans.gcd = a;
        ans.y = 0;
        return ans;
    }
    triplet smallAns = extendedEuclid(b,a%b);
    triplet ans;
    ans.gcd = smallAns.gcd;
    ans.x = smallAns.y;                        // x = y1
    ans.y = smallAns.x - (a/b)*smallAns.y;     // y = x1 - (a/b)*y1
    return ans;
}

signed main()
{
   int a,b;
   cin>>a>>b;
   triplet ans = extendedEuclid(a,b);
   cout<<ans.gcd<<" "<<ans.x<<" "<<ans.y<<endl;
    return 0;
}