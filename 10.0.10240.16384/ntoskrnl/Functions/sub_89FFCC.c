// sub_89FFCC 
 
int __fastcall sub_89FFCC(int a1, unsigned int a2, _DWORD *a3, int a4, unsigned __int8 a5)
{
  _DWORD *v6; // r7
  unsigned int v7; // r10
  int v9; // r9
  unsigned int v10; // r4
  int v11; // r4
  int v12; // r0
  int v13; // r4
  unsigned int v14; // r5
  unsigned int v15; // r6
  int v16; // r0
  int v17; // r3
  int v18; // r0
  int v19; // r4
  int v20; // r6
  unsigned int v21; // r0
  int v22; // r3
  int v23; // r1
  unsigned __int8 *v24; // r0
  int v25; // r2
  int v26; // r4
  int v27; // t1
  unsigned int v28; // r2
  int v29; // r0
  int v30; // r4
  unsigned int v31; // r1
  bool v32; // zf
  unsigned int *v33; // r2
  unsigned int v34; // r1
  unsigned int v35; // r0
  int v36; // r0
  unsigned int v37; // r1
  int v38; // r3
  unsigned int *v39; // r2
  unsigned int v40; // r1
  int v41; // r4
  int v42; // lr
  int v43; // r10
  int v44; // r6
  int v45; // r5
  __int64 *v46; // r1
  int v47; // r0
  int v48; // t1
  int v49; // lr
  int v50; // r9
  int *v51; // r1
  unsigned int v52; // r0
  int v53; // r3
  int v54; // r2
  int v55; // r3
  int *v56; // r4
  int v57; // r7
  int v58; // t1
  int v59; // r4
  int v60; // r0
  int v61; // r9
  unsigned __int8 *v62; // r1
  int v63; // r5
  int v64; // t1
  unsigned int i; // r1
  int v66; // r3
  int *v67; // r3
  int v68; // r2
  int v69; // r3
  int *v70; // r5
  int v71; // r6
  int v72; // t1
  int v73; // r0
  int v74; // r6
  int v75; // r0
  int v76; // r4
  unsigned int v77; // r1
  int v78; // r5
  int *v79; // r6
  unsigned int v80; // r3
  unsigned int v81; // r3
  int v82; // r3
  unsigned int v83; // r0
  unsigned int v84; // r0
  int v85; // r0
  unsigned int v86; // r1
  __int16 v87; // r3
  unsigned int v88; // r0
  int v89; // r0
  unsigned int v90; // r1
  __int16 v91; // r3
  int v93; // [sp+20h] [bp-A0h]
  _DWORD *v94; // [sp+24h] [bp-9Ch] BYREF
  int v95; // [sp+28h] [bp-98h] BYREF
  int v96; // [sp+2Ch] [bp-94h] BYREF
  int v97; // [sp+30h] [bp-90h]
  int v98; // [sp+34h] [bp-8Ch]
  int v99; // [sp+38h] [bp-88h]
  int v100; // [sp+3Ch] [bp-84h] BYREF
  unsigned int v101; // [sp+40h] [bp-80h] BYREF
  int v102; // [sp+44h] [bp-7Ch]
  int v103[2]; // [sp+48h] [bp-78h] BYREF
  int v104; // [sp+50h] [bp-70h] BYREF
  int v105; // [sp+54h] [bp-6Ch]
  int v106; // [sp+58h] [bp-68h]
  int v107; // [sp+5Ch] [bp-64h]
  int v108; // [sp+60h] [bp-60h] BYREF
  int v109; // [sp+64h] [bp-5Ch]
  unsigned int v110; // [sp+68h] [bp-58h]
  unsigned int v111; // [sp+6Ch] [bp-54h]
  int v112; // [sp+70h] [bp-50h] BYREF
  int v113; // [sp+74h] [bp-4Ch] BYREF
  __int64 v114; // [sp+78h] [bp-48h] BYREF
  _DWORD v115[2]; // [sp+80h] [bp-40h] BYREF
  _DWORD v116[14]; // [sp+88h] [bp-38h] BYREF

  v99 = a4;
  v6 = 0;
  v93 = 0;
  v94 = 0;
  v7 = 0;
  v101 = 0;
  v96 = 0;
  v97 = a1;
  v9 = 0;
  v95 = 0;
  v110 = 0;
  v111 = 0;
  v109 = 0;
  __dmb(0xBu);
  do
    v10 = __ldrex((unsigned int *)&ExpFastCacheReArmed);
  while ( !v10 && __strex(0, (unsigned int *)&ExpFastCacheReArmed) );
  __dmb(0xBu);
  if ( v10 == 1 )
    return -1073700219;
  if ( !a5 && !a4 )
    return -1073741811;
  v11 = ExpValidateFastCacheSize(a1, a2, &v113);
  if ( v11 < 0 )
    return v11;
  if ( v99 )
  {
    if ( a2 <= 0x18 )
      return -1073741811;
  }
  else if ( a2 < 0x18 )
  {
    return -1073741811;
  }
  if ( a2 - 24 != a3[2] || *a3 != 1 || (a3[1] & 0xFFFF0000) != 0 )
    return -1073741811;
  if ( v99 )
  {
    v16 = ExAllocatePoolWithTag(1, a2, 542329939);
    v93 = v16;
    if ( !v16 )
      return -1073741801;
    v13 = v16;
  }
  else
  {
    v12 = sub_7A2A90(a2, &v95, (int *)&v94);
    v6 = v94;
    v9 = v95;
    v11 = v12;
    if ( v12 < 0 )
    {
      v14 = 0;
      v15 = 0;
      goto LABEL_134;
    }
    v13 = (int)v94;
  }
  memmove(v13, (int)a3, a2);
  v18 = ExpParseFastCacheHelper(v13, (unsigned int *)&v100, (unsigned int *)&v96, v17);
  v11 = v18;
  if ( v18 < 0 )
  {
    v14 = v96;
    v15 = v93;
    if ( v18 == -1073741762 )
      v11 = -1073741811;
    goto LABEL_134;
  }
  v19 = v100;
  if ( v99 )
  {
    v14 = v96;
    v106 = v96;
    goto LABEL_34;
  }
  v20 = 0;
  v7 = v96;
  v102 = 0;
  v112 = 0;
  if ( v100 )
  {
    v21 = v96;
    do
    {
      v22 = *(_DWORD *)(v21 + 4);
      v21 += 8;
      --v19;
      *(_QWORD *)(v22 + 32) = qword_922C10 + (unsigned int)dword_920280;
    }
    while ( v19 );
    v19 = v100;
    v20 = 0;
  }
  v14 = 0;
  v106 = 0;
  v96 = 0;
  v98 = v19;
  v108 = v19;
  v101 = v7;
  while ( 1 )
  {
    v6[4] = 0;
    v6[5] = 0;
    v23 = v6[2];
    v24 = (unsigned __int8 *)(v6 + 6);
    if ( v6 == (_DWORD *)-24 || v6 == (_DWORD *)-16 )
    {
      v11 = -1073741811;
      goto LABEL_133;
    }
    v25 = v6[4];
    v26 = 0;
    if ( v23 )
    {
      do
      {
        v27 = *v24++;
        v26 = __ROR4__(-23737705 * __ROR4__(-23737705 * __ROR4__(-23737705 * (v27 - 23737705 + v26), 21), 21), 21);
        v25 += v27 - 23737705 + v26;
        --v23;
      }
      while ( v23 );
      v14 = v106;
      v20 = v102;
    }
    v6[4] = v25;
    v6[5] = v26;
    v28 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    --*(_WORD *)(v28 + 308);
    v29 = KeAbPreAcquire((unsigned int)&ExpFastCacheUpdateLock, 0, 0);
    v30 = v29;
    do
      v31 = __ldrex((unsigned __int8 *)&ExpFastCacheUpdateLock);
    while ( __strex(v31 | 1, (unsigned __int8 *)&ExpFastCacheUpdateLock) );
    __dmb(0xBu);
    if ( (v31 & 1) != 0 )
      ExfAcquirePushLockExclusiveEx(&ExpFastCacheUpdateLock, v29, (unsigned int)&ExpFastCacheUpdateLock);
    if ( v30 )
      *(_BYTE *)(v30 + 14) |= 1u;
    v32 = v99 == 0;
    __dmb(0xBu);
    if ( v32 )
      break;
    v33 = (unsigned int *)((char *)&unk_920298 + 40 * v97);
    do
      v34 = __ldrex(v33);
    while ( v34 == v20 && __strex(v20 + 1, v33) );
    __dmb(0xBu);
    if ( v34 == v20 )
      goto LABEL_70;
    __dmb(0xBu);
    do
      v35 = __ldrex(&ExpFastCacheUpdateLock);
    while ( __strex(v35 - 1, &ExpFastCacheUpdateLock) );
    if ( (v35 & 2) != 0 && (v35 & 4) == 0 )
      ExfTryToWakePushLock(&ExpFastCacheUpdateLock);
    v36 = KeAbPostRelease((unsigned int)&ExpFastCacheUpdateLock);
    v37 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    v19 = v100;
    v38 = (__int16)(*(_WORD *)(v37 + 0x134) + 1);
    *(_WORD *)(v37 + 308) = v38;
    if ( !v38 )
    {
      v19 = v100;
      if ( *(_DWORD *)(v37 + 100) != v37 + 100 )
      {
        v19 = v100;
        if ( !*(_WORD *)(v37 + 310) )
          KiCheckForKernelApcDelivery(v36);
      }
    }
LABEL_34:
    if ( v9 )
    {
      ObfDereferenceObject(v9);
      v95 = 0;
    }
    if ( v6 )
    {
      MmUnmapViewInSystemSpace((unsigned int)v6);
      v94 = 0;
    }
    if ( v7 )
    {
      ExFreePoolWithTag(v7);
      v101 = 0;
    }
    v15 = v93;
    v11 = sub_8A0B68(v97, v113, v93, a5, v19, v14, &v112, &v95, &v94, &v108, &v101);
    v6 = v94;
    v9 = v95;
    v7 = v101;
    if ( v11 < 0 )
      goto LABEL_134;
    v20 = v112;
    v102 = v112;
    v98 = v108;
  }
  v39 = (unsigned int *)((char *)&unk_920298 + 40 * v97);
  do
    v40 = __ldrex(v39);
  while ( __strex(v40 + 1, v39) );
  __dmb(0xBu);
LABEL_70:
  v42 = v6[5];
  v41 = v6[4];
  v102 = v41;
  v99 = v42;
  if ( !dword_922C18 )
  {
    v11 = sub_7B5F04((int)&dword_8C8214, &dword_922C18);
    if ( v11 < 0 )
      goto LABEL_123;
    v41 = v102;
  }
  v43 = HIDWORD(qword_922C10);
  v44 = 0;
  v45 = 0;
  v46 = &v114;
  v98 = qword_922C10;
  v114 = qword_922C10;
  v47 = 8;
  do
  {
    v48 = *(unsigned __int8 *)v46;
    v46 = (__int64 *)((char *)v46 + 1);
    v45 = __ROR4__(-23737705 * __ROR4__(-23737705 * __ROR4__(-23737705 * (v48 - 23737705 + v45), 21), 21), 21);
    v44 += v48 - 23737705 + v45;
    --v47;
  }
  while ( v47 );
  v49 = v99;
  v50 = v97;
  v51 = dword_920288;
  v52 = 0;
  do
  {
    v53 = ExpFastCacheReArmed;
    __dmb(0xBu);
    if ( v53 )
      goto LABEL_82;
    if ( v52 != v50 )
    {
      v54 = v51[1];
      if ( !v54 || v51[5] )
      {
LABEL_82:
        v55 = 0;
        v104 = 0;
      }
      else
      {
        v104 = *(_DWORD *)(v54 + 16);
        v55 = *(_DWORD *)(v54 + 20);
      }
      v105 = v55;
      goto LABEL_84;
    }
    v104 = v41;
    v105 = v49;
LABEL_84:
    v56 = &v104;
    v57 = 8;
    do
    {
      v58 = *(unsigned __int8 *)v56;
      v56 = (int *)((char *)v56 + 1);
      v45 = __ROR4__(-23737705 * __ROR4__(-23737705 * __ROR4__(-23737705 * (v58 - 23737705 + v45), 21), 21), 21);
      v44 += v58 - 23737705 + v45;
      --v57;
    }
    while ( v57 );
    v106 = v44;
    v107 = v45;
    ++v52;
    v41 = v102;
    v49 = v99;
    v50 = v97;
    v51 += 10;
  }
  while ( v52 < 5 );
  v59 = 0;
  v60 = 0;
  v61 = v98;
  if ( v97 != -1 )
  {
    v62 = (unsigned __int8 *)v115;
    v63 = 8;
    v115[0] = v98;
    v115[1] = v43;
    do
    {
      v64 = *v62++;
      v60 = __ROR4__(-23737705 * __ROR4__(-23737705 * __ROR4__(-23737705 * (v64 - 23737705 + v60), 21), 21), 21);
      v59 += v60 + v64 - 23737705;
      --v63;
    }
    while ( v63 );
    for ( i = 0; i < 5; ++i )
    {
      v66 = ExpFastCacheReArmed;
      __dmb(0xBu);
      if ( v66 || (v67 = &dword_920288[10 * i], (v68 = v67[1]) == 0) || v67[5] )
      {
        v69 = 0;
        v103[0] = 0;
      }
      else
      {
        v103[0] = *(_DWORD *)(v68 + 16);
        v69 = *(_DWORD *)(v68 + 20);
      }
      v70 = v103;
      v71 = 8;
      v103[1] = v69;
      do
      {
        v72 = *(unsigned __int8 *)v70;
        v70 = (int *)((char *)v70 + 1);
        v60 = __ROR4__(-23737705 * __ROR4__(-23737705 * __ROR4__(-23737705 * (v72 - 23737705 + v60), 21), 21), 21);
        v59 += v60 + v72 - 23737705;
        --v71;
      }
      while ( v71 );
    }
    v44 = v106;
    v45 = v107;
    v61 = v98;
  }
  v116[4] = v59;
  v116[5] = v60;
  v116[0] = v61;
  v116[1] = v43;
  v116[2] = v44;
  v116[3] = v45;
  v73 = CmSetValueKey((_DWORD *)dword_922C18, (unsigned __int16 *)&dword_8C81C4, 3, (int)v116, 0x18u, 0, 0);
  v9 = v95;
  v14 = v96;
  v6 = v94;
  v7 = v101;
  v106 = v96;
  v98 = v108;
  v11 = v73;
  if ( v73 >= 0 )
  {
    v74 = v97;
    v11 = sub_8A10B0(v97, v94);
    if ( v11 >= 0 )
    {
      v75 = KeAbPreAcquire((unsigned int)&ExpFastCacheLock, 0, 0);
      v76 = v75;
      do
        v77 = __ldrex((unsigned __int8 *)&ExpFastCacheLock);
      while ( __strex(v77 | 1, (unsigned __int8 *)&ExpFastCacheLock) );
      __dmb(0xBu);
      if ( (v77 & 1) != 0 )
        ExfAcquirePushLockExclusiveEx(&ExpFastCacheLock, v75, (unsigned int)&ExpFastCacheLock);
      if ( v76 )
        *(_BYTE *)(v76 + 14) |= 1u;
      v78 = 5 * v74;
      v79 = &dword_920288[10 * v74];
      v80 = v79[1];
      v109 = dword_920288[2 * v78];
      v110 = v80;
      ObfReferenceObject(v9);
      v81 = v79[2];
      v79[1] = (int)v6;
      v79[2] = v7;
      v6 = 0;
      v111 = v81;
      v82 = v98;
      dword_920288[2 * v78] = v9;
      v7 = 0;
      v79[3] = v82;
      v79[5] = 0;
      __dmb(0xBu);
      do
        v83 = __ldrex(&ExpFastCacheLock);
      while ( __strex(v83 - 1, &ExpFastCacheLock) );
      if ( (v83 & 2) != 0 && (v83 & 4) == 0 )
        ExfTryToWakePushLock(&ExpFastCacheLock);
      KeAbPostRelease((unsigned int)&ExpFastCacheLock);
      __dmb(0xBu);
      do
        v84 = __ldrex(&ExpFastCacheUpdateLock);
      while ( __strex(v84 - 1, &ExpFastCacheUpdateLock) );
      if ( (v84 & 2) != 0 && (v84 & 4) == 0 )
        ExfTryToWakePushLock(&ExpFastCacheUpdateLock);
      v85 = KeAbPostRelease((unsigned int)&ExpFastCacheUpdateLock);
      v86 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
      v87 = *(_WORD *)(v86 + 0x134) + 1;
      *(_WORD *)(v86 + 308) = v87;
      if ( !v87 && *(_DWORD *)(v86 + 100) != v86 + 100 && !*(_WORD *)(v86 + 310) )
        KiCheckForKernelApcDelivery(v85);
      v14 = v106;
      v11 = 0;
      goto LABEL_133;
    }
  }
LABEL_123:
  __dmb(0xBu);
  do
    v88 = __ldrex(&ExpFastCacheUpdateLock);
  while ( __strex(v88 - 1, &ExpFastCacheUpdateLock) );
  if ( (v88 & 2) != 0 && (v88 & 4) == 0 )
    ExfTryToWakePushLock(&ExpFastCacheUpdateLock);
  v89 = KeAbPostRelease((unsigned int)&ExpFastCacheUpdateLock);
  v90 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v91 = *(_WORD *)(v90 + 0x134) + 1;
  *(_WORD *)(v90 + 308) = v91;
  if ( !v91 && *(_DWORD *)(v90 + 100) != v90 + 100 && !*(_WORD *)(v90 + 310) )
    KiCheckForKernelApcDelivery(v89);
LABEL_133:
  v15 = v93;
LABEL_134:
  if ( v9 )
    ObfDereferenceObject(v9);
  if ( v109 )
    ObfDereferenceObject(v109);
  if ( v6 )
    MmUnmapViewInSystemSpace((unsigned int)v6);
  if ( v110 )
    MmUnmapViewInSystemSpace(v110);
  if ( v14 )
    ExFreePoolWithTag(v14);
  if ( v7 )
    ExFreePoolWithTag(v7);
  if ( v111 )
    ExFreePoolWithTag(v111);
  if ( v15 )
    ExFreePoolWithTag(v15);
  return v11;
}
