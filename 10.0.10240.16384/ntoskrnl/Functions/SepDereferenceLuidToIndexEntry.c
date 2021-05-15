// SepDereferenceLuidToIndexEntry 
 
int __fastcall SepDereferenceLuidToIndexEntry(int a1, int a2, int a3, int a4)
{
  int v4; // r8
  int v6; // r5
  unsigned int v7; // r1
  unsigned int *v8; // r9
  int v9; // r0
  int v10; // r4
  unsigned int v11; // r2
  int v12; // r0
  _DWORD *v13; // r6
  unsigned int *v14; // r2
  unsigned int v15; // r1
  signed int v16; // r1
  unsigned int *v17; // r4
  unsigned int v18; // r2
  int v19; // r0
  unsigned int v20; // r1
  __int16 v21; // r3
  int v23; // r3
  unsigned __int8 *v24; // r5
  int v25; // r0
  int v26; // r4
  unsigned int v27; // r2
  unsigned int *v28; // r4
  unsigned int v29; // r1
  int v30; // r0
  unsigned int v31; // r1
  int v32; // r3
  int v33[8]; // [sp+0h] [bp-20h] BYREF

  v33[1] = a4;
  v4 = -1073741275;
  v33[0] = 0;
  v6 = 0;
  v7 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  --*(_WORD *)(v7 + 308);
  v8 = (unsigned int *)SeLuidToIndexMapping;
  v9 = KeAbPreAcquire(SeLuidToIndexMapping, 0, 0);
  v10 = v9;
  do
    v11 = __ldrex(v8);
  while ( !v11 && __strex(0x11u, v8) );
  __dmb(0xBu);
  if ( v11 )
    ExfAcquirePushLockSharedEx(v8, v9, v8);
  if ( v10 )
    *(_BYTE *)(v10 + 14) |= 1u;
  v12 = SepFindMatchingLuidEntry(*((_DWORD *)SeLuidToIndexMapping + 1), a1, v33);
  v13 = (_DWORD *)v33[0];
  if ( v33[0] )
  {
    __dmb(0xBu);
    v14 = v13 + 3;
    do
    {
      v15 = __ldrex(v14);
      v16 = v15 - 1;
    }
    while ( __strex(v16, v14) );
    if ( v16 <= 0 )
    {
      if ( v16 )
        sub_517DEC(v12);
      __dmb(0xBu);
      v6 = 1;
    }
  }
  v17 = (unsigned int *)SeLuidToIndexMapping;
  __dmb(0xBu);
  do
    v18 = __ldrex(v17);
  while ( v18 == 17 && __strex(0, v17) );
  if ( v18 != 17 )
    ExfReleasePushLockShared(v17, 0);
  v19 = KeAbPostRelease(v17);
  v20 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v21 = *(_WORD *)(v20 + 0x134) + 1;
  *(_WORD *)(v20 + 308) = v21;
  if ( !v21 && *(_DWORD *)(v20 + 100) != v20 + 100 && !*(_WORD *)(v20 + 310) )
    KiCheckForKernelApcDelivery(v19);
  if ( v6 )
  {
    SepCleanSingletonEntry(v13[6]);
    v23 = __mrc(15, 0, 13, 0, 3);
    --*(_WORD *)((v23 & 0xFFFFFFC0) + 0x134);
    v24 = (unsigned __int8 *)SeLuidToIndexMapping;
    v25 = KeAbPreAcquire(SeLuidToIndexMapping, 0, 0);
    v26 = v25;
    do
      v27 = __ldrex(v24);
    while ( __strex(v27 | 1, v24) );
    __dmb(0xBu);
    if ( (v27 & 1) != 0 )
      ExfAcquirePushLockExclusiveEx(v24, v25, v24);
    if ( v26 )
      *(_BYTE *)(v26 + 14) |= 1u;
    if ( RtlRemoveEntryHashTable(*((_DWORD *)SeLuidToIndexMapping + 1), v13, 0) )
    {
      *(_BYTE *)((v13[6] >> 3) + *((_DWORD *)SeLuidToIndexMapping + 3)) &= ~(1 << (v13[6] & 7));
      ExFreePoolWithTag(v13, 0);
    }
    else
    {
      v4 = -1073741823;
    }
    v28 = (unsigned int *)SeLuidToIndexMapping;
    __dmb(0xBu);
    do
      v29 = __ldrex(v28);
    while ( __strex(v29 - 1, v28) );
    if ( (v29 & 2) != 0 && (v29 & 4) == 0 )
      ExfTryToWakePushLock(v28);
    v30 = KeAbPostRelease(v28);
    v31 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    v32 = (__int16)(*(_WORD *)(v31 + 0x134) + 1);
    *(_WORD *)(v31 + 308) = v32;
    if ( !v32 && *(_DWORD *)(v31 + 100) != v31 + 100 && !*(_WORD *)(v31 + 310) )
      KiCheckForKernelApcDelivery(v30);
  }
  return v4;
}
