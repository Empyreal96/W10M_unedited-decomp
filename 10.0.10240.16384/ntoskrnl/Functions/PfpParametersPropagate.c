// PfpParametersPropagate 
 
int __fastcall PfpParametersPropagate(_DWORD *a1)
{
  unsigned int v2; // r6
  unsigned int v3; // r2
  int v4; // r0
  int v5; // r1
  int v6; // r5
  unsigned int v7; // r2
  int v8; // r1
  int v9; // r1
  unsigned int v10; // r1
  unsigned int v11; // r1
  int result; // r0
  unsigned int v13; // r1
  __int16 v14; // r3

  v2 = 0;
  v3 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  --*(_WORD *)(v3 + 308);
  v4 = KeAbPreAcquire((unsigned int)&PfTGlobals, 0, 0);
  v6 = v4;
  do
    v7 = __ldrex((unsigned __int8 *)&PfTGlobals);
  while ( __strex(v7 | 1, (unsigned __int8 *)&PfTGlobals) );
  __dmb(0xBu);
  if ( (v7 & 1) != 0 )
    ExfAcquirePushLockExclusiveEx(&PfTGlobals, v4, (unsigned int)&PfTGlobals);
  if ( v6 )
    *(_BYTE *)(v6 + 14) |= 1u;
  if ( (dword_643904 & 1) != 0 && a1[12] != dword_643A70 )
    v2 = 1;
  if ( (dword_643904 & 2) != 0 )
  {
    v5 = a1[11];
    if ( v5 != dword_643A78 )
      v2 |= 2u;
  }
  if ( (dword_643904 & 3) != 0 && (a1[9] & 1) == 0 || v2 )
  {
    PfTCleanup((int)&PfTGlobals, v5);
    PfTInitialize(&PfTGlobals, v8, 1);
    PfTStart((int)&PfTGlobals, v9, v2);
  }
  if ( ((a1[9] & 2) != 0) != (dword_637340 & 1) )
  {
    if ( (a1[9] & 2) != 0 )
    {
      __dmb(0xBu);
      do
        v10 = __ldrex(&dword_637328[2]);
      while ( __strex(0, &dword_637328[2]) );
      __dmb(0xBu);
      dword_637340 |= 1u;
    }
    else
    {
      PfpRpShutdown(&dword_6372E0);
    }
  }
  __dmb(0xBu);
  do
    v11 = __ldrex(&PfTGlobals);
  while ( __strex(v11 - 1, &PfTGlobals) );
  if ( (v11 & 2) != 0 && (v11 & 4) == 0 )
    ExfTryToWakePushLock(&PfTGlobals);
  result = KeAbPostRelease((unsigned int)&PfTGlobals);
  v13 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v14 = *(_WORD *)(v13 + 0x134) + 1;
  *(_WORD *)(v13 + 308) = v14;
  if ( !v14 && *(_DWORD *)(v13 + 100) != v13 + 100 && !*(_WORD *)(v13 + 310) )
    result = KiCheckForKernelApcDelivery(result);
  return result;
}
