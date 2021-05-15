// RaspTestIntersection 
 
int __fastcall RaspTestIntersection(signed __int64 a1, _DWORD *a2, _DWORD *a3)
{
  int v3; // r9
  __int64 v4; // kr20_8
  int v5; // r5
  _DWORD *v6; // r4
  int v7; // r2
  int v8; // r3
  int v9; // r4
  int v10; // r8
  unsigned int v11; // r10
  unsigned int v12; // r1
  int v13; // r6
  unsigned int v14; // r2
  _DWORD *v15; // r4
  unsigned int v16; // r0
  unsigned int v17; // r1
  unsigned __int64 v18; // kr40_8
  __int64 v19; // kr48_8
  unsigned int v20; // r7
  __int64 v21; // r2
  unsigned int v22; // r8
  __int64 v23; // r0
  __int64 v24; // r0
  __int64 v25; // r0
  unsigned __int64 v26; // kr68_8
  _DWORD *v27; // r2
  int v28; // r4
  signed __int64 v29; // kr18_8
  int v30; // r0
  int v31; // r1
  __int64 v32; // r2
  int v33; // kr88_4
  __int64 v34; // r0
  int v38; // [sp+8h] [bp-50h]
  unsigned int v39; // [sp+8h] [bp-50h]
  int v40; // [sp+Ch] [bp-4Ch]
  int v41; // [sp+10h] [bp-48h]
  int v42; // [sp+18h] [bp-40h]
  int v43; // [sp+18h] [bp-40h]
  int v44; // [sp+1Ch] [bp-3Ch]
  _DWORD *v45; // [sp+20h] [bp-38h]
  __int64 v46; // [sp+24h] [bp-34h]
  unsigned int v47; // [sp+28h] [bp-30h]
  int v48; // [sp+30h] [bp-28h]

  v40 = *(_DWORD *)(*(_DWORD *)a1 + 8) + **(_DWORD **)a1;
  v3 = *(_DWORD *)(*(_DWORD *)a1 + 12) + *(_DWORD *)(*(_DWORD *)a1 + 4);
  v4 = (__int64)v3 << 16;
  v45 = *(_DWORD **)(a1 + 4);
  v5 = v45[3] + v45[1];
  v6 = *(_DWORD **)(a1 + 8);
  v38 = (unsigned __int64)v5 >> 16;
  v48 = *v6 + v6[2];
  v41 = v48 << 16;
  v7 = v6[3];
  v42 = v48 << 16;
  v8 = v6[1];
  v9 = HIDWORD(a1);
  v46 = v8 + v7;
  v10 = (unsigned __int64)(int)v46 >> 16;
  v11 = (_DWORD)v46 << 16;
  v13 = (unsigned __int64)SHIDWORD(a1) >> 16;
  v12 = HIDWORD(a1) << 16;
  if ( v4 == (__int64)(int)v46 << 16 )
  {
    if ( v4 == __PAIR64__(v13, v12) )
      goto LABEL_17;
  }
  else if ( v4 == __PAIR64__(v13, v12) )
  {
LABEL_45:
    v13 = (__PAIR64__(v13, v12++) + 1) >> 32;
    goto LABEL_46;
  }
  if ( v11 == v12 && v10 == v13 )
    goto LABEL_45;
  if ( *(_BYTE *)(a1 + 12) == 1 )
  {
LABEL_46:
    v14 = v5 << 16;
    goto LABEL_9;
  }
  v14 = v5 << 16;
  if ( v5 << 16 == v12 && v38 == v13 )
    v13 = (__PAIR64__(v13, v12++) + 1) >> 32;
LABEL_9:
  if ( *(_BYTE *)(a1 + 12) == 1 )
  {
    *a3 = 0x7FFFFFFF;
    if ( SHIDWORD(v4) < v13 )
      goto LABEL_57;
    if ( (SHIDWORD(v4) > v13 || (unsigned int)v4 > v12) && (v10 > v13 || v10 >= v13 && v11 > v12) )
      goto LABEL_53;
    if ( v4 < __SPAIR64__(v13, v12) )
    {
LABEL_57:
      if ( v10 <= v13 && (v10 < v13 || v11 < v12) )
      {
LABEL_53:
        *a2 = 0x7FFFFFFF;
        return a1;
      }
    }
    if ( __PAIR64__(v10, v11) == v4 )
      __brkdiv0();
    LODWORD(a1) = _rt_sdiv64(
                    __PAIR64__(v10, v11) - v4,
                    (__PAIR64__(v42, v41) - ((__int64)v40 << 16)) * (__PAIR64__(v13, v12) - v4));
    v28 = (unsigned __int64)(a1 + ((__int64)v40 << 16)) >> 32;
    LODWORD(a1) = a1 + (v40 << 16);
    v29 = __PAIR64__(v28, a1);
    LODWORD(a1) = a1 + ((unsigned int)(v28 >> 15) >> 16);
    *a2 = v29 / 0x10000;
    return a1;
  }
  if ( v4 <= __SPAIR64__(v13, v12) )
  {
    LODWORD(a1) = (unsigned __int64)v5 >> 16;
  }
  else
  {
    LODWORD(a1) = (unsigned __int64)v5 >> 16;
    if ( v38 >= v13 && (v38 > v13 || v14 > v12) && (v10 > v13 || v10 >= v13 && v11 > v12) )
      goto LABEL_17;
  }
  if ( v4 < __SPAIR64__(v13, v12)
    && (int)a1 <= v13
    && ((int)a1 < v13 || v14 < v12)
    && v10 <= v13
    && (v10 < v13 || v11 < v12) )
  {
    goto LABEL_17;
  }
  if ( !(__PAIR64__(v10, v11) - __PAIR64__((v14 >> 31) | (2 * a1), 2 * v14) + v4) )
  {
    v30 = ((__PAIR64__(v13, v12) - v4) >> 32) * (v41 - (v40 << 16))
        + (v12 - v4) * ((__PAIR64__(v42, v41) - ((__int64)v40 << 16)) >> 32);
    v33 = (v12 - v4) * (v41 - (v40 << 16));
    v31 = ((v12 - (unsigned int)v4) * (unsigned __int64)(unsigned int)(v41 - (v40 << 16))) >> 32;
    LODWORD(v32) = v33;
    if ( __PAIR64__(v10, v11) == v4 )
      __brkdiv0();
    HIDWORD(v32) = v30 + v31;
    LODWORD(v34) = _rt_sdiv64(__PAIR64__(v10, v11) - v4, v32);
    HIDWORD(a1) = (v34 + ((__int64)v40 << 16)) / 0x10000;
    LODWORD(a1) = 0x7FFFFFFF;
    *a3 = 0x7FFFFFFF;
    *a2 = HIDWORD(a1);
    return a1;
  }
  v43 = *v45 + v45[2];
  v16 = (unsigned __int64)(v46 - 2i64 * v5) >> 32;
  v17 = v46 - 2 * v5;
  v47 = v17 + v3;
  v18 = __PAIR64__(v16, v17) + v3;
  v19 = 2 * (v5 - (__int64)v3);
  a1 = __PAIR64__(
         2 * v19 * HIDWORD(v19) + (((unsigned int)v19 * (unsigned __int64)(unsigned int)v19) >> 32),
         (int)v19 * (int)v19)
     - __PAIR64__(
         (((v3 - v9) * v47) >> 30) | (unsigned int)(4
                                                  * (((unsigned __int64)(v3 - (__int64)v9) >> 32) * v47
                                                   + (v3 - v9) * HIDWORD(v18)
                                                   + (((unsigned int)(v3 - v9) * (unsigned __int64)v47) >> 32))),
         4 * (v3 - v9) * v47);
  if ( (int)((__PAIR64__(
                2 * v19 * HIDWORD(v19) + (((unsigned int)v19 * (unsigned __int64)(unsigned int)v19) >> 32),
                (int)v19 * (int)v19)
            - __PAIR64__(
                (((v3 - v9) * v47) >> 30) | (unsigned int)(4
                                                         * (((unsigned __int64)(v3 - (__int64)v9) >> 32) * v47
                                                          + (v3 - v9) * HIDWORD(v18)
                                                          + (((unsigned int)(v3 - v9) * (unsigned __int64)v47) >> 32))),
                4 * (v3 - v9) * v47)) >> 32) <= 0
    && a1 < 0 )
  {
LABEL_17:
    v15 = a3;
    *a2 = 0x7FFFFFFF;
LABEL_18:
    *v15 = 0x7FFFFFFF;
    return a1;
  }
  v23 = BgpFmSqrt(a1);
  v20 = v23;
  v21 = -131072 * (v5 - (__int64)v3) + v23;
  v22 = HIDWORD(v23);
  HIDWORD(v23) = (v47 >> 31) | (2 * HIDWORD(v18));
  if ( !(2 * v47) && !HIDWORD(v23) )
    __brkdiv0();
  LODWORD(v23) = 2 * v47;
  LODWORD(v24) = _rt_sdiv64(v23, v21);
  v44 = HIDWORD(v24);
  v39 = v24;
  HIDWORD(v24) = (v47 >> 31) | (2 * HIDWORD(v18));
  if ( !(2 * v47) && !HIDWORD(v24) )
    __brkdiv0();
  LODWORD(v24) = 2 * v47;
  LODWORD(v25) = _rt_sdiv64(v24, -131072 * (v5 - (__int64)v3) - __PAIR64__(v22, v20));
  *a2 = ((v40 * (0x10000 - __PAIR64__(v44, v39)) + 2 * __PAIR64__(v44, v39) * v43) * (0x10000 - __PAIR64__(v44, v39))
       + __PAIR64__(2 * v39 * v44 + ((v39 * (unsigned __int64)v39) >> 32), v39 * v39) * v48
       + (unsigned int)((int)(((v40 * (0x10000 - __PAIR64__(v44, v39)) + 2 * __PAIR64__(v44, v39) * v43)
                             * (0x10000 - __PAIR64__(v44, v39))
                             + __PAIR64__(2 * v39 * v44 + ((v39 * (unsigned __int64)v39) >> 32), v39 * v39) * v48) >> 32) >> 31)) >> 32;
  v26 = ((0x10000 - v25) * v40 + 2 * v43 * v25) * (0x10000 - v25)
      + __PAIR64__(
          2 * v25 * HIDWORD(v25) + (((unsigned int)v25 * (unsigned __int64)(unsigned int)v25) >> 32),
          (int)v25 * (int)v25)
      * v48;
  v15 = a3;
  *a3 = (v26 + (unsigned int)(SHIDWORD(v26) >> 31)) >> 32;
  if ( v44 < 0 || __SPAIR64__(v44, v39) > 0x10000 )
  {
    v27 = a2;
    *a2 = 0x7FFFFFFF;
  }
  else
  {
    v27 = a2;
  }
  if ( v25 < 0 || v25 > 0x10000 )
    *a3 = 0x7FFFFFFF;
  HIDWORD(a1) = *v27;
  LODWORD(a1) = *a3;
  if ( *v27 <= *a3 )
  {
    if ( *v27 != *a3 )
      return a1;
    goto LABEL_18;
  }
  *v27 = a1;
  *a3 = HIDWORD(a1);
  return a1;
}
