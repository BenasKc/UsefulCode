#include <bits/stdc++.h>

using namespace std;

string conv(long long int a)
{
  long long int siz = log10(a)+1;
  string str;
  for(long long int i = 0;i < siz;i++){
    str+=(a%10)+'0';
    a /= 10;
  }
  reverse(str.begin(), str.end());
  return str;

}
int main(){
  long long int a;
  cin >> a;
  string f = conv(a);
  cout << f;
}
