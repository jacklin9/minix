#include "syslib.h"

PUBLIC int sys_memset(char c, phys_bytes base, phys_bytes bytes)
{
/* Zero a block of data.  */
  message mess;

  if (bytes == 0L) return(OK);

  mess.MEM_CHAR = c;
  mess.MEM_PTR = (char *) base;
  mess.MEM_COUNT   = bytes;

  return(_taskcall(SYSTASK, SYS_MEMSET, &mess));
}

