/* 
 * CS:APP Data Lab 
 * 
 * <Please put your name and userid here>
 * 
 * bits.c - Source file with your solutions to the Lab.
 *          This is the file you will hand in to your instructor.
 *
 * WARNING: Do not include the <stdio.h> header; it confuses the dlc
 * compiler. You can still use printf for debugging without including
 * <stdio.h>, although you might get a compiler warning. In general,
 * it's not good practice to ignore compiler warnings, but in this
 * case it's OK.  
 */

#if 0
/*
 * Instructions to Students:
 *
 * STEP 1: Read the following instructions carefully.
 */

You will provide your solution to the Data Lab by
editing the collection of functions in this source file.

INTEGER CODING RULES:
 
  Replace the "return" statement in each function with one
  or more lines of C code that implements the function. Your code 
  must conform to the following style:
 
  int Funct(arg1, arg2, ...) {
      /* brief description of how your implementation works */
      int var1 = Expr1;
      ...
      int varM = ExprM;

      varJ = ExprJ;
      ...
      varN = ExprN;
      return ExprR;
  }

  Each "Expr" is an expression using ONLY the following:
  1. Integer constants 0 through 255 (0xFF), inclusive. You are
      not allowed to use big constants such as 0xffffffff.
  2. Function arguments and local variables (no global variables).
  3. Unary integer operations ! ~
  4. Binary integer operations & ^ | + << >>
    
  Some of the problems restrict the set of allowed operators even further.
  Each "Expr" may consist of multiple operators. You are not restricted to
  one operator per line.

  You are expressly forbidden to:
  1. Use any control constructs such as if, do, while, for, switch, etc.
  2. Define or use any macros.
  3. Define any additional functions in this file.
  4. Call any functions.
  5. Use any other operations, such as &&, ||, -, or ?:
  6. Use any form of casting.
  7. Use any data type other than int.  This implies that you
     cannot use arrays, structs, or unions.

 
  You may assume that your machine:
  1. Uses 2s complement, 32-bit representations of integers.
  2. Performs right shifts arithmetically.
  3. Has unpredictable behavior when shifting if the shift amount
     is less than 0 or greater than 31.


EXAMPLES OF ACCEPTABLE CODING STYLE:
  /*
   * pow2plus1 - returns 2^x + 1, where 0 <= x <= 31
   */
  int pow2plus1(int x) {
     /* exploit ability of shifts to compute powers of 2 */
     return (1 << x) + 1;
  }

  /*
   * pow2plus4 - returns 2^x + 4, where 0 <= x <= 31
   */
  int pow2plus4(int x) {
     /* exploit ability of shifts to compute powers of 2 */
     int result = (1 << x);
     result += 4;
     return result;
  }

FLOATING POINT CODING RULES

For the problems that require you to implement floating-point operations,
the coding rules are less strict.  You are allowed to use looping and
conditional control.  You are allowed to use both ints and unsigneds.
You can use arbitrary integer and unsigned constants. You can use any arithmetic,
logical, or comparison operations on int or unsigned data.

You are expressly forbidden to:
  1. Define or use any macros.
  2. Define any additional functions in this file.
  3. Call any functions.
  4. Use any form of casting.
  5. Use any data type other than int or unsigned.  This means that you
     cannot use arrays, structs, or unions.
  6. Use any floating point data types, operations, or constants.


NOTES:
  1. Use the dlc (data lab checker) compiler (described in the handout) to 
     check the legality of your solutions.
  2. Each function has a maximum number of operations (integer, logical,
     or comparison) that you are allowed to use for your implementation
     of the function.  The max operator count is checked by dlc.
     Note that assignment ('=') is not counted; you may use as many of
     these as you want without penalty.
  3. Use the btest test harness to check your functions for correctness.
  4. Use the BDD checker to formally verify your functions
  5. The maximum number of ops for each function is given in the
     header comment for each function. If there are any inconsistencies 
     between the maximum ops in the writeup and in this file, consider
     this file the authoritative source.

/*
 * STEP 2: Modify the following functions according the coding rules.
 * 
 *   IMPORTANT. TO AVOID GRADING SURPRISES:
 *   1. Use the dlc compiler to check that your solutions conform
 *      to the coding rules.
 *   2. Use the BDD checker to formally verify that your solutions produce 
 *      the correct answers.
 */


#endif
/* Copyright (C) 1991-2020 Free Software Foundation, Inc.
   This file is part of the GNU C Library.

   The GNU C Library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.

   The GNU C Library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public
   License along with the GNU C Library; if not, see
   <https://www.gnu.org/licenses/>.  */
