#include <cstdio>
#include <math.h>
#include <iostream>
#include <sstream>

using namespace std;

#define D(x) cout << #x" = " << (x) << endl

const double EPS = 1e-9;

int cmp(double x, double y = 0, double tol = EPS){
  return (x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1;
}

string toStr(long double x){
  char ret[3000];
  string rett;
  sprintf(ret,"%.2Lf", x);
  rett = string(ret);
  return rett;
}

void truncate2(long double &val){
  int t = floor(val*100);
  val = (1.0*t)/100;
}

void truncate3(long double &val){
  int t = floor(val*1000);
  val = (1.0*t)/1000;
}

void print_it(long double a){
  if(cmp(a,1000000.00) >= 0) {puts("$1,000,000.00"); return;}
  if(cmp(a,0.0) == 0)   {puts("$0.00"); return;}
  if(cmp(a,1000) < 0){
    printf("$%.2Lf\n",a);
    return ;
  }
  double b;
  int c;
  b = a/1000.0;
  c = (int)b*1000;
  a = a-c;
  string tmp = toStr(a);
  if(a < 10){
    tmp = "00"+tmp;
  }else if(a<100){
    tmp = "0"+tmp;
  }
  printf("$%d,%s\n",(int)b,  tmp.c_str());
}

int main(){
  int T;
  scanf("%d",&T);
  bool worth_it = true;
  while(T--){
    worth_it = true;
    long double wag;
    int turns;
    cin >> wag >> turns;
    while(turns--){
      int money_line;
      string res;
      cin >> money_line >> res;
      if(worth_it){
        if(res[0]=='L'){ puts("$0.00"); worth_it = false; }
        if(cmp(wag,1000000) >= 0){ puts("$1,000,000.00"); worth_it = false;}
        if(res[0]=='T'){continue;}
        //Codigo de verdad
        long double mult = 0.0, won = 0.0;
        if(money_line >= 0)
          mult = money_line / 100.0;
        else
          mult = -100.0 / money_line;
        truncate3(mult);
        won = wag * mult;
        truncate2(won);
        wag += won;
      }
    }
    truncate2(wag);
    if(worth_it)
      print_it(wag);
  }
}
