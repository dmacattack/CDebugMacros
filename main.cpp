#include "DBG_MACROS.hpp"

int main(int argc, char *argv[] )
{

   // test out the dbg macros, new lines are implied
   DBG_MSG("hello world ");
   DBG_MSG("One argument 0x%X ", 0xDEADBEEF);
   DBG_WRN("hello world int %d string = %s float = %0.2f ", 44, "mondays eh? ", 99.233);
   // additional new lines are permitted
   DBG_ERR("---- the sky is falling ---- \n\n\n\n");

   return 0;
}
