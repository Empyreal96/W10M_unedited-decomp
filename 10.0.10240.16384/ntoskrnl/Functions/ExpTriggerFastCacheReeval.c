// ExpTriggerFastCacheReeval 
 
// local variable allocation has failed, the output may be wrong!
int ExpTriggerFastCacheReeval()
{
  int v0; // r7
  unsigned int v1; // r8
  unsigned int v2; // r5 OVERLAPPED
  unsigned int v3; // r6 OVERLAPPED
  int result; // r0
  unsigned __int64 v5; // r2
  unsigned int v6; // [sp+8h] [bp-20h] BYREF
  int v7; // [sp+Ch] [bp-1Ch]

  KeQueryTickCount((int *)&v6);
  v1 = v6;
  v0 = v7;
  *(_QWORD *)&v2 = ExpPreviousReevalTriggerTickCount;
  if ( !ExpPreviousReevalTriggerTickCount
    || (result = KeQueryTimeIncrement(),
        (__int64)((__PAIR64__(v0, v1) - __PAIR64__(v3, v2)) * (unsigned int)result) >= 36000000000i64) )
  {
    result = EtwRegister((int)MS_Windows_WSServiceStartServiceTrigger_Provider, 0, 0);
    if ( result >= 0 )
    {
      if ( EtwWrite(v6, v7, (int)WSServiceStartServiceTrigger, 0) >= 0 )
      {
        __dmb(0xBu);
        do
          v5 = __ldrexd((unsigned __int64 *)&ExpPreviousReevalTriggerTickCount);
        while ( __strexd(__PAIR64__(v0, v1), (unsigned __int64 *)&ExpPreviousReevalTriggerTickCount) );
        __dmb(0xBu);
      }
      result = EtwUnregister(v6);
    }
  }
  return result;
}
