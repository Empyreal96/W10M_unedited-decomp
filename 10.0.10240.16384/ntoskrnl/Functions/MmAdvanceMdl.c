// MmAdvanceMdl 
 
int __fastcall MmAdvanceMdl(int a1, unsigned int a2)
{
  __int64 v3; // kr00_8
  int v4; // lr
  int v5; // r4
  unsigned int v6; // r5
  int v7; // r2
  int *v8; // r1
  int v9; // t1
  int v10; // lr
  unsigned int v11; // r1
  unsigned int *i; // r6
  unsigned int v13; // r3

  if ( a2 >= *(_DWORD *)(a1 + 20) )
    return -1073741584;
  byte_6348E8 = 1;
  v3 = *(_QWORD *)(a1 + 20);
  v4 = *(_DWORD *)(a1 + 16);
  v5 = 0;
  v6 = ((((_WORD)v4 + WORD2(v3)) & 0xFFF) + (unsigned int)v3 + 4095) >> 12;
  if ( !HIDWORD(v3) )
    goto LABEL_10;
  v7 = 4096 - HIDWORD(v3);
  if ( a2 >= 4096 - HIDWORD(v3) )
  {
    *(_DWORD *)(a1 + 16) = v4 + 4096;
    *(_DWORD *)(a1 + 24) = 0;
    *(_DWORD *)(a1 + 20) = v3 - v7;
    a2 -= v7;
    if ( (*(_WORD *)(a1 + 6) & 1) != 0 )
      *(_DWORD *)(a1 + 12) += v7;
    v5 = 1;
LABEL_10:
    if ( a2 )
    {
      v5 += a2 >> 12;
      *(_DWORD *)(a1 + 20) -= a2;
      *(_DWORD *)(a1 + 24) = a2 & 0xFFF;
      *(_DWORD *)(a1 + 16) += a2 >> 12 << 12;
      if ( (*(_WORD *)(a1 + 6) & 1) != 0 )
        *(_DWORD *)(a1 + 12) += a2;
    }
    if ( v5 )
    {
      if ( (*(_WORD *)(a1 + 6) & 0x200) != 0 )
      {
        v8 = (int *)(a1 + 4 * (v6 + 7));
        do
        {
          v9 = *v8++;
          ++v6;
        }
        while ( (v9 & 0x80000000) == 0 );
      }
      do
      {
        v10 = *(_DWORD *)(a1 + 28);
        v11 = 0;
        for ( i = (unsigned int *)(a1 + 28); v11 < v6; ++i )
        {
          if ( ++v11 == v6 )
            v13 = v10 | 0x80000000;
          else
            v13 = i[1] & 0x7FFFFFFF;
          *i = v13;
        }
        --v5;
      }
      while ( v5 );
      if ( (*(_WORD *)(a1 + 6) & 0x200) == 0 )
        *(_WORD *)(a1 + 6) |= 0x200u;
    }
    return 0;
  }
  *(_DWORD *)(a1 + 20) = v3 - a2;
  *(_DWORD *)(a1 + 24) = HIDWORD(v3) + a2;
  if ( (*(_WORD *)(a1 + 6) & 1) != 0 )
    *(_DWORD *)(a1 + 12) += a2;
  return 0;
}
