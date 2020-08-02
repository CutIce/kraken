//
// Created by hsh on 2020/7/31.
//

#include <iostream>
#include <deque>
#include <queue>
#include <algorithm>
#include <stack>
#include <tuple>
#include <set>
#include <map>
#include <vector>
#include <string.h>

using namespace std;

int main() {
    long e, em, m, mh, h;
    cin >> e >> em >> m >> mh >> h;
    long res = 0;
//
//    long min = e < m ? e :m ;
//    min = min < h? min:h;
//    e-=min;  m-=min;  h-=min;  res+=min;
//
//
//    long min2 = em < mh ? em : mh;
//    if (!e) min = m < h? m:h;
//    else if (!m) min = e<h?e:h;
//    else if (!h) min = m<h?m:h;
//    min = min < min2 ? min: min2;
    long sum = e + em + m + mh + h;
    long div = sum / 3;

//    if (m >= div) {
//        res = (e + em) < (mh + h) ? (e + em) : (mh + h);
//    } else {
//        if (e + em >= div && mh+h < div) {
//            if (e > div) m += em;
//            else m += em - div + h;
//            if (m >= div) res = mh + h;
//            else {
//
//            }
//            }
//        else if (mh+h >=div && e+em <div) {
//            if (h>div) m+=mh;
//            else m+=mh-div+h;
//            if (m>div) res= e+em;
//            else res= div;
//        }
//        else if (e+em >=div && )
//        }
        if (e+em < div && mh+h<div ){
            res = (e+em) < (mh+h ) ? (e+em):( mh+h);
        }
        else if (e+em <div){
            res = e+em;
        }
        else if (h+mh <div){
            res = h+mh;
        }
        else res = div;
        cout << res;
}