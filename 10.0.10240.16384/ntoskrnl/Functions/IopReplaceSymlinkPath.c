// IopReplaceSymlinkPath 
 
int __fastcall IopReplaceSymlinkPath(int a1, unsigned int a2, int a3, unsigned __int16 *a4, unsigned int a5, __int16 a6, __int16 a7)
{
  unsigned int v7; // r7
  unsigned int v9; // r2
  unsigned __int16 v10; // r9
  _WORD *v12; // r4
  unsigned __int16 *v13; // r8
  int result; // r0
  int v15; // r1
  unsigned __int16 *v16; // r4
  __int16 v17; // r6
  unsigned int v18; // r1
  int v19; // r7
  __int16 v20; // r0
  unsigned int v21; // r0
  int v22; // r7
  int v23; // r0
  unsigned int v24; // r1
  unsigned __int16 *v25; // r6
  int v26; // lr
  __int16 v27; // r2
  int v28; // r0
  unsigned __int16 v29; // [sp+0h] [bp-30h] BYREF
  unsigned int v30; // [sp+4h] [bp-2Ch]
  unsigned int v31; // [sp+8h] [bp-28h]
  int v32; // [sp+Ch] [bp-24h]

  v7 = a4[3];
  v9 = a4[5];
  v10 = 0;
  v30 = v7;
  v31 = v9;
  v12 = (_WORD *)(a1 + 2 * a2);
  v13 = (unsigned __int16 *)(a1 + 2 * a5);
  v29 = 0;
  if ( a2 < a5 )
    return -1073741192;
  v32 = (int)a4 + a4[4];
  if ( *(_WORD *)(v32 + 20) != 92 )
  {
    v15 = *(_DWORD *)(a3 + 52);
    v29 = *(_WORD *)(a3 + 48) - v7;
    v10 = v29;
    memmove((int)v12, v15, v29);
    v16 = &v12[v29 >> 1];
    if ( v16 != v13 )
    {
      do
      {
        if ( *v16 == 92 )
          break;
        *v16 = 0;
        v10 -= 2;
        --v16;
        v29 = v10;
      }
      while ( v16 != v13 );
      if ( v16 < v13 )
        return -1073741192;
    }
    v12 = v16 + 1;
LABEL_9:
    v17 = a6;
    goto LABEL_10;
  }
  if ( wcsnicmp(a1, L"\\Device\\Mup", 11) )
    goto LABEL_9;
  v22 = 0;
  if ( **(_WORD **)(a3 + 52) == 59 )
  {
    LOWORD(v23) = 3;
  }
  else
  {
    v22 = 1;
    LOWORD(v23) = 4;
  }
  v24 = 0;
  if ( (*(_WORD *)(a3 + 48) & 0xFFFE) == 0 )
    return -1073741192;
  while ( 1 )
  {
    v25 = (unsigned __int16 *)(*(_DWORD *)(a3 + 52) + 2 * v24);
    v26 = *v25;
    if ( v26 == 92 )
    {
      v23 = (unsigned __int16)(v23 - 1);
      if ( v22 && v23 == 2 )
      {
        if ( (unsigned __int16)(v24 + 1) >= (unsigned int)(*(unsigned __int16 *)(a3 + 48) >> 1) || v25[1] == 59 )
          goto LABEL_36;
        v23 = 0;
      }
      if ( !v23 )
        break;
    }
LABEL_36:
    v24 = (unsigned __int16)(v24 + 1);
    *v12++ = v26;
    if ( v24 >= *(unsigned __int16 *)(a3 + 48) >> 1 )
      return -1073741192;
  }
  v27 = v24;
  if ( v24 < *(unsigned __int16 *)(a3 + 48) >> 1 )
  {
    LOWORD(v28) = *(_WORD *)(*(_DWORD *)(a3 + 52) + 2 * v24);
    do
    {
      v24 = (unsigned __int16)(v27 + 1);
      *v12++ = v28;
      v28 = *(unsigned __int16 *)(*(_DWORD *)(a3 + 52) + 2 * v24);
      if ( v28 == 92 )
        break;
      ++v27;
    }
    while ( v24 < *(unsigned __int16 *)(a3 + 48) >> 1 );
  }
  v7 = v30;
  v13 = (unsigned __int16 *)(a1 + 2 * (a5 + v24));
  v17 = a6 + 2 * v24;
LABEL_10:
  if ( v31 )
  {
    memmove((int)v12, v32 + 20, v31);
    v12 += v31 >> 1;
    v10 += v31;
    v29 = v10;
  }
  if ( v7 )
  {
    v18 = *(unsigned __int16 *)(a3 + 48) - v7;
    v19 = *(_DWORD *)(a3 + 52);
    if ( *(v12 - 1) == 92 && *(_WORD *)(v18 + v19) == 92 )
    {
      *v12 = 0;
      v10 -= 2;
      --v12;
    }
    memmove((int)v12, v18 + v19, v30);
    v12 += v30 >> 1;
    v29 = v10 + v30;
  }
  *v12 = 0;
  v20 = wcslen(v13);
  result = FsRtlRemoveDotsFromPath(v13, (unsigned __int16)(2 * v20), &v29);
  if ( result >= 0 )
  {
    v21 = *(_DWORD *)(a3 + 52);
    *(_WORD *)(a3 + 48) = v29 + v17;
    *(_WORD *)(a3 + 50) = a7;
    if ( a1 != v21 )
    {
      if ( v21 )
        ExFreePoolWithTag(v21);
      *(_DWORD *)(a3 + 52) = a1;
    }
    result = 0;
  }
  return result;
}
