// RaspScaleCoordinates 
 
int __fastcall RaspScaleCoordinates(int a1, int a2)
{
  int v2; // r3
  int v4; // r4
  unsigned int v6; // r1
  int v7; // r3
  int v8; // r9
  int v9; // r2
  int v10; // r7
  int v11; // r10
  int v12; // r1
  __int64 v13; // r2
  __int64 v14; // r0
  int v15; // r2
  __int64 v16; // r2
  __int64 v17; // r0
  int v18; // r0
  int v19; // r2
  int v20; // r1
  __int64 v21; // r2
  int v22; // r0
  int v23; // r2
  int v24; // r1
  __int64 v25; // r2
  int v26; // r0
  int v27; // r2
  int v28; // r1
  __int64 v29; // r2
  int v30; // r0
  int v31; // r3
  int v32; // r5
  unsigned __int16 v33; // r8
  int v34; // r4
  __int64 v35; // r0
  int v36; // r2
  int v37; // r1
  __int64 v38; // r2
  int v39; // r4
  __int64 v40; // r0
  int v41; // r2
  int v42; // r1
  __int64 v43; // r2

  v2 = *(_DWORD *)(a1 + 8);
  v4 = *(unsigned __int16 *)(v2 + 88);
  if ( !*(_WORD *)(v2 + 88) )
    return sub_54DC20();
  v6 = (*(unsigned int *)(v2 + 76) * (unsigned __int64)*(unsigned int *)(a1 + 12)) >> 32;
  v7 = *(_DWORD *)(v2 + 76) * *(_DWORD *)(a1 + 12);
  v8 = __SPAIR64__(v6, v7) >> 26;
  v9 = *(__int16 *)(a2 + 2);
  v10 = v7 << 6;
  v11 = 72 * v4;
  v12 = (v9 >> 31) * (v7 << 6) + v9 * v8;
  v13 = (unsigned int)v9 * (unsigned __int64)(unsigned int)(v7 << 6);
  HIDWORD(v13) += v12;
  HIDWORD(v14) = 0;
  if ( !(72 * v4) )
    __brkdiv0();
  LODWORD(v14) = 72 * v4;
  LODWORD(v17) = _rt_sdiv64(v14, v13);
  v15 = *(__int16 *)(a2 + 6);
  *(_DWORD *)(a2 + 2) = v17;
  HIDWORD(v17) = (v15 >> 31) * v10 + v15 * v8;
  v16 = (unsigned int)v15 * (unsigned __int64)(unsigned int)v10;
  HIDWORD(v16) += HIDWORD(v17);
  HIDWORD(v17) = 0;
  if ( !v11 )
    __brkdiv0();
  LODWORD(v17) = 72 * v4;
  v18 = _rt_sdiv64(v17, v16);
  v19 = *(__int16 *)(a2 + 10);
  *(_DWORD *)(a2 + 6) = v18;
  v20 = (v19 >> 31) * v10 + v19 * v8;
  v21 = (unsigned int)v19 * (unsigned __int64)(unsigned int)v10;
  HIDWORD(v21) += v20;
  v22 = _rt_sdiv64((unsigned int)(72 * v4), v21);
  v23 = *(__int16 *)(a2 + 14);
  *(_DWORD *)(a2 + 10) = v22;
  v24 = (v23 >> 31) * v10 + v23 * v8;
  v25 = (unsigned int)v23 * (unsigned __int64)(unsigned int)v10;
  HIDWORD(v25) += v24;
  v26 = _rt_sdiv64((unsigned int)(72 * v4), v25);
  v27 = *(__int16 *)(a2 + 18);
  *(_DWORD *)(a2 + 14) = v26;
  v28 = (v27 >> 31) * v10 + v27 * v8;
  v29 = (unsigned int)v27 * (unsigned __int64)(unsigned int)v10;
  HIDWORD(v29) += v28;
  v30 = _rt_sdiv64((unsigned int)(72 * v4), v29);
  v31 = *(unsigned __int16 *)(a2 + 24);
  v32 = 0;
  *(_DWORD *)(a2 + 18) = v30;
  if ( v31 )
  {
    v33 = 0;
    do
    {
      v34 = *(_DWORD *)(a2 + 38);
      LODWORD(v35) = v11;
      v36 = (__int16)*(_DWORD *)(v34 + 4 * v32);
      v37 = (v36 >> 31) * v10 + v36 * v8;
      v38 = (unsigned int)v36 * (unsigned __int64)(unsigned int)v10;
      HIDWORD(v38) += v37;
      HIDWORD(v35) = 0;
      *(_DWORD *)(v34 + 4 * v32) = _rt_sdiv64(v35, v38);
      v39 = *(_DWORD *)(a2 + 42);
      LODWORD(v40) = v11;
      v41 = (__int16)*(_DWORD *)(v39 + 4 * v32);
      v42 = (v41 >> 31) * v10 + v41 * v8;
      v43 = (unsigned int)v41 * (unsigned __int64)(unsigned int)v10;
      HIDWORD(v43) += v42;
      HIDWORD(v40) = 0;
      *(_DWORD *)(v39 + 4 * v32) = _rt_sdiv64(v40, v43);
      v32 = ++v33;
    }
    while ( v33 < (unsigned int)*(unsigned __int16 *)(a2 + 24) );
  }
  return 0;
}
