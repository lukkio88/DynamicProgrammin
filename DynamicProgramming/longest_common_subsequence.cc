/*
 * longest_common_subsequence.cc
 *
 *  Created on: 30 May 2017
 *      Author: luca.gagliano
 */

#include "header.h"

//helper functions
int get_index(const int& i, const int& j, const int &m, const int& n)
{
   if (0 <= i && i < m && 0 <= j && j < n) {
      return i * n + j;
   } else {
      return -1;
   }
}

int extend_get_val(
   const std::vector<int>& v,
   const int& i,
   const int& j,
   const int& m,
   const int& n)
{
   if (i < 0 || j < 0) {
      return 0;
   } else {
      return v[get_index(i, j, m, n)];
   }
}

std::string longest_common_subsequence(
   const std::string& x,
   const std::string& y)
{
   int m, n, i, j;
   int diag, up, left;

   m = x.length();
   n = y.length();
   std::vector<int> c(m * n);
   std::vector<int> b(m * n);

   for (i = 0; i < m; ++i) {
      c[get_index(i, 0, m, n)] = 0;
   }

   for (j = 0; j < n; ++j) {
      c[get_index(0, j, m, n)] = 0;
   }

   for (i = 0; i < m; ++i) {
      for (j = 0; j < n; ++j) {
         diag = extend_get_val(c, i - 1, j - 1, m, n);
         up = extend_get_val(c, i - 1, j, m, n);
         left = extend_get_val(c, i, j - 1, m, n);
         if (x[i] == y[j]) {
            c[get_index(i, j, m, n)] = diag + 1;
            b[get_index(i, j, m, n)] = 3;
         } else if (up >= left) {
            c[get_index(i, j, m, n)] = up;
            b[get_index(i, j, m, n)] = 1;
         } else {
            c[get_index(i, j, m, n)] = left;
            b[get_index(i, j, m, n)] = 2;
         }
      }
   }

   //retrieving the string
   std::string rval = "";
   i = m - 1;
   j = n - 1;
   while(i >= 0 && j >= 0) {
      if(b[get_index(i,j,m,n)] == 3) {
         rval = x[i] + rval;
         --i;
         --j;
      } else if(b[get_index(i,j,m,n)] == 2) {
         --j;
      } else {
         --i;
      }
   }
   return rval;
}
