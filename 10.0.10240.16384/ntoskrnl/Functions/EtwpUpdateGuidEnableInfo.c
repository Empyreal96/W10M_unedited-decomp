// EtwpUpdateGuidEnableInfo 
 
int __fastcall EtwpUpdateGuidEnableInfo(int a1, int a2, __int64 a3, int a4, _BYTE *a5)
{
  int v5; // r8
  _DWORD *v6; // r6
  char v7; // r4
  char v8; // r4
  unsigned int v9; // r7
  int v10; // r1
  int v12; // r7
  int i; // r2
  _DWORD *v14; // r5
  int v15; // r1
  int v16; // r2
  int v17; // r3
  _DWORD *v18; // r5
  int v19; // r1
  int v20; // r2
  int v21; // r3
  int v22; // r0
  int v23; // r10
  int v24; // lr
  unsigned int v25; // r1
  int v26; // r5
  int v27; // r8
  _DWORD *v28; // r2
  int v29; // r4
  int v30; // r1
  int v31; // r3
  int v32; // r1
  int v33; // r2
  int v34; // r3
  unsigned int v35; // r3
  int v36; // r3
  int v37; // r3
  _DWORD *v38; // r5
  int v39; // r1
  int v40; // r2
  int v41; // r3
  _DWORD *v42; // r5
  int v43; // r1
  int v44; // r2
  int v45; // r3
  int v46; // r0
  int v47; // r10
  int v48; // lr
  unsigned int v49; // r1
  int v50; // r5
  int v51; // r8
  _DWORD *v52; // r2
  int v53; // r4
  int v54; // r1
  int v55; // r3
  int v56; // r1
  int v57; // r2
  int v58; // r3
  unsigned int v59; // r3
  int v60; // r3
  int v61; // r3
  int v63[8]; // [sp+10h] [bp-40h] BYREF

  v5 = a2 + 72;
  v6 = (_DWORD *)a1;
  if ( *(_DWORD *)(a2 + 72) == 1 )
  {
    v7 = *(_BYTE *)(a1 + 51) ^ (*(_DWORD *)(a2 + 112) ^ *(_BYTE *)(a1 + 51)) & 1;
    *(_BYTE *)(a1 + 51) = v7;
    *(_BYTE *)(a1 + 51) = v7 & 1 | (2 * *(_BYTE *)(a2 + 107));
    *(_WORD *)(a1 + 48) = *(_WORD *)(a2 + 104);
    v8 = *(_BYTE *)(a2 + 106);
    *(_QWORD *)(a1 + 40) = a3;
    *(_BYTE *)(a1 + 50) = v8;
  }
  v9 = 0;
  v10 = a1;
  do
  {
    if ( *(_DWORD *)(v10 + 88) && *(unsigned __int16 *)(v10 + 94) == *(unsigned __int16 *)(v5 + 6) )
    {
      v38 = (_DWORD *)(a1 + 32 * v9 + 88);
      v39 = *(_DWORD *)(v5 + 4);
      v40 = *(_DWORD *)(v5 + 8);
      v41 = *(_DWORD *)(v5 + 12);
      *v38 = *(_DWORD *)v5;
      v38[1] = v39;
      v38[2] = v40;
      v38[3] = v41;
      v42 = (_DWORD *)(a1 + 32 * v9 + 104);
      v43 = *(_DWORD *)(v5 + 20);
      v44 = *(_DWORD *)(v5 + 24);
      v45 = *(_DWORD *)(v5 + 28);
      *v42 = *(_DWORD *)(v5 + 16);
      v42[1] = v43;
      v42[2] = v44;
      v42[3] = v45;
      memset(v63, 0, sizeof(v63));
      v46 = -1;
      v47 = v63[4];
      v48 = v63[5];
      v49 = LOBYTE(v63[1]);
      v63[6] = -1;
      v63[7] = -1;
      v50 = -1;
      v51 = v63[2];
      v52 = v6;
      v53 = 8;
      do
      {
        if ( v52[22] )
        {
          v59 = *((unsigned __int8 *)v52 + 92);
          v63[0] = 1;
          if ( v49 <= v59 )
            LOBYTE(v49) = v59;
          v60 = v52[26];
          v49 = (unsigned __int8)v49;
          LOBYTE(v63[1]) = v49;
          v47 |= v60;
          v48 |= v52[27];
          v46 &= v52[28];
          v61 = v52[29];
          v63[6] = v46;
          v50 &= v61;
          v51 |= v52[24];
        }
        v52 += 8;
        --v53;
      }
      while ( v53 );
      v63[7] = v50;
      v63[4] = v47;
      v63[5] = v48;
      v63[2] = v51;
      v54 = v63[1];
      v55 = v63[3];
      v6[14] = v63[0];
      v6[15] = v54;
      v6[16] = v51;
      v6[17] = v55;
      v56 = v63[5];
      v57 = v63[6];
      v58 = v63[7];
      v6[18] = v63[4];
      v6[19] = v56;
      v6[20] = v57;
      v6[21] = v58;
      *a5 = 1 << v9;
      EtwpUpdateFilterData(v6, v9, a2, *(_DWORD *)(a2 + 72) == 0, a4);
      if ( !*(_DWORD *)(a2 + 72) )
        EtwpUnreferenceGuidEntry((int)v6);
      return 0;
    }
    ++v9;
    v10 += 32;
  }
  while ( v9 < 8 );
  if ( !*(_DWORD *)v5 )
    return sub_807C50(a1, v10);
  v12 = 0;
  for ( i = a1; *(_DWORD *)(i + 88); i += 32 )
  {
    if ( (unsigned int)++v12 >= 8 )
      return -1073741670;
  }
  v14 = (_DWORD *)(a1 + 32 * v12 + 88);
  v15 = *(_DWORD *)(v5 + 4);
  v16 = *(_DWORD *)(v5 + 8);
  v17 = *(_DWORD *)(v5 + 12);
  *v14 = *(_DWORD *)v5;
  v14[1] = v15;
  v14[2] = v16;
  v14[3] = v17;
  v18 = (_DWORD *)(a1 + 32 * v12 + 104);
  v19 = *(_DWORD *)(v5 + 20);
  v20 = *(_DWORD *)(v5 + 24);
  v21 = *(_DWORD *)(v5 + 28);
  *v18 = *(_DWORD *)(v5 + 16);
  v18[1] = v19;
  v18[2] = v20;
  v18[3] = v21;
  memset(v63, 0, sizeof(v63));
  v22 = -1;
  v23 = v63[4];
  v24 = v63[5];
  v25 = LOBYTE(v63[1]);
  v63[6] = -1;
  v63[7] = -1;
  v26 = -1;
  v27 = v63[2];
  v28 = v6;
  v29 = 8;
  do
  {
    if ( v28[22] )
    {
      v35 = *((unsigned __int8 *)v28 + 92);
      v63[0] = 1;
      if ( v25 <= v35 )
        LOBYTE(v25) = v35;
      v36 = v28[26];
      v25 = (unsigned __int8)v25;
      LOBYTE(v63[1]) = v25;
      v23 |= v36;
      v24 |= v28[27];
      v22 &= v28[28];
      v37 = v28[29];
      v63[6] = v22;
      v26 &= v37;
      v27 |= v28[24];
    }
    v28 += 8;
    --v29;
  }
  while ( v29 );
  v63[7] = v26;
  v63[4] = v23;
  v63[5] = v24;
  v63[2] = v27;
  v30 = v63[1];
  v31 = v63[3];
  v6[14] = v63[0];
  v6[15] = v30;
  v6[16] = v27;
  v6[17] = v31;
  v32 = v63[5];
  v33 = v63[6];
  v34 = v63[7];
  v6[18] = v63[4];
  v6[19] = v32;
  v6[20] = v33;
  v6[21] = v34;
  *a5 = 1 << v12;
  EtwpUpdateFilterData(v6, v12, a2, *(_DWORD *)(a2 + 72) == 0, a4);
  EtwpReferenceGuidEntry((int)v6);
  return 0;
}
