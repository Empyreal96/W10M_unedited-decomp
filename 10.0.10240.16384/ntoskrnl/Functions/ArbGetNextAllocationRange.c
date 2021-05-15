// ArbGetNextAllocationRange 
 
int __fastcall ArbGetNextAllocationRange(int a1, int a2)
{
  int v2; // r4
  unsigned int v5; // r1
  int v6; // r1
  __int64 *v7; // r7
  unsigned int v8; // r0
  __int64 *i; // r1
  int v10; // r2
  __int64 v11; // r8
  unsigned int v12; // r2
  __int64 v13; // r0
  unsigned int v14; // r4
  unsigned int v15; // r10
  __int64 v16; // kr28_8
  unsigned __int64 v17; // r4
  __int64 v18; // r0
  __int64 v19; // r2
  __int64 v20; // r2
  int v21; // r2
  int v22; // r3
  unsigned __int64 v23; // kr48_8
  unsigned __int64 v24; // kr50_8
  unsigned int v25; // [sp+0h] [bp-38h]
  __int64 v26; // [sp+4h] [bp-34h]
  unsigned int v28; // [sp+10h] [bp-28h]
  unsigned int v29; // [sp+14h] [bp-24h]

  v2 = a1;
  while ( 1 )
  {
    if ( *(_DWORD *)(a2 + 36) )
      return sub_80E4EC();
    v5 = *(_DWORD *)(a2 + 44);
    if ( v5 < v5 + 56 * *(_DWORD *)(a2 + 40) )
    {
      do
      {
        *(_DWORD *)(v5 + 32) = 0;
        ArbpUpdatePriority(v2);
        v5 = v6 + 56;
      }
      while ( v5 < *(_DWORD *)(a2 + 44) + 56 * *(_DWORD *)(a2 + 40) );
    }
    v7 = *(__int64 **)(a2 + 44);
    v8 = (unsigned int)&v7[7 * *(_DWORD *)(a2 + 40)];
    for ( i = v7 + 7; (unsigned int)i < v8; i += 7 )
    {
      if ( *((_DWORD *)i + 8) < *((_DWORD *)v7 + 8) )
        v7 = i;
    }
    v10 = *((_DWORD *)v7 + 8);
    if ( v10 == 0x7FFFFFFF )
      return 0;
    if ( v10 == 2147483646 || v10 == 2147483645 )
    {
      v11 = *v7;
      HIDWORD(v13) = *((_DWORD *)v7 + 3);
      v12 = *((_DWORD *)v7 + 2);
      v14 = *((_DWORD *)v7 + 1);
      LODWORD(v13) = *(_DWORD *)v7;
    }
    else
    {
      if ( v10 > 0 )
        v21 = v10 - 1;
      else
        v21 = -1 - v10;
      v11 = *v7;
      v22 = *(_DWORD *)(v2 + 32) + 16 * v21;
      v14 = *(_DWORD *)(v22 + 4);
      LODWORD(v13) = *(_DWORD *)v22;
      if ( (unsigned __int64)*v7 > *(_QWORD *)v22 )
      {
        v14 = *((_DWORD *)v7 + 1);
        LODWORD(v13) = *(_DWORD *)v7;
      }
      v23 = v7[1];
      HIDWORD(v13) = HIDWORD(v23);
      v12 = v23;
      v24 = *(_QWORD *)(v22 + 8);
      v15 = v24;
      v25 = *(_DWORD *)(v22 + 12);
      if ( v23 >= v24 )
        goto LABEL_13;
    }
    v25 = HIDWORD(v13);
    v15 = v12;
LABEL_13:
    v26 = v7[2];
    if ( v26 )
    {
      v16 = v7[3];
      HIDWORD(v13) = HIDWORD(v16);
      v17 = __PAIR64__(v14, v16) + v13 - 1;
      LODWORD(v13) = *((_DWORD *)v7 + 6);
      v28 = *((_DWORD *)v7 + 7);
      v29 = v13;
      if ( !v13 )
        __brkdiv0();
      _rt_udiv64(v18, v17);
      v11 = v17 - v19;
      if ( __PAIR64__(HIDWORD(v26) + (unsigned int)((_DWORD)v26 != 0) - 1, (int)v26 - 1) <= __PAIR64__(v25, v15)
                                                                                          - (v17
                                                                                           - v19) )
      {
        if ( !v29 && !v28 )
          __brkdiv0();
        _rt_udiv64(__SPAIR64__(v28, v29), __PAIR64__(v25, v15) - v26 + 1);
        HIDWORD(v13) = (__PAIR64__(v25, v15) - v20) >> 32;
        v12 = v15 - v20;
        goto LABEL_21;
      }
      v2 = a1;
      *(_DWORD *)(a2 + 36) = v7;
    }
    else
    {
LABEL_21:
      if ( v11 != *(_QWORD *)(a2 + 16)
        || __PAIR64__(HIDWORD(v13), v12) != *(_QWORD *)(a2 + 24)
        || (v2 = a1, *(__int64 **)(a2 + 36) != v7) )
      {
        *(_QWORD *)(a2 + 16) = v11;
        *(_DWORD *)(a2 + 24) = v12;
        *(_DWORD *)(a2 + 28) = HIDWORD(v13);
        *(_DWORD *)(a2 + 36) = v7;
        return 1;
      }
    }
  }
}
