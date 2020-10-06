/*

Arnab is given an array of N elements and Q queries. In each query he is given two values l, r.
Arnab has to find the minimum value of all the elements from l to r.

Input format
The first line contains an integer T, denoting the number of test cases.
Each test case contains an integer N.
The next line contains N
 space-separated integers (1 based indexing).
The next line contains a value Q.
The next Q lines contain two integer l and r. 


Output format
Print the answer of each query in a new line.

Example
Input
1
5 
1 2 3 4 5
3
1 2
2 3
3 4

Output
1
2
3

Explanation
The minimum element from index 1 to index 2 is 1, similarly for other queries (1based indexing).

*/


#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long int ull;
const int mod = 1e9+7;
#define endl "\n"
#define append push_back
#define roastedcoder ios_base::sync_with_stdio(false); cin.tie(NULL);
 
int a[100001], st[400004];
 
void buildtree(int si, int ss, int se) {
	if(ss == se) {
		st[si] = a[ss];
		return ;
	}
 
	int mid = ss + (se-ss)/2;
	buildtree(2*si, ss, mid);
	buildtree(2*si + 1, mid + 1, se);
 
	st[si] = min(st[2*si], st[2*si + 1]);
}
 
void update(int si, int ss, int se, int qi, int nv) {
	if(ss == se) {
		a[qi] = nv;
		st[si] = a[ss];
		return ;
	}
 
	int mid = ss + (se-ss)/2;
	if(qi<=mid)
		update(2*si, ss, mid, qi, nv);
	else
		update(2*si + 1, mid+1, se, qi, nv);
	
	st[si] = min(st[2*si], st[2*si + 1]);
}
 
int getmin(int si, int ss, int se, int qs, int qe) {
	 if(ss>qe || qs>se) return INT_MAX;
	
	if(ss>=qs && qe>=se) return st[si];
	
	int mid = ss + (se-ss)/2;
	int L = getmin(2*si, ss, mid, qs, qe);
	int R = getmin(2*si + 1, mid+1, se, qs, qe);
	return min(L, R);
}
 
int main() {
	roastedcoder
	int t;
	cin>>t;
	while(t--){
	int n, q; cin>>n;
	for(int i = 1; i<=n; i++) cin>>a[i];
	buildtree(1, 1, n);
	cin>>q;
	while(q--) {
		
			int l, r; cin>>l>>r;
			cout<<getmin(1, 1, n, l, r)<<endl;
		
	}		
	}
}
