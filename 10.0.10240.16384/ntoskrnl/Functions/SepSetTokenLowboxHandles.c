// SepSetTokenLowboxHandles 
 
int __fastcall SepSetTokenLowboxHandles(int a1, int a2, int a3, int a4)
{
  int v4; // r4
  unsigned __int8 *v6; // r6
  unsigned int v9; // r5
  int v10; // r0
  unsigned int v11; // r5
  int v13; // r4
  int v14; // r7
  int v15; // r0
  int v16; // r5
  unsigned int v17; // r1
  int v18; // r0
  unsigned int v19; // r1
  int v20; // r3
  unsigned int v21; // r1
  int v22; // r0
  unsigned int v23; // r1
  __int16 v24; // r3
  int v25; // [sp+0h] [bp-28h] BYREF
  int v26; // [sp+4h] [bp-24h]
  int v27; // [sp+8h] [bp-20h]

  v25 = a2;
  v26 = a3;
  v27 = a4;
  v4 = *(_DWORD *)(a1 + 192);
  v26 = a4;
  v6 = (unsigned __int8 *)(v4 + 52);
  v9 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  --*(_WORD *)(v9 + 308);
  v10 = KeAbPreAcquire(v4 + 52, 0, 0);
  do
    v11 = __ldrex(v6);
  while ( __strex(v11 | 1, v6) );
  __dmb(0xBu);
  if ( (v11 & 1) != 0 )
    return sub_51BA38(v10);
  if ( v10 )
    *(_BYTE *)(v10 + 14) |= 1u;
  if ( !*(_DWORD *)(v4 + 56) )
  {
    if ( !RtlpCreateHashTable(v4 + 56, 128, 0, 0) )
    {
      v13 = -1073741670;
LABEL_24:
      __dmb(0xBu);
      do
        v17 = __ldrex((unsigned int *)v6);
      while ( __strex(v17 - 1, (unsigned int *)v6) );
      goto LABEL_16;
    }
    *(_DWORD *)(*(_DWORD *)(a1 + 192) + 56) = *(_DWORD *)(v4 + 56);
  }
  v13 = SepGetLowBoxHandlesEntry(v6, a2, &v25);
  if ( v13 )
    goto LABEL_24;
  v14 = v25;
  *(_DWORD *)(a1 + 632) = v25;
  if ( a3 && !*(_DWORD *)(v14 + 20) )
  {
    v15 = ExAllocatePoolWithTag(1, 4 * a3, 1850238291);
    v16 = v15;
    if ( !v15 )
    {
      SepDereferenceLowBoxHandlesEntry(*(_DWORD *)(a1 + 192), v14);
      __dmb(0xBu);
      do
        v21 = __ldrex((unsigned int *)v6);
      while ( __strex(v21 - 1, (unsigned int *)v6) );
      if ( (v21 & 2) != 0 && (v21 & 4) == 0 )
        ExfTryToWakePushLock(v6);
      v22 = KeAbPostRelease(v6);
      v23 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
      v24 = *(_WORD *)(v23 + 0x134) + 1;
      *(_WORD *)(v23 + 308) = v24;
      if ( !v24 && *(_DWORD *)(v23 + 100) != v23 + 100 && !*(_WORD *)(v23 + 310) )
        KiCheckForKernelApcDelivery(v22);
      return -1073741801;
    }
    v13 = SepReferenceLowBoxObjects(a3, v26, v15);
    if ( v13 < 0 )
    {
      ExFreePoolWithTag(v16, 0);
    }
    else
    {
      *(_DWORD *)(*(_DWORD *)(a1 + 632) + 20) = a3;
      *(_DWORD *)(*(_DWORD *)(a1 + 632) + 24) = v16;
    }
  }
  __dmb(0xBu);
  do
    v17 = __ldrex((unsigned int *)v6);
  while ( __strex(v17 - 1, (unsigned int *)v6) );
LABEL_16:
  if ( (v17 & 2) != 0 && (v17 & 4) == 0 )
    ExfTryToWakePushLock(v6);
  v18 = KeAbPostRelease(v6);
  v19 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v20 = (__int16)(*(_WORD *)(v19 + 0x134) + 1);
  *(_WORD *)(v19 + 308) = v20;
  if ( !v20 && *(_DWORD *)(v19 + 100) != v19 + 100 && !*(_WORD *)(v19 + 310) )
    KiCheckForKernelApcDelivery(v18);
  return v13;
}
