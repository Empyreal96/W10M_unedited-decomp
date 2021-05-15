// MiInsertInSystemSpace 
 
int __fastcall MiInsertInSystemSpace(int a1, int a2, int a3, __int64 *a4, char a5)
{
  int v7; // r6
  int v8; // r0
  int v9; // r2
  int v10; // r9
  int v12; // r3
  unsigned int v13; // r4
  int v14; // r1
  char *v15; // r3
  _BYTE *v16; // r0
  _BYTE *v17; // r9
  __int64 v18; // kr00_8
  int v19; // r3
  unsigned int v20; // r8
  unsigned __int8 *v21; // r10
  int v22; // r0
  int v23; // r5
  unsigned int v24; // r2
  unsigned __int8 *v25; // r3
  unsigned int v26; // r1
  unsigned int v27; // r0
  int v28; // r2
  _DWORD *v29; // r5
  _DWORD *v30; // r3
  unsigned int *v31; // r5
  unsigned int v32; // r1
  int v33; // r0
  __int16 v34; // r3
  unsigned int v35; // r5
  int v36; // r2
  unsigned int v37; // r1
  int v38; // r1
  int v39; // r2
  unsigned int *v40; // r2
  unsigned int v41; // r1
  int v42; // r0
  int v43; // [sp+0h] [bp-90h]
  int v44; // [sp+4h] [bp-8Ch]
  char *v45; // [sp+8h] [bp-88h]
  unsigned int v46; // [sp+8h] [bp-88h]
  int v47; // [sp+Ch] [bp-84h]
  unsigned int *v48; // [sp+10h] [bp-80h]
  int v49; // [sp+14h] [bp-7Ch]
  int v50; // [sp+18h] [bp-78h]
  int v51; // [sp+1Ch] [bp-74h]
  int v53; // [sp+20h] [bp-70h]
  int v55[24]; // [sp+30h] [bp-60h] BYREF

  v7 = 16 * a2;
  v8 = MiSectionControlArea(a3);
  v10 = v8;
  v51 = v8;
  v47 = v8;
  if ( (*(_DWORD *)(v9 + 32) & 0x8000000) != 0 )
    return sub_51A8CC();
  if ( (a5 & 1) != 0 )
    v47 = v8 | 2;
  v50 = 0;
  v45 = algn_63480C;
  v12 = *(_DWORD *)(v8 + 28);
  v13 = 0;
  v43 = 0;
  v44 = 0x7FFFF;
  if ( (v12 & 0x20) != 0 )
  {
    if ( (v12 & 0x4000000) != 0 )
    {
      v44 = -1;
      if ( MiCreatePerSessionProtos(v8, -1) < 0 )
      {
        v38 = 0x7FFFF;
        v44 = 0x7FFFF;
        v39 = 0;
LABEL_72:
        ++*(_DWORD *)(a1 + 16);
        if ( v13 )
        {
          MiReleasePtes(v45, v13, v7);
          v39 = v43;
          v38 = v44;
        }
        if ( v50 == 1 )
        {
          MiChargeWsles(&dword_634F00, -v7, 0);
          v39 = v43;
          v38 = v44;
        }
        if ( v38 != 0x7FFFF )
        {
          MiDereferencePerSessionProtos(v10, v38, v39);
          v39 = v43;
        }
        if ( v39 )
          MiReturnCommit(MiSystemPartition, v39);
        return 0;
      }
    }
    v14 = *(_DWORD *)(*(_DWORD *)v10 + 32);
    v43 = v14;
    if ( v14 )
    {
      if ( !MiChargeCommit(MiSystemPartition, v14, 0) )
      {
        v39 = 0;
        v43 = 0;
LABEL_71:
        v38 = v44;
        goto LABEL_72;
      }
    }
  }
  if ( (char *)a1 == algn_632F64 )
  {
    v48 = (unsigned int *)&dword_634F00;
    if ( !MiChargeWsles(&dword_634F00, v7, 0) )
    {
LABEL_70:
      v39 = v43;
      goto LABEL_71;
    }
    v50 = 1;
    v49 = 0;
    v15 = algn_63480C;
  }
  else
  {
    v36 = *(_DWORD *)(*(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74) + 324);
    v48 = (unsigned int *)(v36 + 3248);
    v49 = v36;
    v15 = (char *)(v36 + 8320);
    v45 = (char *)(v36 + 8320);
  }
  v13 = MiReservePtes(v15);
  if ( !v13 )
    goto LABEL_70;
  v16 = (_BYTE *)ExAllocatePoolWithTag(512, 64, 2002151757);
  v17 = v16;
  if ( !v16 )
  {
    v10 = v51;
    goto LABEL_70;
  }
  memset(v16, 0, 64);
  *((_DWORD *)v17 + 6) = a2 << 16;
  *((_DWORD *)v17 + 8) = v47;
  v46 = v13 << 10;
  v18 = *a4;
  *((_DWORD *)v17 + 7) = v43;
  *((_DWORD *)v17 + 14) = v44;
  *((_DWORD *)v17 + 12) = (v13 << 10) | 2;
  *((_QWORD *)v17 + 2) = v18 / 4096;
  if ( (char *)a1 == algn_632F64 )
    v19 = -1;
  else
    v19 = *(_DWORD *)(v49 + 8);
  *((_DWORD *)v17 + 13) = v19;
  *((_DWORD *)v17 + 9) = MiReferenceFileObjectForMap(a3);
  v20 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  --*(_WORD *)(v20 + 0x136);
  v21 = *(unsigned __int8 **)(a1 + 4);
  v22 = KeAbPreAcquire(v21, 0, 0);
  v23 = v22;
  do
    v24 = __ldrex(v21);
  while ( __strex(v24 | 1, v21) );
  __dmb(0xBu);
  if ( (v24 & 1) != 0 )
    ExfAcquirePushLockExclusiveEx(v21, v22, v21);
  if ( v23 )
    *(_BYTE *)(v23 + 14) |= 1u;
  v53 = KfRaiseIrql(2);
  if ( (dword_682604 & 0x210000) != 0 )
  {
    ExpAcquireSpinLockExclusiveAtDpcLevelInstrumented(v48);
  }
  else
  {
    v25 = (unsigned __int8 *)v48 + 3;
    do
      v26 = __ldrex(v25);
    while ( __strex(v26 | 0x80, v25) );
    __dmb(0xBu);
    if ( v26 >> 7 )
      ExpWaitForSpinLockExclusiveAndAcquire(v48);
    while ( 1 )
    {
      v27 = *v48;
      if ( (*v48 & 0xBFFFFFFF) == 0x80000000 )
        break;
      if ( (v27 & 0x40000000) == 0 )
      {
        do
          v37 = __ldrex(v48);
        while ( v37 == v27 && __strex(v27 | 0x40000000, v48) );
        __dmb(0xBu);
      }
      __dmb(0xAu);
      __yield();
    }
  }
  v28 = 0;
  ++*(_DWORD *)(a1 + 12);
  v29 = *(_DWORD **)(a1 + 8);
  if ( v29 )
  {
    while ( 1 )
    {
      if ( MiSystemViewCompareVa(v46, v29) < 0 )
      {
        v30 = (_DWORD *)*v29;
        if ( !*v29 )
        {
          v28 = 0;
          break;
        }
      }
      else
      {
        v30 = (_DWORD *)v29[1];
        if ( !v30 )
        {
          v28 = 1;
          break;
        }
      }
      v29 = v30;
    }
  }
  RtlAvlInsertNodeEx(a1 + 8, v29, v28, v17);
  MiUnlockWorkingSetExclusive(v48, v53);
  if ( (*(_DWORD *)(v51 + 28) & 0x400) == 0 )
  {
    v55[0] = v51;
    MiManageSubsectionView(v55, v17 + 40, 3);
  }
  v31 = *(unsigned int **)(a1 + 4);
  __dmb(0xBu);
  do
    v32 = __ldrex(v31);
  while ( __strex(v32 - 1, v31) );
  if ( (v32 & 2) != 0 && (v32 & 4) == 0 )
    ExfTryToWakePushLock(v31);
  v33 = KeAbPostRelease(v31);
  v34 = *(_WORD *)(v20 + 310) + 1;
  *(_WORD *)(v20 + 310) = v34;
  if ( !v34 && *(_DWORD *)(v20 + 100) != v20 + 100 )
    KiCheckForKernelApcDelivery(v33);
  if ( (v47 & 1) != 0 )
  {
    v40 = (unsigned int *)(v51 + 52);
    do
      v41 = __ldrex(v40);
    while ( __strex(v41 + 1, v40) );
    __dmb(0xBu);
  }
  if ( v7 )
  {
    v35 = v13 + 0x40000000;
    do
    {
      if ( v35 > 0x3FFFFF )
      {
        *(_DWORD *)v13 = 0;
      }
      else
      {
        __dmb(0xBu);
        *(_DWORD *)v13 = 0;
        if ( v13 >= 0xC0300000 && v13 <= 0xC0300FFF )
        {
          v42 = *(_DWORD *)(*(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74) + 32);
          MiArmWriteConvertedHardwarePde(v42, v42 + 4 * (v13 & 0xFFF), 0);
        }
      }
      v13 += 4;
      v35 += 4;
      --v7;
    }
    while ( v7 );
  }
  return v46;
}