/* This header is separate from features.h so that the compiler can
   include it implicitly at the start of every compilation.  It must
   not itself include <features.h> or any other header that includes
   <features.h> because the implicit include comes before any feature
   test macros that may be defined in a source file before it first
   explicitly includes a system header.  GCC knows the name of this
   header in order to preinclude it.  */
/* glibc's intent is to support the IEC 559 math functionality, real
   and complex.  If the GCC (4.9 and later) predefined macros
   specifying compiler intent are available, use them to determine
   whether the overall intent is to support these features; otherwise,
   presume an older compiler has intent to support these features and
   define these macros by default.  */
/* wchar_t uses Unicode 10.0.0.  Version 10.0 of the Unicode Standard is
   synchronized with ISO/IEC 10646:2017, fifth edition, plus
   the following additions from Amendment 1 to the fifth edition:
   - 56 emoji characters
   - 285 hentaigana
   - 3 additional Zanabazar Square characters */
/*
 * onebitParity - returns 1 if x contains an odd number of 0's
 *   Examples: onebitParity(5) = 0, onebitParity(7) = 1
 *   Legal ops: & ^ << >>
 *   Max ops: 20
 *   Rating: 1
 */
int onebitParity(int x) {
   x ^= (x >> 16);
   x ^= (x >> 8);
   x ^= (x >> 4);
   x ^= (x >> 2);
   x ^= (x >> 1);
   return (x & 1);
}
/* 
 * checkSubstraction - Determine if can compute x-y without overflow
 *   Example: checkSubstraction(0x80000000,0x80000000) = 1,
 *            checkSubstraction(0x80000000,0x70000000) = 0, 
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 20
 *   Rating: 1
 */
int checkSubstraction(int x, int y) {
   int negativeY = (~y) + 1;
   int diff = x + negativeY;

   int signX = x >> 31, signY = y >> 31, signDiff = diff >> 31;
   return !((signX ^ signY) & (signX ^ signDiff));
}
/* 
 * twoscom2SignedVal - Convert from two's complement to signed-magnitude 
 *   where the MSB is the sign bit
 *   You can assume that x > TMin
 *   Example: twoscom2SignedVal(-5) = 0x80000005.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 15
 *   Rating: 1
 */
int twoscom2SignedVal(int x) {
   int sign = x >> 31; // 1..1 or 0..0
   int absoluteX = (x ^ sign) + (sign & 1);
   return absoluteX | (sign << 31);
}
/*
 * nibbleReverse - Reverse nibbles(4bits) in a 32-bit word
 *   Examples: nibbleReverse(0x80000002) = 0x20000008
 *             nibbleReverse(0x89ABCDEF) = 0xFEDCBA98
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 25
 *   Rating: 1
 */
int nibbleReverse(int x) {
   int mask0 = 0xFF | (0xFF << 8); // 0x0000FFFF
   int mask1 = 0xFF | (0xFF << 16); // 0x00FF00FF
   int temp1 = 0x0F | (0x0F << 8); // 0x0F0F
   int mask2 = temp1 | (temp1 << 16); // 0x0F0F0F0F
   
   int temp2 = x << 16;
   int temp3 = (x >> 16) & mask0;
   x = temp2 | temp3;

   temp2 = (x >> 8) & mask1;
   temp3 = (x << 8) & (~mask1);
   x = temp2 | temp3;

   temp2 = (x >> 4) & mask2;
   temp3 = (x << 4) & (~mask2);
   x = temp2 | temp3;
   return x;
}
/* 
 * bitFilter - Generate a mask consisting of all 1's and filter input with it.
 * Examples: bitFilter(0xFF00, 11, 4) = 0x0F00,
 * bitFilter(0x2A00, 13, 9) = 0x2A00,
 * bitFilter(0x1300, 4, 2) = 0
 * Assume 0 <= lowbit <= 31, and 0 <= highbit <= 31
 * If lowbit > highbit, then mask should be all 0's
 *   Legal ops: & | << >>
 *   Max ops: 20
 *   Rating: 1
 */
int bitFilter(int input, int highbit, int lowbit) {
   int highmask = 1 << highbit;
   highmask |= (highmask >> 1);
   highmask |= (highmask >> 2);
   highmask |= (highmask >> 4);
   highmask |= (highmask >> 8);
   highmask |= (highmask >> 16);

   input &= highmask;
   input = ((input >> lowbit) << lowbit);
   return input;
}
/*
 * addAndDivideBy4 - adds two numbers and divide by 4 (round toward 0). But when overflow occurs
 *          while adding two numbers, returns the first operand.
 *   Examples: addAndDivideBy4(1073741824,1073741824) = 1073741824
 *             addAndDivideBy4(-2147483648,-1) = -2147483648
 *             addAndDivideBy4(32,9) = 10
 *             addAndDivideBy4(-22,9) = -3
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 20
 *   Rating: 1
 */
