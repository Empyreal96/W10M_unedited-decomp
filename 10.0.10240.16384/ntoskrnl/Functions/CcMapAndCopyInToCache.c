// CcMapAndCopyInToCache 
 
int __fastcall CcMapAndCopyInToCache(int a1, int a2, unsigned int *a3, int a4, int a5, int a6, _QWORD *a7, unsigned __int8 a8, int a9)
{
  unsigned int v9; // r5
  int v10; // r10
  BOOL v11; // r3
  int v12; // r1
  int v13; // r6
  _DWORD *v14; // r8
  int v15; // r4
  _DWORD *v16; // r1
  int v17; // r2
  int v18; // r0
  int v20; // r10
  int v21; // r2
  int *v22; // r4
  int v23; // r0
  unsigned int *v24; // r2
  unsigned int v25; // r1
  unsigned int *v26; // r2
  unsigned int v27; // r0
  int v28; // r1
  _DWORD *v29; // r2
  int *v30; // r0
  int v31; // r3
  unsigned int *v32; // r2
  unsigned int v33; // r1
  unsigned int *v34; // r2
  unsigned int v35; // r0
  unsigned int v36; // r1
  int v37; // r4
  int v38; // r1
  unsigned int v39; // r4
  int v40; // r0
  unsigned int v41; // r8
  unsigned int v42; // r0
  unsigned int v43; // r10
  int v44; // r3
  int v45; // r1
  int v46; // r2
  int v47; // r0
  int v48; // r0
  unsigned int v49; // r1
  unsigned int v50; // r2
  int v51; // r2
  unsigned int v52; // r0
  int v53; // r3
  int v54; // r0
  unsigned int *v55; // r2
  unsigned int v56; // r1
  unsigned int v57; // r1
  int v58; // r0
  int v59; // r0
  unsigned int v60; // kr00_4
  unsigned __int64 v61; // kr08_8
  unsigned int v62; // r1
  int v63; // r2
  int v64; // r3
  int v65; // r0
  unsigned int *v66; // r2
  unsigned int v67; // r1
  unsigned int v68; // r1
  int v69; // r0
  unsigned int v70; // r2
  unsigned int *v71; // r1
  int v72; // r0
  int v73; // r0
  char v75; // [sp+10h] [bp-B0h]
  char v76; // [sp+11h] [bp-AFh]
  char v77; // [sp+12h] [bp-AEh]
  char v78; // [sp+13h] [bp-ADh]
  unsigned __int8 v79; // [sp+14h] [bp-ACh]
  int v81; // [sp+1Ch] [bp-A4h]
  int v82; // [sp+20h] [bp-A0h]
  unsigned int v83; // [sp+24h] [bp-9Ch] BYREF
  unsigned int v84; // [sp+28h] [bp-98h]
  unsigned int v85; // [sp+2Ch] [bp-94h]
  unsigned int v86; // [sp+30h] [bp-90h]
  int v87; // [sp+34h] [bp-8Ch] BYREF
  unsigned int v88; // [sp+38h] [bp-88h]
  int v89; // [sp+3Ch] [bp-84h]
  unsigned int v90; // [sp+40h] [bp-80h]
  unsigned int v91; // [sp+44h] [bp-7Ch]
  unsigned __int64 v92; // [sp+48h] [bp-78h] BYREF
  int v93; // [sp+50h] [bp-70h]
  unsigned int v94; // [sp+54h] [bp-6Ch]
  unsigned int v95; // [sp+58h] [bp-68h]
  unsigned int v96; // [sp+5Ch] [bp-64h]
  unsigned int v97; // [sp+60h] [bp-60h]
  int v98; // [sp+64h] [bp-5Ch]
  BOOL v99; // [sp+68h] [bp-58h]
  unsigned int v100; // [sp+6Ch] [bp-54h]
  int v101; // [sp+70h] [bp-50h]
  int v102; // [sp+74h] [bp-4Ch]
  unsigned int v103; // [sp+78h] [bp-48h]
  int v104; // [sp+7Ch] [bp-44h]
  int v105; // [sp+80h] [bp-40h]
  int v106; // [sp+84h] [bp-3Ch]
  int v107; // [sp+88h] [bp-38h]
  unsigned int v108; // [sp+8Ch] [bp-34h]
  BOOL v109; // [sp+90h] [bp-30h]
  _DWORD v110[10]; // [sp+98h] [bp-28h] BYREF
  int varg_r0; // [sp+C8h] [bp+8h]
  int varg_r1; // [sp+CCh] [bp+Ch]
  unsigned int *varg_r2; // [sp+D0h] [bp+10h]
  unsigned int varg_r3; // [sp+D4h] [bp+14h]

  varg_r3 = a4;
  v9 = a4;
  varg_r2 = a3;
  v89 = a2;
  varg_r1 = a2;
  v10 = a1;
  varg_r0 = a1;
  v86 = 0;
  v11 = (*(_DWORD *)(a6 + 44) & 0x10) != 0;
  v12 = v11;
  v99 = v11;
  v75 = v11;
  v84 = v9;
  v94 = v9;
  v13 = *a3 & 0xFFF;
  v106 = v13;
  v93 = 4;
  v105 = 4;
  v87 = 0;
  v103 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v96 = v103;
  v81 = 0;
  v98 = 0;
  v76 = 0;
  v77 = 0;
  v14 = 0;
  v88 = *a3;
  LODWORD(v92) = v88;
  v85 = a3[1];
  HIDWORD(v92) = v85;
  v100 = *(unsigned __int8 *)(v103 + 972) + 4 * *(_DWORD *)(v103 + 948);
  v95 = v100;
  v15 = v11;
  v78 = v11;
  if ( !v11 )
  {
    v15 = 0;
    if ( IoIsFileOriginRemote(a6) && !CcCanIWriteStream(a6, v9, 0, 0) )
    {
LABEL_11:
      v15 = 1;
      if ( (*(_DWORD *)(v10 + 96) & 0x400) == 0 )
      {
        v18 = KeAcquireQueuedSpinLock(5);
        *(_DWORD *)(v10 + 96) |= 0x400u;
        KeReleaseQueuedSpinLock(5, v18);
      }
      goto LABEL_13;
    }
    v16 = (_DWORD *)(__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0);
    v17 = (v16[240] >> 9) & 7;
    if ( (*(_DWORD *)(v16[84] + 192) & 0x100000) != 0 )
    {
      v17 = 0;
    }
    else if ( ((v16[240] >> 9) & 7u) >= 2 )
    {
LABEL_9:
      if ( v17 <= 0 && (*(_DWORD *)(a6 + 44) & 0x8000) == 0 )
        goto LABEL_11;
LABEL_13:
      v78 = v15;
      v12 = v99;
      goto LABEL_14;
    }
    if ( v16 == (_DWORD *)(__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) && v16[250] )
      goto LABEL_13;
    goto LABEL_9;
  }
LABEL_14:
  v102 = a8;
  if ( v15 )
  {
    if ( !a8 )
      return 0;
  }
  else if ( !a8 )
  {
    v93 = 6;
    v105 = 6;
  }
  if ( v12 )
  {
    v20 = KeAcquireQueuedSpinLock(5);
    v21 = a1;
    if ( (*(_DWORD *)(a1 + 96) & 0x20) == 0 )
      goto LABEL_49;
    KeAcquireQueuedSpinLockAtDpcLevel(((unsigned int)KeGetPcr() & 0xFFFFF000) + 2624);
    v14 = *(_DWORD **)(a1 + 352);
    if ( !v14 )
    {
      v22 = (int *)(((unsigned int)KeGetPcr() & 0xFFFFF000) + 2624);
      if ( (dword_682604 & 0x10000) != 0 )
      {
        KiReleaseQueuedSpinLockInstrumented(v22);
        goto LABEL_32;
      }
      v23 = *v22;
      if ( !*v22 )
      {
        v24 = (unsigned int *)v22[1];
        __dmb(0xBu);
        do
          v25 = __ldrex(v24);
        while ( (int *)v25 == v22 && __strex(0, v24) );
        if ( (int *)v25 == v22 )
        {
LABEL_32:
          KeReleaseQueuedSpinLock(5, v20);
          KeDelayExecutionThread(0, 0, (unsigned int *)&Cc5Milliseconds);
          RtlRaiseStatus(-1073741608);
        }
        v23 = KxWaitForLockChainValid(v22);
      }
      *v22 = 0;
      __dmb(0xBu);
      v26 = (unsigned int *)(v23 + 4);
      do
        v27 = __ldrex(v26);
      while ( __strex(v27 ^ 1, v26) );
      goto LABEL_32;
    }
    v28 = *v14;
    v29 = (_DWORD *)v14[1];
    if ( *(_DWORD **)(*v14 + 4) != v14 || (_DWORD *)*v29 != v14 )
      __fastfail(3u);
    *v29 = v28;
    *(_DWORD *)(v28 + 4) = v29;
    v14[1] = 0;
    *v14 = 0;
    *(_DWORD *)(a1 + 352) = 0;
    *(_DWORD *)(a1 + 96) &= 0xFFFFFFDF;
    v77 = 1;
    v30 = (int *)(((unsigned int)KeGetPcr() & 0xFFFFF000) + 2624);
    v91 = (unsigned int)v30;
    if ( (dword_682604 & 0x10000) != 0 )
    {
      KiReleaseQueuedSpinLockInstrumented(v30);
    }
    else
    {
      v31 = *v30;
      if ( !*v30 )
      {
        v32 = (unsigned int *)v30[1];
        __dmb(0xBu);
        do
          v33 = __ldrex(v32);
        while ( (int *)v33 == v30 && __strex(0, v32) );
        if ( (int *)v33 == v30 )
          goto LABEL_48;
        v31 = KxWaitForLockChainValid(v30);
        v30 = (int *)v91;
      }
      *v30 = 0;
      __dmb(0xBu);
      v34 = (unsigned int *)(v31 + 4);
      do
        v35 = __ldrex(v34);
      while ( __strex(v35 ^ 1, v34) );
    }
LABEL_48:
    v21 = a1;
LABEL_49:
    ++*(_DWORD *)(v21 + 364);
    v76 = 1;
    KeReleaseQueuedSpinLock(5, v20);
    v10 = a1;
  }
  if ( v14 )
  {
    v36 = ((unsigned int)KeGetPcr() & 0xFFFFF000) + 1408;
    v37 = *(_DWORD *)(v36 + 1456);
    ++*(_DWORD *)(v37 + 20);
    if ( *(unsigned __int16 *)(v37 + 4) < (unsigned int)*(unsigned __int16 *)(v37 + 8)
      || (++*(_DWORD *)(v37 + 24),
          v37 = *(_DWORD *)(v36 + 1460),
          ++*(_DWORD *)(v37 + 20),
          *(unsigned __int16 *)(v37 + 4) < (unsigned int)*(unsigned __int16 *)(v37 + 8)) )
    {
      RtlpInterlockedPushEntrySList((unsigned __int64 *)v37, v14);
    }
    else
    {
      ++*(_DWORD *)(v37 + 24);
      (*(void (__fastcall **)(_DWORD *))(v37 + 44))(v14);
    }
  }
  v38 = a5;
  v82 = a5;
  while ( v9 )
  {
    v86 = 0;
    v39 = v88;
    v40 = CcGetVirtualAddress(v10, v38, v88, v85, &v87, &v83, 0, 0);
    v97 = v40;
    v41 = v83;
    if ( v83 > v9 )
    {
      v41 = v9;
      v83 = v9;
    }
    v86 = v41;
    v9 -= v41;
    varg_r3 = v9;
    v42 = v40 - v13;
    v90 = v42;
    v97 = v42;
    v43 = v41 + v13;
    v83 = v41 + v13;
    v44 = 1;
    v91 = v85;
    v108 = v85;
    v45 = v39 - v13;
    v101 = v39 - v13;
    v107 = v39 - v13;
    while ( 1 )
    {
      v109 = v43 > 0x1000;
      v104 = 0;
      if ( (v44 & v82) != 0 )
      {
        if ( __SPAIR64__(v91, v45) < *a7 )
        {
          v46 = v81;
        }
        else
        {
          v46 = v81 | 1;
          v81 = v46;
          v98 = v46;
        }
        if ( (*(_DWORD *)(a1 + 96) & 0x40) != 0 )
        {
          v81 = v46 | 2;
          v98 = v46 | 2;
        }
        v47 = MmCopyToCachedPage(v42);
        v104 = v47;
        if ( v47 < 0 )
        {
          v48 = FsRtlNormalizeNtstatus(v47, -1073741592);
          RtlRaiseStatus(v48);
        }
        v51 = v89;
      }
      else
      {
        if ( v43 > 0x1000 && (v82 & 4) != 0 )
        {
          v49 = v103;
          *(_BYTE *)(v103 + 972) = 1;
          if ( !*(_DWORD *)(v49 + 948) )
            *(_DWORD *)(v49 + 948) = 1;
        }
        if ( !MmCheckCachedPageStates(v42, 1, v93, 0) && !v102 )
        {
          v79 = 0;
          goto LABEL_100;
        }
        v50 = v43 <= 0x1000 ? v43 - v13 : 4096 - v13;
        memmove(v90 + v13, v89, v50);
        v51 = v89;
        v52 = v103;
        *(_BYTE *)(v103 + 972) = v100 & 3;
        *(_DWORD *)(v52 + 948) = v100 >> 2;
      }
      v89 = v51 - v13 + 4096;
      varg_r1 = v89;
      v13 = 0;
      v106 = 0;
      if ( v43 <= 0x1000 )
        break;
      v42 = v90 + 4096;
      v90 = v42;
      v97 = v42;
      v43 -= 4096;
      v83 = v43;
      v45 = v101 + 4096;
      v101 = v45;
      v107 = v45;
      if ( v9 )
      {
        v44 = 2;
      }
      else if ( v43 <= 0x1000 )
      {
        v44 = 4;
      }
      else
      {
        v44 = 2;
      }
    }
    v53 = v87;
    v54 = *(_DWORD *)(v87 + 4);
    __dmb(0xBu);
    v55 = (unsigned int *)(v53 + 8);
    do
    {
      v56 = __ldrex(v55);
      v57 = v56 - 1;
    }
    while ( __strex(v57, v55) );
    __dmb(0xBu);
    if ( !(_WORD)v57 )
    {
      v58 = *(_DWORD *)(v54 + 116);
      if ( v58 )
        KeSetEvent(v58, 0, 0);
    }
    v87 = 0;
    v10 = a1;
    CcSetDirtyInMask(a1, &v92, v41, a9);
    if ( v84 - v9 > 0x1000000 )
    {
      CcFlushCachePriv(*(_DWORD *)(a6 + 20), &v92, v41, 0, v99, (int)v110);
      if ( v110[0] < 0 )
      {
        v59 = FsRtlNormalizeNtstatus(v110[0], -1073741591);
        RtlRaiseStatus(v59);
      }
    }
    if ( v9 < 0x1000 )
    {
      v38 = v82;
      if ( (v82 & 4) == 0 )
      {
        v38 = 0;
        v82 = 0;
      }
    }
    else
    {
      v82 |= 1u;
    }
    v60 = v88;
    v88 += v41;
    v61 = __PAIR64__(v85, v60) + v41;
    v85 = HIDWORD(v61);
    v92 = v61;
  }
  v79 = 1;
LABEL_100:
  v62 = v95;
  v63 = v96;
  *(_BYTE *)(v96 + 972) = v95 & 3;
  *(_DWORD *)(v63 + 948) = v62 >> 2;
  v64 = v87;
  if ( v87 )
  {
    v65 = *(_DWORD *)(v87 + 4);
    __dmb(0xBu);
    v66 = (unsigned int *)(v64 + 8);
    do
    {
      v67 = __ldrex(v66);
      v68 = v67 - 1;
    }
    while ( __strex(v68, v66) );
    __dmb(0xBu);
    if ( !(_WORD)v68 )
    {
      v69 = *(_DWORD *)(v65 + 116);
      if ( v69 )
        KeSetEvent(v69, 0, 0);
    }
  }
  if ( v78 )
  {
    if ( v77 )
      v70 = 0;
    else
      v70 = v94;
    if ( v77 )
      v71 = 0;
    else
      v71 = varg_r2;
    CcFlushCachePriv(*(_DWORD *)(a6 + 20), v71, v70, 0, v75, (int)v110);
    if ( v76 )
    {
      v72 = KeAcquireQueuedSpinLock(5);
      --*(_DWORD *)(varg_r0 + 364);
      KeReleaseQueuedSpinLock(5, v72);
    }
    if ( v110[0] < 0 )
    {
      v73 = FsRtlNormalizeNtstatus(v110[0], -1073741591);
      RtlRaiseStatus(v73);
    }
  }
  return v79;
}
