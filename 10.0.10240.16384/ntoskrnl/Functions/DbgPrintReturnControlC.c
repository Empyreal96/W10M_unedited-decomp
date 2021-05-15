// DbgPrintReturnControlC 
 
int DbgPrintReturnControlC(int a1, ...)
{
  va_list varg_r1; // [sp+14h] [bp+Ch] BYREF

  va_start(varg_r1, a1);
  return vDbgPrintExWithPrefixInternal((int)&byte_5CB13F, 101, 0, a1, (int)varg_r1);
}
