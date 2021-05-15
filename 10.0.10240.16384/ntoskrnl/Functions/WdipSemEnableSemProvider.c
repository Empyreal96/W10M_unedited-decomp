// WdipSemEnableSemProvider 
 
int WdipSemEnableSemProvider()
{
  unsigned int v0; // r3
  unsigned int v1; // r0
  int result; // r0
  int v3; // r3
  unsigned int v4; // r4

  __dmb(0xBu);
  v0 = WdipDiagLoggerId;
  do
    v1 = __ldrex((unsigned int *)&WdipDiagLoggerId);
  while ( __strex(v0, (unsigned int *)&WdipDiagLoggerId) );
  __dmb(0xBu);
  result = WdipSemEnableDisableTrace((unsigned __int16)v1, (int)WDI_SEM_PROVIDER, 0, 2, 0, 2, 0, 1);
  if ( result >= 0 )
  {
    __dmb(0xBu);
    v3 = WdipContextLoggerId;
    do
      v4 = __ldrex((unsigned int *)&WdipContextLoggerId);
    while ( __strex(v3, (unsigned int *)&WdipContextLoggerId) );
    __dmb(0xBu);
    result = WdipSemEnableDisableTrace((unsigned __int16)v4, (int)WDI_SEM_PROVIDER, 0, v3, 0, 1, 0, 1);
    if ( result >= 0 && !WdipSemRegHandle )
    {
      result = EtwRegister((int)WDI_SEM_PROVIDER, 0, 0);
      if ( result >= 0 )
        WdipSemRegHandle = 0i64;
    }
  }
  return result;
}
