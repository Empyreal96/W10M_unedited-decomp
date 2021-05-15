// sub_9476D8 
 
_DWORD *__fastcall sub_9476D8(int a1, int a2)
{
  unsigned int v2; // r3
  unsigned int v3; // r6
  int v4; // r3
  __int64 v5; // kr00_8
  __int64 v6; // kr08_8
  unsigned int v7; // r1
  int v8; // r3
  unsigned __int64 v9; // r2
  int v10; // r0
  unsigned int v11; // r3
  unsigned int v12; // r6
  int v13; // r3
  __int64 v14; // kr20_8
  __int64 v15; // kr28_8
  unsigned int v16; // r1
  int v17; // r3
  unsigned __int64 v18; // r2
  unsigned int v19; // r10
  int v20; // r0
  unsigned int v21; // r3
  int *v22; // lr
  unsigned int v23; // r3
  unsigned int v24; // r6
  int v25; // r3
  unsigned int v26; // r5
  int v27; // r4
  unsigned int v28; // r2
  unsigned int v29; // r3
  unsigned int v30; // r3
  unsigned int v31; // r5
  int v32; // r3
  unsigned int v33; // r6
  int v34; // r4
  unsigned int v35; // r2
  unsigned int v36; // r3
  int v37; // r0
  int v38; // r1
  unsigned int v39; // r10
  unsigned int v40; // r10
  int *v41; // lr
  unsigned int v42; // r3
  unsigned int v43; // r6
  int v44; // r3
  unsigned int v45; // r5
  int v46; // r4
  unsigned int v47; // r2
  unsigned int v48; // r3
  unsigned int v49; // r3
  unsigned int v50; // r5
  int v51; // r3
  unsigned int v52; // r6
  int v53; // r4
  unsigned int v54; // r2
  unsigned int v55; // r3
  int v56; // r0
  int v57; // r1
  _DWORD *v58; // r10
  int v60; // r3
  _DWORD *v61; // r2
  int v62; // r1
  unsigned int v63; // r3
  unsigned int v64; // r5
  int v65; // r3
  __int64 v66; // krC0_8
  __int64 v67; // krC8_8
  unsigned int v68; // r1
  int v69; // r3
  unsigned __int64 v70; // r2
  int v71; // r2
  int v72; // r3
  int v73; // lr
  unsigned int v74; // r3
  unsigned int v75; // r2
  int v76; // r3
  unsigned int v77; // r6
  int v78; // r4
  __int64 v79; // r2
  int v80; // r1
  unsigned int v81; // r3
  unsigned int v82; // r2
  int v83; // r3
  __int64 v84; // krE8_8
  __int64 v85; // r4
  __int64 v86; // r2
  unsigned int v87; // r1
  unsigned int v88; // r3
  int v89; // r0
  unsigned __int64 v90; // r2
  unsigned int *v91; // r1
  unsigned int v92; // r2
  unsigned int v93; // [sp+10h] [bp-60h]
  int v94; // [sp+10h] [bp-60h]
  int v95; // [sp+14h] [bp-5Ch]
  unsigned int v96; // [sp+18h] [bp-58h]
  unsigned int v97; // [sp+20h] [bp-50h]
  int v98; // [sp+20h] [bp-50h]
  unsigned int v99; // [sp+20h] [bp-50h]
  int v100; // [sp+28h] [bp-48h]
  unsigned int v101; // [sp+28h] [bp-48h]
  int v102; // [sp+38h] [bp-38h]
  int v103; // [sp+38h] [bp-38h]
  int v104; // [sp+38h] [bp-38h]
  int v105; // [sp+38h] [bp-38h]
  int v106; // [sp+38h] [bp-38h]

  v95 = a1;
  v2 = __mrc(15, 0, 9, 13, 0);
  v3 = v2 << 29;
  v4 = v2 ^ (v2 >> 3);
  v5 = 67117057i64 * (unsigned int)v4;
  v6 = 1880096896i64 * (unsigned int)v4 + 67117057i64 * v3;
  v7 = (1880096896i64 * v3 + (unsigned __int64)HIDWORD(v6)) >> 32;
  v8 = 1880096896 * v3 + HIDWORD(v6);
  if ( (unsigned int)(v6 + HIDWORD(v5)) < HIDWORD(v5) )
    v7 = (__PAIR64__(v7, v8++) + 1) >> 32;
  LODWORD(v9) = v5 ^ v8;
  HIDWORD(v9) = (v6 + HIDWORD(v5)) ^ v7;
  v10 = FsRtlRemovePerStreamContextEx(2048i64, v9);
  v100 = v10;
  v11 = __mrc(15, 0, 9, 13, 0);
  v12 = v11 << 29;
  v13 = v11 ^ (v11 >> 3);
  v14 = 67117057i64 * (unsigned int)v13;
  v15 = 1880096896i64 * (unsigned int)v13 + 67117057i64 * v12;
  v16 = (1880096896i64 * v12 + (unsigned __int64)HIDWORD(v15)) >> 32;
  v17 = 1880096896 * v12 + HIDWORD(v15);
  if ( (unsigned int)(v15 + HIDWORD(v14)) < HIDWORD(v14) )
    v16 = (__PAIR64__(v16, v17++) + 1) >> 32;
  LODWORD(v18) = v14 ^ v17;
  HIDWORD(v18) = (v15 + HIDWORD(v14)) ^ v16;
  v19 = FsRtlRemovePerStreamContextEx((unsigned int)(v10 + 1), v18);
  v96 = v19;
  v20 = (*(int (__fastcall **)(int, int, _DWORD))(v95 + 216))(512, v100 + 31, *(_DWORD *)(v95 + 832));
  v102 = v20;
  if ( !v20 )
  {
    ++*(_DWORD *)(v95 + 1056);
LABEL_30:
    v58 = 0;
    goto LABEL_32;
  }
  v21 = v19;
  v93 = v19;
  v22 = (int *)v20;
  if ( v19 >= 8 )
  {
    v97 = v19 >> 3;
    do
    {
      v23 = __mrc(15, 0, 9, 13, 0);
      v24 = v23 << 29;
      v25 = v23 ^ (v23 >> 3);
      v26 = (67117057 * (unsigned __int64)(unsigned int)v25) >> 32;
      v94 = 67117057 * v25;
      v27 = 1880096896 * v25 + 67117057 * v24;
      v28 = (1880096896i64 * v24 + ((1880096896i64 * (unsigned int)v25 + 67117057 * (unsigned __int64)v24) >> 32)) >> 32;
      v29 = 1880096896 * v24 + ((1880096896i64 * (unsigned int)v25 + 67117057 * (unsigned __int64)v24) >> 32);
      if ( v27 + v26 < v26 )
        v28 = (__PAIR64__(v28, v29++) + 1) >> 32;
      *v22 = v29 ^ v94;
      v22[1] = v28 ^ (v27 + v26);
      v22 += 2;
      v19 -= 8;
      --v97;
    }
    while ( v97 );
    v93 = v19;
    v19 = v96;
    v21 = v93;
  }
  if ( v21 )
  {
    v30 = __mrc(15, 0, 9, 13, 0);
    v31 = v30 << 29;
    v32 = v30 ^ (v30 >> 3);
    v33 = (67117057 * (unsigned __int64)(unsigned int)v32) >> 32;
    v98 = 67117057 * v32;
    v34 = 1880096896 * v32 + 67117057 * v31;
    v35 = (1880096896i64 * v31 + ((1880096896i64 * (unsigned int)v32 + 67117057 * (unsigned __int64)v31) >> 32)) >> 32;
    v36 = 1880096896 * v31 + ((1880096896i64 * (unsigned int)v32 + 67117057 * (unsigned __int64)v31) >> 32);
    if ( v34 + v33 < v33 )
      v35 = (__PAIR64__(v35, v36++) + 1) >> 32;
    v37 = v98 ^ v36;
    v38 = (v34 + v33) ^ v35;
    v39 = v93;
    do
    {
      *(_BYTE *)v22 = v37;
      v37 = FsRtlPrivateResetHighestLockOffset(v37, v38, 8);
      --v39;
      v22 = (int *)((char *)v22 + 1);
    }
    while ( v39 );
    v19 = v96;
  }
  v40 = v100 - v19;
  v99 = v96 + v102;
  v41 = (int *)(v96 + v102 + 31);
  if ( v40 >= 8 )
  {
    v101 = v40 >> 3;
    do
    {
      v42 = __mrc(15, 0, 9, 13, 0);
      v43 = v42 << 29;
      v44 = v42 ^ (v42 >> 3);
      v45 = (67117057 * (unsigned __int64)(unsigned int)v44) >> 32;
      v103 = 67117057 * v44;
      v46 = 1880096896 * v44 + 67117057 * v43;
      v47 = (1880096896i64 * v43 + ((1880096896i64 * (unsigned int)v44 + 67117057 * (unsigned __int64)v43) >> 32)) >> 32;
      v48 = 1880096896 * v43 + ((1880096896i64 * (unsigned int)v44 + 67117057 * (unsigned __int64)v43) >> 32);
      if ( v46 + v45 < v45 )
        v47 = (__PAIR64__(v47, v48++) + 1) >> 32;
      *v41 = v48 ^ v103;
      v41[1] = v47 ^ (v46 + v45);
      v41 += 2;
      v40 -= 8;
      --v101;
    }
    while ( v101 );
  }
  if ( v40 )
  {
    v49 = __mrc(15, 0, 9, 13, 0);
    v50 = v49 << 29;
    v51 = v49 ^ (v49 >> 3);
    v52 = (67117057 * (unsigned __int64)(unsigned int)v51) >> 32;
    v104 = 67117057 * v51;
    v53 = 1880096896 * v51 + 67117057 * v50;
    v54 = (1880096896i64 * v50 + ((1880096896i64 * (unsigned int)v51 + 67117057 * (unsigned __int64)v50) >> 32)) >> 32;
    v55 = 1880096896 * v50 + ((1880096896i64 * (unsigned int)v51 + 67117057 * (unsigned __int64)v50) >> 32);
    if ( v53 + v52 < v52 )
      v54 = (__PAIR64__(v54, v55++) + 1) >> 32;
    v56 = v104 ^ v55;
    v57 = (v53 + v52) ^ v54;
    do
    {
      *(_BYTE *)v41 = v56;
      v56 = FsRtlPrivateResetHighestLockOffset(v56, v57, 8);
      --v40;
      v41 = (int *)((char *)v41 + 1);
    }
    while ( v40 );
  }
  if ( !v99 )
    goto LABEL_30;
  v58 = (_DWORD *)((v99 + 3) & 0xFFFFFFFC);
LABEL_32:
  if ( !v58 )
    return 0;
  v60 = 28;
  v61 = v58;
  v62 = 7;
  do
  {
    *v61++ = 0;
    v60 -= 4;
    --v62;
  }
  while ( v62 );
  for ( ; v60; --v60 )
  {
    *(_BYTE *)v61 = 0;
    v61 = (_DWORD *)((char *)v61 + 1);
  }
  KeInitializeEvent((int)(v58 + 3), 0, 0);
  *v58 = v58 + 3;
  v63 = __mrc(15, 0, 9, 13, 0);
  v64 = v63 << 29;
  v65 = v63 ^ (v63 >> 3);
  v66 = 67117057i64 * (unsigned int)v65;
  v67 = 1880096896i64 * (unsigned int)v65 + 67117057i64 * v64;
  v68 = (1880096896i64 * v64 + (unsigned __int64)HIDWORD(v67)) >> 32;
  v69 = 1880096896 * v64 + HIDWORD(v67);
  if ( (unsigned int)(v67 + HIDWORD(v66)) < HIDWORD(v66) )
    v68 = (__PAIR64__(v68, v69++) + 1) >> 32;
  LODWORD(v70) = v66 ^ v69;
  HIDWORD(v70) = (v67 + HIDWORD(v66)) ^ v68;
  _rt_udiv64(10i64, v70);
  if ( v72 || v71 )
  {
    v73 = v95;
  }
  else
  {
    v73 = v95;
    *(_DWORD *)(v95 + 992) |= 0x2000000u;
    v58[1] = 1;
  }
  __dmb(0xFu);
  v74 = __mrc(15, 0, 9, 13, 0);
  v75 = v74 << 29;
  v76 = v74 ^ (v74 >> 3);
  v77 = (67117057 * (unsigned __int64)(unsigned int)v76) >> 32;
  v105 = 67117057 * v76;
  v78 = 1880096896 * v75;
  v79 = 67117057i64 * v75 + 1880096896i64 * (unsigned int)v76;
  v80 = v78 + HIDWORD(v79);
  if ( (unsigned int)v79 + v77 < v77 )
    ++v80;
  v106 = v105 ^ v80 ^ v73;
  v81 = __mrc(15, 0, 9, 13, 0);
  v82 = v81 << 29;
  v83 = v81 ^ (v81 >> 3);
  v84 = 67117057i64 * (unsigned int)v83;
  v85 = 1880096896i64 * v82;
  v86 = 67117057i64 * v82 + 1880096896i64 * (unsigned int)v83;
  v87 = (v85 + (unsigned __int64)HIDWORD(v86)) >> 32;
  v88 = v85 + HIDWORD(v86);
  v89 = v86 + HIDWORD(v84);
  if ( (unsigned int)(v86 + HIDWORD(v84)) < HIDWORD(v84) )
    v87 = (__PAIR64__(v87, v88++) + 1) >> 32;
  LODWORD(v90) = v84 ^ v88;
  HIDWORD(v90) = v89 ^ v87;
  v91 = (unsigned int *)((1 << FsRtlRemovePerStreamContextEx(2i64, v90)) | v106);
  __disable_irq();
  if ( !KdDebuggerNotPresent )
  {
    while ( 1 )
      ;
  }
  __enable_irq();
  __dmb(0xBu);
  do
    v92 = __ldrex(v91);
  while ( !v92 && __strex(0, v91) );
  __dmb(0xBu);
  return v58;
}
