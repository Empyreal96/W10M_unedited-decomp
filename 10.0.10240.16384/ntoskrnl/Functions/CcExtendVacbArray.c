// CcExtendVacbArray 
 
// local variable allocation has failed, the output may be wrong!
int __fastcall CcExtendVacbArray(_DWORD *a1, int a2, __int64 a3)
{
  unsigned int v3; // r5
  unsigned int v4; // r6
  _DWORD *v5; // r4
  int v6; // r9
  __int64 v7; // r0
  unsigned int v9; // r2
  unsigned int v10; // r3
  unsigned int v11; // r0
  unsigned int v12; // r3
  unsigned int v13; // r7
  unsigned int v14; // r8
  unsigned int v15; // r7
  unsigned int v16; // r3
  unsigned __int8 *v17; // r9
  int v18; // r0
  int v19; // r5
  unsigned int v20; // r2
  _DWORD *v21; // r10
  int v22; // r6
  int v23; // r7
  int v24; // r1
  int v25; // r1
  unsigned int v26; // r0
  unsigned int v27; // r2
  __int64 v28; // kr08_8
  unsigned __int8 *v29; // r6
  int v30; // r5
  int v31; // r9
  unsigned int v32; // r2
  unsigned int v33; // r0
  signed int v34; // r6
  unsigned int v35; // r1
  char *v36; // r5
  __int64 v37; // kr10_8
  unsigned int *v38; // r2
  unsigned int v39; // r5
  unsigned int *v40; // r5
  int v41; // r6
  unsigned int v42; // r1
  unsigned int *i; // r2
  unsigned int v44; // r3
  int v45; // r3
  unsigned int v46; // r5
  unsigned int v47; // r5
  int v48; // r3
  unsigned int v49; // r7
  int v50; // r8
  int v51; // r3
  signed __int64 v52; // kr40_8
  unsigned int v53; // r9
  int v54; // r0
  unsigned __int8 *v55; // r6
  int v56; // r5
  int v57; // r8
  unsigned int v58; // r2
  unsigned __int8 *v59; // r6
  int v60; // r0
  int v61; // r5
  unsigned int v62; // r2
  int v63; // r3
  int v64; // r8
  _BYTE *v65; // r5
  int v66; // r1 OVERLAPPED
  _DWORD *v67; // r2 OVERLAPPED
  _BYTE *v68; // r5
  __int64 v69; // kr48_8
  int v70; // r2
  _DWORD *v71; // r3
  unsigned int v72; // r3
  int v73; // r1
  unsigned int v74; // r0
  unsigned int v75; // r2
  unsigned int *v76; // r5
  int v77; // r6
  unsigned int v78; // r1
  int v79; // [sp+8h] [bp-50h]
  __int64 v80; // [sp+Ch] [bp-4Ch]
  int v81; // [sp+14h] [bp-44h]
  int v82; // [sp+18h] [bp-40h]
  unsigned int v83; // [sp+1Ch] [bp-3Ch]
  int v85[3]; // [sp+28h] [bp-30h] BYREF
  int v86; // [sp+34h] [bp-24h]
  _DWORD *varg_r0; // [sp+60h] [bp+8h]
  int varg_r1; // [sp+64h] [bp+Ch]
  __int64 varg_r2; // [sp+68h] [bp+10h]

  varg_r0 = a1;
  varg_r1 = a2;
  v3 = HIDWORD(a3);
  v4 = a3;
  v5 = a1;
  v6 = 0;
  HIDWORD(v7) = 0;
  varg_r2 = a3;
  v79 = 0;
  v82 = 0;
  if ( a3 < 0 )
    return sub_526614();
  if ( (a1[24] & 0x200) != 0 && a3 > 0x200000 )
  {
    v6 = 1;
    v79 = 1;
  }
  v85[1] = (int)v85;
  v9 = a1[7];
  v85[0] = (int)v85;
  v85[2] = 0;
  v86 = 0;
  v10 = a1[6];
  if ( __SPAIR64__(v3, v4) <= __SPAIR64__(v9, v10) )
    goto LABEL_47;
  v11 = 0x2000000;
  if ( __SPAIR64__(v9, v10) >= 0x2000000 )
    goto LABEL_46;
  v12 = v4;
  v13 = v3;
  v80 = __PAIR64__(v3, v4);
  if ( __SPAIR64__(v3, v4) >= 0x2000000 )
  {
    v13 = 0;
    HIDWORD(v7) = 1;
    v12 = 0x2000000;
    v82 = 1;
    v80 = 0x2000000i64;
  }
  v14 = -1;
  if ( v13 )
  {
    v15 = -1;
  }
  else if ( v12 <= 0x100000 )
  {
    v15 = 16;
  }
  else
  {
    v15 = 4 * (v12 >> 18);
  }
  v83 = v15;
  if ( !v5[7] )
  {
    v16 = v5[6];
    if ( v16 <= 0x100000 )
      v14 = 16;
    else
      v14 = 4 * (v16 >> 18);
  }
  if ( v15 > v14 )
  {
    if ( v6 )
      v15 += (v15 + 7) & 0xFFFFFFF8;
    if ( HIDWORD(v7) )
      v15 += 8;
    v81 = ExAllocatePoolWithTag(512, v15, 1884709699);
    if ( !v81 )
      return -1073741670;
    if ( v6 )
    {
      v29 = (unsigned __int8 *)(v5 + 45);
      v30 = KeAbPreAcquire(v5 + 45, 0, 0);
      v31 = KfRaiseIrql(1);
      do
        v32 = __ldrex(v29);
      while ( __strex(v32 & 0xFE, v29) );
      __dmb(0xBu);
      if ( (v32 & 1) == 0 )
        ExpAcquireFastMutexContended(v5 + 45, v30);
      if ( v30 )
        *(_BYTE *)(v30 + 14) |= 1u;
      v5[46] = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
      v5[52] = v31;
    }
    v17 = (unsigned __int8 *)(v5 + 18);
    v18 = KeAbPreAcquire(v5 + 18, 0, 0);
    v19 = v18;
    do
      v20 = __ldrex(v17);
    while ( __strex(v20 | 1, v17) );
    __dmb(0xBu);
    if ( (v20 & 1) != 0 )
      ExfAcquirePushLockExclusiveEx(v5 + 18, v18, v5 + 18);
    if ( v19 )
      *(_BYTE *)(v19 + 14) |= 1u;
    v21 = (_DWORD *)v5[16];
    if ( v21 )
      memmove(v81, v5[16], v14);
    else
      v14 = 0;
    memset((_BYTE *)(v81 + v14), 0, v83 - v14);
    if ( v82 )
    {
      v44 = v81 + v15;
      *(_DWORD *)(v44 - 8) = 0;
      *(_DWORD *)(v44 - 4) = 0;
    }
    v22 = v79;
    if ( !v79 )
    {
      v23 = v80;
LABEL_33:
      v24 = HIDWORD(v80);
      __pld(v17);
      v5[6] = v23;
      v5[7] = v24;
      v5[16] = v81;
      v25 = *(_DWORD *)v17;
      if ( (*(_DWORD *)v17 & 0xFFFFFFF0) > 0x10 )
        v26 = v25 - 16;
      else
        v26 = 0;
      if ( (v25 & 2) != 0 )
        goto LABEL_96;
      __dmb(0xBu);
      do
        v27 = __ldrex((unsigned int *)v17);
      while ( v27 == v25 && __strex(v26, (unsigned int *)v17) );
      if ( v27 != v25 )
LABEL_96:
        ExfReleasePushLock(v5 + 18);
      KeAbPostRelease(v5 + 18);
      if ( v22 )
      {
        v40 = v5 + 45;
        v41 = v5[52];
        v5[46] = 0;
        __dmb(0xBu);
        do
          v42 = __ldrex(v40);
        while ( !v42 && __strex(1u, v40) );
        if ( v42 )
          ExpReleaseFastMutexContended(v5 + 45, v42, 1);
        KfLowerIrql((unsigned __int8)v41);
        KeAbPostRelease(v5 + 45);
      }
      if ( v21 != v5 + 12 && v21 )
        ExFreePoolWithTag(v21, 0);
      v3 = HIDWORD(varg_r2);
      v4 = varg_r2;
      v11 = 0x2000000;
      goto LABEL_45;
    }
    v33 = 0;
    v34 = 0;
    v35 = v81 + v83;
    if ( *((__int64 *)v5 + 3) > 0x200000 && v21 )
    {
      v36 = (char *)v21 + v14;
      do
      {
        v37 = *(_QWORD *)v36;
        if ( *(char **)(*(_DWORD *)v36 + 4) != v36 || *(char **)HIDWORD(v37) != v36 )
          __fastfail(3u);
        *(_DWORD *)HIDWORD(v37) = v37;
        *(_DWORD *)(v37 + 4) = HIDWORD(v37);
        *(_QWORD *)v35 = v37;
        if ( *(_DWORD *)HIDWORD(v37) != (_DWORD)v37 )
          __fastfail(3u);
        *(_DWORD *)HIDWORD(v37) = v35;
        *(_DWORD *)(v37 + 4) = v35;
        v34 = (__PAIR64__(v34, v33) + 0x80000) >> 32;
        v33 += 0x80000;
        v36 += 8;
        v35 += 8;
      }
      while ( __SPAIR64__(v34, v33) < *((_QWORD *)v5 + 3) );
LABEL_65:
      v23 = v80;
      if ( __SPAIR64__(v34, v33) < v80 )
      {
        v38 = v5 + 4;
        do
        {
          v39 = *v38;
          *(_DWORD *)v35 = *v38;
          *(_DWORD *)(v35 + 4) = v38;
          if ( *(unsigned int **)(v39 + 4) != v38 )
            __fastfail(3u);
          *(_DWORD *)(v39 + 4) = v35;
          v34 = (__PAIR64__(v34, v33) + 0x80000) >> 32;
          v33 += 0x80000;
          *v38 = v35;
          v35 += 8;
        }
        while ( __SPAIR64__(v34, v33) < v80 );
      }
      v22 = v79;
      goto LABEL_33;
    }
    for ( i = (unsigned int *)v5[5]; ; i = (unsigned int *)i[1] )
    {
      if ( i == v5 + 4 )
        goto LABEL_65;
      v45 = *(i - 1);
      v46 = *(i - 2);
      if ( v34 <= v45 )
      {
        if ( v34 >= v45 )
        {
LABEL_91:
          if ( v33 > v46 )
            continue;
        }
        do
        {
          v47 = *i;
          *(_DWORD *)v35 = *i;
          *(_DWORD *)(v35 + 4) = i;
          if ( *(unsigned int **)(v47 + 4) != i )
            __fastfail(3u);
          *(_DWORD *)(v47 + 4) = v35;
          *i = v35;
          v48 = *(i - 1);
          v46 = *(i - 2);
          v34 = (__PAIR64__(v34, v33) + 0x80000) >> 32;
          v33 += 0x80000;
          v35 += 8;
        }
        while ( v34 < v48 );
        if ( v34 <= v48 )
          goto LABEL_91;
      }
    }
  }
  v23 = v80;
LABEL_45:
  v10 = HIDWORD(v80);
  v5[6] = v23;
  v5[7] = HIDWORD(v80);
LABEL_46:
  v28 = *((_QWORD *)v5 + 3);
  HIDWORD(v7) = HIDWORD(v28);
  v9 = v28;
  if ( __SPAIR64__(v3, v4) <= v28 )
  {
LABEL_47:
    CcFreeUnusedVacbLevels(v85, HIDWORD(v7), v9, v10);
    return 0;
  }
  v49 = 1;
  v50 = 25;
  if ( v28 >= 0 )
  {
    if ( SHIDWORD(v28) <= 0 )
      goto LABEL_101;
    do
    {
      do
      {
        v50 += 7;
        v51 = 1 << (v50 - 32);
        ++v49;
        v11 = 1 << v50;
      }
      while ( SHIDWORD(v28) > v51 );
      if ( SHIDWORD(v28) < v51 )
        break;
LABEL_101:
      ;
    }
    while ( (unsigned int)v28 > v11 );
  }
  v52 = __PAIR64__(v3, v4) - 1;
  v9 = v50;
  v53 = v49;
  v7 = (__int64)(__PAIR64__(v3, v4) - 1) >> v50;
  v10 = v7 | HIDWORD(v7);
  if ( !v7 )
    goto LABEL_161;
  do
  {
    v50 += 7;
    v9 = v50;
    ++v53;
    v7 = v52 >> v50;
    v10 = v7 | HIDWORD(v7);
  }
  while ( v52 >> v50 );
  v5 = a1;
  if ( v53 <= v49 )
  {
LABEL_161:
    v5[6] = v4;
    v5[7] = v3;
    goto LABEL_47;
  }
  v54 = KeAcquireQueuedSpinLock(4);
  if ( v53 >= CcMaxVacbLevelsSeen )
    CcMaxVacbLevelsSeen = v53 + 1;
  KeReleaseQueuedSpinLock(4, v54);
  if ( CcAllocateVacbLevels(v53 - v49, 0, v85) )
  {
    if ( v79 )
    {
      v55 = (unsigned __int8 *)(a1 + 45);
      v56 = KeAbPreAcquire(a1 + 45, 0, 0);
      v57 = KfRaiseIrql(1);
      do
        v58 = __ldrex(v55);
      while ( __strex(v58 & 0xFE, v55) );
      __dmb(0xBu);
      if ( (v58 & 1) == 0 )
        ExpAcquireFastMutexContended(a1 + 45, v56);
      if ( v56 )
        *(_BYTE *)(v56 + 14) |= 1u;
      a1[46] = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
      a1[52] = v57;
    }
    v59 = (unsigned __int8 *)(a1 + 18);
    v60 = KeAbPreAcquire(a1 + 18, 0, 0);
    v61 = v60;
    do
      v62 = __ldrex(v59);
    while ( __strex(v62 | 1, v59) );
    __dmb(0xBu);
    if ( (v62 & 1) != 0 )
      ExfAcquirePushLockExclusiveEx(a1 + 18, v60, a1 + 18);
    if ( v61 )
      *(_BYTE *)(v61 + 14) |= 1u;
    if ( v49 == 1 )
      CcCalculateVacbLevelLockCount(a1, a1[16]);
    if ( v49 == 1 && (a1[24] & 0x200) != 0 )
      v63 = 512;
    else
      v63 = 0;
    v64 = a1[16];
    if ( *(_QWORD *)(v63 + v64 + 512) )
    {
      do
      {
        v65 = (_BYTE *)v85[0];
        ++v49;
        if ( (int *)v85[0] == v85 )
          KeBugCheckEx(52, 4324, -1073740768);
        *(_QWORD *)&v66 = *(_QWORD *)v85[0];
        if ( *(_DWORD *)(*(_DWORD *)v85[0] + 4) != v85[0] || *v67 != v85[0] )
          __fastfail(3u);
        *v67 = v66;
        *(_DWORD *)(v66 + 4) = v67;
        --v86;
        memset(v65, 0, 520);
        *(_DWORD *)v65 = 0;
        *(_DWORD *)v65 = a1[16];
        ReferenceVacbLevel(a1, v65, v49, 1, 0);
        a1[16] = v65;
      }
      while ( v53 > v49 );
    }
    else if ( v49 == 1 && (a1[24] & 0x200) != 0 )
    {
      v68 = (_BYTE *)v85[0];
      if ( (int *)v85[0] == v85 )
        KeBugCheckEx(52, 4324, -1073740768);
      v69 = *(_QWORD *)v85[0];
      if ( *(_DWORD *)(*(_DWORD *)v85[0] + 4) != v85[0] || *(_DWORD *)HIDWORD(v69) != v85[0] )
        __fastfail(3u);
      *(_DWORD *)HIDWORD(v69) = v69;
      *(_DWORD *)(v69 + 4) = HIDWORD(v69);
      --v86;
      memset(v68, 0, 520);
      *(_DWORD *)v68 = 0;
      a1[16] = v68;
      v70 = *(_DWORD *)(v64 + 512);
      v71 = *(_DWORD **)(v64 + 1020);
      *(_DWORD *)(v70 + 4) = v71;
      *v71 = v70;
      ExFreeToNPagedLookasideList(&CcVacbLevelWithBcbListHeadsLookasideList, v64);
    }
    v72 = varg_r2;
    __pld(v59);
    *((_QWORD *)a1 + 3) = __PAIR64__(HIDWORD(varg_r2), v72);
    v73 = *(_DWORD *)v59;
    if ( (*(_DWORD *)v59 & 0xFFFFFFF0) <= 0x10 )
      v74 = 0;
    else
      v74 = v73 - 16;
    if ( (v73 & 2) != 0 )
      goto LABEL_152;
    __dmb(0xBu);
    do
      v75 = __ldrex((unsigned int *)v59);
    while ( v75 == v73 && __strex(v74, (unsigned int *)v59) );
    if ( v75 != v73 )
LABEL_152:
      ExfReleasePushLock(a1 + 18);
    KeAbPostRelease(a1 + 18);
    if ( v79 )
    {
      v76 = a1 + 45;
      v77 = a1[52];
      a1[46] = 0;
      __dmb(0xBu);
      do
        v78 = __ldrex(v76);
      while ( !v78 && __strex(1u, v76) );
      if ( v78 )
        ExpReleaseFastMutexContended(a1 + 45, v78, 1);
      KfLowerIrql((unsigned __int8)v77);
      KeAbPostRelease(a1 + 45);
    }
    v3 = HIDWORD(varg_r2);
    v4 = varg_r2;
    goto LABEL_161;
  }
  return -1073741670;
}
