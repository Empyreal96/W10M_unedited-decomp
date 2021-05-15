// MiGatherMappedPages 
 
int __fastcall MiGatherMappedPages(int a1, unsigned int a2, _DWORD *a3)
{
  unsigned int v3; // r4
  _DWORD *v5; // r7
  int v6; // r1
  _DWORD *v8; // r8
  int v9; // r4
  int v10; // r9
  int v11; // lr
  unsigned __int8 *v12; // r3
  unsigned int v13; // r1
  unsigned int v14; // r3
  unsigned int *v15; // r4
  int v16; // r3
  unsigned int *v17; // r10
  unsigned __int8 *v18; // r3
  unsigned int v19; // r1
  unsigned int v20; // r0
  unsigned int *v21; // r2
  unsigned int v22; // r0
  int v23; // r0
  int v24; // r1
  int v25; // r10
  _DWORD *v26; // r5
  int v27; // r0
  int v28; // r0
  int v29; // r9
  __int64 v30; // r0
  unsigned int v31; // r3
  int v32; // r3
  unsigned int v33; // r3
  unsigned int v34; // r3
  int v35; // r8
  int v36; // r1
  int v37; // r0
  int v38; // r7
  int v39; // r4
  int v40; // r2
  unsigned int *v41; // r2
  unsigned int v42; // r0
  int v43; // lr
  int v44; // r2
  unsigned int v45; // r3
  unsigned int *v46; // r1
  unsigned int v47; // r0
  unsigned int *v48; // r1
  unsigned int v49; // r0
  unsigned int *v50; // r2
  unsigned int v51; // r0
  unsigned __int8 *v52; // r1
  int v53; // r3
  unsigned int v54; // r2
  unsigned int v55; // r2
  int v56; // r3
  char v57; // r2
  int v58; // lr
  int *v59; // r1
  int v60; // r0
  int v61; // r2
  unsigned int *v62; // r2
  unsigned int v63; // r0
  unsigned int v64; // r1
  int v65; // r2
  unsigned int *v66; // r2
  unsigned int v67; // r0
  int v68; // r3
  int v69; // r4
  unsigned int v70; // [sp+18h] [bp-40h]
  int v71; // [sp+18h] [bp-40h]
  char v72; // [sp+18h] [bp-40h]
  int v73; // [sp+1Ch] [bp-3Ch]
  int v74; // [sp+1Ch] [bp-3Ch]
  unsigned int v75; // [sp+24h] [bp-34h]
  __int64 v76; // [sp+28h] [bp-30h] BYREF
  __int64 v77[5]; // [sp+30h] [bp-28h] BYREF

  v3 = a2;
  v5 = (_DWORD *)a1;
  if ( a2 >= 0x10 )
  {
    v3 = 0;
    v6 = a1;
    do
    {
      if ( *(_DWORD *)(v6 + 2056) != 0xFFFFF )
        break;
      ++v3;
      v6 += 20;
    }
    while ( v3 < 0x10 );
    if ( v3 == 16 )
      return sub_53C1AC();
  }
  if ( *(_DWORD *)(a1 + 592) || *(_BYTE *)(a1 + 596) == 1 )
    KeDelayExecutionThread(0, 0, (unsigned int *)Mi30Milliseconds);
  v8 = &v5[5 * v3];
  v9 = v8[514];
  if ( v9 == 0xFFFFF )
    return 0;
  while ( 1 )
  {
    v10 = MmPfnDatabase + 24 * v9;
    v11 = KfRaiseIrql(2);
    v73 = v11;
    v12 = (unsigned __int8 *)(v10 + 15);
    do
      v13 = __ldrex(v12);
    while ( __strex(v13 | 0x80, v12) );
    __dmb(0xBu);
    if ( v13 >> 7 )
    {
      v52 = (unsigned __int8 *)(v10 + 15);
      do
      {
        do
        {
          __dmb(0xAu);
          __yield();
          v53 = *(_DWORD *)(v10 + 12);
          __dmb(0xBu);
        }
        while ( (v53 & 0x80000000) != 0 );
        do
          v54 = __ldrex(v52);
        while ( __strex(v54 | 0x80, v52) );
        __dmb(0xBu);
      }
      while ( v54 >> 7 );
    }
    if ( v9 != v8[514] )
    {
      __dmb(0xBu);
      v50 = (unsigned int *)(v10 + 12);
      do
        v51 = __ldrex(v50);
      while ( __strex(v51 & 0x7FFFFFFF, v50) );
      KfLowerIrql(v11);
      goto LABEL_45;
    }
    v14 = *(_DWORD *)(v10 + 8) & 0xFFFFF800 | (2 * (*(_DWORD *)(v10 + 8) & 0x3FC));
    v15 = *(unsigned int **)v14;
    v70 = v14;
    v16 = *(_DWORD *)(*(_DWORD *)v14 + 28);
    if ( (v16 & 0x20) != 0 )
    {
      MiUnlinkPageFromList(v10, 0);
      v55 = *(_DWORD *)(v10 + 8);
      if ( (v55 & 0x400) != 0 )
      {
        v55 &= 0xFFFFF800;
        v56 = (*(unsigned __int16 *)((v55 | (2 * (*(_DWORD *)(v10 + 8) & 0x3FC))) + 0x10) >> 1) & 0x1F;
      }
      else
      {
        v56 = (v55 >> 5) & 0x1F;
      }
      v72 = v56;
      if ( (*(_BYTE *)(v10 + 23) & 7) == 3 )
      {
        MiClearPfnImageVerified(v10, 12, v55, 3);
        v57 = v72;
        if ( (MiFlags & 0x30000) == 0 || (v72 & 2) == 0 || (v15[13] & 0xC000000) == 0 )
          goto LABEL_77;
        MiMarkPfnVerified(v10, 6);
      }
      v57 = v72;
LABEL_77:
      v58 = 32 * (v57 & 0x1F);
      v59 = (int *)(v10 + 8);
      if ( (unsigned int)(v10 + 1073741832) > 0x3FFFFF )
      {
        *v59 = v58;
      }
      else
      {
        __dmb(0xBu);
        *v59 = v58;
        if ( (unsigned int)(v10 + 1070596104) <= 0xFFF )
        {
          v60 = *(_DWORD *)(*(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74) + 32);
          MiArmWriteConvertedHardwarePde(v60, (_DWORD *)(v60 + 4 * ((unsigned __int16)v59 & 0xFFF)), v58);
        }
      }
      MiDereferenceControlAreaPfn(v15, 0, 3);
      MiInsertPageInList(v10, 8, v61);
      __dmb(0xBu);
      v62 = (unsigned int *)(v10 + 12);
      do
        v63 = __ldrex(v62);
      while ( __strex(v63 & 0x7FFFFFFF, v62) );
      goto LABEL_44;
    }
    if ( (v16 & 8) == 0 )
      break;
    MiUnlinkPageFromList(v10, 0);
    MiInsertPageInList(v10, 16, v40);
    __dmb(0xBu);
    v41 = (unsigned int *)(v10 + 12);
    do
      v42 = __ldrex(v41);
    while ( __strex(v42 & 0x7FFFFFFF, v41) );
LABEL_44:
    KfLowerIrql(v73);
LABEL_45:
    v9 = v8[514];
    if ( v9 == 0xFFFFF )
      return 0;
  }
  v17 = v15 + 9;
  if ( (dword_682604 & 0x210000) != 0 )
  {
    ExpAcquireSpinLockExclusiveAtDpcLevelInstrumented(v15 + 9);
  }
  else
  {
    v18 = (unsigned __int8 *)v15 + 39;
    do
      v19 = __ldrex(v18);
    while ( __strex(v19 | 0x80, v18) );
    __dmb(0xBu);
    if ( v19 >> 7 )
      ExpWaitForSpinLockExclusiveAndAcquire(v15 + 9);
    while ( 1 )
    {
      v20 = *v17;
      if ( (*v17 & 0xBFFFFFFF) == 0x80000000 )
        break;
      if ( (v20 & 0x40000000) == 0 )
      {
        do
          v64 = __ldrex(v17);
        while ( v64 == v20 && __strex(v20 | 0x40000000, v17) );
        __dmb(0xBu);
      }
      __dmb(0xAu);
      __yield();
    }
  }
  if ( (v15[7] & 8) != 0 )
  {
    if ( (dword_682604 & 0x10000) != 0 )
    {
      ExpReleaseSpinLockExclusiveFromDpcLevelInstrumented(v15 + 9);
    }
    else
    {
      __dmb(0xBu);
      *v17 = 0;
    }
    MiUnlinkPageFromList(v10, 0);
    MiInsertPageInList(v10, 16, v65);
    __dmb(0xBu);
    v66 = (unsigned int *)(v10 + 12);
    do
      v67 = __ldrex(v66);
    while ( __strex(v67 & 0x7FFFFFFF, v66) );
    goto LABEL_44;
  }
  ++v15[10];
  if ( (dword_682604 & 0x10000) != 0 )
  {
    ExpReleaseSpinLockExclusiveFromDpcLevelInstrumented(v15 + 9);
  }
  else
  {
    __dmb(0xBu);
    v15[9] = 0;
  }
  MiReferencePageForModifiedWrite(v10, 1);
  __dmb(0xBu);
  v21 = (unsigned int *)(v10 + 12);
  do
    v22 = __ldrex(v21);
  while ( __strex(v22 & 0x7FFFFFFF, v21) );
  KfLowerIrql(v11);
  v23 = MI_REFERENCE_CONTROL_AREA_FILE(v15);
  v25 = *(_DWORD *)(v23 + 20);
  v26 = (_DWORD *)v23;
  if ( v5[148] )
    v27 = 0;
  else
    v27 = CcNotifyOfMappedWrite(*(_DWORD *)(v23 + 20), v24, 0, 0, 0);
  v28 = MiBuildMappedCluster((_DWORD *)v10, (unsigned int)(a3 + 32), v27);
  v29 = v28;
  if ( (_DWORD *)v28 != a3 + 32 )
    a3[31] = v28;
  a3[23] = v15;
  v30 = MiStartingOffset(v70, *(_DWORD *)(MmPfnDatabase + 24 * *(_DWORD *)(v28 + 28) + 4) | 0x80000000, -1);
  v31 = *(_DWORD *)(v29 + 20);
  v71 = HIDWORD(v30);
  v74 = v30;
  v77[0] = v30;
  a3[19] = v31;
  a3[20] = (v31 >> 12) - 1;
  v75 = v31 >> 12;
  v76 = v30 + *(unsigned int *)(v29 + 20);
  a3[24] = 0;
  v32 = a3[5];
  if ( (*(_DWORD *)(v26[1] + 32) & 0x10) != 0 )
    v33 = v32 | 2;
  else
    v33 = v32 & 0xFFFFFFFD;
  a3[5] = v33;
  v34 = v15[7];
  v35 = 0;
  if ( (v34 & 4) != 0 )
  {
    MI_DEREFERENCE_CONTROL_AREA_FILE(v15, v26);
    v38 = -1073741740;
    v35 = 1;
LABEL_39:
    a3[2] = v38;
    a3[3] = 0;
    v39 = KfRaiseIrql(1);
    MiWriteComplete(a3, a3 + 2, v35);
    KfLowerIrql(v39);
    return 1;
  }
  if ( (v34 & 0x10) != 0 )
  {
    MI_DEREFERENCE_CONTROL_AREA_FILE(v15, v26);
    v38 = -1073741672;
    v35 = 1;
    goto LABEL_39;
  }
  a3[22] = v26;
  if ( FsRtlAcquireFileForModWriteEx(v26, (int)&v76, a3 + 24) < 0 )
  {
    v38 = -1073741740;
    MI_DEREFERENCE_CONTROL_AREA_FILE(v15, v26);
    a3[24] = 0;
LABEL_57:
    if ( (v38 & 0xC0000000) != -1073741824 )
      return 1;
    goto LABEL_39;
  }
  v37 = CcNotifyOfMappedWrite(v25, v36, v74, v71, *(_DWORD *)(v29 + 20));
  if ( !v37 )
  {
    FsRtlReleaseFileForModWrite((int)v26, a3[24]);
    MI_DEREFERENCE_CONTROL_AREA_FILE(v15, v26);
    v38 = -1073741740;
    a3[24] = 0;
    v35 = 1;
    goto LABEL_39;
  }
  if ( v37 == 1 )
    a3[24] |= 1u;
  v43 = 2;
  a3[26] = v74;
  a3[27] = v71;
  v44 = v5[99];
  v45 = v5[928];
  if ( v44 )
  {
    if ( v45 >= 0x400 )
    {
      v68 = 0;
LABEL_108:
      v5[99] = v68;
      goto LABEL_51;
    }
    v68 = v44 - 1;
LABEL_107:
    v43 = 4;
    goto LABEL_108;
  }
  if ( v45 < 0x100 )
  {
    if ( v45 >= 0x80 )
      v68 = 8;
    else
      v68 = 32;
    goto LABEL_107;
  }
LABEL_51:
  v46 = (unsigned int *)(((unsigned int)KeGetPcr() & 0xFFFFF000) + 2988);
  do
    v47 = __ldrex(v46);
  while ( __strex(v47 + 1, v46) );
  v48 = (unsigned int *)(((unsigned int)KeGetPcr() & 0xFFFFF000) + 2984);
  do
    v49 = __ldrex(v48);
  while ( __strex(v49 + v75, v48) );
  if ( (v15[7] & 0x40000000) == 0 )
  {
    v38 = IoAsynchronousPageWrite(v26, v29, v77, MiWriteComplete, a3, v43, 0, 0, a3 + 2, a3 + 4);
    goto LABEL_57;
  }
  MiFlushFileOnlyMdl(v26, v29, 0, a3 + 2);
  v69 = KfRaiseIrql(1);
  MiWriteComplete(a3, a3 + 2, 0);
  KfLowerIrql(v69);
  return 1;
}
