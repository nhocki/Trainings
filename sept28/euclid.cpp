#include <cstdio>
#include <math.h>

const double EPS = 1e-9;

int cmp(double x, double y = 0, double tol = EPS){
    return (x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1;
}


int main(){
  long double xa,xb,xc,xd,xe,xf,ya,yb,yc,yd,ye,yf;
  while(scanf("%Lf%Lf%Lf%Lf%Lf%Lf%Lf%Lf%Lf%Lf%Lf%Lf",&xa,&ya,&xb,&yb,&xc,&yc,&xd,&yd,&xe,&ye,&xf,&yf) == 12){
    
    if(cmp(xa + ya + xb + yb + xc + yc + xd + yd + xe + ye + xf + yf, 0.0) == 0){
      break;
    }
    
    
    long double m1 = sqrt((xc-xa)*(xc-xa) + (yc-ya)*(yc-ya));
    long double m2 = sqrt((xb-xa)*(xb-xa) + (yb-ya)*(yb-ya));
    long double area = fabs((xe-xd)*(yf-yd) - (ye-yd)*(xf-xd))/2.0;
    long double dot = (xc-xa)*(xb-xa) + (yc-ya)*(yb-ya);
    long double angle = acos(dot/(m1*m2));
    
    long double alpha = area/(sin(angle)*m1*m2);

    long double xh = xa + alpha*(xc - xa);
    long double yh = ya + alpha*(yc - ya);
    long double xg = xb + alpha*(xc - xa);
    long double yg = yb + alpha*(yc - ya);

    printf("%.3Lf %.3Lf %.3Lf %.3Lf\n",xg, yg, xh, yh);
  }
}