int addAndDivideBy4(int x, int y) {
   int signX = (x >> 31);
   int signY = (y >> 31);
   int sum = x + y;
   int signSum = (sum >> 31);
   int overflow = (signX ^ ~signY) & (signX ^ signSum); // 11...1 if overflow, 00...0 if not
   int divideByFour = (sum >> 2) + !(!(signSum & (sum & 3)));
   
   return (overflow & x) + (~overflow & divideByFour);
}
/* 
 * numZerosFirst - returns count of number of continuous 0's from first bits
 *   Example: numZerosFirst(0) = 32
 *   Example: numZerosFirst(0x80000000) = 0
 *   Example: numZerosFirst(0x40000000) = 1
 *   Example: numZerosFirst(0x00008000) = 16
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 50
 *   Rating: 1 
 */
int numZerosFirst(int x) {
   int res = 0;
   int hasSixteen = 0;
   int hasEight = 0;
   int hasFour = 0;
   int hasTwo = 0;
   int hasOne = 0;
   hasSixteen = !(x & (((0xFF << 8) + 0xFF) << 16)) << 4;
   res += hasSixteen;
   x <<= hasSixteen;
   hasEight = !(x & (0xFF << 24)) << 3;
   res += hasEight;
   x <<= hasEight;
   hasFour = !(x & (0xF << 28)) << 2;
   res += hasFour;
   x <<= hasFour;
   hasTwo = !(x & (0x3 << 30)) << 1;
   res += hasTwo;
   x <<= hasTwo;
   hasOne = !(x & (1 << 31));
   res += hasOne;
   x <<= hasOne;
   hasOne = !(x & (1 << 31));
   res += hasOne;
   return res;
}
/* 
 * absFloat - Return bit-level equivalent of absolute value of f for
 *   floating point argument f.
 *   Both the argument and result are passed as unsigned int's, but
 *   they are to be interpreted as the bit-level representations of
 *   single-precision floating point values.
 *   When argument is NaN, return argument..
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 10
 *   Rating: 1
 */
unsigned absFloat(unsigned uf) {
   unsigned abs = uf & 0x7FFFFFFF;
   int mask = 0x7F800000;
   int isNan = ((mask & uf) == mask) && !!(uf & 0x7FFFFF);
   return isNan ? uf : abs;
}
/* 
 * castFloat2Int - Return bit-level equivalent of expression (int) f
 *   for floating point argument f.
 *   Argument is passed as unsigned int, but
 *   it is to be interpreted as the bit-level representation of a
 *   single-precision floating point value.
 *   Anything out of range (including NaN and infinity) should return
 *   0x80000000u.
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 30
 *   Rating: 1
 */
int castFloat2Int(unsigned uf) {
   int expo = (uf >> 23) & 0xFF;
   int fraction = (uf & 0x7FFFFF) | 0x800000;
   int sign = uf >> 31;

   if(expo >= 157) return 0x80000000u;
   if(expo <= 126) return 0;
   if(expo <= 150) fraction >>= (150 - expo);
   else fraction <<= (expo - 150);

   return sign ? (~fraction + 1) : fraction;
}
/* 
 * compareFloat - Compute f < g for floating point arguments f and g.
 *   Both the arguments are passed as unsigned int's, but
 *   they are to be interpreted as the bit-level representations of
 *   single-precision floating point values.
 *   If either argument is NaN, return 0.
 *   +0 and -0 are considered equal.
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 30
 *   Rating: 1
 */
int compareFloat(unsigned uf, unsigned ug) {
   int signF = uf >> 31;
   int expF = (uf >> 23) & 0xFF;
   int fractionF = uf & 0x7FFFFF;
   int signG = ug >> 31;
   int expG = (ug >> 23) & 0xFF;
   int fractionG = ug & 0x7FFFFF;
   int result = 0;

   if(!(expF | fractionF | expG | fractionG)) return 0;
   if(((expF == 0xFF) && (fractionF != 0)) || ((expG == 0xFF) && (fractionG != 0))) return 0;
   if(signF != signG) return !(signG & 1);
   if(uf == ug) return 0;
   if(expF != expG) result = (expG > expF);
   else{
      result = (fractionG > fractionF);
   }
   return result ^ (signF & 1);
}
