/*
 * main.cc
 *
 *  Created on: 30 May 2017
 *      Author: luca.gagliano
 */

#include "header.h"

int main(int argc, char** argv) {
   std::string x = "AGGTAB";
   std::string y = "GXTXAYB";
   std::cout << longest_common_subsequence(x,y) << std::endl;
   return 0;
}
