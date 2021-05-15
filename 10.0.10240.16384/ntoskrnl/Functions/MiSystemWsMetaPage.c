// MiSystemWsMetaPage 
 
int __fastcall MiSystemWsMetaPage(int a1, int **a2)
{
  unsigned int v2; // r5
  int *v3; // r4
  unsigned int v4; // r2
  int v5; // r0
  unsigned int v6; // r6
  unsigned int v7; // r1
  unsigned int v8; // r2
  int result; // r0

  v2 = 0;
  v3 = &dword_634E00;
  do
  {
    if ( v3[12] )
    {
      v4 = v3[23];
      v5 = 0;
      v6 = (((unsigned int)(*(_DWORD *)(v4 + 56) - 1) >> 10) & 0x3FFFFC) - 0x40000000;
      v7 = ((v4 >> 10) & 0x3FFFFC) - 0x40000000;
      v8 = *(_DWORD *)(a1 + 4) | 0x80000000;
      if ( v8 >= 0xC0000000 )
      {
        while ( v8 <= 0xC03FFFFF && ((v8 >> 10) & 0x3FFFFC) != 3148800 )
        {
          if ( v8 <= v6 && v8 >= v7 )
          {
            if ( v5 )
              result = 2;
            else
              result = 1;
            *a2 = v3;
            return result;
          }
          if ( v5 != 1 )
          {
            v8 <<= 10;
            ++v5;
            v7 &= 0xFFFFF000;
            if ( v8 >= 0xC0000000 )
              continue;
          }
          break;
        }
      }
    }
    ++v2;
    v3 += 32;
  }
  while ( v2 < 3 );
  return 0;
}
