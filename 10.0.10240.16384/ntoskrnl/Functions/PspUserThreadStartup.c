// PspUserThreadStartup 
 
int PspUserThreadStartup()
{
  unsigned int *v0; // r0
  unsigned int v1; // r6
  int v2; // r4
  unsigned __int8 *v3; // r3
  unsigned int v4; // r2
  int v5; // r3
  int v6; // r5
  __int16 v7; // r3
  _DWORD *v8; // r8
  int v9; // r4
  int result; // r0
  unsigned __int8 *v11; // r3
  unsigned int v12; // r1
  _DWORD *v13; // r5
  int v14; // r4
  int v15; // r1
  unsigned int v16; // r2
  unsigned int v17; // r1
  _DWORD v18[10]; // [sp+18h] [bp-28h] BYREF

  v0 = (unsigned int *)KfLowerIrql(0);
  v1 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v2 = *(_DWORD *)(v1 + 0x74);
  if ( (*(_DWORD *)(v2 + 188) & 0x8000) == 0 )
  {
    __dmb(0xBu);
    v3 = (unsigned __int8 *)(v2 + 189);
    do
      v4 = __ldrex(v3);
    while ( __strex(v4 | 0x80, v3) );
    __dmb(0xBu);
    --*(_WORD *)(v1 + 308);
    __dmb(0xFu);
    v5 = *(_DWORD *)(v2 + 168);
    __dmb(0xBu);
    if ( (v5 & 1) != 0 )
    {
      v6 = KeAbPreAcquire(v2 + 168, 0, 0);
      ExfAcquirePushLockExclusiveEx((_DWORD *)(v2 + 168), v6, v2 + 168);
      if ( v6 )
        *(_BYTE *)(v6 + 14) |= 1u;
      v0 = ExfReleasePushLockExclusive((unsigned int *)(v2 + 168));
      if ( v6 )
        v0 = (unsigned int *)KeAbPostRelease(v2 + 168);
    }
    v7 = *(_WORD *)(v1 + 308) + 1;
    *(_WORD *)(v1 + 308) = v7;
    if ( !v7 && *(_DWORD *)(v1 + 100) != v1 + 100 && !*(_WORD *)(v1 + 310) )
      v0 = (unsigned int *)KiCheckForKernelApcDelivery((int)v0);
  }
  if ( (*(_DWORD *)(v1 + 960) & 2) == 0 )
    v0 = (unsigned int *)PspTerminateThreadByPointer((_DWORD *)v1, -1073741749, 1);
  v8 = *(_DWORD **)(v1 + 116);
  if ( (v8[184] & 1) != 0 )
  {
    result = DbgkCreateMinimalThread(v1);
  }
  else
  {
    v9 = *(_DWORD *)(v1 + 156);
    *(_DWORD *)(v9 + 196) = MmGetSessionLocaleId(v0);
    PspWriteTebIdealProcessor(v1, v1);
    result = DbgkCreateThread(v1);
    if ( (v8[48] & 0x80000) == 0 )
    {
      __dmb(0xBu);
      v11 = (unsigned __int8 *)v8 + 194;
      do
        v12 = __ldrex(v11);
      while ( __strex(v12 | 8, v11) );
      __dmb(0xBu);
      if ( !((unsigned __int8)(v12 & 8) >> 3) )
        result = PfProcessCreateNotification(v8, v8[73]);
    }
  }
  while ( !MEMORY[0xFFFF9330] )
  {
    KeQuerySystemTime(v18);
    v13 = (_DWORD *)((unsigned int)KeGetPcr() & 0xFFFFF000);
    v14 = ReadTimeStampCounter();
    result = ExGenRandom(1);
    v15 = v13[738];
    __dmb(0xBu);
    v16 = v18[0] ^ v13[928] ^ v14 ^ v13[932] ^ result ^ v15 ^ v18[1] ^ (unsigned int)v18;
    __dmb(0xBu);
    do
      v17 = __ldrex((unsigned int *)0xFFFF9330);
    while ( !v17 && __strex(v16, (unsigned int *)0xFFFF9330) );
    __dmb(0xBu);
  }
  if ( (*(_DWORD *)(v1 + 960) & 1) != 0 )
    return KeWaitForSingleObject(v1, 6, 1, 0, 0);
  if ( (v8[184] & 1) == 0 )
    result = PspInitializeThunkContext();
  return result;
}
