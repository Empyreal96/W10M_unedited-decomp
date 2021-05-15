// PfGenerateTrace 
 
int __fastcall PfGenerateTrace(int *a1, int a2)
{
  unsigned int v4; // r2
  int v5; // r0
  int v6; // r5
  unsigned int v7; // r2
  int v8; // r5
  unsigned int v9; // r1
  int v10; // r0
  unsigned int v11; // r1
  int v12; // r3
  unsigned int *v13; // r2
  unsigned int v14; // r1
  unsigned int v15; // r5
  unsigned int v16; // r1
  int v17; // r0
  unsigned int v18; // r1
  __int16 v19; // r3
  unsigned int *v20; // r2
  unsigned int v21; // r1
  unsigned int v23[8]; // [sp+10h] [bp-20h] BYREF

  v4 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  --*(_WORD *)(v4 + 308);
  v5 = KeAbPreAcquire((unsigned int)&PfTGlobals, 0, 0);
  v6 = v5;
  do
    v7 = __ldrex((unsigned __int8 *)&PfTGlobals);
  while ( __strex(v7 | 1, (unsigned __int8 *)&PfTGlobals) );
  __dmb(0xBu);
  if ( (v7 & 1) != 0 )
    ExfAcquirePushLockExclusiveEx(&PfTGlobals, v5, (unsigned int)&PfTGlobals);
  if ( v6 )
    *(_BYTE *)(v6 + 14) |= 1u;
  if ( *a1 )
  {
    if ( !a2 )
    {
      __dmb(0xBu);
      v13 = (unsigned int *)(a1 + 13);
      do
        v14 = __ldrex(v13);
      while ( __strex(v14 + 1, v13) );
      __dmb(0xBu);
    }
    KeResetEvent((int)(a1 + 9));
    KeSetEvent((int)(a1 + 5), 0, 0);
    v15 = *a1;
    ObfReferenceObject(*a1);
    __dmb(0xBu);
    do
      v16 = __ldrex(&PfTGlobals);
    while ( __strex(v16 - 1, &PfTGlobals) );
    if ( (v16 & 2) != 0 && (v16 & 4) == 0 )
      ExfTryToWakePushLock(&PfTGlobals);
    v17 = KeAbPostRelease((unsigned int)&PfTGlobals);
    v18 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    v19 = *(_WORD *)(v18 + 0x134) + 1;
    *(_WORD *)(v18 + 308) = v19;
    if ( !v19 && *(_DWORD *)(v18 + 100) != v18 + 100 && !*(_WORD *)(v18 + 310) )
      KiCheckForKernelApcDelivery(v17);
    v23[0] = (unsigned int)(a1 + 9);
    v23[1] = v15;
    KeWaitForMultipleObjects(2u, v23, 1, 0, 0, 0, 0, 0);
    ObfDereferenceObject(v15);
    if ( !a2 )
    {
      __dmb(0xBu);
      v20 = (unsigned int *)(a1 + 13);
      do
        v21 = __ldrex(v20);
      while ( __strex(v21 - 1, v20) );
      __dmb(0xBu);
    }
    v8 = 0;
  }
  else
  {
    v8 = -1073741177;
    __dmb(0xBu);
    do
      v9 = __ldrex(&PfTGlobals);
    while ( __strex(v9 - 1, &PfTGlobals) );
    if ( (v9 & 2) != 0 && (v9 & 4) == 0 )
      ExfTryToWakePushLock(&PfTGlobals);
    v10 = KeAbPostRelease((unsigned int)&PfTGlobals);
    v11 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    v12 = (__int16)(*(_WORD *)(v11 + 0x134) + 1);
    *(_WORD *)(v11 + 308) = v12;
    if ( !v12 && *(_DWORD *)(v11 + 100) != v11 + 100 && !*(_WORD *)(v11 + 310) )
      KiCheckForKernelApcDelivery(v10);
  }
  return v8;
}
