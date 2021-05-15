// SepAddLuidToIndexEntry 
 
int __fastcall SepAddLuidToIndexEntry(unsigned int *a1, _DWORD *a2)
{
  int v4; // r9
  _DWORD *v5; // r5
  unsigned int v7; // r2
  unsigned __int8 *v8; // r6
  int v9; // r0
  int v10; // r4
  unsigned int v11; // r2
  unsigned int *v12; // r7
  int v13; // r4
  unsigned int v14; // r6
  int v15; // r2
  int v16; // r1
  int v17; // r4
  unsigned int *v18; // r5
  unsigned int v19; // r1
  int v20; // r0
  unsigned int v21; // r1
  __int16 v22; // r3
  unsigned int v23; // r6
  int v24; // [sp+0h] [bp-20h]

  v4 = 0;
  v5 = (_DWORD *)ExAllocatePoolWithTag(1, 32, 1950639443);
  if ( !v5 )
    return sub_7F6780();
  v7 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  --*(_WORD *)(v7 + 308);
  v8 = (unsigned __int8 *)SeLuidToIndexMapping;
  v9 = KeAbPreAcquire((unsigned int)SeLuidToIndexMapping, 0, 0);
  v10 = v9;
  do
    v11 = __ldrex(v8);
  while ( __strex(v11 | 1, v8) );
  __dmb(0xBu);
  if ( (v11 & 1) != 0 )
    ExfAcquirePushLockExclusiveEx(v8, v9, (unsigned int)v8);
  if ( v10 )
    *(_BYTE *)(v10 + 14) |= 1u;
  v12 = (unsigned int *)SeLuidToIndexMapping;
  v13 = *((_DWORD *)SeLuidToIndexMapping + 1);
  v24 = v13;
  v14 = RtlFindClearBitsAndSet((unsigned int *)SeLuidToIndexMapping + 2, 1u, 0);
  if ( v14 == -1 )
  {
    v23 = RtlNumberOfSetBits(v12 + 2) + 64;
    v4 = ExAllocatePoolWithTag(1, v23 >> 3, 1950639443);
    if ( !v4 )
    {
LABEL_24:
      v17 = -1073741801;
LABEL_25:
      ExFreePoolWithTag((unsigned int)v5);
      if ( v4 )
        ExFreePoolWithTag(v4);
      goto LABEL_14;
    }
    v17 = SepExpandSingletonArrays();
    if ( v17 < 0 )
      goto LABEL_25;
    ExFreePoolWithTag(v12[3]);
    v12[2] = v23;
    v12[3] = v4;
    RtlClearAllBits((int)(v12 + 2));
    RtlSetBits((_BYTE *)v12 + 8, 0, v23 - 64);
    v13 = v24;
    v14 = RtlFindClearBitsAndSet(v12 + 2, 1u, 0);
    v4 = 0;
  }
  v5[6] = v14;
  v5[7] = 0;
  v5[3] = 1;
  v5[4] = *a1;
  v5[5] = a1[1];
  v15 = *a1;
  if ( !*a1 )
    v15 = 1;
  if ( !RtlInsertEntryHashTable(v13, (int)v5, v15, 0) )
  {
    *(_BYTE *)((v14 >> 3) + v12[3]) &= ~(1 << (v14 & 7));
    goto LABEL_24;
  }
  v17 = 0;
  SepInitSingletonEntry(v14, v16, *a1, a1[1]);
  *a2 = v5[6];
  a2[1] = v5[7];
LABEL_14:
  v18 = (unsigned int *)SeLuidToIndexMapping;
  __dmb(0xBu);
  do
    v19 = __ldrex(v18);
  while ( __strex(v19 - 1, v18) );
  if ( (v19 & 2) != 0 && (v19 & 4) == 0 )
    ExfTryToWakePushLock(v18);
  v20 = KeAbPostRelease((unsigned int)v18);
  v21 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v22 = *(_WORD *)(v21 + 0x134) + 1;
  *(_WORD *)(v21 + 308) = v22;
  if ( !v22 && *(_DWORD *)(v21 + 100) != v21 + 100 && !*(_WORD *)(v21 + 310) )
    KiCheckForKernelApcDelivery(v20);
  return v17;
}
