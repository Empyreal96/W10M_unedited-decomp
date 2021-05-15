// MiFindClearBitsAligned 
 
int __fastcall MiFindClearBitsAligned(unsigned int *a1, unsigned int a2, unsigned int a3)
{
  unsigned int v4; // r3
  int result; // r0
  unsigned int v6; // r7
  unsigned int v7; // r4
  unsigned int v8; // r6
  unsigned int v9; // r2
  _DWORD *i; // r5

  v4 = *a1;
  result = -1;
  if ( a2 < v4 )
  {
    v6 = v4 - a2;
    v7 = 64;
    if ( a3 < v4 && a3 > 0x40 )
      v7 = (a3 + 63) & 0xFFFFFFC0;
    if ( v7 <= v6 )
    {
      v8 = a1[1];
      while ( 1 )
      {
        v9 = 0;
        for ( i = (_DWORD *)(v8 + 4 * (v7 >> 5)); v9 < a2; v9 += 32 )
        {
          if ( *i++ )
            break;
        }
        if ( v9 == a2 )
          break;
        v7 = ((v7 + v9) & 0xFFFFFFC0) + 64;
        if ( v7 > v6 )
          return result;
      }
      result = v7;
    }
  }
  return result;
}
