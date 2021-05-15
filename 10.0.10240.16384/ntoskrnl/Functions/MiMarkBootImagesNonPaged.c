// MiMarkBootImagesNonPaged 
 
_DWORD *__fastcall MiMarkBootImagesNonPaged(int a1)
{
  _DWORD *result; // r0
  _DWORD *i; // r1
  _DWORD *v3; // t1
  unsigned int v4; // r2
  unsigned int *v5; // r8
  unsigned int v6; // r9
  unsigned int v7; // r4
  unsigned int v8; // t1

  v3 = *(_DWORD **)(a1 + 16);
  result = (_DWORD *)(a1 + 16);
  for ( i = v3; i != result; i = (_DWORD *)*i )
  {
    v4 = i[6];
    if ( (*(_DWORD *)(((v4 >> 20) & 0xFFC) - 1070596096) & 0x402) != 1026 )
    {
      v5 = (unsigned int *)(((v4 >> 10) & 0x3FFFFC) - 0x40000000);
      v6 = 0;
      if ( v5 > &v5[(unsigned int)(i[8] + 4095) >> 12] )
        v7 = 0;
      else
        v7 = (4 * ((unsigned int)(i[8] + 4095) >> 12) + 3) >> 2;
      if ( v7 )
      {
        do
        {
          v8 = *v5++;
          ++v6;
          *(_BYTE *)(MmPfnDatabase + 24 * (v8 >> 12) + 19) |= 8u;
        }
        while ( v6 < v7 );
      }
    }
  }
  return result;
}
