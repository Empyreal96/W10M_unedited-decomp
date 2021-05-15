// MiReduceMdl 
 
int __fastcall MiReduceMdl(int a1)
{
  int v1; // r9
  char *v2; // r6
  unsigned int v3; // r4
  int v4; // r7
  int v5; // r5
  unsigned int v6; // r1
  char *v7; // r2
  int v9; // r2
  __int16 v10; // r1
  int v11; // t1
  int v12; // r7

  v1 = *(_DWORD *)(a1 + 20);
  v2 = (char *)(a1 + 28);
  v3 = ((((unsigned __int16)*(_DWORD *)(a1 + 16) + (unsigned __int16)*(_DWORD *)(a1 + 24)) & 0xFFFu) + v1 + 4095) >> 12;
  v4 = dword_6348FC;
  v5 = 0;
  v6 = 0;
  v7 = (char *)(a1 + 28);
  if ( v3 != 1 )
  {
    do
    {
      if ( *(_DWORD *)v7 != dword_6348FC )
        break;
      ++v6;
      ++v5;
      v7 += 4;
    }
    while ( v6 < v3 - 1 );
  }
  if ( v5 )
  {
    v12 = v2 - v7;
    *(_WORD *)(a1 + 4) -= 4 * v5;
    *(_DWORD *)(a1 + 20) = v1 - (v5 << 12);
    do
    {
      ++v6;
      *(_DWORD *)&v7[v12] = *(_DWORD *)v7;
      v7 += 4;
    }
    while ( v6 < v3 );
    v4 = dword_6348FC;
    v3 -= v5;
  }
  if ( *(_DWORD *)(a1 + 4 * (v3 + 6)) == v4 )
    return sub_521C24();
  v9 = 0;
  v10 = *(_WORD *)(a1 + 6) | 0x4000;
  *(_WORD *)(a1 + 6) = v10;
  if ( v3 )
  {
    while ( 1 )
    {
      v11 = *(_DWORD *)v2;
      v2 += 4;
      if ( v11 == dword_6348FC )
        break;
      if ( ++v9 >= v3 )
        return v5;
    }
    *(_WORD *)(a1 + 6) = v10 & 0xBFFF;
  }
  return v5;
}
