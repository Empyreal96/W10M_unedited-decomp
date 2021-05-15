// MiIsNextVaTrimCandidate 
 
int __fastcall MiIsNextVaTrimCandidate(int a1, _DWORD *a2, int a3, int a4)
{
  _DWORD *v4; // r7
  unsigned int *v5; // r6
  int v7; // r5
  unsigned int *v8; // r4
  int result; // r0
  unsigned int v10; // r2
  unsigned int v11; // r4
  int v12; // r3
  unsigned int v13; // r5
  unsigned int v14; // r2
  unsigned int v15; // r4
  int v16; // r1
  unsigned int v17; // t1
  int varg_r0; // [sp+20h] [bp+8h]
  _DWORD *varg_r1; // [sp+24h] [bp+Ch]

  varg_r0 = a1;
  varg_r1 = a2;
  v4 = *(_DWORD **)(a1 + 92);
  v5 = a2;
  v7 = (((*(_DWORD *)(a2[a3 + 1] * v4[9] + v4[63]) >> 10) & 0x3FFFFC) - 0x40000000) << 10;
  if ( (a4 & 0x80) != 0 )
  {
    v8 = (unsigned int *)(((*(_DWORD *)(a2[a3 + 1] * v4[9] + v4[63]) >> 10) & 0x3FFFFC) - 1073741820);
    if ( ((*(_DWORD *)(a2[a3 + 1] * v4[9] + v4[63]) >> 10) & 0x3FFFFCu) - 3145724 <= 0xFFF
      || ((((*(_DWORD *)(a2[a3 + 1] * v4[9] + v4[63]) >> 10) & 0xFFFC) + 4) & 0xFFF) == 0 )
    {
      return 0xFFFFF;
    }
  }
  else
  {
    if ( ((*(_DWORD *)(a2[a3 + 1] * v4[9] + v4[63]) >> 10) & 0x3FFFFCu) - 3145728 <= 0xFFF
      || ((*(_DWORD *)(a2[a3 + 1] * v4[9] + v4[63]) >> 10) & 0xFFC) == 0 )
    {
      return 0xFFFFF;
    }
    v8 = (unsigned int *)(((*(_DWORD *)(a2[a3 + 1] * v4[9] + v4[63]) >> 10) & 0x3FFFFC) - 1073741828);
  }
  v10 = *v8;
  if ( (*v8 & 2) == 0 )
    return 0xFFFFF;
  if ( (v10 & 0x400) != 0 )
    return 0xFFFFF;
  if ( v8 == (unsigned int *)-1070593024 )
    return 0xFFFFF;
  v11 = v10 >> 12;
  if ( !MI_IS_PFN(v10 >> 12) )
    return 0xFFFFF;
  v12 = MmPfnDatabase + 24 * v11;
  if ( !*(_DWORD *)v12 || (*(_BYTE *)(v12 + 19) & 8) != 0 )
    return 0xFFFFF;
  if ( (a4 & 0x80) != 0 )
    v13 = v7 + 4096;
  else
    v13 = v7 - 4096;
  v14 = MiTryLocateWsle(v13, a1, *(_DWORD *)v12);
  result = 0xFFFFF;
  if ( v14 != 0xFFFFF && v14 >= v4[1] )
  {
    v15 = *v5;
    v16 = 0;
    if ( *v5 )
    {
      while ( 1 )
      {
        v17 = v5[1];
        ++v5;
        if ( v17 == v14 )
          break;
        if ( ++v16 >= v15 )
          goto LABEL_23;
      }
    }
    else
    {
LABEL_23:
      result = v14;
    }
  }
  return result;
}
