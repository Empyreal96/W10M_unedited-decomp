// CcAcquireByteRangeForWrite 
 
BOOL __fastcall CcAcquireByteRangeForWrite(int a1, _DWORD *a2, int a3, _DWORD *a4, _DWORD *a5, int *a6, int *a7, unsigned __int8 a8)
{
  _DWORD *v9; // r10
  unsigned int *v10; // r8
  int v11; // r4
  int v12; // r1
  unsigned __int8 *v13; // lr
  unsigned int v14; // r2
  _DWORD *v15; // lr
  __int64 v16; // r0
  unsigned int v17; // r2
  int v18; // kr20_4
  unsigned int v19; // r4
  int *v20; // r9
  int v21; // r1
  int v22; // r0
  unsigned __int64 v23; // r2
  unsigned int v24; // r4
  signed __int64 v25; // kr28_8
  int v26; // r2
  unsigned int v27; // r5
  unsigned int v28; // r3
  unsigned int v29; // r4
  int v30; // kr1C_4
  unsigned int v31; // kr30_4
  _DWORD *v32; // r5
  char v33; // r2
  int i; // r4
  unsigned int v35; // lr
  int v36; // r0
  int v37; // r1
  unsigned int v38; // r2
  int v39; // r0
  unsigned int v40; // r0
  int v41; // lr
  int v42; // r2
  int v43; // r3
  int v44; // r3
  int v45; // r2
  int v46; // r3
  int v47; // r8
  int v48; // r1
  int v49; // r10
  int *v50; // r1
  int v51; // r2
  int v52; // r0
  int v53; // r0
  int v54; // r1
  int v55; // r0
  unsigned int *v56; // r2
  unsigned int v57; // r1
  int v58; // r2
  int v59; // r3
  int v60; // r1
  unsigned int v61; // r0
  unsigned int v62; // r2
  int v63; // r2
  unsigned int v64; // r1
  int v65; // r10
  int v66; // r1
  unsigned int v67; // lr
  unsigned int v68; // r2
  int v69; // r1
  unsigned int v70; // r0
  unsigned int v71; // r2
  int v72; // r1
  int v73; // r10
  int v74; // r1
  unsigned int v75; // r2
  unsigned int v76; // r0
  unsigned int v77; // r3
  int v78; // r4
  unsigned int v79; // r1
  int v80; // r3
  unsigned int v81; // lr
  unsigned int v82; // r1
  int v83; // r5
  unsigned int v84; // r3
  unsigned int v85; // r3
  int v86; // r4
  unsigned int v87; // r1
  int v88; // r3
  _DWORD *v89; // r2
  int v90; // r0
  _DWORD *v91; // r1
  void **v92; // r0
  _DWORD *v93; // r2
  int v94; // r0
  _DWORD *v95; // r1
  void **v96; // r0
  unsigned int v97; // r9
  unsigned int *v98; // r5
  int v99; // r4
  unsigned int v100; // r1
  unsigned __int64 v101; // r0
  int v102; // r3
  unsigned int v104; // [sp+20h] [bp-80h] BYREF
  unsigned int v105; // [sp+24h] [bp-7Ch]
  int v106; // [sp+28h] [bp-78h]
  int v107; // [sp+2Ch] [bp-74h]
  unsigned int v108; // [sp+30h] [bp-70h]
  int v109; // [sp+38h] [bp-68h]
  int v110; // [sp+3Ch] [bp-64h]
  unsigned int *v111; // [sp+40h] [bp-60h]
  int v112; // [sp+44h] [bp-5Ch]
  unsigned int v113; // [sp+48h] [bp-58h]
  unsigned int v114; // [sp+4Ch] [bp-54h]
  unsigned int v115; // [sp+50h] [bp-50h]
  unsigned int v116; // [sp+54h] [bp-4Ch]
  int v117; // [sp+58h] [bp-48h]
  _DWORD *v118; // [sp+5Ch] [bp-44h]
  _DWORD *v119; // [sp+60h] [bp-40h]
  int *v120; // [sp+64h] [bp-3Ch]
  _QWORD *v121; // [sp+68h] [bp-38h]
  __int64 v122; // [sp+6Ch] [bp-34h]
  int v123; // [sp+74h] [bp-2Ch]
  unsigned int v124; // [sp+78h] [bp-28h] BYREF
  int v125; // [sp+7Ch] [bp-24h]
  int varg_r0; // [sp+A8h] [bp+8h]
  _DWORD *varg_r1; // [sp+ACh] [bp+Ch]
  int varg_r2; // [sp+B0h] [bp+10h]
  _DWORD *varg_r3; // [sp+B4h] [bp+14h]

  v121 = a4;
  varg_r3 = a4;
  v113 = a3;
  varg_r2 = a3;
  varg_r1 = a2;
  v9 = (_DWORD *)a1;
  v106 = a1;
  varg_r0 = a1;
  v111 = 0;
  v122 = 0i64;
  v112 = 0;
  v117 = 0;
  v118 = 0;
  v120 = 0;
  v104 = 0;
  v116 = 0;
  v115 = 0;
  v119 = 0;
  v114 = 0;
  v108 = -1;
  v109 = -1;
  v107 = 0x7FFFFFFF;
  v110 = 0x7FFFFFFF;
  v123 = a8;
  if ( a8 )
  {
    PsBoostThreadIoEx(__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0, 0, 0);
    a4 = v121;
  }
  *a5 = 0;
  a5[1] = 0;
  v10 = (unsigned int *)a6;
  *a6 = 0;
  if ( a4 )
    (*(void (__fastcall **)(_DWORD, _DWORD, _DWORD, _DWORD))(v9[38] + 4))(
      *(_DWORD *)v9[38],
      *(_DWORD *)(v9[38] + 4),
      *a4,
      a4[1]);
  v111 = v9 + 45;
  v11 = KeAbPreAcquire((unsigned int)(v9 + 45), 0, 0);
  v12 = KfRaiseIrql(1);
  v118 = (_DWORD *)v12;
  v13 = (unsigned __int8 *)(v9 + 45);
  do
    v14 = __ldrex(v13);
  while ( __strex(v14 & 0xFE, v13) );
  __dmb(0xBu);
  if ( (v14 & 1) == 0 )
  {
    ExpAcquireFastMutexContended(v9 + 45, v11);
    v12 = (int)v118;
    v13 = (unsigned __int8 *)(v9 + 45);
  }
  if ( v11 )
    *(_BYTE *)(v11 + 14) |= 1u;
  *((_DWORD *)v13 + 1) = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  *((_DWORD *)v13 + 7) = v12;
  v15 = (_DWORD *)v9[26];
  v118 = v15;
  if ( !v15 || !v15[2] || (LODWORD(v16) = v113, !v15[1]) && !v113 )
  {
    v109 = v125;
    v105 = v124;
    goto LABEL_60;
  }
  if ( !a2 )
  {
    v27 = 0;
    v105 = 0;
    v28 = 0;
    v109 = 0;
    if ( !v113 )
    {
      v27 = v15[6];
      v105 = v27;
      v28 = v15[7];
      v109 = v28;
    }
    v20 = CcFindBitmapRangeToClean(v15, v12, v27, v28);
    v120 = v20;
    v29 = v20[5];
    v21 = v20[2];
    v22 = v20[3];
    if ( __SPAIR64__(v109, v27) > (__int64)(__PAIR64__(v22, v29) + (unsigned int)v21) )
    {
      v30 = v20[4];
      v105 = v30 + v21;
      v109 = (__PAIR64__(v22, v30) + (unsigned int)v21) >> 32;
    }
    v26 = v20[7];
    v116 = v26 + 4 * (v29 >> 5);
    goto LABEL_31;
  }
  v17 = *a2;
  HIDWORD(v16) = a2[1];
  v105 = *(__int64 *)a2 >> 12;
  v109 = SHIDWORD(v16) >> 12;
  v18 = v113 + v17 - 1;
  LODWORD(v16) = (v16 + (unsigned __int64)v17 - 1) >> 32;
  v19 = __SPAIR64__(v16, v18) >> 12;
  v108 = v19;
  v107 = (int)v16 >> 12;
  v20 = CcFindBitmapRangeToClean(v15, v18, v105, SHIDWORD(v16) >> 12);
  v120 = v20;
  v21 = v20[2];
  v22 = v20[3];
  v23 = __PAIR64__(v22, v20[4]) + (unsigned int)v21;
  if ( v107 < SHIDWORD(v23) )
    goto LABEL_25;
  if ( v107 <= SHIDWORD(v23) && v19 < (unsigned int)v23 )
    goto LABEL_60;
  v24 = v20[5];
  v25 = __PAIR64__(v22, v24) + (unsigned int)v21;
  if ( v109 > SHIDWORD(v25) )
  {
LABEL_25:
    v114 = v104;
LABEL_61:
    i = v104;
    goto LABEL_62;
  }
  if ( v109 >= SHIDWORD(v25) && v105 > (unsigned int)v25 )
  {
LABEL_60:
    v114 = v104;
    goto LABEL_61;
  }
  v26 = v20[7];
  if ( __SPAIR64__(v107, v108) >= v25 )
    v116 = v26 + 4 * (v24 >> 5);
  else
    v116 = v26 + 4 * ((v108 - v21) >> 5);
LABEL_31:
  if ( __SPAIR64__(v109, v105) < (__int64)(__PAIR64__(v22, v20[4]) + (unsigned int)v21) )
  {
    v31 = v20[4] + v21;
    v109 = (__PAIR64__(v22, v20[4]) + (unsigned int)v21) >> 32;
    v105 = v31;
  }
  v114 = v105 - v21;
  v32 = (_DWORD *)(v26 + 4 * ((v105 - v21) >> 5));
  v119 = v32;
  _rt_sdiv64(32i64, __SPAIR64__(v109, v105));
  i = -1 << v33;
  v35 = v105;
  v36 = v109;
  if ( ((-1 << v33) & *v32) == 0 )
  {
    i = -1;
    v35 = v105 & 0xFFFFFFE0;
    v37 = v107;
    v38 = v116;
    do
    {
      v119 = ++v32;
      v105 = v35 + 32;
      v36 = (__PAIR64__(v36, v35) + 32) >> 32;
      v35 += 32;
      v109 = v36;
      if ( (unsigned int)v32 > v38 )
      {
        v39 = v113;
        if ( !v113 )
          v20[5] = v114 - 1;
        do
        {
          v20 = (int *)*v20;
          v120 = v20;
          if ( v20 == v118 + 4 )
          {
            if ( v39 )
              goto LABEL_62;
            v20 = (int *)*v20;
            v120 = v20;
          }
        }
        while ( !v20[6] );
        v40 = v20[4];
        v41 = v20[2];
        v42 = v20[3];
        v107 = v42;
        v104 = v40 + v41;
        v43 = __CFADD__(v40, v41) + v42;
        if ( v37 < v43 )
          goto LABEL_62;
        if ( v37 <= v43 )
        {
          v9 = (_DWORD *)v106;
          if ( v108 < v104 )
            goto LABEL_62;
        }
        v115 = v20[5];
        v104 = v115 + v41;
        v44 = __CFADD__(v115, v41) + v42;
        if ( v109 > v44 || v109 >= v44 && v105 > v104 )
          goto LABEL_62;
        v45 = v20[7];
        v32 = (_DWORD *)(v45 + 4 * (v40 >> 5));
        v119 = v32;
        v116 = v45 + 4 * (v115 >> 5);
        v105 = v41 + (v40 & 0xFFFFFFE0);
        v46 = (__PAIR64__(v107, v41) + (v40 & 0xFFFFFFE0)) >> 32;
        v35 = v105;
        v109 = v46;
        v114 = v40;
        v36 = v46;
        v38 = v116;
      }
    }
    while ( !*v32 );
  }
  for ( i = -i; (*v32 & i) == 0; i *= 2 )
    v36 = (__PAIR64__(v36, v35++) + 1) >> 32;
  v109 = v36;
  v105 = v35;
  if ( !a2 )
  {
    v115 = 50331648;
    goto LABEL_177;
  }
  if ( __SPAIR64__(v36, v35) < (*(_QWORD *)a2 + v113 + 4095i64) >> 12 )
  {
    if ( (_DWORD *)v9[4] == v9 + 4 )
    {
      v115 = 50331648;
      goto LABEL_177;
    }
    v117 = 1;
  }
LABEL_62:
  v47 = v106;
  v48 = v106 + 16;
  v107 = v106 + 16;
  v115 = 50331648;
  v108 = CcDbgLsnLargerThanHint;
  while ( 2 )
  {
    v49 = *(_DWORD *)(v47 + 20) - 16;
    v104 = v49;
    if ( (*(_DWORD *)(v47 + 96) & 0x200) != 0 )
    {
      if ( a2 )
        v50 = a2;
      else
        v50 = (int *)(v47 + 128);
      v51 = *v50;
      v52 = v50[1];
      if ( *(_QWORD *)v50 )
      {
        v124 = v51 + 4096;
        v125 = __CFADD__(v51, 4096) + v52;
        v53 = CcFindBcb(v47, v50, &v124, &v104);
        v48 = v107;
        if ( v53 )
          v49 = v104;
        else
          v49 = *(_DWORD *)(v104 + 20) - 16;
      }
      else
      {
        v48 = v107;
      }
    }
    v32 = v119;
    v10 = (unsigned int *)a6;
    v20 = v120;
    while ( 1 )
    {
      while ( 1 )
      {
        while ( 1 )
        {
          if ( v49 + 16 == v48 )
          {
            v54 = v106;
            v67 = (unsigned int)v111;
            goto LABEL_155;
          }
          if ( *(_WORD *)v49 == 765 )
            break;
          v49 = *(_DWORD *)(v49 + 20) - 16;
        }
        v54 = v106;
        if ( (*(_DWORD *)(v106 + 96) & 0x1000000) == 0 || !v121 || *(_QWORD *)(v49 + 40) <= *v121 )
          break;
        v49 = *(_DWORD *)(v49 + 20) - 16;
        CcDbgLsnLargerThanHint = ++v108;
        v48 = v107;
      }
      if ( a2 && (signed __int64)(*(_QWORD *)a2 + v113) <= *(_QWORD *)(v49 + 8) )
        break;
      v55 = *a6;
      if ( *a6 )
      {
        if ( !*(_BYTE *)(v49 + 2) )
          break;
        v104 = *(_DWORD *)(v49 + 8);
        if ( __PAIR64__(*(_DWORD *)(v49 + 12), v104) != *(_QWORD *)a5 + (unsigned int)v55
          || *(_DWORD *)(v49 + 52)
          || (v104 & 0x1FFFFFF) == 0 )
        {
          break;
        }
LABEL_98:
        ++*(_DWORD *)(v49 + 52);
        v56 = v111;
        v111[1] = 0;
        v104 = v56[7];
        __dmb(0xBu);
        do
          v57 = __ldrex(v56);
        while ( !v57 && __strex(1u, v56) );
        if ( v57 )
          ExpReleaseFastMutexContended(v56, v57);
        KfLowerIrql((unsigned __int8)v104);
        KeAbPostRelease((unsigned int)v111);
        v59 = *(_DWORD *)(v106 + 96);
        if ( (v59 & 0x200) == 0 || (v59 & 2) != 0 )
        {
          CcUnpinFileDataEx(v49, 1, 2);
          v104 = KeAbPreAcquire((unsigned int)v111, 0, 0);
          v69 = KfRaiseIrql(1);
          v117 = v69;
          v70 = (unsigned int)v111;
          do
            v71 = __ldrex((unsigned __int8 *)v70);
          while ( __strex(v71 & 0xFE, (unsigned __int8 *)v70) );
          __dmb(0xBu);
          if ( (v71 & 1) == 0 )
          {
            ExpAcquireFastMutexContended(v70, v104);
            v69 = v117;
            v70 = (unsigned int)v111;
          }
          if ( v104 )
            *(_BYTE *)(v104 + 14) |= 1u;
          *(_DWORD *)(v70 + 4) = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
          *(_DWORD *)(v70 + 28) = v69;
LABEL_138:
          v63 = v106;
          goto LABEL_139;
        }
        if ( !ExAcquireResourceExclusiveLite(v49 + 56, *a6 == 0, v58, *a6) )
        {
          CcUnpinFileDataEx(v49, 1, 0);
          v73 = KeAbPreAcquire((unsigned int)v111, 0, 0);
          v74 = KfRaiseIrql(1);
          v104 = v74;
          v67 = (unsigned int)v111;
          do
            v75 = __ldrex((unsigned __int8 *)v67);
          while ( __strex(v75 & 0xFE, (unsigned __int8 *)v67) );
          __dmb(0xBu);
          if ( (v75 & 1) == 0 )
          {
            ExpAcquireFastMutexContended(v67, v73);
            v74 = v104;
            v67 = (unsigned int)v111;
          }
          if ( v73 )
            *(_BYTE *)(v73 + 14) |= 1u;
          *(_DWORD *)(v67 + 4) = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
          *(_DWORD *)(v67 + 28) = v74;
LABEL_152:
          v108 = CcDbgLsnLargerThanHint;
          v54 = v106;
          goto LABEL_155;
        }
        v104 = KeAbPreAcquire((unsigned int)v111, 0, 0);
        v60 = KfRaiseIrql(1);
        v108 = v60;
        v61 = (unsigned int)v111;
        do
          v62 = __ldrex((unsigned __int8 *)v61);
        while ( __strex(v62 & 0xFE, (unsigned __int8 *)v61) );
        __dmb(0xBu);
        if ( (v62 & 1) == 0 )
        {
          ExpAcquireFastMutexContended(v61, v104);
          v60 = v108;
          v61 = (unsigned int)v111;
        }
        if ( v104 )
          *(_BYTE *)(v104 + 14) |= 1u;
        *(_DWORD *)(v61 + 4) = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
        *(_DWORD *)(v61 + 28) = v60;
        if ( *(_BYTE *)(v49 + 2) )
        {
          v63 = v106;
          if ( (*(_DWORD *)(v106 + 96) & 0x1000000) != 0 && v121 )
          {
            if ( *(_QWORD *)(v49 + 40) > *v121 )
            {
              v61 = (unsigned int)v111;
              if ( *(_BYTE *)(v49 + 2) )
                ++CcDbgLsnLargerThanHint;
              goto LABEL_118;
            }
            goto LABEL_138;
          }
LABEL_139:
          v117 = 0;
          v72 = *a6;
          if ( !*a6 )
          {
            *a5 = *(_DWORD *)(v49 + 8);
            a5[1] = *(_DWORD *)(v49 + 12);
          }
          *a7 = v49;
          *a6 = *(_DWORD *)(v49 + 4) + v72;
          if ( (*(_DWORD *)(v63 + 96) & v115) != 0 && *(_QWORD *)(v49 + 40) > __SPAIR64__(v122, HIDWORD(v122)) )
          {
            HIDWORD(v122) = *(_DWORD *)(v49 + 40);
            LODWORD(v122) = *(_DWORD *)(v49 + 44);
          }
          v49 = *(_DWORD *)(v49 + 20) - 16;
          v108 = CcDbgLsnLargerThanHint;
          v48 = v107;
        }
        else
        {
LABEL_118:
          *(_DWORD *)(v61 + 4) = 0;
          v104 = *(_DWORD *)(v61 + 28);
          __dmb(0xBu);
          do
            v64 = __ldrex((unsigned int *)v61);
          while ( !v64 && __strex(1u, (unsigned int *)v61) );
          if ( v64 )
            ExpReleaseFastMutexContended((unsigned int *)v61, v64);
          KfLowerIrql((unsigned __int8)v104);
          KeAbPostRelease((unsigned int)v111);
          CcUnpinFileDataEx(v49, 0, 0);
          v65 = KeAbPreAcquire((unsigned int)v111, 0, 0);
          v66 = KfRaiseIrql(1);
          v104 = v66;
          v67 = (unsigned int)v111;
          do
            v68 = __ldrex((unsigned __int8 *)v67);
          while ( __strex(v68 & 0xFE, (unsigned __int8 *)v67) );
          __dmb(0xBu);
          if ( (v68 & 1) == 0 )
          {
            ExpAcquireFastMutexContended(v67, v65);
            v66 = v104;
            v67 = (unsigned int)v111;
          }
          if ( v65 )
            *(_BYTE *)(v65 + 14) |= 1u;
          *(_DWORD *)(v67 + 4) = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
          *(_DWORD *)(v67 + 28) = v66;
          if ( *a6 )
            goto LABEL_152;
          v49 = *(_DWORD *)(v106 + 20) - 16;
          v108 = CcDbgLsnLargerThanHint;
          v48 = v107;
        }
      }
      else
      {
        if ( *(_BYTE *)(v49 + 2) )
        {
          if ( a2 )
          {
            if ( *(_QWORD *)a2 < *(_QWORD *)(v49 + 24) )
              goto LABEL_88;
          }
          else if ( *(_QWORD *)(v49 + 8) >= *(_QWORD *)(v106 + 128) )
          {
LABEL_88:
            if ( v117 )
            {
              if ( v109 < 0 )
              {
                v9 = (_DWORD *)v106;
                goto LABEL_177;
              }
              if ( v109 <= 0 && v105 <= (unsigned int)(*(__int64 *)(v49 + 8) >> 12) )
              {
                v9 = (_DWORD *)v106;
                goto LABEL_177;
              }
            }
            goto LABEL_98;
          }
        }
        v49 = *(_DWORD *)(v49 + 20) - 16;
        v48 = v107;
      }
    }
    v67 = v106 + 180;
LABEL_155:
    if ( v117 )
    {
      v9 = (_DWORD *)v106;
LABEL_177:
      if ( (gCcTrace & 1) != 0 )
        DbgPrintEx(
          127,
          0,
          (int)"CcAcquireByteRange (AcceptPage) [0x%I64x, 0x%x]: %p (0x%I64x) BM:%p Dirty: 0x%x\n",
          v113);
      v81 = CcMaxLazyWritePages;
      while ( (*v32 & i) != 0 )
      {
        if ( a2 )
        {
          v9 = (_DWORD *)v106;
          if ( (__int64)(__PAIR64__(v109, v105) + *v10) >= (unsigned int)((*(_QWORD *)a2 + v113 + 4095i64) >> 12) )
            break;
        }
        if ( (unsigned int)v32 > v20[7] + 4 * ((unsigned int)v20[5] >> 5) )
          KeBugCheckEx(52, 4380, -1073740768);
        if ( !a2 && *v10 >= v81 )
          break;
        *v32 -= i;
        ++*v10;
        i *= 2;
        if ( !i )
        {
          ++v32;
          i = 1;
          if ( (unsigned int)v32 > v116 )
            break;
        }
      }
      v82 = *v10;
      v83 = (int)v118;
      v84 = v118[1];
      if ( *v10 >= v84 )
        v118[1] = 0;
      else
        v118[1] = v84 - v82;
      v85 = *(_DWORD *)(v83 + 8);
      if ( v85 < v82 )
        KeBugCheckEx(52, 4427, -1073740768);
      *(_DWORD *)(v83 + 8) = v85 - v82;
      v20[6] -= v82;
      v86 = KeAcquireQueuedSpinLock(5);
      v87 = *v10;
      CcGlobalDirtyPageStatistics -= *v10;
      if ( v87 == -1 )
        KeBugCheckEx(52, 4194, -1073740768);
      v9[19] -= v87;
      *(_DWORD *)(v9[89] + 20) -= v87;
      if ( (v9[24] & 0x1000000) != 0 )
        *(_DWORD *)(v9[38] + 12) -= v87;
      if ( CcPagesYetToWrite <= v87 )
        v88 = 0;
      else
        v88 = CcPagesYetToWrite - v87;
      CcPagesYetToWrite = v88;
      if ( !v9[19] )
      {
        if ( KdDebuggerEnabled && !KdDebuggerNotPresent && !v9[1] )
        {
          DbgPrint("CC: SharedCacheMap->OpenCount == 0 && DirtyPages == 0 && going onto CleanList!\n");
          __debugbreak();
        }
        if ( (v9[24] & v115) != 0 )
        {
          v89 = v9 + 20;
          v90 = v9[20];
          v91 = (_DWORD *)v9[21];
          if ( *(_DWORD **)(v90 + 4) != v9 + 20 || (_DWORD *)*v91 != v89 )
            __fastfail(3u);
          *v91 = v90;
          *(_DWORD *)(v90 + 4) = v91;
          v92 = (void **)dword_632604;
          *v89 = &CcCleanSharedCacheMapWithLogHandleList;
          v9[21] = v92;
          if ( *v92 != &CcCleanSharedCacheMapWithLogHandleList )
            __fastfail(3u);
          *v92 = v89;
          dword_632604 = (int)(v9 + 20);
        }
        v93 = v9 + 22;
        v94 = v9[22];
        v95 = (_DWORD *)v9[23];
        if ( *(_DWORD **)(v94 + 4) != v9 + 22 || (_DWORD *)*v95 != v93 )
          __fastfail(3u);
        *v95 = v94;
        *(_DWORD *)(v94 + 4) = v95;
        v96 = (void **)dword_63260C;
        *v93 = &CcCleanSharedCacheMapList;
        v9[23] = v96;
        if ( *v96 != &CcCleanSharedCacheMapList )
          __fastfail(3u);
        *v96 = v93;
        dword_63260C = (int)(v9 + 22);
      }
      KeReleaseQueuedSpinLock(5, v86);
      if ( v20[6] )
      {
        if ( v20[4] == v114 )
          v20[4] = *v10 + v105 - v20[2];
        if ( !v113 )
        {
          v97 = v105;
          *(_QWORD *)(v83 + 24) = __PAIR64__(v109, *v10) + v105;
LABEL_225:
          if ( (_DWORD *)v9[4] == v9 + 4 )
            v9[30] = *(_DWORD *)(v83 + 4);
          v98 = v9 + 45;
          v9[46] = 0;
          v99 = v9[52];
          __dmb(0xBu);
          do
            v100 = __ldrex(v98);
          while ( !v100 && __strex(1u, v98) );
          if ( v100 )
            ExpReleaseFastMutexContended(v9 + 45, v100);
          KfLowerIrql((unsigned __int8)v99);
          KeAbPostRelease((unsigned int)(v9 + 45));
          *v10 <<= 12;
          v101 = (unsigned __int64)v97 << 12;
          v102 = HIDWORD(v101) | (v109 << 12);
          *a5 = v101;
          a5[1] = v102;
          *a7 = 0;
          goto LABEL_233;
        }
      }
      else
      {
        v20[4] = -1;
        v20[5] = 0;
        *(_QWORD *)(v83 + 24) = *((_QWORD *)v20 + 1) + 4096i64;
      }
      v97 = v105;
      goto LABEL_225;
    }
    if ( *a6 )
    {
      if ( !a2 )
      {
        v76 = *a6;
        *(_QWORD *)(v54 + 128) = *(_QWORD *)a5 + (unsigned int)*a6;
        v77 = *(_DWORD *)(v54 + 120);
        if ( v77 <= v76 >> 12 )
          *(_DWORD *)(v54 + 120) = 0;
        else
          *(_DWORD *)(v54 + 120) = v77 - (v76 >> 12);
      }
    }
    else if ( *(_QWORD *)(v54 + 128) && !a2 )
    {
      *(_DWORD *)(v54 + 128) = 0;
      *(_DWORD *)(v54 + 132) = 0;
      v47 = v106;
      v48 = v107;
      continue;
    }
    break;
  }
  *(_DWORD *)(v67 + 4) = 0;
  v78 = *(_DWORD *)(v67 + 28);
  __dmb(0xBu);
  do
    v79 = __ldrex((unsigned int *)v67);
  while ( !v79 && __strex(1u, (unsigned int *)v67) );
  if ( v79 )
    ExpReleaseFastMutexContended((unsigned int *)v67, v79);
  KfLowerIrql((unsigned __int8)v78);
  KeAbPostRelease((unsigned int)v111);
  if ( v122 )
  {
    if ( (*(_DWORD *)(v106 + 96) & 0x2000000) != 0 )
      (*(void (__fastcall **)(_DWORD, _DWORD, _DWORD, _DWORD))(v106 + 156))(
        *(_DWORD *)(v106 + 152),
        *(_DWORD *)(v106 + 156),
        HIDWORD(v122),
        v122);
    else
      (*(void (__fastcall **)(_DWORD, _DWORD, _DWORD, _DWORD))(*(_DWORD *)(v106 + 152) + 4))(
        **(_DWORD **)(v106 + 152),
        *(_DWORD *)(*(_DWORD *)(v106 + 152) + 4),
        HIDWORD(v122),
        v122);
    v80 = v123;
    goto LABEL_234;
  }
LABEL_233:
  v80 = v123;
LABEL_234:
  if ( v80 )
    PsBoostThreadIoEx(__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0, 1, 0);
  return *v10 != 0;
}
