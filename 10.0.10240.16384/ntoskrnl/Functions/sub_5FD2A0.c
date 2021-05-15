// sub_5FD2A0 
 
_DWORD *__fastcall sub_5FD2A0(int a1, int a2, int a3)
{
  int v3; // r8
  int v4; // r9
  unsigned int v5; // r3
  unsigned int v6; // r7
  int v7; // r3
  __int64 v8; // kr00_8
  int v9; // r6
  unsigned int v10; // r0
  unsigned int v11; // r3
  unsigned __int64 v12; // r2
  int v13; // r0
  int v14; // r10
  unsigned int v15; // r3
  unsigned int v16; // r6
  int v17; // r3
  __int64 v18; // kr28_8
  __int64 v19; // kr30_8
  unsigned int v20; // r1
  int v21; // r3
  unsigned __int64 v22; // r2
  unsigned int v23; // r4
  int v24; // r2
  unsigned int v25; // r3
  unsigned int v26; // r5
  int v27; // r3
  __int64 v28; // kr48_8
  __int64 v29; // kr50_8
  unsigned int v30; // r1
  int v31; // r3
  unsigned __int64 v32; // r2
  int v33; // r4
  int v34; // r0
  _DWORD *v35; // r9
  int v36; // r9
  int v37; // r0
  unsigned int v38; // r10
  int *v39; // r7
  unsigned int v40; // lr
  unsigned int v41; // r3
  unsigned int v42; // r6
  int v43; // r3
  unsigned int v44; // r5
  int v45; // r4
  unsigned int v46; // r2
  unsigned int v47; // r3
  unsigned int v48; // r3
  unsigned int v49; // r5
  int v50; // r3
  unsigned int v51; // r6
  int v52; // r4
  unsigned int v53; // r2
  unsigned int v54; // r3
  int v55; // r0
  int v56; // r1
  unsigned int v57; // r10
  _DWORD *v58; // r7
  int *v59; // lr
  unsigned int v60; // r8
  unsigned int v61; // r3
  unsigned int v62; // r6
  int v63; // r3
  unsigned int v64; // r5
  int v65; // r4
  unsigned int v66; // r2
  unsigned int v67; // r3
  unsigned int v68; // r3
  unsigned int v69; // r5
  int v70; // r3
  unsigned int v71; // r6
  int v72; // r4
  unsigned int v73; // r2
  unsigned int v74; // r3
  int v75; // r0
  int v76; // r1
  unsigned int v77; // r2
  _DWORD *v78; // r1
  unsigned int v79; // r0
  int v80; // t1
  char *v81; // r1
  int v82; // r3
  int (__fastcall *v85)(int, int); // [sp+4h] [bp-3Ch]
  unsigned int v86; // [sp+8h] [bp-38h]
  int v87; // [sp+Ch] [bp-34h]
  int (__fastcall *v89)(int, unsigned int, int); // [sp+14h] [bp-2Ch]
  void (__fastcall *v90)(_DWORD *, int); // [sp+18h] [bp-28h]
  int v91; // [sp+18h] [bp-28h]
  int v92; // [sp+18h] [bp-28h]
  int v93; // [sp+18h] [bp-28h]
  int v94; // [sp+18h] [bp-28h]

  v3 = a1;
  v4 = 1;
  v5 = __mrc(15, 0, 9, 13, 0);
  v6 = v5 << 29;
  v7 = v5 ^ (v5 >> 3);
  v8 = 67117057i64 * (unsigned int)v7;
  v9 = 1880096896 * v7 + 67117057 * v6;
  v10 = (1880096896i64 * v6 + ((1880096896i64 * (unsigned int)v7 + 67117057 * (unsigned __int64)v6) >> 32)) >> 32;
  v11 = 1880096896 * v6 + ((1880096896i64 * (unsigned int)v7 + 67117057 * (unsigned __int64)v6) >> 32);
  if ( (unsigned int)(v9 + HIDWORD(v8)) < HIDWORD(v8) )
    v10 = (__PAIR64__(v10, v11++) + 1) >> 32;
  LODWORD(v12) = v8 ^ v11;
  HIDWORD(v12) = (v9 + HIDWORD(v8)) ^ v10;
  v13 = FsRtlRemovePerStreamContextEx(2048i64, v12);
  v14 = v13 + 3;
  v87 = v13 + 3;
  v15 = __mrc(15, 0, 9, 13, 0);
  v16 = v15 << 29;
  v17 = v15 ^ (v15 >> 3);
  v18 = 67117057i64 * (unsigned int)v17;
  v19 = 1880096896i64 * (unsigned int)v17 + 67117057i64 * v16;
  v20 = (1880096896i64 * v16 + (unsigned __int64)HIDWORD(v19)) >> 32;
  v21 = 1880096896 * v16 + HIDWORD(v19);
  if ( (unsigned int)(v19 + HIDWORD(v18)) < HIDWORD(v18) )
    v20 = (__PAIR64__(v20, v21++) + 1) >> 32;
  LODWORD(v22) = v18 ^ v21;
  HIDWORD(v22) = (v19 + HIDWORD(v18)) ^ v20;
  v23 = FsRtlRemovePerStreamContextEx((unsigned int)(v13 + 4), v22) & 0xFFFFFFFC;
  v24 = *(_DWORD *)(v3 + 928);
  v85 = *(int (__fastcall **)(int, int))(v3 + 344);
  v86 = v23;
  v90 = *(void (__fastcall **)(_DWORD *, int))(v3 + 348);
  v89 = *(int (__fastcall **)(int, unsigned int, int))(v3 + 352);
  if ( (*(_DWORD *)(v3 + 992) & 0x10000000) != 0 )
  {
    v4 = 0;
    v24 = 0;
  }
  if ( v24 && v24 == 1 )
  {
    v25 = __mrc(15, 0, 9, 13, 0);
    v26 = v25 << 29;
    v27 = v25 ^ (v25 >> 3);
    v28 = 67117057i64 * (unsigned int)v27;
    v29 = 1880096896i64 * (unsigned int)v27 + 67117057i64 * v26;
    v30 = (1880096896i64 * v26 + (unsigned __int64)HIDWORD(v29)) >> 32;
    v31 = 1880096896 * v26 + HIDWORD(v29);
    if ( (unsigned int)(v29 + HIDWORD(v28)) < HIDWORD(v28) )
      v30 = (__PAIR64__(v30, v31++) + 1) >> 32;
    LODWORD(v32) = v28 ^ v31;
    HIDWORD(v32) = (v29 + HIDWORD(v28)) ^ v30;
    v87 = v14 + (((unsigned int)FsRtlRemovePerStreamContextEx(2i64, v32) + 1) << 12);
    v33 = v87 + a2;
    v34 = v85(v87 + a2 + 4, -1);
    v35 = (_DWORD *)v34;
    if ( !v34 )
      goto LABEL_20;
    if ( !v89(v34, (unsigned int)(v33 + 4095) >> 12 << 12, 64) )
    {
      v90(v35, v33);
LABEL_20:
      ++*(_DWORD *)(v3 + 1056);
      return 0;
    }
    v23 = v86;
    *v35 = v87 + a2 + 4;
    v36 = (int)(v35 + 1);
  }
  else
  {
    if ( v4 )
      v37 = 0;
    else
      v37 = 512;
    v36 = (*(int (__fastcall **)(int, int, _DWORD))(v3 + 216))(v37, v14 + a2, *(_DWORD *)(v3 + 832));
  }
  if ( !v36 )
    goto LABEL_20;
  v38 = v23;
  v39 = (int *)v36;
  if ( v23 >= 8 )
  {
    v40 = v23 >> 3;
    do
    {
      v41 = __mrc(15, 0, 9, 13, 0);
      v42 = v41 << 29;
      v43 = v41 ^ (v41 >> 3);
      v44 = (67117057 * (unsigned __int64)(unsigned int)v43) >> 32;
      v91 = 67117057 * v43;
      v45 = 1880096896 * v43 + 67117057 * v42;
      v46 = (1880096896i64 * v42 + ((1880096896i64 * (unsigned int)v43 + 67117057 * (unsigned __int64)v42) >> 32)) >> 32;
      v47 = 1880096896 * v42 + ((1880096896i64 * (unsigned int)v43 + 67117057 * (unsigned __int64)v42) >> 32);
      if ( v45 + v44 < v44 )
        v46 = (__PAIR64__(v46, v47++) + 1) >> 32;
      v39[1] = v46 ^ (v45 + v44);
      *v39 = v47 ^ v91;
      v39 += 2;
      --v40;
      v38 -= 8;
    }
    while ( v40 );
    v3 = a1;
  }
  if ( v38 )
  {
    v48 = __mrc(15, 0, 9, 13, 0);
    v49 = v48 << 29;
    v50 = v48 ^ (v48 >> 3);
    v51 = (67117057 * (unsigned __int64)(unsigned int)v50) >> 32;
    v92 = 67117057 * v50;
    v52 = 1880096896 * v50 + 67117057 * v49;
    v53 = (1880096896i64 * v49 + ((1880096896i64 * (unsigned int)v50 + 67117057 * (unsigned __int64)v49) >> 32)) >> 32;
    v54 = 1880096896 * v49 + ((1880096896i64 * (unsigned int)v50 + 67117057 * (unsigned __int64)v49) >> 32);
    if ( v52 + v51 < v51 )
      v53 = (__PAIR64__(v53, v54++) + 1) >> 32;
    v55 = v92 ^ v54;
    v56 = (v52 + v51) ^ v53;
    do
    {
      *(_BYTE *)v39 = v55;
      v39 = (int *)((char *)v39 + 1);
      v55 = FsRtlPrivateResetHighestLockOffset(v55, v56, 8);
      --v38;
    }
    while ( v38 );
  }
  v57 = v87 - v86;
  v58 = (_DWORD *)(v36 + v86);
  v59 = (int *)(v36 + v86 + a2);
  if ( v87 - v86 >= 8 )
  {
    v60 = v57 >> 3;
    do
    {
      v61 = __mrc(15, 0, 9, 13, 0);
      v62 = v61 << 29;
      v63 = v61 ^ (v61 >> 3);
      v64 = (67117057 * (unsigned __int64)(unsigned int)v63) >> 32;
      v93 = 67117057 * v63;
      v65 = 1880096896 * v63 + 67117057 * v62;
      v66 = (1880096896i64 * v62 + ((1880096896i64 * (unsigned int)v63 + 67117057 * (unsigned __int64)v62) >> 32)) >> 32;
      v67 = 1880096896 * v62 + ((1880096896i64 * (unsigned int)v63 + 67117057 * (unsigned __int64)v62) >> 32);
      if ( v65 + v64 < v64 )
        v66 = (__PAIR64__(v66, v67++) + 1) >> 32;
      v59[1] = v66 ^ (v65 + v64);
      *v59 = v67 ^ v93;
      v59 += 2;
      v57 -= 8;
      --v60;
    }
    while ( v60 );
    v3 = a1;
    v58 = (_DWORD *)(v36 + v86);
  }
  if ( v57 )
  {
    v68 = __mrc(15, 0, 9, 13, 0);
    v69 = v68 << 29;
    v70 = v68 ^ (v68 >> 3);
    v71 = (67117057 * (unsigned __int64)(unsigned int)v70) >> 32;
    v94 = 67117057 * v70;
    v72 = 1880096896 * v70 + 67117057 * v69;
    v73 = (1880096896i64 * v69 + ((1880096896i64 * (unsigned int)v70 + 67117057 * (unsigned __int64)v69) >> 32)) >> 32;
    v74 = 1880096896 * v69 + ((1880096896i64 * (unsigned int)v70 + 67117057 * (unsigned __int64)v69) >> 32);
    if ( v72 + v71 < v71 )
      v73 = (__PAIR64__(v73, v74++) + 1) >> 32;
    v75 = v94 ^ v74;
    v76 = (v72 + v71) ^ v73;
    do
    {
      *(_BYTE *)v59 = v75;
      v75 = FsRtlPrivateResetHighestLockOffset(v75, v76, 8);
      v59 = (int *)((char *)v59 + 1);
      --v57;
    }
    while ( v57 );
  }
  if ( !v58 )
    return 0;
  v77 = *(_DWORD *)(v3 + 796);
  v78 = v58;
  if ( v77 >= 4 )
  {
    v79 = v77 >> 2;
    do
    {
      v80 = *(_DWORD *)v3;
      v3 += 4;
      v77 -= 4;
      --v79;
      *v78++ = v80;
    }
    while ( v79 );
  }
  if ( v77 )
  {
    v81 = (char *)v78 - v3;
    do
    {
      --v77;
      v81[v3] = *(_BYTE *)v3;
      ++v3;
    }
    while ( v77 );
  }
  v58[195] = v36;
  v58[199] = a2;
  v58[232] = a3;
  v82 = v58[248];
  if ( (v82 & 0x10000000) == 0 )
    v58[248] = v82 | 0x20000000;
  return v58;
}
