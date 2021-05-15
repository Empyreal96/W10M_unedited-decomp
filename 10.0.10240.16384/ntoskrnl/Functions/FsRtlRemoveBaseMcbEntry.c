// FsRtlRemoveBaseMcbEntry 
 
int __fastcall FsRtlRemoveBaseMcbEntry(int a1, __int64 a2, __int64 a3)
{
  unsigned int v4; // r7
  int v5; // r10
  unsigned int v6; // r8
  unsigned int v7; // r9
  int v9; // r0
  int v11; // r4
  int v12; // r3
  _DWORD *v13; // r1
  int v14; // r3
  unsigned int v15; // r3
  unsigned int v16; // r0
  int v17; // r2
  int v18; // r2
  int v19; // r2
  int v20; // r1
  int v21; // r2
  int v22; // r2
  int v23; // r3
  unsigned int v24; // kr18_4
  _DWORD *v25; // r2
  unsigned int v26; // r6
  unsigned int v27; // r3
  int v28; // r1
  int v29; // r2
  int v30; // r3
  int v31; // r3
  int v32; // r0
  int v33; // r2
  int v34; // r3
  int v35; // r3
  unsigned int v36; // [sp+0h] [bp-28h]
  __int64 v37[4]; // [sp+4h] [bp-24h] BYREF

  v37[0] = a2;
  v36 = HIDWORD(a2);
  v5 = HIDWORD(a3);
  v4 = a3;
  v6 = HIDWORD(a2);
  v7 = a2;
  if ( a2 || (v9 = *(_DWORD *)(a1 + 4)) == 0 )
  {
LABEL_7:
    if ( a3 <= 0 )
      return 1;
    while ( 1 )
    {
      if ( !FsRtlFindLargeIndex(a1, v7, v37) )
        return 1;
      v11 = v37[0];
      if ( LODWORD(v37[0]) )
        v12 = *(_DWORD *)(*(_DWORD *)(a1 + 12) + 8 * LODWORD(v37[0]) - 8);
      else
        v12 = 0;
      if ( v12 != v7
        || v6
        || (v13 = (_DWORD *)(*(_DWORD *)(a1 + 12) + 8 * LODWORD(v37[0])),
            (unsigned int)(*v13 - 1) >= (__int64)(v7 + __PAIR64__(v5, v4))) )
      {
        if ( LODWORD(v37[0]) )
          v23 = *(_DWORD *)(*(_DWORD *)(a1 + 12) + 8 * LODWORD(v37[0]) - 8);
        else
          v23 = 0;
        if ( v23 == v7 && !v6 )
        {
          v28 = *(_DWORD *)(a1 + 12) + 8 * LODWORD(v37[0]);
          if ( *(_DWORD *)(v28 + 4) == -1 )
            return 1;
          if ( LODWORD(v37[0]) )
          {
            v29 = *(_DWORD *)(v28 - 4);
            if ( v29 == -1
              || (LODWORD(v37[0]) == 1 ? (v30 = 0) : (v30 = *(_DWORD *)(v28 - 16)), !(*(_DWORD *)(v28 - 8) + v29 - v30)) )
            {
              *(_DWORD *)(v28 - 8) += v4;
              *(_DWORD *)(*(_DWORD *)(a1 + 12) + 8 * v11 + 4) += v4;
              return 1;
            }
          }
          if ( FsRtlAddEntry(a1, v37[0], 1) )
          {
            *(_DWORD *)(*(_DWORD *)(a1 + 12) + 8 * v11 + 4) = -1;
            *(_DWORD *)(*(_DWORD *)(a1 + 12) + 8 * v11) = v7 + v4;
            *(_DWORD *)(*(_DWORD *)(a1 + 12) + 8 * v11 + 12) += v4;
            return 1;
          }
          return 0;
        }
        v24 = v7 + v4;
        v6 = (__PAIR64__(v6, v7) + __PAIR64__(v5, v4)) >> 32;
        v25 = (_DWORD *)(*(_DWORD *)(a1 + 12) + 8 * LODWORD(v37[0]));
        if ( (unsigned int)(*v25 - 1) >= __SPAIR64__(v6, v7 + v4) )
        {
          if ( v25[1] != -1 )
          {
            if ( !FsRtlAddEntry(a1, v37[0], 2) )
              return 0;
            *(_DWORD *)(*(_DWORD *)(a1 + 12) + 8 * v11 + 4) = *(_DWORD *)(*(_DWORD *)(a1 + 12) + 8 * v11 + 20);
            *(_DWORD *)(*(_DWORD *)(a1 + 12) + 8 * v11) = v7;
            *(_DWORD *)(*(_DWORD *)(a1 + 12) + 8 * v11 + 12) = -1;
            *(_DWORD *)(*(_DWORD *)(a1 + 12) + 8 * v11 + 8) = v4 + v7;
            if ( v11 )
              v32 = *(_DWORD *)(*(_DWORD *)(a1 + 12) + 8 * v11 - 8);
            else
              v32 = 0;
            if ( v11 == -1 )
              v33 = 0;
            else
              v33 = *(_DWORD *)(*(_DWORD *)(a1 + 12) + 8 * v11);
            *(_DWORD *)(*(_DWORD *)(a1 + 12) + 8 * v11 + 20) = *(_DWORD *)(*(_DWORD *)(a1 + 12) + 8 * v11)
                                                             + *(_DWORD *)(*(_DWORD *)(a1 + 12) + 8 * v11 + 20)
                                                             - v33
                                                             - v32
                                                             + *(_DWORD *)(*(_DWORD *)(a1 + 12) + 8 * v11 + 8);
          }
          v4 = 0;
          v5 = 0;
          v7 = v24;
        }
        else
        {
          v26 = *v25 - v7;
          if ( v25[1] != -1 )
          {
            v27 = *(_DWORD *)(a1 + 4) - 1;
            if ( LODWORD(v37[0]) == v27 || LODWORD(v37[0]) >= v27 || v25[3] == -1 )
            {
              *v25 = v7;
            }
            else
            {
              if ( !FsRtlAddEntry(a1, LODWORD(v37[0]) + 1, 1) )
                return 0;
              *(_DWORD *)(*(_DWORD *)(a1 + 12) + 8 * v11 + 12) = -1;
              *(_DWORD *)(*(_DWORD *)(a1 + 12) + 8 * v11 + 8) = *(_DWORD *)(*(_DWORD *)(a1 + 12) + 8 * v11);
              *(_DWORD *)(*(_DWORD *)(a1 + 12) + 8 * v11) -= v26;
            }
          }
          v6 = (__PAIR64__(v36, v7) + v26) >> 32;
          v7 += v26;
          v5 = (__PAIR64__(v5, v4) - v26) >> 32;
          v4 -= v26;
        }
        v36 = v6;
      }
      else
      {
        if ( LODWORD(v37[0]) )
          v14 = *(v13 - 2);
        else
          v14 = 0;
        v15 = *v13 - v14;
        v6 = (v7 + (unsigned __int64)v15) >> 32;
        v7 += v15;
        v5 = (__PAIR64__(v5, v4) - v15) >> 32;
        v4 -= v15;
        v36 = v6;
        if ( v13[1] == -1 )
          goto LABEL_29;
        v16 = *(_DWORD *)(a1 + 4) - 1;
        if ( LODWORD(v37[0]) == v16 )
        {
          if ( LODWORD(v37[0]) )
          {
            v22 = *(v13 - 1);
            if ( v22 == -1 )
              goto LABEL_27;
            v31 = LODWORD(v37[0]) == 1 ? 0 : *(v13 - 4);
            if ( !(*(v13 - 2) + v22 - v31) )
              goto LABEL_27;
          }
          goto LABEL_64;
        }
        if ( LODWORD(v37[0]) )
        {
          v17 = *(v13 - 1);
          if ( v17 == -1 )
            goto LABEL_20;
          if ( LODWORD(v37[0]) == 1 )
            return sub_5202E0();
          if ( !(*(v13 - 2) + v17 - *(v13 - 4)) )
            goto LABEL_20;
        }
        if ( LODWORD(v37[0]) >= v16 || v13[3] == -1 )
        {
          if ( !LODWORD(v37[0]) )
            goto LABEL_87;
LABEL_20:
          v18 = *(v13 - 1);
          if ( v18 == -1 || (LODWORD(v37[0]) != 1 ? (v34 = *(v13 - 4)) : (v34 = 0), !(*(v13 - 2) + v18 - v34)) )
          {
LABEL_21:
            v19 = *(v13 - 1);
            if ( v19 == -1 )
              goto LABEL_22;
            v35 = LODWORD(v37[0]) == 1 ? 0 : *(v13 - 4);
            if ( !(*(v13 - 2) + v19 - v35) )
              goto LABEL_22;
            goto LABEL_27;
          }
LABEL_87:
          if ( LODWORD(v37[0]) < v16 && v13[3] != -1 )
          {
            if ( LODWORD(v37[0]) )
              goto LABEL_21;
LABEL_22:
            if ( LODWORD(v37[0]) < v16 && v13[3] != -1 )
            {
              v13[1] = -1;
              v20 = v11 - 1;
              v21 = 1;
LABEL_28:
              FsRtlRemoveLargeEntry(a1, v20, v21);
              goto LABEL_29;
            }
LABEL_27:
            v20 = LODWORD(v37[0]) - 1;
            v21 = 2;
            goto LABEL_28;
          }
LABEL_64:
          v21 = 1;
          v20 = v37[0];
          goto LABEL_28;
        }
        v13[1] = -1;
      }
LABEL_29:
      if ( v5 < 0 || v5 <= 0 && !v4 )
        return 1;
    }
  }
  if ( a3 >= 0 )
  {
    if ( a3 >= *(unsigned int *)(*(_DWORD *)(a1 + 12) + 8 * v9 - 8) )
    {
      *(_DWORD *)(a1 + 4) = 0;
      return 1;
    }
    goto LABEL_7;
  }
  return 1;
}
