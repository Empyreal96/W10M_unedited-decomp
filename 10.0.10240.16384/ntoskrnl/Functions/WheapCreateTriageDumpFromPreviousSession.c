// WheapCreateTriageDumpFromPreviousSession 
 
int __fastcall WheapCreateTriageDumpFromPreviousSession(int a1)
{
  int v1; // r7
  unsigned int v2; // r1
  signed int v3; // r1
  int v4; // r6
  int v5; // r5
  int v6; // r8
  unsigned int v7; // r2
  int v8; // r3
  unsigned __int8 v9; // r5
  unsigned int v10; // r1

  v1 = 0;
  __dmb(0xBu);
  do
  {
    v2 = __ldrex(&WheapTriageDumpCreation);
    v3 = v2 + 1;
  }
  while ( __strex(v3, &WheapTriageDumpCreation) );
  __dmb(0xBu);
  if ( v3 > 1 )
    return -1073741823;
  v4 = WheapCreateLiveTriageDump(a1);
  if ( v4 >= 0 )
  {
    v5 = KeAbPreAcquire((unsigned int)&WheapTriageDumpLock, 0, 0);
    v6 = KfRaiseIrql(1);
    do
      v7 = __ldrex((unsigned __int8 *)&WheapTriageDumpLock);
    while ( __strex(v7 & 0xFE, (unsigned __int8 *)&WheapTriageDumpLock) );
    __dmb(0xBu);
    if ( (v7 & 1) == 0 )
      ExpAcquireFastMutexContended((int)&WheapTriageDumpLock, v5);
    if ( v5 )
      *(_BYTE *)(v5 + 14) |= 1u;
    dword_619804 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    dword_61981C = v6;
    __dmb(0xBu);
    WheapTriageDumpGenerated = 1;
    v8 = (unsigned __int8)WheapCrashDumpInitialized;
    __dmb(0xBu);
    if ( v8 )
    {
      v1 = 1;
      __dmb(0xBu);
      WheapTriageDumpReported = 1;
    }
    dword_619804 = 0;
    v9 = dword_61981C;
    __dmb(0xBu);
    do
      v10 = __ldrex((unsigned int *)&WheapTriageDumpLock);
    while ( !v10 && __strex(1u, (unsigned int *)&WheapTriageDumpLock) );
    if ( v10 )
      ExpReleaseFastMutexContended((unsigned int *)&WheapTriageDumpLock, v10);
    KfLowerIrql(v9);
    KeAbPostRelease((unsigned int)&WheapTriageDumpLock);
    if ( v1 )
    {
      v4 = WheapWriteTriageDump(WheapTriageDump, WheapTriageDumpLength);
      ExFreePoolWithTag(WheapTriageDump);
      WheapTriageDump = 0;
      WheapTriageDumpLength = 0;
    }
  }
  return v4;
}
