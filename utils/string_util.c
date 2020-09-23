//
//  string_util.c
//  arithmetic
//
//  Created by 我叫城北徐公° on 2020/9/23.
//  Copyright © 2020 alex. All rights reserved.
//

#include "string_util.h"

#include <string.h>
#include <stdlib.h>
#include <stdio.h>
 
//字符串替换函数
char * strreplace(char const * const original,
    char const * const pattern, char const * const replacement)
{
  size_t const replen = strlen(replacement);
  size_t const patlen = strlen(pattern);
  size_t const orilen = strlen(original);
 
  size_t patcnt = 0;
  const char * oriptr;
  const char * patloc;
 
  // find how many times the pattern occurs in the original string
  for (oriptr = original; (patloc = strstr(oriptr, pattern)); oriptr = patloc + patlen)
  {
    patcnt++;
  }
 
  {
    // allocate memory for the new string
    size_t const retlen = orilen + patcnt * (replen - patlen);
    char * const returned = (char *) malloc( sizeof(char) * (retlen + 1) );
 
    if (returned != NULL)
    {
      // copy the original string,
      // replacing all the instances of the pattern
      char * retptr = returned;
      for (oriptr = original; (patloc = strstr(oriptr, pattern)); oriptr = patloc + patlen)
      {
        size_t const skplen = patloc - oriptr;
        // copy the section until the occurence of the pattern
        strncpy(retptr, oriptr, skplen);
        retptr += skplen;
        // copy the replacement
        strncpy(retptr, replacement, replen);
        retptr += replen;
      }
      // copy the rest of the string.
      strcpy(retptr, oriptr);
    }
    return returned;
  }
}
 
 
//https://github.com/CurryGuy/lua-player-plus/blob/7cb0f6056ead933289cf7dacffd6ce54243630b7/lpp-c%2B%2B/Libs/strreplace.c
char *strreplace2(const char *src, const char *from, const char *to)
{
   size_t size    = strlen(src) + 1;
   size_t fromlen = strlen(from);
   size_t tolen   = strlen(to);
   char *value = malloc(size);
   char *dst = value;
   if ( value != NULL )
   {
      for ( ;; )
      {
         const char *match = strstr(src, from);
         if ( match != NULL )
         {
            size_t count = match - src;
            char *temp;
            size += tolen - fromlen;
            temp = realloc(value, size);
            if ( temp == NULL )
            {
               free(value);
               return NULL;
            }
            dst = temp + (dst - value);
            value = temp;
            memmove(dst, src, count);
            src += count;
            dst += count;
            memmove(dst, to, tolen);
            src += fromlen;
            dst += tolen;
         }
         else /* No match found. */
         {
            strcpy(dst, src);
            break;
         }
      }
   }
   return value;
}
//
////cl strreplace.c
////gcc strreplace.c
//int main(int argc, char const *argv[])
//{
//
//    char* data=strreplace("23232320545011","0","");
//    printf("%s\n", data);
//    return 0;
//}
