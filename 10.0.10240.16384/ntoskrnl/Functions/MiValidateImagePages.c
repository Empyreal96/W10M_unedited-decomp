// MiValidateImagePages 
 
int __fastcall MiValidateImagePages(int *a1, int a2, int a3, int a4)
{
  int v4; // r6
  int v5; // r8
  char v6; // r4
  int v8; // r3
  int v9; // r4
  int v10; // r1
  int v11; // r3
  int v12; // r7
  int v13; // r5
  int v14; // r10
  unsigned int v15; // r6
  int v16; // r9
  __int16 v17; // r3
  __int64 v18; // r0
  unsigned int v19; // r5
  int v20; // r8
  unsigned int v21; // r4
  int v22; // r5
  int v23; // r6
  int v24; // r7
  int v25; // r0
  unsigned __int8 *v26; // r1
  unsigned int v27; // r3
  int v28; // r2
  int v29; // r10
  int v30; // r4
  unsigned int *v31; // r8
  unsigned int v32; // r1
  int v33; // r1
  int v34; // r0
  unsigned int v35; // r7
  __int16 *v36; // r9
  int v37; // r0
  unsigned __int8 *v38; // r3
  unsigned int v39; // r1
  int v40; // r3
  int v41; // r4
  unsigned int v42; // r4
  unsigned int v43; // r2
  unsigned int *v44; // r2
  unsigned int v45; // r0
  unsigned int v46; // r3
  unsigned int v47; // r2
  __int16 v48; // r3
  unsigned int *v49; // r6
  int v50; // r0
  int v51; // r5
  unsigned int v52; // r2
  int v53; // r0
  unsigned __int8 *v54; // r1
  int v55; // r3
  unsigned int v56; // r2
  unsigned int *v57; // r2
  unsigned int v58; // r0
  int v59; // r7
  int v60; // r1
  unsigned int v61; // r0
  unsigned int v62; // r4
  int v63; // r3
  int v64; // r0
  unsigned int *v65; // r2
  unsigned int v66; // r0
  unsigned int *v67; // r2
  unsigned int v68; // r0
  int v69; // r4
  unsigned int *v70; // r2
  unsigned int v71; // r0
  unsigned __int8 *v72; // r1
  unsigned int v73; // r3
  unsigned int v74; // r2
  unsigned int *v75; // r4
  unsigned int v76; // r2
  int v77; // r0
  __int16 v78; // r3
  char v79[4]; // [sp+10h] [bp-78h] BYREF
  int *v80; // [sp+14h] [bp-74h]
  int v81; // [sp+18h] [bp-70h]
  int v82; // [sp+1Ch] [bp-6Ch]
  int v83; // [sp+20h] [bp-68h] BYREF
  unsigned int v84; // [sp+24h] [bp-64h]
  int v85; // [sp+28h] [bp-60h]
  int v86; // [sp+2Ch] [bp-5Ch]
  int v87; // [sp+30h] [bp-58h]
  int v88; // [sp+34h] [bp-54h]
  int v89; // [sp+38h] [bp-50h]
  int v90; // [sp+3Ch] [bp-4Ch]
  int v91; // [sp+40h] [bp-48h]
  int v92; // [sp+44h] [bp-44h]
  int v93; // [sp+48h] [bp-40h]
  unsigned int v94; // [sp+4Ch] [bp-3Ch]
  unsigned int v95; // [sp+50h] [bp-38h]
  int v96; // [sp+54h] [bp-34h]
  int v97; // [sp+58h] [bp-30h] BYREF
  int v98; // [sp+5Ch] [bp-2Ch]
  int v99; // [sp+60h] [bp-28h]
  int v100; // [sp+64h] [bp-24h]
  int v101; // [sp+68h] [bp-20h]

  v4 = *a1;
  v5 = a4;
  v92 = a4;
  v6 = *(_BYTE *)(v4 + 10);
  v85 = a3;
  v96 = a2;
  v80 = a1;
  v101 = v4;
  if ( (v6 & 1) != 0 )
    return sub_544438();
  v86 = 0;
  v8 = __mrc(15, 0, 13, 0, 3);
  v9 = (int)(a1 + 20);
  v10 = a1[21];
  v100 = *(_DWORD *)((v8 & 0xFFFFFFC0) + 0x74);
  v87 = v10;
  v88 = 0;
  v11 = a1[7];
  v12 = 17;
  v13 = 0;
  v81 = 17;
  v82 = 0;
  v79[0] = 17;
  v83 = 0;
  v14 = 0;
  v93 = 0;
  if ( (v11 & 0x4000000) != 0 )
  {
    v47 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    v48 = *(_WORD *)(v47 + 0x136);
    v93 = v47;
    *(_WORD *)(v47 + 310) = v48 - 1;
    v49 = (unsigned int *)(v4 + 28);
    v50 = KeAbPreAcquire((unsigned int)v49, 0, 0);
    v51 = v50;
    do
      v52 = __ldrex(v49);
    while ( !v52 && __strex(0x11u, v49) );
    __dmb(0xBu);
    if ( v52 )
      ExfAcquirePushLockSharedEx(v49, v50, v49);
    a3 = v85;
    a1 = v80;
    v10 = v87;
    if ( v51 )
      *(_BYTE *)(v51 + 14) |= 1u;
    v13 = 0;
  }
  v98 = 4194300;
  while ( 1 )
  {
    v15 = *(_DWORD *)(v9 + 4);
    v99 = *(_DWORD *)(v9 + 8);
    v16 = (int)(v15 - v10) >> 2;
    v17 = *(_WORD *)(v9 + 18);
    v91 = v16;
    if ( (v17 & 2) != 0 )
    {
      if ( (a3 & 1) != 0 )
        goto LABEL_20;
      if ( (a1[7] & 0x4000000) != 0 )
      {
        if ( !*(_DWORD *)(v9 + 12) )
          goto LABEL_20;
        v53 = MiGetSharedProtos(a1, v5, v9);
        if ( !v53 )
          goto LABEL_19;
        v15 = *(_DWORD *)(v53 + 16);
      }
    }
    v18 = MiStartingOffset(v9, v15, v5);
    v19 = v18;
    v94 = v15 + 4 * *(_DWORD *)(v9 + 28);
    v95 = 0;
    v20 = HIDWORD(v18);
    v89 = 0;
    v90 = HIDWORD(v18);
    v84 = v18;
    if ( v15 < v94 )
      break;
LABEL_16:
    if ( v14 )
    {
      MiUnlockProtoPoolPage(v14, v12);
      v14 = 0;
      v82 = 0;
    }
    v5 = v92;
    v13 = v83;
LABEL_19:
    a3 = v85;
    a1 = v80;
    v10 = v87;
LABEL_20:
    v9 = v99;
    if ( !v99 )
      goto LABEL_21;
  }
  while ( (v15 & 0xFFF) == 0 )
  {
    if ( v14 )
      MiUnlockProtoPoolPage(v14, v12);
LABEL_27:
    v24 = v86;
    if ( v86 == 1 )
      v25 = MiLockProtoPoolPage(v15, v79);
    else
      v25 = MiCheckProtoPtePageState(v15, v79);
    v14 = v25;
    v82 = v25;
    if ( v25 )
    {
      v12 = (unsigned __int8)v79[0];
      v81 = (unsigned __int8)v79[0];
      goto LABEL_9;
    }
    if ( v24 == 1 )
    {
      MmAccessFault(1, v15, 0, 0);
      v81 = (unsigned __int8)v79[0];
    }
    else
    {
      v46 = (4096 - (v15 & 0xFFF)) >> 2;
      v16 += v46;
      v15 += 4 * v46;
      v20 = (__PAIR64__(v20, v19) + (v46 << 12)) >> 32;
      v19 += v46 << 12;
      v84 = v19;
      v81 = (unsigned __int8)v79[0];
      v90 = v20;
      v91 = v16;
    }
LABEL_15:
    v12 = v81;
    if ( v15 >= v94 )
      goto LABEL_16;
  }
  if ( !v14 )
    goto LABEL_27;
LABEL_9:
  while ( 1 )
  {
    v21 = *(_DWORD *)v15;
    if ( (*(_DWORD *)v15 & 2) == 0 && ((v21 & 0x400) != 0 || (v21 & 0x800) == 0) )
      break;
    if ( MI_IS_PFN(v21 >> 12) )
    {
      v22 = MmPfnDatabase + 24 * (v21 >> 12);
      v26 = (unsigned __int8 *)(v22 + 15);
      do
        v27 = __ldrex(v26);
      while ( __strex(v27 | 0x80, v26) );
      __dmb(0xBu);
      if ( v27 >> 7 )
      {
        v54 = (unsigned __int8 *)(v22 + 15);
        do
        {
          do
          {
            __dmb(0xAu);
            __yield();
            v55 = *(_DWORD *)(v22 + 12);
            __dmb(0xBu);
          }
          while ( (v55 & 0x80000000) != 0 );
          do
            v56 = __ldrex(v54);
          while ( __strex(v56 | 0x80, v54) );
          __dmb(0xBu);
        }
        while ( v56 >> 7 );
      }
      if ( *(_DWORD *)v15 == v21 )
        goto LABEL_12;
      __dmb(0xBu);
      v57 = (unsigned int *)(v22 + 12);
      do
        v58 = __ldrex(v57);
      while ( __strex(v58 & 0x7FFFFFFF, v57) );
    }
  }
  v22 = 0;
LABEL_12:
  v97 = v22;
  if ( !v22 )
  {
    if ( !v86 )
      goto LABEL_14;
    if ( (*(_DWORD *)v15 & 0x400) != 0 )
      goto LABEL_14;
    if ( (*(_DWORD *)v15 & 0x10) == 0 )
      goto LABEL_14;
    MiUnlockProtoPoolPage(v14, v12);
    v14 = 0;
    v59 = (int)v80;
    v82 = 0;
    if ( (v85 & 2) != 0 && !MiPageHasRelocations(v80, v16) )
      goto LABEL_14;
    if ( MiGetEffectivePagePriorityThread((_DWORD *)(__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0)) <= 5 )
      v61 = MiGetEffectivePagePriorityThread((_DWORD *)(__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0));
    else
      v61 = 5;
    if ( v15 == v95 )
    {
      v62 = 4096;
      v63 = v89 + 1;
    }
    else
    {
      v95 = v15;
      v62 = (int)(v94 - v15) >> 2 << 12;
      v63 = 0;
    }
    v89 = v63;
    v64 = MiPrefetchControlArea(v59, v60, v16 << 12, 0, v62, v61, v60, v92);
    v83 = v64;
    if ( v64 < 0 )
    {
      if ( v64 != -1073741670 && v64 != -1073741663 && v64 != -1073741801 && v62 > 0x1000 )
        FsRtlIsTotalDeviceFailure(v64);
      KeDelayExecutionThread(0, 0, (unsigned int *)MiShortTime);
    }
LABEL_130:
    v19 = v84;
    goto LABEL_15;
  }
  v28 = *(_DWORD *)v15 & 2;
  v29 = *(_DWORD *)v15 >> 12;
  if ( (v85 & 4) != 0 )
  {
    v43 = *(_DWORD *)(v22 + 4) | 0x80000000;
    if ( (v43 > (v98 & ((unsigned int)MmHighestUserAddress >> 10)) - 0x40000000 || v43 < 0xC0000000)
      && ((*(unsigned __int8 *)(v22 + 19) >> 5) & 1) != 0 )
    {
      MiDriverPageIsDangling(v22);
      *(_BYTE *)(v22 + 19) &= 0xDFu;
    }
    __dmb(0xBu);
    v44 = (unsigned int *)(v22 + 12);
    do
      v45 = __ldrex(v44);
    while ( __strex(v45 & 0x7FFFFFFF, v44) );
    goto LABEL_14;
  }
  if ( (v85 & 1) != 0 && (*(_BYTE *)(v22 + 23) & 7) == 3 )
  {
    __dmb(0xBu);
    v65 = (unsigned int *)(v22 + 12);
    do
      v66 = __ldrex(v65);
    while ( __strex(v66 & 0x7FFFFFFF, v65) );
    goto LABEL_14;
  }
  if ( (*(_DWORD *)(v22 + 8) & 0x400) == 0 && !v86 )
  {
    __dmb(0xBu);
    v67 = (unsigned int *)(v22 + 12);
    do
      v68 = __ldrex(v67);
    while ( __strex(v68 & 0x7FFFFFFF, v67) );
    goto LABEL_14;
  }
  if ( !v28 && (*(_BYTE *)(v22 + 18) & 0x20) != 0 )
  {
    if ( (v85 & 2) == 0 || (v80[7] & 2) != 0 )
    {
      v69 = v82;
      v83 = 1;
      MiObtainProtoReference(v82, 1);
      MiWaitForCollidedFaultComplete(v22, v69, 0, 0, 17, v12, &v83);
      v14 = 0;
      v82 = 0;
      v83 = 0;
      goto LABEL_130;
    }
    MiDeleteLockedTransitionPte(v15, v22, 17, 1);
    goto LABEL_14;
  }
  v30 = 8;
  if ( !v28 )
  {
    if ( (*(_BYTE *)(v22 + 19) & 8) != 0 )
      v30 = *(_BYTE *)(v22 + 19) & 7;
    if ( !MiUnlinkPageFromList(v22, 0) )
    {
      MiDiscardTransitionPte(v22);
      __dmb(0xBu);
      v70 = (unsigned int *)(v22 + 12);
      do
        v71 = __ldrex(v70);
      while ( __strex(v71 & 0x7FFFFFFF, v70) );
      if ( v86 == 1 )
      {
        v14 = v82;
        goto LABEL_130;
      }
      goto LABEL_14;
    }
    *(_DWORD *)(v22 + 12) &= 0xC0000000;
  }
  MiAddLockedPageCharge(v22, 1);
  __dmb(0xBu);
  v31 = (unsigned int *)(v22 + 12);
  do
    v32 = __ldrex(v31);
  while ( __strex(v32 & 0x7FFFFFFF, v31) );
  MiUnlockProtoPoolPage(v82, v12);
  v82 = 0;
  if ( (v85 & 2) != 0 )
  {
    if ( (MiFlags & 0x100000) != 0 && (v80[13] & 0xC000000) != 0 && (*(_BYTE *)(v22 + 23) & 7) == 3 )
      v34 = 0;
    else
      v34 = MiRelocateImagePfn(v80, v96, v16, v29, 0);
  }
  else
  {
    v34 = MiValidateImagePfn(v80, v33, v84, v90, v100, v16);
  }
  v83 = v34;
  if ( v30 != 8 && !v88 )
    v88 = MiCreateDecayPfn(v30);
  v35 = 0;
  v36 = 0;
  v37 = KfRaiseIrql(2);
  v81 = v37;
  v38 = (unsigned __int8 *)(v22 + 15);
  do
    v39 = __ldrex(v38);
  while ( __strex(v39 | 0x80, v38) );
  __dmb(0xBu);
  if ( v39 >> 7 )
  {
    v72 = (unsigned __int8 *)(v22 + 15);
    do
    {
      do
      {
        __dmb(0xAu);
        __yield();
        v73 = *v31;
        __dmb(0xBu);
      }
      while ( (v73 & 0x80000000) != 0 );
      do
        v74 = __ldrex(v72);
      while ( __strex(v74 | 0x80, v72) );
      __dmb(0xBu);
    }
    while ( v74 >> 7 );
  }
  v79[0] = v37;
  if ( (v85 & 2) != 0 && (*(_DWORD *)(v22 + 8) & 0x400) == 0 )
  {
    v36 = MiSystemPartition;
    v35 = MiCaptureDirtyBitToPfn(v22);
  }
  if ( !MI_REMOVE_LOCKED_PAGE_CHARGE_RETURN_DECREF(v22) )
    goto LABEL_63;
  if ( v30 == 8 || (*(_BYTE *)(v22 + 18) & 0x10) != 0 || (*(_DWORD *)(v22 + 12) & 0x40000000) != 0 )
  {
    MiPfnReferenceCountIsZero(v22, v29);
LABEL_63:
    v41 = v81;
    goto LABEL_64;
  }
  MiInsertAndUnlockStandbyPages(v88, &v97, 1u, v81);
  v41 = 17;
  v81 = 17;
  v79[0] = 17;
LABEL_64:
  if ( v41 != 17 )
  {
    __dmb(0xBu);
    do
    {
      v42 = __ldrex(v31);
      v40 = __strex(v42 & 0x7FFFFFFF, v31);
    }
    while ( v40 );
    v41 = v81;
  }
  if ( v35 )
    MiReleasePageFileInfo((int)v36, v35, 1, v40);
  if ( v41 != 17 )
  {
    KfLowerIrql(v41);
    v81 = 17;
    v79[0] = 17;
  }
  v13 = v83;
  if ( v83 >= 0 )
  {
    v20 = v90;
    v16 = v91;
LABEL_14:
    v15 += 4;
    ++v16;
    v20 = (__PAIR64__(v20, v84) + 4096) >> 32;
    v19 = v84 + 4096;
    v14 = v82;
    v90 = v20;
    v91 = v16;
    v84 += 4096;
    goto LABEL_15;
  }
  if ( v83 == -1073741670 )
    a3 = 36;
  else
    a3 = 58;
  dword_632EE4 = a3;
LABEL_21:
  if ( v88 )
    MiDecayPfnFullyInitialized(v88, v10, a3, v88);
  v23 = v93;
  if ( !v93 )
    return v13;
  v75 = (unsigned int *)(v101 + 28);
  __dmb(0xBu);
  do
    v76 = __ldrex(v75);
  while ( v76 == 17 && __strex(0, v75) );
  if ( v76 != 17 )
    ExfReleasePushLockShared(v75, 0);
  v77 = KeAbPostRelease((unsigned int)v75);
  v78 = *(_WORD *)(v23 + 310) + 1;
  *(_WORD *)(v23 + 310) = v78;
  if ( !v78 && *(_DWORD *)(v23 + 100) != v23 + 100 )
    KiCheckForKernelApcDelivery(v77);
  return v13;
}
