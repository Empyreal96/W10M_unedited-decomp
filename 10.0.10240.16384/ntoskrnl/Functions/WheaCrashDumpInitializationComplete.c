// WheaCrashDumpInitializationComplete 
 
int WheaCrashDumpInitializationComplete()
{
  int v0; // r6
  int v1; // r7
  int v2; // r5
  int v3; // r0
  unsigned int v4; // r2
  int v6; // r3
  unsigned __int8 v7; // r5
  unsigned int v8; // r1
  int v9; // r3

  v0 = 0;
  v1 = 0;
  v2 = KeAbPreAcquire((unsigned int)&WheapTriageDumpLock, 0, 0);
  v3 = KfRaiseIrql(1);
  do
    v4 = __ldrex((unsigned __int8 *)&WheapTriageDumpLock);
  while ( __strex(v4 & 0xFE, (unsigned __int8 *)&WheapTriageDumpLock) );
  __dmb(0xBu);
  if ( (v4 & 1) == 0 )
    return sub_81B85C(v3);
  if ( v2 )
    *(_BYTE *)(v2 + 14) |= 1u;
  dword_619804 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  dword_61981C = v3;
  __dmb(0xBu);
  WheapCrashDumpInitialized = 1;
  v6 = (unsigned __int8)WheapTriageDumpGenerated;
  __dmb(0xBu);
  if ( v6 )
  {
    v9 = (unsigned __int8)WheapTriageDumpReported;
    __dmb(0xBu);
    if ( !v9 )
    {
      v0 = 1;
      __dmb(0xBu);
      WheapTriageDumpReported = 1;
    }
  }
  dword_619804 = 0;
  v7 = dword_61981C;
  __dmb(0xBu);
  do
    v8 = __ldrex((unsigned int *)&WheapTriageDumpLock);
  while ( !v8 && __strex(1u, (unsigned int *)&WheapTriageDumpLock) );
  if ( v8 )
    ExpReleaseFastMutexContended((unsigned int *)&WheapTriageDumpLock, v8);
  KfLowerIrql(v7);
  KeAbPostRelease((unsigned int)&WheapTriageDumpLock);
  if ( v0 )
  {
    v1 = WheapWriteTriageDump(WheapTriageDump, WheapTriageDumpLength);
    ExFreePoolWithTag(WheapTriageDump);
    WheapTriageDump = 0;
    WheapTriageDumpLength = 0;
  }
  return v1;
}
