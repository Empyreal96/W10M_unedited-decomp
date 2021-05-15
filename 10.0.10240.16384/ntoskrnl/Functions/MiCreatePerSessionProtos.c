// MiCreatePerSessionProtos 
 
int __fastcall MiCreatePerSessionProtos(int *a1, unsigned int a2, int a3, unsigned int a4)
{
  int v6; // r8
  unsigned int v7; // r4
  int v8; // r2
  unsigned __int8 *v9; // r5
  int v10; // r0
  int v11; // r6
  unsigned int v12; // r2
  int v13; // r7
  int v14; // r6
  _DWORD *v15; // r0
  _DWORD *v16; // r2
  unsigned int v17; // r1
  int v18; // r0
  __int16 v19; // r3
  _DWORD *v21; // r2
  int v22; // r3
  unsigned int v23; // r1
  int v24; // r0
  int v25; // r3
  unsigned int v26[8]; // [sp+8h] [bp-20h] BYREF

  v26[0] = a4;
  if ( a2 >= 0x7FFFF && a2 != -1 )
    return -1073741618;
  v7 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v8 = *a1;
  --*(_WORD *)(v7 + 310);
  v9 = (unsigned __int8 *)(v8 + 28);
  v10 = KeAbPreAcquire(v8 + 28, 0, 0);
  v11 = v10;
  do
    v12 = __ldrex(v9);
  while ( __strex(v12 | 1, v9) );
  __dmb(0xBu);
  if ( (v12 & 1) != 0 )
    ExfAcquirePushLockExclusiveEx(v9, v10, (unsigned int)v9);
  if ( v11 )
    *(_BYTE *)(v11 + 14) |= 1u;
  v13 = (int)(a1 + 20);
  v14 = (int)(a1 + 20);
  if ( a1 == (int *)-80 )
  {
LABEL_17:
    __dmb(0xBu);
    do
      v17 = __ldrex((unsigned int *)v9);
    while ( __strex(v17 - 1, (unsigned int *)v9) );
    if ( (v17 & 2) != 0 && (v17 & 4) == 0 )
      ExfTryToWakePushLock((unsigned int *)v9);
    v18 = KeAbPostRelease((unsigned int)v9);
    v19 = *(_WORD *)(v7 + 310) + 1;
    *(_WORD *)(v7 + 310) = v19;
    if ( !v19 && *(_DWORD *)(v7 + 100) != v7 + 100 )
      KiCheckForKernelApcDelivery(v18);
    return 0;
  }
  while ( (*(_WORD *)(v14 + 18) & 2) == 0 )
  {
LABEL_16:
    v14 = *(_DWORD *)(v14 + 8);
    if ( !v14 )
      goto LABEL_17;
  }
  v15 = MiLocateSessionProtosInSubsection(v14, a2);
  v26[0] = (unsigned int)v15;
  if ( v15 )
  {
    ++v15[5];
    goto LABEL_16;
  }
  v6 = MiAllocatePerSessionProtos(v14, 0, 0, 0, v26);
  if ( v6 >= 0 )
  {
    v16 = (_DWORD *)v26[0];
    *(_DWORD *)(v26[0] + 12) = a2;
    MiUpdatePerSessionProto((int)a1, v14, v16, 1);
    goto LABEL_16;
  }
  for ( ; v13 != v14; v13 = *(_DWORD *)(v13 + 8) )
  {
    if ( (*(_WORD *)(v13 + 18) & 2) != 0 )
    {
      v21 = MiLocateSessionProtosInSubsection(v13, a2);
      v22 = v21[5];
      v26[0] = (unsigned int)v21;
      v21[5] = --v22;
      if ( !v22 )
      {
        MiUpdatePerSessionProto((int)a1, v13, v21, 0);
        MiReturnCommit((int)MiSystemPartition, *(_DWORD *)(v13 + 28));
        ExFreePoolWithTag(*(_DWORD *)(v26[0] + 16));
        ExFreePoolWithTag(v26[0]);
      }
    }
  }
  __dmb(0xBu);
  do
    v23 = __ldrex((unsigned int *)v9);
  while ( __strex(v23 - 1, (unsigned int *)v9) );
  if ( (v23 & 2) != 0 && (v23 & 4) == 0 )
    ExfTryToWakePushLock((unsigned int *)v9);
  v24 = KeAbPostRelease((unsigned int)v9);
  v25 = (__int16)(*(_WORD *)(v7 + 310) + 1);
  *(_WORD *)(v7 + 310) = v25;
  if ( !v25 && *(_DWORD *)(v7 + 100) != v7 + 100 )
    KiCheckForKernelApcDelivery(v24);
  return v6;
}
