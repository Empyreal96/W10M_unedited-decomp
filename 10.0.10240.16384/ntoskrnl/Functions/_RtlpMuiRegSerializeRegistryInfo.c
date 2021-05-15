// _RtlpMuiRegSerializeRegistryInfo 
 
int __fastcall RtlpMuiRegSerializeRegistryInfo(_DWORD *a1, int a2, int *a3)
{
  unsigned int v6; // r1
  int v7; // r0
  _DWORD *v8; // r3
  unsigned int v9; // r5
  unsigned int v10; // r3
  _DWORD *v11; // r3
  unsigned int v12; // r3
  _DWORD *v13; // r3
  unsigned int v14; // r3
  int result; // r0
  int v16; // r2
  int v17; // r2
  int v18; // r2
  unsigned int *v19; // r1
  unsigned int v20; // r9
  int v21; // r8
  unsigned int *v22; // r1
  unsigned int *v23; // r1
  unsigned int *v24; // r1
  unsigned int v25; // r2
  unsigned int v26; // r2
  unsigned int v27; // r2
  int v28; // r1
  int v29; // r1
  int v30; // r1

  if ( !a1 || !a3 )
    return -1073741811;
  v6 = *a3;
  if ( *a3 )
  {
    if ( !a2 )
      return -1073741811;
    v7 = 1;
  }
  else
  {
    if ( a2 )
      return -1073741811;
    v7 = 0;
  }
  v8 = (_DWORD *)a1[5];
  v9 = 104;
  if ( v8 )
  {
    v10 = *v8 + 104;
    if ( v10 < 0x68 )
      return -1073741811;
    v9 = (v10 + 7) & 0xFFFFFFF8;
  }
  v11 = (_DWORD *)a1[6];
  if ( v11 )
  {
    v12 = *v11 + v9;
    if ( v12 < v9 )
      return -1073741811;
    v9 = (v12 + 7) & 0xFFFFFFF8;
  }
  v13 = (_DWORD *)a1[7];
  if ( v13 )
  {
    v14 = *v13 + v9;
    if ( v14 < v9 )
      return -1073741811;
    v9 = (v14 + 7) & 0xFFFFFFF8;
  }
  if ( a1[9] )
    return sub_817E38(v7);
  v16 = a1[22];
  if ( v16 && a1[19] )
  {
    if ( v16 + v9 < v9 )
      return -1073741811;
    v9 = (v16 + v9 + 7) & 0xFFFFFFF8;
  }
  v17 = a1[24];
  if ( v17 && a1[23] )
  {
    if ( v17 + v9 < v9 )
      return -1073741811;
    v9 = (v17 + v9 + 7) & 0xFFFFFFF8;
  }
  v18 = a1[21];
  if ( !v18 || !a1[20] )
    goto LABEL_23;
  if ( v18 + v9 < v9 )
    return -1073741811;
  v9 = (v18 + v9 + 7) & 0xFFFFFFF8;
LABEL_23:
  if ( !v7 )
  {
LABEL_39:
    *a3 = v9;
    return 0;
  }
  if ( v6 >= v9 )
  {
    memset((_BYTE *)a2, 0, *a3);
    memmove(a2, (int)a1, 0x64u);
    v19 = (unsigned int *)a1[5];
    v20 = 104;
    v21 = a2 + 104;
    if ( v19 )
    {
      memmove(a2 + 104, (int)v19, *v19);
      *(_DWORD *)(a2 + 20) = 104;
      v20 = (*(_DWORD *)a1[5] + 111) & 0xFFFFFFF8;
      v21 = v20 + a2;
    }
    v22 = (unsigned int *)a1[6];
    if ( v22 )
    {
      memmove(v21, (int)v22, *v22);
      *(_DWORD *)(a2 + 24) = v21 - a2;
      v20 = (*(_DWORD *)a1[6] + v20 + 7) & 0xFFFFFFF8;
      v21 = v20 + a2;
    }
    v23 = (unsigned int *)a1[7];
    if ( v23 )
    {
      memmove(v21, (int)v23, *v23);
      *(_DWORD *)(a2 + 28) = v21 - a2;
      v20 = (*(_DWORD *)a1[7] + v20 + 7) & 0xFFFFFFF8;
      v21 = v20 + a2;
    }
    v24 = (unsigned int *)a1[9];
    if ( v24 )
    {
      memmove(v21, (int)v24, *v24);
      *(_DWORD *)(a2 + 36) = v21 - a2;
      v20 = (*(_DWORD *)a1[9] + v20 + 7) & 0xFFFFFFF8;
      v21 = v20 + a2;
    }
    v25 = a1[22];
    if ( v25 )
    {
      v29 = a1[19];
      if ( v29 )
      {
        memmove(v21, v29, v25);
        *(_DWORD *)(a2 + 76) = v21 - a2;
        v20 = (a1[22] + v20 + 7) & 0xFFFFFFF8;
        v21 = v20 + a2;
      }
    }
    v26 = a1[24];
    if ( v26 )
    {
      v30 = a1[23];
      if ( v30 )
      {
        memmove(v21, v30, v26);
        *(_DWORD *)(a2 + 92) = v21 - a2;
        v21 = ((a1[24] + v20 + 7) & 0xFFFFFFF8) + a2;
      }
    }
    v27 = a1[21];
    if ( v27 )
    {
      v28 = a1[20];
      if ( v28 )
      {
        memmove(v21, v28, v27);
        *(_DWORD *)(a2 + 80) = v21 - a2;
      }
    }
    *(_DWORD *)(a2 + 32) = 0;
    *(_DWORD *)(a2 + 40) = 0;
    *(_DWORD *)(a2 + 48) = 0;
    *(_DWORD *)(a2 + 52) = 0;
    *(_DWORD *)(a2 + 56) = 0;
    *(_DWORD *)(a2 + 60) = 0;
    *(_DWORD *)a2 = 1024;
    goto LABEL_39;
  }
  result = -1073741789;
  *a3 = v9;
  return result;
}
