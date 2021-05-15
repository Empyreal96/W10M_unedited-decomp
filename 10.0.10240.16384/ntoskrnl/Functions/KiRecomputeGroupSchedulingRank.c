// KiRecomputeGroupSchedulingRank 
 
int __fastcall KiRecomputeGroupSchedulingRank(int a1, unsigned int *a2, int a3)
{
  int result; // r0
  unsigned int v6; // r4
  unsigned int v7; // r8
  unsigned int v8; // r2
  unsigned int v9; // r1
  unsigned int v10; // r4
  int v11; // r9
  unsigned int v12; // r10
  unsigned __int64 v13; // kr00_8
  unsigned int v14; // r1
  unsigned int v15; // r2
  unsigned int v16; // r3
  unsigned int v17; // r1
  int v18; // r3
  unsigned int v19; // r2
  unsigned int v20; // r1
  unsigned int v21; // r3
  unsigned int *v22; // r4
  unsigned int v23; // r3
  unsigned int v24; // r0
  __int64 v25; // r0
  _DWORD *i; // r3
  int v27; // [sp+0h] [bp-28h]

  if ( *(__int64 *)(a1 + 32) > 0 )
    return sub_52264C(a1, *(_DWORD *)(a1 + 32));
  v6 = *(_DWORD *)(a1 + 8);
  v7 = a2[1];
  v27 = a2[24] + 1;
  a2[24] = v27;
  result = KiCycleDivisorShortTerm;
  v8 = v6 * KiCycleDivisorShortTerm;
  v9 = (*(_QWORD *)&KiCycleDivisorShortTerm * (unsigned __int64)v6) >> 32;
  v10 = *a2;
  v11 = (v9 << 25) | (v8 >> 7);
  v12 = v9 >> 7;
  v13 = *((_QWORD *)a2 + 3) + __PAIR64__(v9 >> 7, v11);
  *((_QWORD *)a2 + 3) = v13;
  if ( __PAIR64__(v7, v10) > v13 )
  {
    LODWORD(v25) = -1;
    if ( !v11 && !v12 )
      __brkdiv0();
    HIDWORD(v25) = (__PAIR64__(v7, v10) - v13 + __PAIR64__(v12, v11)) >> 32;
    result = _rt_udiv64(__SPAIR64__(v12, v11), ((v10 - (unsigned int)v13 + v11) | 0xFFFFFFFF00000000ui64) + v25);
    a2[24] = v27 + result;
    *((_QWORD *)a2 + 3) = __PAIR64__(v12, v11) * (unsigned int)result + v13;
  }
  if ( (a2[23] & 1) != 0 )
  {
    v14 = (unsigned int)(a2 + 20);
    v15 = a2[21];
    if ( v15 )
    {
      for ( i = *(_DWORD **)v15; i; i = (_DWORD *)*i )
        v15 = (unsigned int)i;
    }
    else
    {
      v16 = a2[22];
      while ( 1 )
      {
        v15 = v16 & 0xFFFFFFFC;
        if ( (v16 & 0xFFFFFFFC) == 0 || *(_DWORD *)v15 == v14 )
          break;
        v16 = *(_DWORD *)(v15 + 8);
        v14 = v15;
      }
    }
    if ( v15 )
    {
      v17 = a2[24];
      v18 = v17 - *(_DWORD *)(v15 + 16);
      if ( !v18 )
      {
        if ( *((_WORD *)a2 + 47) )
        {
          v19 = *(unsigned __int16 *)(v15 + 14);
          v20 = 31 - __clz(*((unsigned __int16 *)a2 + 47));
          v21 = 0;
          if ( v19 )
            v21 = 31 - __clz(v19);
          v18 = v21 - v20;
        }
        else
        {
          if ( !v17 )
          {
            if ( __PAIR64__(v7, v10) <= *(_QWORD *)(v15 - 80) )
              return result;
            goto LABEL_17;
          }
          v18 = 1;
        }
      }
      if ( v18 <= 0 )
        return result;
LABEL_17:
      v22 = a2;
      do
      {
        v23 = v22[59];
        if ( v23 )
          v24 = v23 + 228;
        else
          v24 = a3 + 1976;
        *((_BYTE *)v22 + 92) &= 0xFEu;
        RtlRbRemoveNode(v24, v22 + 20);
        v22 = (unsigned int *)v22[59];
      }
      while ( v22 && (v22[23] & 1) != 0 && !v22[57] && !*((_WORD *)v22 + 47) );
      return KiInsertSchedulingGroupQueue(a3, a2, 0);
    }
  }
  return result;
}
