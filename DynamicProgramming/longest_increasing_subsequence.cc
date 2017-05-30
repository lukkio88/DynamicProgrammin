/*
 * longest_increasing_subsequence.cc
 *
 *  Created on: 30 May 2017
 *      Author: luca.gagliano
 */

#include "header.h"

std::vector<int> longest_increasing_subsequence(std::vector<int>& v, int& l_max)
{
   int n = v.size();
   int i, j;
   std::vector<int> l(n);
   std::vector<int> prev(n);
   int max, i_max, i_prev;

   for (i = 0; i < n; ++i) {
      l[i] = 1;
      prev[i] = -1;
      for (j = 0; j < i; ++j) {
         if (v[j] < v[i] && (l[i] < (l[j] + 1))) {
            l[i] = (l[j] + 1);
            prev[i] = j;
         }
      }
   }

   //find the final max
   max = l[0];
   i_max = 0;
   for (i = 1; i < n; ++i) {
      max = (max >= l[i]) ? max : l[i];
      i_max = i;
   }

   std::vector<int> rval(max);
   rval[max - 1] = v[i_max];
   i_prev = prev[i_max];
   for (i = max - 2; i >= 0; --i) {
      rval[i] = v[i_prev];
      i_prev = prev[i_prev];
   }

   l_max = max;
   return rval;
}


