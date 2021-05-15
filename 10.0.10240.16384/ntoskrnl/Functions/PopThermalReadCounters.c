// PopThermalReadCounters 
 
int __fastcall PopThermalReadCounters(int a1, int a2, char a3, int a4, unsigned int *a5)
{
  unsigned int v6; // r4
  unsigned int v7; // r2
  int v8; // r0
  int v9; // r5
  unsigned int v10; // r2
  int v11; // r0
  int v12; // r1
  unsigned int v13; // r0
  unsigned int v14; // r2
  int v15; // r0
  unsigned int v16; // r1
  __int16 v17; // r3
  unsigned __int8 *v19; // r4
  unsigned int v20; // r2
  int v21; // r0
  int v22; // r5
  unsigned int v23; // r2
  int v24; // r1
  unsigned int v25; // r0
  unsigned int v26; // r2
  int v27; // r0
  unsigned int v28; // r1
  __int16 v29; // r3
  unsigned int v30[8]; // [sp+10h] [bp-20h] BYREF

  if ( (a3 & 1) != 0 && !*(_BYTE *)(a1 + 280) )
  {
    v6 = a1 + 320;
    v7 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    --*(_WORD *)(v7 + 308);
    v8 = KeAbPreAcquire(a1 + 320, 0, 0);
    v9 = v8;
    do
      v10 = __ldrex((unsigned __int8 *)v6);
    while ( __strex(v10 | 1, (unsigned __int8 *)v6) );
    __dmb(0xBu);
    if ( (v10 & 1) != 0 )
      ExfAcquirePushLockExclusiveEx((_DWORD *)v6, v8, v6);
    if ( v9 )
      *(_BYTE *)(v9 + 14) |= 1u;
    *(_DWORD *)(v6 + 4) = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    KeResetEvent(a1 + 344);
    v11 = *(_DWORD *)(a1 + 28);
    *(_DWORD *)(a1 + 160) = 0;
    IoCancelIrp(v11);
    if ( *(_DWORD *)(v6 + 4) )
      *(_DWORD *)(v6 + 4) = 0;
    __pld((void *)v6);
    v12 = *(_DWORD *)v6;
    v13 = *(_DWORD *)v6 - 16;
    if ( (*(_DWORD *)v6 & 0xFFFFFFF0) <= 0x10 )
      v13 = 0;
    if ( (v12 & 2) != 0 )
      goto LABEL_18;
    __dmb(0xBu);
    do
      v14 = __ldrex((unsigned int *)v6);
    while ( v14 == v12 && __strex(v13, (unsigned int *)v6) );
    if ( v14 != v12 )
LABEL_18:
      ExfReleasePushLock((_DWORD *)v6, v12);
    v15 = KeAbPostRelease(v6);
    v16 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    v17 = *(_WORD *)(v16 + 0x134) + 1;
    *(_WORD *)(v16 + 308) = v17;
    if ( !v17 && *(_DWORD *)(v16 + 100) != v16 + 100 && !*(_WORD *)(v16 + 310) )
      KiCheckForKernelApcDelivery(v15);
    v30[0] = a1 + 344;
    v30[1] = a1 + 328;
    if ( KeWaitForMultipleObjects(2u, v30, 1, 0, 0, 0, 0, 0) )
      return -1073741823;
  }
  v19 = (unsigned __int8 *)(a1 + 320);
  v20 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  --*(_WORD *)(v20 + 308);
  v21 = KeAbPreAcquire(a1 + 320, 0, 0);
  v22 = v21;
  do
    v23 = __ldrex(v19);
  while ( __strex(v23 | 1, v19) );
  __dmb(0xBu);
  if ( (v23 & 1) != 0 )
    ExfAcquirePushLockExclusiveEx((_DWORD *)(a1 + 320), v21, a1 + 320);
  if ( v22 )
    *(_BYTE *)(v22 + 14) |= 1u;
  *(_DWORD *)(a1 + 324) = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  *a5 = *(_DWORD *)(a1 + 176) / 0xAu;
  a5[1] = *(_DWORD *)(a1 + 48);
  a5[2] = *(_DWORD *)(a1 + 264);
  if ( *(_DWORD *)(a1 + 324) )
    *(_DWORD *)(a1 + 324) = 0;
  __pld(v19);
  v24 = *(_DWORD *)v19;
  v25 = *(_DWORD *)v19 - 16;
  if ( (*(_DWORD *)v19 & 0xFFFFFFF0) <= 0x10 )
    v25 = 0;
  if ( (v24 & 2) != 0 )
    goto LABEL_40;
  __dmb(0xBu);
  do
    v26 = __ldrex((unsigned int *)v19);
  while ( v26 == v24 && __strex(v25, (unsigned int *)v19) );
  if ( v26 != v24 )
LABEL_40:
    ExfReleasePushLock((_DWORD *)(a1 + 320), v24);
  v27 = KeAbPostRelease(a1 + 320);
  v28 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v29 = *(_WORD *)(v28 + 0x134) + 1;
  *(_WORD *)(v28 + 308) = v29;
  if ( !v29 && *(_DWORD *)(v28 + 100) != v28 + 100 && !*(_WORD *)(v28 + 310) )
    KiCheckForKernelApcDelivery(v27);
  return 0;
}
