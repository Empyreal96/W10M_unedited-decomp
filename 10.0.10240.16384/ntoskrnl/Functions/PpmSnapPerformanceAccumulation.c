// PpmSnapPerformanceAccumulation 
 
int __fastcall PpmSnapPerformanceAccumulation(int a1, int a2, int a3, int a4, int a5)
{
  unsigned int v7; // r10
  unsigned __int64 *v8; // r4
  unsigned int v9; // r6
  unsigned __int64 v10; // kr18_8
  unsigned int v11; // r4
  __int64 v12; // r4
  unsigned __int64 v13; // r0
  __int64 v14; // kr20_8
  unsigned __int64 *v15; // r3
  unsigned __int64 v16; // kr28_8
  int v17; // r3
  unsigned int v18; // r6
  unsigned int v19; // r5
  _BYTE *v20; // r0
  int v21; // r3
  int result; // r0
  unsigned __int64 v23; // r4
  int v24; // r2
  int v25; // r3
  int v26; // r3
  unsigned int v27; // r2
  unsigned int v28; // r3
  bool v29; // cf
  int v30; // r3
  unsigned __int64 *v31; // r2
  unsigned __int64 v32; // kr38_8
  unsigned int v33; // kr08_4
  unsigned int v34; // r1
  __int64 v35; // [sp+4h] [bp-58h] BYREF
  unsigned int v36; // [sp+Ch] [bp-50h]
  unsigned int v37; // [sp+10h] [bp-4Ch]
  int v38; // [sp+14h] [bp-48h]
  int v39; // [sp+18h] [bp-44h]
  unsigned int v40; // [sp+1Ch] [bp-40h]
  int v41; // [sp+20h] [bp-3Ch]

  v41 = a4;
  v38 = *(_DWORD *)(a1 + 3196);
  v39 = a2;
  v40 = 0;
  v7 = 0;
  if ( a3 )
  {
    KeQueryPerformanceCounter(&v35, 0);
    v36 = HIDWORD(v35);
    v37 = v35;
    __dmb(0xBu);
    v8 = (unsigned __int64 *)(a1 + 2968);
    do
    {
      v10 = __ldrexd(v8);
      v7 = HIDWORD(v10);
      v9 = v10;
    }
    while ( __strexd(v10, v8) );
    __dmb(0xBu);
    if ( !v10 )
      return 0;
    v11 = v35;
  }
  else
  {
    __disable_irq();
    KeQueryPerformanceCounter(&v35, 0);
    v12 = v35;
    v36 = HIDWORD(v35);
    v37 = v35;
    LODWORD(v13) = ReadTimeStampCounter();
    v14 = v12 - *(_QWORD *)(a1 + 3040);
    __dmb(0xBu);
    v15 = (unsigned __int64 *)(a1 + 3056);
    do
      v16 = __ldrexd(v15);
    while ( __strexd(v16 + v14, v15) );
    __dmb(0xBu);
    v17 = HIDWORD(v35);
    v11 = v35;
    v18 = *(_DWORD *)(a1 + 3020);
    v19 = *(_DWORD *)(a1 + 3016);
    *(_DWORD *)(a1 + 3040) = v35;
    *(_DWORD *)(a1 + 3044) = v17;
    if ( v13 > __PAIR64__(v18, v19) )
      *(_QWORD *)(a1 + 3024) = *(_QWORD *)(a1 + 3024) - __PAIR64__(v18, v19) + v13;
    *(_QWORD *)(a1 + 3016) = v13;
    v9 = 0;
  }
  v20 = memset((_BYTE *)a5, 0, 80);
  *(_DWORD *)(a5 + 56) = *(_DWORD *)(a1 + 2368);
  *(_DWORD *)(a5 + 60) = *(_DWORD *)(a1 + 2372);
  if ( v38 )
  {
    *(_DWORD *)(a5 + 64) = *(_DWORD *)(a1 + 2392);
    *(_DWORD *)(a5 + 68) = *(_DWORD *)(a1 + 2396);
    *(_DWORD *)(a5 + 72) = *(_DWORD *)(a1 + 2400);
    *(_DWORD *)(a5 + 76) = *(_DWORD *)(a1 + 2404);
  }
  if ( !a3 )
    __enable_irq();
  v21 = *(_DWORD *)(a1 + 3112);
  LODWORD(v35) = 0;
  if ( v21 == 3 )
    return sub_5414B0(v20);
  result = PpmUpdatePerformanceFeedback(a1, v39, a3, 0);
  if ( result )
  {
    if ( v41 && PopSnapEnergyCounters )
      PopSnapEnergyCounters(*(_DWORD *)(a1 + 20), a3, 1);
    v40 = v7;
    if ( v36 <= v7 && (v36 < v7 || v11 <= v9) )
    {
      v36 = v7;
      v37 = v9;
    }
    v23 = *(_QWORD *)(a1 + 2960);
    v24 = v35;
    v39 = *(_DWORD *)(a1 + 3024);
    v38 = *(_DWORD *)(a1 + 3028);
    if ( *(_DWORD *)(a1 + 3032) )
    {
      *(_DWORD *)(a5 + 24) = *(_DWORD *)(a1 + 3064);
      v25 = *(_DWORD *)(a1 + 3068);
    }
    else if ( *(_DWORD *)(a1 + 3036) )
    {
      *(_DWORD *)(a5 + 24) = *(_DWORD *)(a1 + 3072);
      v25 = *(_DWORD *)(a1 + 3076);
    }
    else
    {
      v33 = *(_DWORD *)(a1 + 3048);
      v34 = *(_DWORD *)(a1 + 3052);
      *(_DWORD *)(a5 + 24) = 100 * v33;
      v24 = v35;
      v25 = (100 * __PAIR64__(v34, v33)) >> 32;
    }
    *(_DWORD *)(a5 + 28) = v25;
    if ( *(_DWORD *)(a1 + 3036) )
    {
      *(_DWORD *)(a5 + 32) = *(_DWORD *)(a1 + 3072);
      v26 = *(_DWORD *)(a1 + 3076);
    }
    else
    {
      *(_DWORD *)(a5 + 32) = *(_DWORD *)(a5 + 24);
      v26 = *(_DWORD *)(a5 + 28);
    }
    *(_DWORD *)(a5 + 36) = v26;
    *(_DWORD *)(a5 + 40) = *(_DWORD *)(a1 + 3088);
    *(_DWORD *)(a5 + 44) = *(_DWORD *)(a1 + 3092);
    if ( !a3 )
    {
      if ( !v24 )
        v23 += *(_QWORD *)(a1 + 2952);
LABEL_31:
      v27 = v36;
      v28 = v37;
      *(_DWORD *)a5 = v37;
      *(_DWORD *)(a5 + 4) = v27;
      v29 = v28 >= (unsigned int)v23;
      *(_DWORD *)(a5 + 8) = v28 - v23;
      v30 = v39;
      *(_DWORD *)(a5 + 12) = v27 - (HIDWORD(v23) + !v29);
      *(_DWORD *)(a5 + 48) = v30;
      result = 1;
      *(_DWORD *)(a5 + 52) = v38;
      return result;
    }
    __dmb(0xBu);
    v31 = (unsigned __int64 *)(a1 + 2968);
    do
      v32 = __ldrexd(v31);
    while ( __strexd(v32, v31) );
    __dmb(0xBu);
    if ( __PAIR64__(v7, v9) == v32 )
    {
      if ( !(_DWORD)v35 )
        v23 = v23 - __PAIR64__(v40, v9) + __PAIR64__(v36, v37);
      goto LABEL_31;
    }
    return 0;
  }
  return result;
}
