/*
 * header.h
 *
 *  Created on: 30 May 2017
 *      Author: luca.gagliano
 */

#ifndef HEADER_H_
#define HEADER_H_

#include <iostream>
#include <cstdlib>
#include <vector>

std::vector<int> longest_increasing_subsequence(std::vector<int>& v, int& l_max);
std::string longest_common_subsequence(
   const std::string& x,
   const std::string& y);

#endif /* HEADER_H_ */
