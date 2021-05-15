// IopDebugPrint 
 
int IopDebugPrint(int a1, int a2, ...)
{
  va_list varg_r2; // [sp+20h] [bp+10h] BYREF

  va_start(varg_r2, a2);
  vDbgPrintExWithPrefixInternal((int)"NTOSPNP:", 32, a1, a2, (int)varg_r2);
  return a1;
}
