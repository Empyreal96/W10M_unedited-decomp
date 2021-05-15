// PfSnPrefetchCacheEntryGet 
 
int __fastcall PfSnPrefetchCacheEntryGet(_DWORD *a1, unsigned int a2, unsigned int a3, int *a4)
{
  unsigned int v5; // r5
  int v6; // r6
  int v8; // r9
  int v9; // r10
  unsigned int v10; // r1
  int v11; // r0
  int v12; // lr
  int v13; // r3
  int v14; // r2
  unsigned int v15; // r4
  int v16; // r0
  bool v17; // zf
  _DWORD *v18; // r2
  __int64 v19; // r0
  _DWORD *v20; // r1
  _DWORD *v21; // r0
  int v22; // r4
  _DWORD *v24; // r1
  __int64 *v25; // r2
  __int64 v26; // kr00_8
  __int64 v27; // kr08_8
  _DWORD *i; // r2
  unsigned int v29; // r3
  unsigned int v30; // r1
  int v31; // r2
  int v32; // [sp+0h] [bp-28h]
  int v33; // [sp+0h] [bp-28h]

  v5 = a1[1];
  v6 = 0;
  v8 = -1 << (v5 & 0x1F);
  v9 = v8 & a3;
  v32 = v8 & a3;
  v10 = (v8 & a3) >> 24;
  v11 = (unsigned __int8)((v8 & a3) >> 16);
  v12 = (unsigned __int8)((unsigned __int16)(v8 & a3) >> 8);
  v13 = (unsigned __int8)(v8 & a3);
  v14 = 11623883;
  v15 = v5 >> 5;
  while ( 1 )
  {
    if ( v6 )
      goto LABEL_5;
    if ( !v15 )
      break;
    v14 = (37 * (37 * (37 * (v13 + 11623883) + v12) + v11) + v10) & (v15 - 1);
    v6 = a1[2] + 4 * v14;
LABEL_5:
    while ( 1 )
    {
      v6 = *(_DWORD *)v6;
      if ( (v6 & 1) != 0 )
        break;
      if ( v9 == (*(_DWORD *)(v6 + 4) & v8) )
        goto LABEL_7;
    }
    v6 = 0;
LABEL_7:
    if ( !v6 )
      break;
    v16 = memcmp(v6 + 16, a2, 64);
    v10 = HIBYTE(v32);
    v12 = BYTE1(v32);
    v13 = (unsigned __int8)v32;
    v14 = 11623883;
    v17 = v16 == 0;
    v11 = BYTE2(v32);
    if ( v17 )
    {
      v18 = (_DWORD *)(v6 + 8);
      v19 = *(_QWORD *)(v6 + 8);
      if ( *(_DWORD *)(v19 + 4) != v6 + 8 || *(_DWORD **)HIDWORD(v19) != v18 )
        __fastfail(3u);
      *(_DWORD *)HIDWORD(v19) = v19;
      *(_DWORD *)(v19 + 4) = HIDWORD(v19);
      v20 = a1 + 3;
      v21 = (_DWORD *)a1[4];
      *v18 = a1 + 3;
      *(_DWORD *)(v6 + 12) = v21;
      if ( (_DWORD *)*v21 != a1 + 3 )
        sub_7D685C();
      v22 = 0;
LABEL_15:
      *v21 = v18;
      v20[1] = v18;
      goto LABEL_16;
    }
  }
  if ( !a4 )
    return 0;
  v22 = 1;
  if ( a1[2] || PfSnPrefetchCacheCtxStart(a1, v10, v14) >= 0 )
  {
    v6 = a1[5];
    if ( v6 )
    {
      a1[5] = *(_DWORD *)v6;
    }
    else
    {
      v24 = a1 + 3;
      v25 = (__int64 *)a1[3];
      v26 = *v25;
      if ( *((_DWORD **)v25 + 1) != a1 + 3 || *(__int64 **)(v26 + 4) != v25 )
        __fastfail(3u);
      *v24 = v26;
      *(_DWORD *)(v26 + 4) = v24;
      v27 = *(_QWORD *)(a1 + 1);
      v6 = (int)(v25 - 1);
      v33 = *((_DWORD *)v25 - 1) & (-1 << (v27 & 0x1F));
      for ( i = (_DWORD *)(HIDWORD(v27)
                         + 4
                         * ((37 * (37 * (37 * ((unsigned __int8)v33 + 11623883) + BYTE1(v33)) + BYTE2(v33)) + HIBYTE(v33)) & (((unsigned int)v27 >> 5) - 1)));
            (*i & 1) == 0;
            i = (_DWORD *)*i )
      {
        if ( *i == v6 )
        {
          *i = *(_DWORD *)v6;
          --*a1;
          *(_DWORD *)v6 |= 0x80000002;
          break;
        }
      }
    }
    memset((_BYTE *)v6, 0, 104);
    memmove(v6 + 16, a2, 0x40u);
    *(_DWORD *)(v6 + 4) = a3;
    v29 = a1[1];
    v30 = ((v29 >> 5) - 1) & (37
                            * (37
                             * (37 * ((unsigned __int8)((-1 << (v29 & 0x1F)) & a3) + 11623883)
                              + (unsigned __int8)((unsigned __int16)((-1 << (v29 & 0x1F)) & a3) >> 8))
                             + (unsigned __int8)(((-1 << (v29 & 0x1F)) & a3) >> 16))
                            + (((-1 << (v29 & 0x1F)) & a3) >> 24));
    v31 = a1[2];
    *(_DWORD *)v6 = *(_DWORD *)(v31 + 4 * v30);
    *(_DWORD *)(v31 + 4 * v30) = v6;
    v20 = a1 + 3;
    v18 = (_DWORD *)(v6 + 8);
    ++*a1;
    v21 = (_DWORD *)a1[4];
    *(_DWORD *)(v6 + 8) = a1 + 3;
    *(_DWORD *)(v6 + 12) = v21;
    if ( (_DWORD *)*v21 != a1 + 3 )
      __fastfail(3u);
    goto LABEL_15;
  }
  v6 = 0;
LABEL_16:
  if ( a4 )
    *a4 = v22;
  return v6;
}
