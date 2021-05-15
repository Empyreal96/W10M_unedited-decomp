// MiRemoveFromSystemSpace 
 
int __fastcall MiRemoveFromSystemSpace(int a1, unsigned int a2, int a3)
{
  unsigned int v4; // r8
  unsigned int *v5; // r5
  int v6; // r3
  unsigned __int8 *v7; // r6
  int v8; // r0
  int v9; // r4
  unsigned int v10; // r2
  unsigned __int8 *v12; // r3
  unsigned int v13; // r1
  unsigned int v14; // r0
  int *v15; // r4
  int v16; // r0
  __int64 v17; // kr00_8
  unsigned int *v18; // r6
  unsigned int v19; // r1
  int v20; // r0
  unsigned int *v21; // r2
  __int16 v22; // r3
  int v23; // r8
  unsigned int v24; // r6
  int v25; // r1
  unsigned int v26; // r1
  unsigned int v27; // r1
  int v28; // [sp+8h] [bp-78h]
  int v30; // [sp+10h] [bp-70h]
  int v31; // [sp+14h] [bp-6Ch]
  int v33[24]; // [sp+20h] [bp-60h] BYREF

  v4 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v31 = (a2 >> 10) & 0x3FFFFC;
  if ( (char *)a1 == algn_632F64 )
  {
    v5 = (unsigned int *)&dword_634F00;
    v6 = 0;
  }
  else
  {
    v6 = *(_DWORD *)(*(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74) + 324);
    v5 = (unsigned int *)(v6 + 3248);
  }
  v30 = v6;
  --*(_WORD *)(v4 + 310);
  v7 = *(unsigned __int8 **)(a1 + 4);
  v8 = KeAbPreAcquire(v7, 0, 0);
  v9 = v8;
  do
    v10 = __ldrex(v7);
  while ( __strex(v10 | 1, v7) );
  __dmb(0xBu);
  if ( (v10 & 1) != 0 )
    ExfAcquirePushLockExclusiveEx(v7, v8, v7);
  if ( v9 )
    *(_BYTE *)(v9 + 14) |= 1u;
  v28 = KfRaiseIrql(2);
  if ( (dword_682604 & 0x210000) != 0 )
    return sub_51A998();
  v12 = (unsigned __int8 *)v5 + 3;
  do
    v13 = __ldrex(v12);
  while ( __strex(v13 | 0x80, v12) );
  __dmb(0xBu);
  if ( v13 >> 7 )
    ExpWaitForSpinLockExclusiveAndAcquire(v5);
  while ( 1 )
  {
    v14 = *v5;
    if ( (*v5 & 0xBFFFFFFF) == 0x80000000 )
      break;
    if ( (v14 & 0x40000000) == 0 )
    {
      do
        v26 = __ldrex(v5);
      while ( v26 == v14 && __strex(v14 | 0x40000000, v5) );
      __dmb(0xBu);
    }
    __dmb(0xAu);
    __yield();
  }
  v15 = *(int **)(a1 + 8);
  if ( !v15 )
    goto LABEL_52;
  do
  {
    v16 = MiSystemViewCompareVa(a2, v15);
    if ( v16 < 0 )
    {
      v15 = (int *)*v15;
    }
    else
    {
      if ( v16 <= 0 )
        break;
      v15 = (int *)v15[1];
    }
  }
  while ( v15 );
  if ( !v15 )
LABEL_52:
    KeBugCheckEx(215, a2, 1);
  --*(_DWORD *)(a1 + 12);
  RtlAvlRemoveNode(a1 + 8, v15);
  MiUnlockWorkingSetExclusive(v5, v28);
  v17 = *((_QWORD *)v15 + 4);
  v33[0] = v17 & 0xFFFFFFF8;
  MiManageSubsectionView(v33, v15 + 10, 4);
  v18 = *(unsigned int **)(a1 + 4);
  __dmb(0xBu);
  do
    v19 = __ldrex(v18);
  while ( __strex(v19 - 1, v18) );
  if ( (v19 & 2) != 0 && (v19 & 4) == 0 )
    ExfTryToWakePushLock(v18);
  v20 = KeAbPostRelease(v18);
  v22 = *(_WORD *)(v4 + 310) + 1;
  *(_WORD *)(v4 + 310) = v22;
  if ( !v22 )
  {
    v21 = (unsigned int *)(v4 + 100);
    if ( *(_DWORD *)(v4 + 100) != v4 + 100 )
      KiCheckForKernelApcDelivery(v20);
  }
  if ( HIDWORD(v17) )
    ObfDereferenceObjectWithTag(HIDWORD(v17));
  if ( (v17 & 1) == 1 )
  {
    __dmb(0xBu);
    v23 = v17 & 0xFFFFFFF8;
    v21 = (unsigned int *)((v17 & 0xFFFFFFF8) + 52);
    do
      v27 = __ldrex(v21);
    while ( __strex(v27 - 1, v21) );
  }
  else
  {
    v23 = v17 & 0xFFFFFFF8;
  }
  v24 = (unsigned int)v15[6] >> 12;
  if ( a3 == 1 )
    MiRemoveMappedPtes(v15, v5);
  v25 = v15[14];
  if ( v25 != 0x7FFFF )
    MiDereferencePerSessionProtos(v23, v25, v21);
  if ( (char *)a1 == algn_632F64 )
  {
    MiReleasePtes(algn_63480C, v31 - 0x40000000, v24);
    MiChargeWsles(v5, -v24, 0);
  }
  else
  {
    MiReleasePtes(v30 + 8320, v31 - 0x40000000, v24);
  }
  return ExFreePoolWithTag(v15, 0);
}
