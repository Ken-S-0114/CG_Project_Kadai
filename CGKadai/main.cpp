//
//  main.cpp
//  CGKadai
//
//  Created by 佐藤賢 on 2017/11/25.
//  Copyright © 2017年 佐藤賢. All rights reserved.
//

#include <stdio.h>
#include <math.h>

double __veci(double va[], double vb[])
{
  int i;
  double x = 0.0;
  
  for(i = 0; i < 3; i++){
    x += va[i] * vb[i];
  }
  
  return x;
}

double __veco(double va[], double vb[], double vc[])
{
  vc[0] = va[1] * vb[2] - va[2] * vb[1];
  vc[1] = va[2] * vb[0] - va[0] * vb[2];
  vc[2] = va[0] * vb[1] - va[1] * vb[0];
  
  return 0;
}

double heimen(double *a, double *b, double *c,
              double x1, double x2, double x3,
              double y1, double y2, double y3,
              double z1, double z2, double z3){
  double d;
  *a = (y2 - x2) * (z3 - x3) - (z2 - x2) * (y3 - x3);
  *b = (y3 - x3) * (z1 - x1) - (z3 - x3) * (y1 - x1);
  *c = (y1 - x1) * (z2 - y2) - (z1 - x1) * (y2 - x2);
  
  d = -1 * (*a * x1 + *b * x2 + *c * x3);
  return d;
}

double housen(double va[], double vb[], double vc[], double gaiseki[]){
  double vd[3];
  double ve[4];
  
  vd[0] = va[0] - va[2];
  vd[1] = vb[0] - vb[2];
  vd[2] = vc[0] - vc[2];
  
  ve[0] = va[1] - va[2];
  ve[1] = vb[1] - vb[2];
  ve[3] = vc[1] - vc[2];
  
  gaiseki[0] = va[1] * vb[2] - va[2] * vb[1];
  gaiseki[1] = va[2] * vb[0] - va[0] * vb[2];
  gaiseki[2] = va[0] * vb[1] - va[1] * vb[0];
  
  return 0;
}


double tris(double *a, double *b, double *c,
            double x1, double x2, double x3,
            double y1, double y2, double y3,
            double z1, double z2, double z3){
  double S;
  *a = (y2 - x2) * (z3 - x3) - (z2 - x2) * (y3 - x3);
  *b = (y3 - x3) * (z1 - x1) - (z3 - x3) * (y1 - x1);
  *c = (y1 - x1) * (z2 - y2) - (z1 - x1) * (y2 - x2);
  
  S = sqrt(*a * *a + *b * *b + *c * *c) / 2;
  return S;
}

double heimen2(double *a, double *b, double *c,
               double x, double y, double z,
               double f, double g, double h){
  
  *a = f * -1 * x;
  *b = g * -1 * y;
  *c = h * -1 * z;
  
  return 0;
}


int main(void)
{
  // ベクトル値
  double va[3] = {17.0, 44.0, 34.0};
  double vb[3] = {52.0, 4.0, 9.0};
  double vc[3];
  
  // ３点の頂点座標
  double vx[3] = {10.0, 80.0, 35.0};
  double vy[3] = {10.0, 20.0, 70.0};
  double vz[3] = {10.0, 15.0, 30.0};
  
  // 三角形の頂点座標
  double va2[3] = {1.0, 1.0, 1.0};
  double vb2[3] = {18.0, 45.0, 35.0};
  double vc2[3] = {53.0, 5.0, 10.0};
  
  double x;           // 内積
  double gaiseki[3];  // 外積
  
  // 平面方程式・三角形の結果出力用
  double a, b, c;
  
  // １点(x, y, z)
  double x0 = 1.0, y0 = 1.0, z0 = 2.0;
  // 方向ベクトル
  double f = 4.0, g = -4.0, h = 8.0;
  
  int i;        // カウント用
  
  printf("課題1-----------------\n");
  // 内積を求める
  x =  __veci(va, vb);
  printf("va, vbの内積 = %lf\n", x);
  
  // 外積を求める
  __veco(va, vb, vc);
  printf("va, vbの外積 = ");
  for(i = 0; i < 3; i++){
    if(i == 2){
      printf("%.lf \n", vc[i]);
      break;
    }
    printf("%.lf, ", vc[i]);
  };
  
  printf("課題2-----------------\n");
  // ３点を含む平面方程式を求める
  heimen(&a, &b, &c, vx[0], vy[0], vz[0], vx[1], vy[1], vz[1], vx[2], vy[2], vz[2]);
  
  printf("平面方程式 = ");
  printf("%.lfx + ", a);
  
  if(b < 0){
    printf("(%.lfy) + ", b);
  } else {
    printf("%.lfy + ", b);
  }
  
  if(c < 0){
    printf("(%.lfz) +", c);
  } else {
    printf("%.lfz + ", c);
  }
  
  printf("d = 0\n");
  
  printf("課題3-----------------\n");
  // 平面方程式の係数を求める
  printf("係数d = %.lf\n",heimen(&a, &b, &c, vx[0], vy[0], vz[0], vx[1], vy[1], vz[1], vx[2], vy[2], vz[2]));
  
  printf("課題4-----------------\n");
  // 三角形の法線を求める
  housen(va2, vb2, vc2, gaiseki);
  
  printf("三角形の法線(左回り) = ");
  for(i = 0; i < 3; i++){
    if(i == 2){
      printf("%.lf\n", gaiseki[i]);
      break;
    }
    printf("%.lf, ", gaiseki[i]);
  }
  
  housen(va2, vc2, vb2, gaiseki);
  
  printf("三角形の法線(右回り) = ");
  for(i = 0; i < 3; i++){
    if(i == 2){
      printf("%.lf\n", gaiseki[i]);
      break;
    }
    printf("%.lf, ", gaiseki[i]);
  }
  
  printf("課題5-----------------\n");
  // 本直線に垂直で、かつ、点 (x, y, z) を通過する平面方程式を求める
  heimen2(&a,&b,&c,x0,y0,z0,f,g,h);
  
  printf("平面方程式2 = ");
  printf("%.lfx + ", f);
  
  if(g < 0){
    printf("(%.lfy) + ", g);
  } else {
    printf("%.lfy + ", g);
  }
  
  if(h < 0){
    printf("(%.lfz) +", h);
  } else {
    printf("%.lfz + ", h);
  }
  
  if(a + b + c < 0){
    printf("(%.lf) = 0 \n", a + b + c);
  } else {
    printf("%.lf = 0 \n", a + b + c);
  }
  
  printf("課題6-----------------\n");
  // 三角形の面積を求める
  printf("三角形の面積 = %lf \n",tris(&a, &b, &c, vx[0], vy[0], vz[0], vx[1], vy[1], vz[1], vx[2], vy[2], vz[2]));
  
  printf("課題7-----------------\n");
  printf("長所：可視・不可視の判断ができるようになる。\n三角形の面もしくは頂点の法線ベクトルが視点の方向を向いていれば可視となる。\n");
  printf("短所：法線ベクトルを求めるのに手間がかかる。\n面が表かどうか（頂点の順序が左回り）、ベクトルの外積を求める、ベクトルの長さを１にする。\n以上の３段階を踏む必要がある。\n");
  
  return 0;
  
}
