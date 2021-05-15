// MiPickClusterForMappedFileFault 
 
int __fastcall MiPickClusterForMappedFileFault(int a1, int a2, int a3, _DWORD *a4, int a5, int a6, _DWORD *a7, unsigned int *a8)
{
  int *v9; // r0
  unsigned int v10; // r5
  int v11; // r6
  int v12; // r9
  int v14; // r7
  int v15; // r4
  unsigned int v16; // lr
  int v17; // r1
  int result; // r0
  unsigned int v19; // r4
  int v20; // r3
  unsigned int v21; // r2
  int v22; // lr
  int v23; // r0
  _DWORD *v24; // r2
  _DWORD *v25; // r1
  _DWORD *i; // r8
  int v27; // r2
  unsigned int v28; // r2
  int v29; // [sp+0h] [bp-38h]
  unsigned int v32; // [sp+Ch] [bp-2Ch]

  v9 = *(int **)(a2 + 120);
  v10 = *(_DWORD *)(a2 + 132);
  v11 = *(_DWORD *)(a2 + 96);
  v12 = *v9;
  v29 = *(_DWORD *)(a2 + 104);
  v14 = 1;
  v15 = __mrc(15, 0, 13, 0, 3);
  v16 = v15 & 0xFFFFFFC0;
  if ( (v11 & 0x400) == 0 )
    goto LABEL_49;
  if ( *(_BYTE *)((v15 & 0xFFFFFFC0) + 0x3CD) )
    goto LABEL_49;
  v17 = *(_DWORD *)(v12 + 28);
  if ( (v17 & 8) != 0 && *(_BYTE *)((v15 & 0xFFFFFFC0) + 0x3CC) != 2 )
    goto LABEL_49;
  if ( *(int *)(a1 + 3840) < 128 )
    goto LABEL_49;
  if ( dword_6348DC )
    return sub_544FD4();
  if ( *(_DWORD *)(a1 + 3712) <= 0x100u )
  {
LABEL_49:
    i = (_DWORD *)v10;
    v19 = v10;
  }
  else
  {
    v19 = (unsigned int)&a4[v9[7] - 1];
    if ( a3 )
    {
      v20 = v29;
    }
    else if ( (v17 & 0x20) != 0 )
    {
      v29 = 4;
      if ( (v9[4] & 4) != 0 )
      {
        v20 = 8;
        v29 = 8;
      }
      else
      {
        v20 = 4;
      }
    }
    else
    {
      v20 = v29;
      if ( !v29 )
      {
        v20 = *(_DWORD *)(v16 + 948) + 1;
        v29 = v20;
      }
    }
    v21 = v10 + 4 * v20;
    v22 = a3;
    if ( v19 > v21 - 4 )
      v19 = v21 - 4;
    if ( !a3 && (v17 & 0x20000000) != 0 )
    {
      v32 = MiStartingOffset(v9, v10);
      v23 = dword_6348E4;
      v28 = v10 + 4 * ((dword_6348E4 - ((dword_6348E4 - 1) & v32)) >> 12);
      v22 = 0;
      if ( v19 > v28 - 4 )
        v19 = v28 - 4;
    }
    else
    {
      v32 = 0;
      v23 = dword_6348E4;
    }
    if ( v19 > (v10 & 0xFFFFF000 | 0xFFC) )
      v19 = v10 & 0xFFFFF000 | 0xFFC;
    v24 = (_DWORD *)v19;
    if ( v19 > v10 )
    {
      do
      {
        if ( *v24 == v11 )
        {
          ++v14;
        }
        else if ( v24 == (_DWORD *)v19 )
        {
          v19 -= 4;
        }
        --v24;
      }
      while ( (unsigned int)v24 > v10 );
    }
    v25 = (_DWORD *)(v19 - 4 * v29 + 4);
    if ( v25 < a4 )
      v25 = a4;
    if ( (unsigned int)v25 < (v10 & 0xFFFFF000) )
      v25 = (_DWORD *)(v10 & 0xFFFFF000);
    if ( v22 || (*(_BYTE *)(a2 + 113) & 0x20) != 0 )
    {
      v25 = (_DWORD *)v10;
    }
    else if ( (*(_DWORD *)(v12 + 28) & 0x20000000) != 0
           && (unsigned int)v25 < v10 - 4 * ((v32 >> 12) & ((unsigned int)(v23 - 1) >> 12)) )
    {
      v25 = (_DWORD *)(v10 - 4 * ((v32 >> 12) & ((unsigned int)(v23 - 1) >> 12)));
    }
    for ( i = v25; (unsigned int)v25 < v10; ++v25 )
    {
      if ( *v25 == v11 )
      {
        ++v14;
      }
      else if ( v25 == i )
      {
        ++i;
      }
    }
  }
  v27 = 1;
  if ( a6 == -1 )
    v27 = 3;
  else
    --v14;
  if ( v14 )
    result = MiObtainFaultCharges(a1, v14, v27);
  else
    result = 0;
  if ( a6 != -1 )
    ++result;
  *a7 = i;
  *a8 = v19;
  return result;
}
