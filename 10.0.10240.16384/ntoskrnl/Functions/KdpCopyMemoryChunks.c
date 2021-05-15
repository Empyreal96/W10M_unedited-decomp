// KdpCopyMemoryChunks 
 
int __fastcall KdpCopyMemoryChunks(unsigned int a1, unsigned int a2, int a3, unsigned int a4, unsigned int a5, char a6, _DWORD *a7)
{
  unsigned int v7; // lr
  unsigned int v8; // r9
  unsigned int v12; // r4
  unsigned int v13; // r5
  unsigned int v15; // r2
  unsigned int v16; // [sp+8h] [bp-20h]

  v16 = a4;
  v7 = a4;
  v8 = a5;
  if ( a5 > 8 )
  {
    v8 = 8;
  }
  else if ( !a5 )
  {
    v8 = 4;
  }
  v12 = 1;
  v13 = a4;
  if ( a4 )
  {
    do
    {
      if ( v12 < v8 )
      {
        do
        {
          v15 = 2 * v12;
          if ( 2 * v12 > v13 )
            break;
          if ( ((2 * v12 - 1) & a1) != 0 )
            break;
          v12 *= 2;
        }
        while ( v15 < v8 );
      }
      for ( ; v12 > v13; v12 >>= 1 )
        ;
      if ( MmDbgCopyMemory(a1, a2, a3, v12, v12) < 0 )
        break;
      a2 = (__PAIR64__(a2, a1) + v12) >> 32;
      a1 += v12;
      a3 += v12;
      v13 -= v12;
    }
    while ( v13 );
    v7 = v16;
  }
  if ( a7 )
    *a7 = v7 - v13;
  if ( (a6 & 1) != 0 && v13 < v7 )
    return sub_903BF0();
  if ( v13 )
    return -1073741823;
  return 0;
}
