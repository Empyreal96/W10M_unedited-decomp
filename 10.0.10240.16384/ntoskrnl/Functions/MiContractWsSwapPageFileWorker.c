// MiContractWsSwapPageFileWorker 
 
int __fastcall MiContractWsSwapPageFileWorker(int a1)
{
  int v2; // r4
  unsigned int v3; // r8
  unsigned __int8 *v4; // r7
  int v5; // r0
  int v6; // r4
  unsigned int v7; // r2
  int v8; // r6
  unsigned int v9; // r5
  unsigned int v10; // r1
  int v11; // r6
  unsigned int v12; // r0
  _DWORD *v13; // r1
  unsigned int v14; // r1
  int v15; // r0
  __int16 v16; // r3
  unsigned int *v17; // r2
  int result; // r0
  unsigned int v19; // r1
  int v20; // [sp+8h] [bp-60h]
  _DWORD var58[24]; // [sp+10h] [bp-58h] BYREF

  v2 = *(_DWORD *)(a1 + 4 * MiWsSwapPageFileNumber(a1) + 3600);
  v3 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  memset(var58, 0, 56);
  var58[3] = a1;
  var58[4] = -1;
  LOBYTE(var58[11]) = *(_WORD *)(v2 + 96) & 0xF;
  var58[5] = 0x10000;
  LOWORD(var58[6]) = 0;
  BYTE2(var58[6]) = 4;
  var58[7] = 0;
  var58[9] = &var58[8];
  var58[8] = &var58[8];
  --*(_WORD *)(v3 + 310);
  v4 = (unsigned __int8 *)(a1 + 652);
  v5 = KeAbPreAcquire(a1 + 652, 0, 0);
  v6 = v5;
  do
    v7 = __ldrex(v4);
  while ( __strex(v7 | 1, v4) );
  __dmb(0xBu);
  if ( (v7 & 1) != 0 )
    ExfAcquirePushLockExclusiveEx((_DWORD *)(a1 + 652), v5, a1 + 652);
  if ( v6 )
    *(_BYTE *)(v6 + 14) |= 1u;
  v8 = KfRaiseIrql(2);
  v20 = v8;
  if ( (dword_682604 & 0x210000) != 0 )
  {
    v9 = 192;
    ExpAcquireSpinLockExclusiveAtDpcLevelInstrumented((unsigned int *)&dword_632D80);
  }
  else
  {
    do
      v10 = __ldrex((unsigned __int8 *)&dword_632D80 + 3);
    while ( __strex(v10 | 0x80, (unsigned __int8 *)&dword_632D80 + 3) );
    __dmb(0xBu);
    v9 = 0xC0u;
    if ( v10 >> 7 )
      ExpWaitForSpinLockExclusiveAndAcquire((unsigned int *)&dword_632D80);
    while ( 1 )
    {
      v11 = dword_632D80;
      if ( (dword_632D80 & 0xBFFFFFFF) == 0x80000000 )
        break;
      if ( (dword_632D80 & 0x40000000) == 0 )
      {
        do
          v12 = __ldrex((unsigned int *)&dword_632D80);
        while ( v12 == v11 && __strex(v11 | 0x40000000, (unsigned int *)&dword_632D80) );
        __dmb(0xBu);
      }
      __dmb(0xAu);
      __yield();
    }
    v8 = v20;
  }
  v13 = *(_DWORD **)(a1 + 804);
  var58[1] = a1 + 800;
  var58[2] = v13;
  if ( *v13 != a1 + 800 )
    __fastfail(3u);
  *v13 = &var58[1];
  *(_DWORD *)(a1 + 804) = &var58[1];
  if ( (dword_682604 & 0x10000) != 0 )
  {
    ExpReleaseSpinLockExclusiveFromDpcLevelInstrumented(&MiState[v9], var58[23]);
  }
  else
  {
    __dmb(0xBu);
    MiState[v9] = 0;
  }
  KfLowerIrql(v8);
  KeReleaseSemaphoreEx(a1 + 780, 0, 1, 1, 1);
  KeWaitForSingleObject((unsigned int)&var58[6], 0, 0, 0, 0);
  __dmb(0xBu);
  do
    v14 = __ldrex((unsigned int *)v4);
  while ( __strex(v14 - 1, (unsigned int *)v4) );
  if ( (v14 & 2) != 0 && (v14 & 4) == 0 )
    ExfTryToWakePushLock((unsigned int *)(a1 + 652));
  v15 = KeAbPostRelease(a1 + 652);
  v16 = *(_WORD *)(v3 + 310) + 1;
  *(_WORD *)(v3 + 310) = v16;
  if ( !v16 && *(_DWORD *)(v3 + 100) != v3 + 100 )
    KiCheckForKernelApcDelivery(v15);
  v17 = (unsigned int *)(a1 + 648);
  result = 0;
  do
    v19 = __ldrex(v17);
  while ( __strex(0, v17) );
  return result;
}
