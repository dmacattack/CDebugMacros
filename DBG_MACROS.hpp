#ifndef __DBG_MACROS_H__
#define __DBG_MACROS_H__

//----------------------------------------------------------
// includes
//----------------------------------------------------------
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>

//----------------------------------------------------------
// color macros
//----------------------------------------------------------
#define TXT_RED     "\x1b[31m"
#define TXT_GREEN   "\x1b[32m"
#define TXT_YELLOW  "\x1b[33m"
#define TXT_BLUE    "\x1b[34m"
#define TXT_MAGENTA "\x1b[35m"
#define TXT_CYAN    "\x1b[36m"
#define TXT_RESET   "\x1b[0m"

//----------------------------------------------------------
// enums
//----------------------------------------------------------
enum eDBG_TAG
{
   eDBGMSG_TAG,
   eDBGWRN_TAG,
   eDBGERR_TAG
};

//----------------------------------------------------------
// function prototypes
//----------------------------------------------------------
void printMsg(const int tag, const char* file, const char* func, const char *fmt, ...);
void printMsgNoNL(const int tag, const char* file, const char* func, const char *fmt, ...);
const char* getTag(const int tag);
void setColor(const int tag);

//----------------------------------------------------------
// DEBUG MACROS
//----------------------------------------------------------
#define DBG_MSG(...) printMsg(eDBGMSG_TAG, __FILE__, __FUNCTION__, __VA_ARGS__)
#define DBG_MSG_NO_NL(...) printMsgNoNL(eDBGMSG_TAG, __FILE__, __FUNCTION__, __VA_ARGS__)
#define DBG_WRN(...) printMsg(eDBGWRN_TAG, __FILE__, __FUNCTION__, __VA_ARGS__)
#define DBG_WRN_NO_NL(...) printMsgNoNL(eDBGWRN_TAG, __FILE__, __FUNCTION__, __VA_ARGS__)
#define DBG_ERR(...) printMsg(eDBGERR_TAG, __FILE__, __FUNCTION__, __VA_ARGS__)
#define DBG_ERR_NO_NL(...) printMsgNoNL(eDBGERR_TAG, __FILE__, __FUNCTION__, __VA_ARGS__)

//----------------------------------------------------------
// printMsg
// function that prints the tag, file, function, 
// and message to the console in the appropriate color
//----------------------------------------------------------
void printMsg(const int tag, const char* file, const char* func, const char *fmt, ...)
{
   // set the color
   setColor(tag);
   
   // print the message information, type, file/funct/etc
   fprintf( stderr, "%s - %s::%s ", getTag(tag), file, func);
   
   // print the variadic args
   va_list args;
   va_start(args, fmt);
   vfprintf(stderr, fmt, args); 
   va_end(args);
   
   // send new line and reset the color
   fprintf(stderr, "%s \n", TXT_RESET);
}

//----------------------------------------------------------
// printMsgNoNL
// function that prints the tag, file, function, 
// and message to the console in the appropriate color
// but omits the newLine character
//----------------------------------------------------------
void printMsgNoNL(const int tag, const char* file, const char* func, const char *fmt, ...)
{
   // set the color
   setColor(tag);
   
   // print the message information, type, file/funct/etc
   fprintf( stderr, "%s - %s::%s ", getTag(tag), file, func);
   
   // print the variadic args
   va_list args;
   va_start(args, fmt);
   vfprintf(stderr, fmt, args); 
   va_end(args);
   
   // reset the color
   fprintf(stderr, "%s", TXT_RESET);
}

//----------------------------------------------------------
// getTag
// returns the string of the dbg msg type
//----------------------------------------------------------
const char* getTag(const int tag)
{
   return ( tag == eDBGMSG_TAG ? "[M]" :
          ( tag == eDBGWRN_TAG ? "[W]" :
          ( tag == eDBGERR_TAG ? "[E]" : "[?]" )));
}

//----------------------------------------------------------
// setColor
// sets the color on the console
//----------------------------------------------------------
void setColor(const int tag)
{
   switch( tag )
   {
      case eDBGMSG_TAG:
         fprintf( stderr, "%s", TXT_GREEN );
      break;
      
      case eDBGWRN_TAG:
         fprintf( stderr, "%s", TXT_BLUE );
      break;
      
      case eDBGERR_TAG:
         fprintf( stderr, "%s", TXT_RED );
      break;
      
      default:
         fprintf( stderr, "%s", TXT_RESET );
      break;
   }
}

#endif /* __DBG_MACROS_H__ */
