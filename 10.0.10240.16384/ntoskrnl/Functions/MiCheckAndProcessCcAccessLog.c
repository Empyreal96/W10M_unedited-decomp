// MiCheckAndProcessCcAccessLog 
 
int __fastcall MiCheckAndProcessCcAccessLog(int result, unsigned int a2, int a3)
{
  int v3; // r5

  v3 = result;
  if ( dword_634480 )
  {
    do
      result = __ldrex((unsigned int *)&dword_634480);
    while ( __strex(0, (unsigned int *)&dword_634480) );
    if ( result )
    {
      if ( __PAIR64__(a2, v3) - *(_QWORD *)(result + 16) > PfKernelGlobals || a3 )
        result = MiQueuePageAccessLog();
      else
        result = MiReturnCcAccessLog();
    }
  }
  return result;
}
