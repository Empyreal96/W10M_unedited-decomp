// FsRtlAddBaseMcbEntryEx 
 
int __fastcall FsRtlAddBaseMcbEntryEx(int a1, unsigned int a2, int a3, int a4, int a5, int a6, int a7)
{
  unsigned int v7; // r6
  int v8; // r8
  int v9; // r10
  int v11; // r7
  unsigned int v12; // r9
  unsigned int v13; // r4
  int v14; // r2
  int v16; // lr
  unsigned int v17; // r3
  unsigned int v18; // r2
  int v19; // r0
  int v20; // r1
  int v21; // r3
  int v22; // r3
  int v23; // r3
  int v24; // r2
  int v25; // r9
  unsigned int v26; // r4
  unsigned int v27; // r0
  unsigned int *v28; // r2
  unsigned int v29; // lr
  int v30; // r3
  int v31; // r0
  int *v32; // r1
  unsigned int v33; // r2
  unsigned int v34; // r3
  int v35; // r3
  int v36; // r2
  int v37; // r3
  unsigned int v38; // r3
  int v39; // r2
  int v40; // r3
  int v41; // r3
  int v42; // r2
  int v43; // r0
  int v44; // r2
  unsigned int v45; // r1
  int v46; // r2
  int v47; // r2
  int v48; // r2
  int v49; // r3
  int v50; // r3
  int v51; // r3
  int v52; // r3
  unsigned int v53; // [sp+0h] [bp-28h] BYREF
  unsigned int v54; // [sp+4h] [bp-24h]
  int v55[8]; // [sp+8h] [bp-20h] BYREF

  v53 = a2;
  v54 = a3;
  v55[0] = a4;
  v7 = a3;
  v8 = a5;
  v9 = a7;
  v11 = -1;
  if ( FsRtlFindLargeIndex(a1, a3, &v53) )
  {
    v25 = *(_DWORD *)(a1 + 12);
    v26 = v53;
    v27 = a7 + v7 - 1;
    v28 = (unsigned int *)(v25 + 8 * v53);
    v29 = v28[1];
    if ( v29 == -1 )
    {
      if ( FsRtlFindLargeIndex(a1, a7 + v7 - 1, v55) && v26 == v55[0] - 1 )
      {
        if ( v55[0] )
          v51 = *(_DWORD *)(v25 + 8 * v55[0] - 8);
        else
          v51 = 0;
        v27 = v25 + 8 * v55[0];
        if ( *(_DWORD *)(v27 + 4) != v51 - v7 + a5 )
          return sub_520348(v27);
        if ( v55[0] )
          v52 = *(_DWORD *)(v27 - 8);
        else
          v52 = 0;
        v9 = v52 - v7;
      }
    }
    else
    {
      if ( v53 )
        v30 = *(v28 - 2);
      else
        v30 = 0;
      if ( a5 != v29 - v30 + v7 )
        return sub_520348(v27);
      if ( v27 <= *v28 - 1 )
        return 0;
      if ( v53 >= *(_DWORD *)(a1 + 4) || v53 == -1 )
        v7 = 0;
      else
        v7 = *v28;
      if ( v53 )
        v50 = *(v28 - 2);
      else
        v50 = 0;
      v8 = *v28 - v50 + v29;
      v9 = v27 - v7 + 1;
    }
  }
  v12 = *(_DWORD *)(a1 + 4);
  v13 = v12;
  v53 = v12;
  if ( !v12 )
    goto LABEL_3;
  v16 = *(_DWORD *)(a1 + 12);
  v17 = *(_DWORD *)(v16 + 8 * v12 - 8);
  v55[0] = v16;
  if ( v17 <= v7 || (v31 = FsRtlFindLargeIndex(a1, v7, &v53), v16 = v55[0], v13 = v53, !v31) )
  {
    if ( v13 )
    {
      v18 = v16 + 8 * v13;
      v19 = *(_DWORD *)(v18 - 8);
      if ( v19 == v7 )
      {
        v20 = *(_DWORD *)(v18 - 4);
        if ( v20 == -1 )
        {
          v22 = -1;
        }
        else
        {
          v21 = v13 == 1 ? 0 : *(_DWORD *)(v18 - 16);
          v22 = v20 - v21 + v19 - 1;
        }
        if ( v22 + 1 == v8 )
        {
          *(_DWORD *)(v16 + 8 * v12 - 8) += v9;
          return 0;
        }
      }
    }
LABEL_3:
    if ( v7 )
    {
      v23 = v13 ? *(_DWORD *)(*(_DWORD *)(a1 + 12) + 8 * v13 - 8) - 1 : -1;
      if ( v23 + 1 != v7 )
      {
        if ( FsRtlAddEntry(a1, v13, 2) )
        {
          v24 = v9 + v7;
LABEL_22:
          *(_DWORD *)(*(_DWORD *)(a1 + 12) + 8 * v13 + 4) = -1;
          *(_DWORD *)(*(_DWORD *)(a1 + 12) + 8 * v13) = v7;
          *(_DWORD *)(*(_DWORD *)(a1 + 12) + 8 * v13 + 12) = v8;
          *(_DWORD *)(*(_DWORD *)(a1 + 12) + 8 * v13 + 8) = v24;
          return 0;
        }
        return -1073741670;
      }
    }
    if ( FsRtlAddEntry(a1, v13, 1) )
    {
      v14 = v9 + v7;
LABEL_6:
      *(_DWORD *)(*(_DWORD *)(a1 + 12) + 8 * v13 + 4) = v8;
      *(_DWORD *)(*(_DWORD *)(a1 + 12) + 8 * v13) = v14;
      return 0;
    }
    return -1073741670;
  }
  v32 = (int *)(v55[0] + 8 * v53);
  v54 = v9 + v7;
  v27 = v9 + v7 - 1;
  if ( v32[1] != -1 || v53 && *(v32 - 2) > v7 )
    return sub_520348(v27);
  v33 = *v32 - 1;
  v55[0] = *v32;
  if ( v27 > v33 )
    return sub_520348(v27);
  if ( v53 )
    v34 = *(v32 - 2);
  else
    v34 = 0;
  if ( v34 < v7 && v27 < v33 )
  {
    if ( FsRtlAddEntry(a1, v53, 2) )
    {
      v24 = v54;
      goto LABEL_22;
    }
    return -1073741670;
  }
  if ( v53 )
    v35 = *(v32 - 2);
  else
    v35 = 0;
  if ( v27 >= v33 || v35 != v7 )
  {
    if ( v53 )
      v38 = *(v32 - 2);
    else
      v38 = 0;
    if ( v38 >= v7 || v27 != v33 )
    {
      if ( !v53 || (v39 = *(v32 - 1), v39 == -1) )
      {
        v41 = -1;
      }
      else
      {
        if ( v53 == 1 )
          v40 = 0;
        else
          v40 = *(v32 - 4);
        v41 = *(v32 - 2) + v39 - v40 - 1;
      }
      if ( v41 + 1 == v8 && (v53 >= v12 - 1 ? (v42 = -1) : (v42 = v32[3]), v42 == v9 + v8) )
      {
        v43 = a1;
        if ( v53 )
        {
          v44 = 2;
          *(v32 - 2) = v32[2];
          v45 = v13;
        }
        else
        {
          v44 = 1;
          v45 = 0;
          *(_DWORD *)(v16 + 12) = v8;
        }
      }
      else
      {
        if ( v53 >= v12 - 1 )
          v47 = -1;
        else
          v47 = v32[3];
        if ( v47 == v9 + v8 )
        {
          v32[3] = v8;
        }
        else
        {
          if ( !v53 )
            goto LABEL_94;
          v48 = *(v32 - 1);
          if ( v48 != -1 )
          {
            if ( v53 == 1 )
              v49 = 0;
            else
              v49 = *(v32 - 4);
            v11 = *(v32 - 2) + v48 - v49 - 1;
          }
          if ( v11 + 1 != v8 )
          {
LABEL_94:
            v32[1] = v8;
            return 0;
          }
          *(v32 - 2) = v55[0];
        }
        v44 = 1;
        v45 = v13;
        v43 = a1;
      }
      FsRtlRemoveLargeEntry(v43, v45, v44);
      return 0;
    }
    if ( v53 >= v12 - 1 )
      v46 = -1;
    else
      v46 = v32[3];
    if ( v46 == v9 + v8 )
    {
      *v32 = v7;
    }
    else
    {
      if ( !FsRtlAddEntry(a1, v53, 1) )
        return -1073741670;
      *(_DWORD *)(*(_DWORD *)(a1 + 12) + 8 * v13 + 4) = -1;
      *(_DWORD *)(*(_DWORD *)(a1 + 12) + 8 * v13) = v7;
    }
    *(_DWORD *)(*(_DWORD *)(a1 + 12) + 8 * v13 + 12) = v8;
    return 0;
  }
  if ( v53 )
  {
    v36 = *(v32 - 1);
    if ( v36 != -1 )
    {
      if ( v53 == 1 )
        v37 = 0;
      else
        v37 = *(v32 - 4);
      v11 = *(v32 - 2) + v36 - v37 - 1;
    }
  }
  if ( v11 + 1 == v8 )
  {
    if ( v53 )
    {
      *(v32 - 2) += v9;
      return 0;
    }
    if ( FsRtlAddEntry(a1, 0, 1) )
    {
      *(_DWORD *)(*(_DWORD *)(a1 + 12) + 4) = v8;
      **(_DWORD **)(a1 + 12) = v9;
      return 0;
    }
  }
  else if ( FsRtlAddEntry(a1, v53, 1) )
  {
    v14 = v54;
    goto LABEL_6;
  }
  return -1073741670;
}
